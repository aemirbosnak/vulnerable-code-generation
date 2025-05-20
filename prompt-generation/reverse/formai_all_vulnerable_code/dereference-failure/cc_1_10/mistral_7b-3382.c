//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100
#define EVENT_LEN 256
#define LOG_FILE "holmes_log.txt"

struct event {
    char timestamp[20];
    char description[EVENT_LEN];
};

void log_event(char *description) {
    FILE *log_file;
    struct event current_event;
    time_t rawtime;
    struct tm *timeinfo;

    log_file = fopen(LOG_FILE, "a");

    if (log_file == NULL) {
        perror("Unable to open log file");
        return;
    }

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(current_event.timestamp, sizeof(current_event.timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);
    strcpy(current_event.description, description);

    fwrite(&current_event, sizeof(struct event), 1, log_file);
    fclose(log_file);

    printf("Event logged: %s - %s\n", current_event.timestamp, current_event.description);
}

void main(int argc, char *argv[]) {
    char event_description[EVENT_LEN];

    if (argc < 2) {
        printf("Usage: %s [event description]\n", argv[0]);
        return;
    }

    strcpy(event_description, argv[1]);

    log_event(event_description);
}

// Example usage:
// gcc sherlock_logger.c -o sherlock_logger
// ./sherlock_logger "Professor Moriarty was seen at 221B Baker Street"