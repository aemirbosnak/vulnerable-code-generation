//FormAI DATASET v1.0 Category: System event logger ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    INFO = 1,
    WARN = 2,
    ERROR = 3
} LogLevel;

typedef struct {
    LogLevel log_level;
    char *message;
    time_t timestamp;
} LogEvent;

typedef struct {
    LogEvent *events;
    int num_events;
    int max_size;
} SystemEventLogger;

void log_event(SystemEventLogger *logger, LogEvent event) {
    if (logger->num_events == logger->max_size) {
        logger->max_size *= 2;
        logger->events = realloc(logger->events, logger->max_size * sizeof(LogEvent));
    }
    logger->events[logger->num_events++] = event;
}

void print_event(LogEvent event) {
    char *level;
    switch (event.log_level) {
        case INFO:
            level = "INFO";
            break;
        case WARN:
            level = "WARN";
            break;
        case ERROR:
            level = "ERROR";
            break;
    }
    char *time_str = ctime(&event.timestamp);
    time_str[strlen(time_str) - 1] = '\0';
    printf("[%s] %s - %s\n", time_str, level, event.message);
}

void print_events(SystemEventLogger *logger) {
    for (int i = 0; i < logger->num_events; i++) {
        print_event(logger->events[i]);
    }
}

void free_logger(SystemEventLogger *logger) {
    free(logger->events);
    free(logger);
}

int main() {
    SystemEventLogger *logger = malloc(sizeof(SystemEventLogger));
    logger->max_size = 10;
    logger->num_events = 0;
    logger->events = malloc(logger->max_size * sizeof(LogEvent));

    LogEvent event1 = {INFO, "System initialized", time(NULL)};
    log_event(logger, event1);

    LogEvent event2 = {WARN, "Low disk space", time(NULL)};
    log_event(logger, event2);

    LogEvent event3 = {ERROR, "Failed to connect to database", time(NULL)};
    log_event(logger, event3);

    print_events(logger);

    free_logger(logger);

    return 0;
}