//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define BUFFER_SIZE 256

typedef struct {
    time_t timestamp;
    char event_type[50];
    char event_description[200];
} LogEvent;

// Function declarations
void log_event(const char *event_type, const char *event_description);
void write_log(LogEvent event);
void print_log();
void initialize_log();
void display_help();

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <event_type> <event_description>\n", argv[0]);
        display_help();
        return EXIT_FAILURE;
    }

    initialize_log();

    const char *event_type = argv[1];
    char event_description[BUFFER_SIZE] = "";

    for (int i = 2; i < argc; i++) {
        strcat(event_description, argv[i]);
        if (i < argc - 1) {
            strcat(event_description, " ");  // Add space between words
        }
    }

    log_event(event_type, event_description);
    print_log(); // Optionally print the log after logging

    return EXIT_SUCCESS;
}

void initialize_log() {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Failed to initialize log file");
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

void log_event(const char *event_type, const char *event_description) {
    LogEvent event;
    event.timestamp = time(NULL);
    strncpy(event.event_type, event_type, sizeof(event.event_type) - 1);
    event.event_type[sizeof(event.event_type) - 1] = '\0'; // Ensure null termination
    strncpy(event.event_description, event_description, sizeof(event.event_description) - 1);
    event.event_description[sizeof(event.event_description) - 1] = '\0'; // Ensure null termination

    write_log(event);
}

void write_log(LogEvent event) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Error opening log file for writing");
        exit(EXIT_FAILURE);
    }

    char time_buf[26];
    struct tm* tm_info;

    tm_info = localtime(&event.timestamp);
    strftime(time_buf, 26, "%Y-%m-%d %H:%M:%S", tm_info);

    fprintf(file, "[%s] [%s]: %s\n", time_buf, event.event_type, event.event_description);
    fclose(file);
}

void print_log() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Error opening log file for reading");
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        printf("%s", buffer);
    }
    
    fclose(file);
}

void display_help() {
    printf("Event Logger Help:\n");
    printf("This program logs events to a file ('%s') and displays them.\n", LOG_FILE);
    printf("To log an event, use the following format:\n");
    printf("  ./event_logger <event_type> <event_description>\n");
    printf("Example:\n");
    printf("  ./event_logger INFO \"Application started\"\n");
    printf("Event types can include INFO, WARNING, ERROR, and others of your choosing.\n");
    printf("Each entry will be timestamped and stored in the log file.\n");
}