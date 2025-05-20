//Falcon-180B DATASET v1.0 Category: System event logger ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define EVENT_LOG_FILE "event_log.txt"

typedef struct {
    time_t timestamp;
    char event_type[16];
    char event_message[256];
} EventLogEntry;

void log_event(const char* event_type, const char* event_message) {
    time_t now = time(NULL);
    struct tm tm = *localtime(&now);

    EventLogEntry entry = {
       .timestamp = now,
       .event_type = strncpy(event_type, "", 15),
       .event_message = strncpy(event_message, "", 255)
    };

    FILE* log_file = fopen(EVENT_LOG_FILE, "a");
    if (log_file == NULL) {
        printf("Error: Could not open event log file.\n");
        exit(1);
    }

    fprintf(log_file, "%04d-%02d-%02d %02d:%02d:%02d %s - %s\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec,
            entry.event_type, entry.event_message);

    fclose(log_file);
}

int main() {
    log_event("INFO", "Program started.");

    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Do something\n");
        printf("2. Do something else\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                log_event("INFO", "Option 1 selected.");
                break;
            case 2:
                log_event("INFO", "Option 2 selected.");
                break;
            case 3:
                log_event("INFO", "Program exited.");
                break;
            default:
                log_event("ERROR", "Invalid option selected.");
        }
    } while (choice!= 3);

    return 0;
}