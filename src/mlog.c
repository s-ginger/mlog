#include <stdlib.h>
#include <string.h>
#include "mlog.h"

mlogger global_logger;

void logger_init(LogLevel level, FILE* output, int show_time, int dev_mode) {
    global_logger.min_level = level;
    global_logger.output = output;
    global_logger.show_timestamp = show_time;
    global_logger.is_dev_mode = dev_mode;
}

void logger_log(LogLevel level, const char* format, ...) {
    // фильтрация по уровню
    if (level < global_logger.min_level) {
        return;
    }
    // отключаем DEBUG в проде
    if (level == LOG_DEBUG && !global_logger.is_dev_mode) {
        return;
    }

    FILE* out = global_logger.output ? global_logger.output : stdout;

    // время
    if (global_logger.show_timestamp) {
        char timebuf[20];
        time_now(timebuf, sizeof(timebuf));
        fprintf(out, "[%s] ", timebuf);
    }

    // уровень
    fprintf(out, "%s: ", level_to_str(level));

    // сообщение
    va_list args;
    va_start(args, format);
    vfprintf(out, format, args);
    va_end(args);

    fputc('\n', out);
}

const char* level_to_str(LogLevel level) {
    switch (level) {
        case LOG_INFO:  return "INFO";
        case LOG_WARN:  return "WARN";
        case LOG_ERROR: return "ERROR";
        case LOG_FATAL: return "FATAL";
        case LOG_DEBUG: return "DEBUG";
        default:        return "UNKNOWN";
    }
}

void time_now(char *buf, size_t buf_size) {
    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);
    snprintf(buf, buf_size, "%02d-%02d-%04d %02d:%02d:%02d",
             timeinfo->tm_mday,
             timeinfo->tm_mon + 1,
             timeinfo->tm_year + 1900,
             timeinfo->tm_hour,
             timeinfo->tm_min,
             timeinfo->tm_sec);
}
