//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_LENGTH 256

typedef enum {
    INFO,
    WARNING,
    ERROR,
    CRITICAL
} LogLevel;

const char *log_level_names[] = {
    "INFO",
    "WARNING",
    "ERROR",
    "CRITICAL"
};

void log_event(LogLevel level, const char *message) {
    FILE *fp = fopen(LOG_FILE, "a");
    if (fp == NULL) {
        perror("Could not open log file");
        exit(EXIT_FAILURE);
    }

    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    fprintf(fp, "[%04d-%02d-%02d %02d:%02d:%02d] [%s] %s\n",
            local->tm_year + 1900, local->tm_mon + 1, local->tm_mday,
            local->tm_hour, local->tm_min, local->tm_sec,
            log_level_names[level], message);

    fclose(fp);
}

void log_info(const char *message) {
    log_event(INFO, message);
}

void log_warning(const char *message) {
    log_event(WARNING, message);
}

void log_error(const char *message) {
    log_event(ERROR, message);
}

void log_critical(const char *message) {
    log_event(CRITICAL, message);
}

void print_menu() {
    printf("Event Logger Menu:\n");
    printf("1. Log Info\n");
    printf("2. Log Warning\n");
    printf("3. Log Error\n");
    printf("4. Log Critical\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

void clear_log_file() {
    FILE *fp = fopen(LOG_FILE, "w");
    if (fp == NULL) {
        perror("Could not clear log file");
        exit(EXIT_FAILURE);
    }
    fclose(fp);
}

int main() {
    char event_message[MAX_EVENT_LENGTH];
    int choice;

    // Clear existing log entries.
    clear_log_file();

    do {
        print_menu();
        scanf("%d", &choice);
        getchar(); // To consume the newline character from input buffer.

        switch (choice) {
            case 1:
                printf("Enter message for Info log: ");
                fgets(event_message, MAX_EVENT_LENGTH, stdin);
                event_message[strcspn(event_message, "\n")] = 0; // Remove newline
                log_info(event_message);
                break;

            case 2:
                printf("Enter message for Warning log: ");
                fgets(event_message, MAX_EVENT_LENGTH, stdin);
                event_message[strcspn(event_message, "\n")] = 0; // Remove newline
                log_warning(event_message);
                break;

            case 3:
                printf("Enter message for Error log: ");
                fgets(event_message, MAX_EVENT_LENGTH, stdin);
                event_message[strcspn(event_message, "\n")] = 0; // Remove newline
                log_error(event_message);
                break;

            case 4:
                printf("Enter message for Critical log: ");
                fgets(event_message, MAX_EVENT_LENGTH, stdin);
                event_message[strcspn(event_message, "\n")] = 0; // Remove newline
                log_critical(event_message);
                break;

            case 5:
                printf("Exiting the logger. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}