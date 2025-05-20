//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_LENGTH 256

void log_event(const char *event);
const char *get_current_time();

int main(int argc, char *argv[]) {
    // Ensure user has provided an event message to log
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <event_message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Join arguments to form a complete event message
    char event_message[MAX_EVENT_LENGTH] = "";
    for (int i = 1; i < argc; i++) {
        strcat(event_message, argv[i]);
        if (i < argc - 1) {
            strcat(event_message, " "); // Add a space between words
        }
    }

    // Log the event
    log_event(event_message);
    printf("Event logged: %s\n", event_message);

    return EXIT_SUCCESS;
}

void log_event(const char *event) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }

    const char *timestamp = get_current_time();
    fprintf(file, "[%s] %s\n", timestamp, event);
    fclose(file);
}

const char *get_current_time() {
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    static char formatted_time[20];

    // Format: YYYY-MM-DD HH:MM:SS
    strftime(formatted_time, sizeof(formatted_time), "%Y-%m-%d %H:%M:%S", tm_struct);
    return formatted_time;
}