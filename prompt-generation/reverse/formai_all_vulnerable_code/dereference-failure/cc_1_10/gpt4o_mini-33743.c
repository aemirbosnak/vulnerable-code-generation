//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_LENGTH 256

void log_event(const char *level, const char *message);
void get_timestamp(char *buffer, size_t size);
void display_usage(const char *program_name);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *level = argv[1];
    const char *message = argv[2];

    if (strcmp(level, "INFO") != 0 && strcmp(level, "WARNING") != 0 && strcmp(level, "ERROR") != 0) {
        fprintf(stderr, "Error: Log level must be INFO, WARNING, or ERROR.\n");
        return EXIT_FAILURE;
    }

    log_event(level, message);
    printf("Event logged successfully.\n");
    return EXIT_SUCCESS;
}

void log_event(const char *level, const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }

    char timestamp[20];
    get_timestamp(timestamp, sizeof(timestamp));

    fprintf(file, "[%s] [%s] %s\n", timestamp, level, message);
    fclose(file);
}

void get_timestamp(char *buffer, size_t size) {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", timeinfo);
}

void display_usage(const char *program_name) {
    printf("Usage: %s <log level> <message>\n", program_name);
    printf("Log level can be INFO, WARNING, or ERROR.\n");
}