//LLAMA2-13B DATASET v1.0 Category: System event logger ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <syslog.h>

#define MAX_EVENT_LEN 1024
#define MAX_LOG_FILES 10

typedef struct {
    char *message;
    time_t timestamp;
} event_t;

typedef struct {
    char *filename;
    FILE *file;
} log_file_t;

static log_file_t log_files[MAX_LOG_FILES];

void init_log(void) {
    int i;

    for (i = 0; i < MAX_LOG_FILES; i++) {
        log_files[i].filename = malloc(sizeof("log_%d.txt") * sizeof(char) + 1);
        sprintf(log_files[i].filename, "log_%d.txt", i);
        log_files[i].file = fopen(log_files[i].filename, "w");
        if (log_files[i].file == NULL) {
            perror("Failed to open log file");
            exit(EXIT_FAILURE);
        }
    }
}

void log_event(const char *message) {
    event_t event;
    char timestamp[32];

    gettimeofday(&event.timestamp, NULL);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&event.timestamp));
    event.message = malloc(sizeof(message) * sizeof(char) + 1);
    strcpy(event.message, message);

    int i;
    for (i = 0; i < MAX_LOG_FILES; i++) {
        if (log_files[i].file != NULL) {
            fprintf(log_files[i].file, "%s %s\n", timestamp, event.message);
            free(event.message);
            break;
        }
    }
}

int main(void) {
    init_log();

    log_event("System started");
    log_event("User logged in");
    log_event("User logged out");

    return 0;
}