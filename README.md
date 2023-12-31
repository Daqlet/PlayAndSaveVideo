# PlayAndSaveVideo

Описание программы:
------------------

Программа "PlayAndSaveVideo" является примером использования библиотеки GStreamer на языке программирования C++ для выполнения базовых операций с видео, таких как открытие, обработка и сохранение видеофайлов под другим именем.

## Цель программы

Целью этой программы является демонстрация простого примера использования GStreamer для работы с видео в контексте C++.

## Требования

Для успешной компиляции и запуска программы необходимо выполнить следующие требования:

1. **GStreamer**: Убедитесь, что у вас установлена библиотека GStreamer вместе с необходимыми плагинами для работы с видео.

## Как использовать программу

Чтобы использовать программу "GStreamer Video Processing Example", выполните следующие шаги:

1. **Компиляция**: Скомпилируйте программу с помощью вашей среды разработки или командной строки. Убедитесь, что правильно настроены пути к заголовочным файлам и библиотекам GStreamer.

   ```bash
   g++ main.cpp -o video_processor `pkg-config --cflags --libs gstreamer-1.0`
   ```

2. **Запуск**: Запустите программу с двумя аргументами командной строки: путем к исходному видеофайлу и путем для сохранения обработанного видеофайла.

   ```bash
   ./video_processor input.mp4 output.mp4
   ```

3. **Обработка видео**: Программа откроет видео из `input.mp4`, показывает видео на экране и сохранит результат в `output.mp4`.

## Примечания

- Этот пример использует элементы GStreamer, такие как `filesrc`, `filesink` и `playbin`, для управления видео. Вы можете настроить этот конвейер и добавить дополнительные элементы для более сложной обработки видео в соответствии с вашими потребностями.

- Убедитесь, что у вас установлены необходимые кодеки и плагины GStreamer для правильной обработки видео.

- Этот пример ориентирован на работу с видео в формате H.264, и вы можете настроить элементы конвейера и кодеки в соответствии с вашими потребностями.
