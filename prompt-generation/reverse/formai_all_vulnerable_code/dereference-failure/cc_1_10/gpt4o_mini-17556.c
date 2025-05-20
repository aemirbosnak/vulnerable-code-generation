//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define LOG_FILENAME "event.log"
#define MAX_EVENT_LENGTH 256
#define TIMESTAMP_LENGTH 20

void get_current_time(char *buffer, size_t length) {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, length, "%Y-%m-%d %H:%M:%S", timeinfo);
}

void log_event(const char *event) {
    FILE *file = fopen(LOG_FILENAME, "a");
    if (!file) {
        perror("Failed to open log file");
        return;
    }

    char timestamp[TIMESTAMP_LENGTH];
    get_current_time(timestamp, sizeof(timestamp));

    fprintf(file, "[%s] %s\n", timestamp, event);
    fclose(file);
}

void read_log_file() {
    FILE *file = fopen(LOG_FILENAME, "r");
    if (!file) {
        perror("Failed to open log file");
        return;
    }

    char line[MAX_EVENT_LENGTH + TIMESTAMP_LENGTH + 10]; // buffer to read a line
    printf("Event Log:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void simulate_event(const char *event_message) {
    printf("Simulating event: %s...\n", event_message);
    sleep(1);  // simulate some delay
    log_event(event_message);
    printf("Event logged: %s\n", event_message);
}

void print_help() {
    printf("Event Logger Command Line Interface\n");
    printf("Usage:\n");
    printf("  log <event>       Log an event with the provided message\n");
    printf("  read              Read and display the log file\n");
    printf("  help              Show this help message\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "No command provided. Type 'help' for usage.\n");
        return 1;
    }

    if (strcmp(argv[1], "log") == 0 && argc == 3) {
        simulate_event(argv[2]);
    } else if (strcmp(argv[1], "read") == 0) {
        read_log_file();
    } else if (strcmp(argv[1], "help") == 0) {
        print_help();
    } else {
        fprintf(stderr, "Invalid command. Type 'help' for usage.\n");
        return 1;
    }

    return 0;
}