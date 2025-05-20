//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_LENGTH 256

void log_event(const char *event) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }
    
    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    timestamp[strcspn(timestamp, "\n")] = 0; // Remove newline character from ctime string

    fprintf(file, "[%s] %s\n", timestamp, event);
    fclose(file);
}

void simulate_user_login(const char *username) {
    char event[MAX_EVENT_LENGTH];
    snprintf(event, MAX_EVENT_LENGTH, "User %s logged in.", username);
    log_event(event);
}

void simulate_file_access(const char *filename) {
    char event[MAX_EVENT_LENGTH];
    snprintf(event, MAX_EVENT_LENGTH, "File %s accessed.", filename);
    log_event(event);
}

void simulate_user_logout(const char *username) {
    char event[MAX_EVENT_LENGTH];
    snprintf(event, MAX_EVENT_LENGTH, "User %s logged out.", username);
    log_event(event);
}

void print_log_contents() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Unable to read log file");
        return;
    }

    char line[512];
    printf("Event Log:\n");
    
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

int main() {
    char username[50];
    
    // Gather a sample username
    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0; // Remove newline character

    // Simulate user actions
    simulate_user_login(username);
    sleep(1); // Simulate time between events

    simulate_file_access("example.txt");
    sleep(1); // Simulate time between events

    simulate_user_logout(username);
    sleep(1); // Simulate time between events

    // Print the contents of the event log
    print_log_contents();

    return 0;
}