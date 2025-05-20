//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

#define MAX_LOG_SIZE 1024
#define LOG_FILE "system_events.log"
#define MAX_EVENT_TYPE_LENGTH 32

typedef enum {
    INFO,
    WARNING,
    ERROR,
    DEBUG,
} LogLevel;

typedef struct {
    LogLevel level;
    char message[MAX_LOG_SIZE];
    time_t timestamp;
} LogEvent;

typedef struct {
    LogEvent *events;
    int event_count;
    int event_capacity;
    pthread_mutex_t lock;
} EventLogger;

void initialize_logger(EventLogger *logger, int capacity) {
    logger->events = malloc(capacity * sizeof(LogEvent));
    logger->event_count = 0;
    logger->event_capacity = capacity;
    pthread_mutex_init(&logger->lock, NULL);
}

void log_event(EventLogger *logger, LogLevel level, const char *message) {
    pthread_mutex_lock(&logger->lock);

    if (logger->event_count < logger->event_capacity) {
        LogEvent *event = &logger->events[logger->event_count++];
        event->level = level;
        strncpy(event->message, message, MAX_LOG_SIZE);
        event->timestamp = time(NULL);
    } else {
        printf("Log capacity reached! Consider increasing capacity.\n");
    }
    
    pthread_mutex_unlock(&logger->lock);
}

void write_logs_to_file(EventLogger *logger) {
    pthread_mutex_lock(&logger->lock);
    
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Failed to open log file");
        pthread_mutex_unlock(&logger->lock);
        return;
    }

    for (int i = 0; i < logger->event_count; i++) {
        LogEvent *event = &logger->events[i];
        char *level_str = "";
        
        switch (event->level) {
            case INFO: level_str = "INFO"; break;
            case WARNING: level_str = "WARNING"; break;
            case ERROR: level_str = "ERROR"; break;
            case DEBUG: level_str = "DEBUG"; break;
        }
        
        fprintf(file, "[%s] [%s] %s\n", ctime(&event->timestamp), level_str, event->message);
    }
    
    fclose(file);
    logger->event_count = 0;
    pthread_mutex_unlock(&logger->lock);
}

void free_logger(EventLogger *logger) {
    pthread_mutex_destroy(&logger->lock);
    free(logger->events);
}

// Sample function to simulate events
void *simulate_events(void *arg) {
    EventLogger *logger = (EventLogger *)arg;

    log_event(logger, INFO, "System started.");
    log_event(logger, WARNING, "Low memory warning.");
    log_event(logger, ERROR, "Disk read failure.");
    log_event(logger, DEBUG, "Debugging session started.");
    log_event(logger, INFO, "User logged in.");
    
    write_logs_to_file(logger);
    
    return NULL;
}

int main() {
    EventLogger logger;
    initialize_logger(&logger, 100);

    pthread_t thread;
    pthread_create(&thread, NULL, simulate_events, &logger);
    pthread_join(thread, NULL);

    free_logger(&logger);
    return 0;
}