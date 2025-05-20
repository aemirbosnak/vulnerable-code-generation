//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#define MAX_LOG_SIZE 1024
#define LOG_FILE "event_log.txt"

void get_current_time(char *buffer, size_t size) {
    time_t now;
    struct tm *timeinfo;

    time(&now);
    timeinfo = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", timeinfo);
}

void log_event(const char *event_message) {
    FILE *log_file;
    char timestamp[20];

    get_current_time(timestamp, sizeof(timestamp));

    log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    fprintf(log_file, "[%s] %s\n", timestamp, event_message);
    fclose(log_file);
}

void display_help() {
    printf("Command Options:\n");
    printf("  log <message>  - Log an event with the provided message.\n");
    printf("  view           - Display logged events.\n");
    printf("  clear          - Clear the log file.\n");
    printf("  help           - Show this help menu.\n");
    printf("  exit           - Exit the program.\n");
}

void view_logs() {
    FILE *log_file;
    char buffer[MAX_LOG_SIZE];

    log_file = fopen(LOG_FILE, "r");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Event Log:\n");
    while (fgets(buffer, sizeof(buffer), log_file)) {
        printf("%s", buffer);
    }
    fclose(log_file);
}

void clear_logs() {
    if (remove(LOG_FILE) == 0) {
        printf("Log file cleared successfully.\n");
    } else {
        fprintf(stderr, "Unable to clear log file: %s\n", strerror(errno));
    }
}

int main() {
    char command[256];
    char event_message[200];

    printf("Welcome to the C System Event Logger.\n");
    display_help();

    while (1) {
        printf("\nEnter command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove trailing newline

        if (strncmp(command, "log ", 4) == 0) {
            strncpy(event_message, command + 4, sizeof(event_message) - 1);
            log_event(event_message);
            printf("Event logged: %s\n", event_message);
        } else if (strcmp(command, "view") == 0) {
            view_logs();
        } else if (strcmp(command, "clear") == 0) {
            clear_logs();
        } else if (strcmp(command, "help") == 0) {
            display_help();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the logger. Goodbye!\n");
            break;
        } else {
            printf("Unknown command. Use 'help' for a list of commands.\n");
        }
    }

    return 0;
}