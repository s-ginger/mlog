# mlog — минималистичный логгер на C

Простая и лёгкая библиотека для логирования в C с поддержкой уровней логов, вывода времени и режима разработчика.

## Возможности
- Уровни логов: `INFO`, `WARN`, `ERROR`, `FATAL`, `DEBUG`
- Вывод времени (можно отключить)
- Режим разработчика для включения `DEBUG` логов
- Поддержка форматирования как в `printf`
- Лёгкая интеграция через [FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html)

---

## Установка через FetchContent

```cmake
include(FetchContent)

FetchContent_Declare(
    mlog
    GIT_REPOSITORY https://github.com/s-ginger/mlog
    GIT_TAG main
)

FetchContent_MakeAvailable(mlog)

add_executable(myapp main.c)
target_link_libraries(myapp PRIVATE mlog)
