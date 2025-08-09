#ifndef MLOG_H
#define MLOG_H

#include <stdio.h>
#include <stdarg.h>
#include <time.h> 

typedef enum {
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
    LOG_FATAL,
    LOG_DEBUG
} LogLevel;

typedef struct {
    LogLevel min_level;   
    FILE* output;         
    int show_timestamp;   // 1 — показывать время
    int is_dev_mode;      // 1 — разрешать DEBUG
} mlogger;

extern mlogger global_logger;

void logger_init(LogLevel level, FILE* output, int show_time, int dev_mode);
void logger_log(LogLevel level, const char* format, ...);
const char* level_to_str(LogLevel level);
void time_now(char *buf, size_t buf_size);

#define TRUE 1
#define FALSE 0

#define LOG_DEBUG(...) logger_log(LOG_DEBUG, __VA_ARGS__)
#define LOG_INFO(...)  logger_log(LOG_INFO, __VA_ARGS__)
#define LOG_WARN(...)  logger_log(LOG_WARN, __VA_ARGS__)
#define LOG_ERROR(...) logger_log(LOG_ERROR, __VA_ARGS__)
#define LOG_FATAL(...) logger_log(LOG_FATAL, __VA_ARGS__)

#endif
