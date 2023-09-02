#include <gst/gst.h>
#include <string>

int main(int argc, char* argv[]) {
    // Инициализируем GStreamer
    gst_init(&argc, &argv);

    std::string inputVideoPath = argv[1];
    std::string outputVideoPath = argv[2];

    // Создаем конвейер
    GstElement* pipeline = gst_pipeline_new("video-processing-pipeline");

    // Создаем элементы конвейера
    GstElement* source = gst_element_factory_make("filesrc", "file-source");
    GstElement* sink = gst_element_factory_make("filesink", "file-sink");

    // Устанавливаем имена файлов исходного и целевого видео
    g_object_set(G_OBJECT(source), "location", inputVideoPath.c_str(), NULL);
    g_object_set(G_OBJECT(sink), "location", outputVideoPath.c_str(), NULL);

    std::string command = std::string("playbin uri=file:///" + inputVideoPath);
    GstElement* play = gst_parse_launch(command.c_str(), NULL);

    if (!pipeline || !source || !sink || !play) {
        g_error("Failed to create one or more elements.");
        return -1;
    }

    // Добавляем элементы в конвейер
    gst_bin_add_many(GST_BIN(pipeline), source, sink, play, NULL);

    // Соединяем элементы конвейера
    gst_element_link(source, sink);

    // Запускаем конвейер
    GstStateChangeReturn ret = gst_element_set_state(pipeline, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_FAILURE) {
        g_error("Failed to start pipeline.");
        return -1;
    }

    // Ожидаем завершения конвейера
    GstBus* bus = gst_element_get_bus(pipeline);
    GstMessage* msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_EOS);

    if (msg != NULL) {
        gst_message_unref(msg);
    }

    // Освобождаем ресурсы
    gst_object_unref(bus);
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);
    gst_deinit();

    return 0;
}
