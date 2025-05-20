//LLAMA2-13B DATASET v1.0 Category: System event logger ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENT_LENGTH 1024
#define MAX_LOG_SIZE 1024 * 1024

// Structure to store event data
typedef struct {
    char timestamp[20];
    char event_type[50];
    char message[MAX_EVENT_LENGTH];
} event_t;

// Function to format timestamp
char *format_timestamp(time_t t) {
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&t));
    return buffer;
}

// Function to log an event
void log_event(event_t *event) {
    // Open log file
    FILE *log_file = fopen("log.txt", "a");

    // Write timestamp and event type
    fprintf(log_file, "%s %s: %s\n", format_timestamp(time(NULL)), event->event_type, event->message);

    // Write message to log file
    fprintf(log_file, "%s\n", event->message);

    // Close log file
    fclose(log_file);
}

int main() {
    // Initialize event buffer
    event_t event;
    memset(event.timestamp, 0, sizeof(event.timestamp));
    memset(event.event_type, 0, sizeof(event.event_type));
    memset(event.message, 0, sizeof(event.message));

    // Read events from standard input
    char input[1024];
    while (fgets(input, 1024, stdin) != NULL) {
        // Parse event data
        char *token = strtok(input, ":");
        strcpy(event.timestamp, token);
        token = strtok(NULL, ":");
        strcpy(event.event_type, token);
        token = strtok(NULL, "\n");
        strcpy(event.message, token);

        // Log event
        log_event(&event);
    }

    return 0;
}