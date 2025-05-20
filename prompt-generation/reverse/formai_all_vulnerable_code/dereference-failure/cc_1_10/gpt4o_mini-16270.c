//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENT_LENGTH 256

void log_event(const char *event) {
    FILE *logfile = fopen("event_log.txt", "a");
    if (logfile == NULL) {
        fprintf(stderr, "Error opening log file!\n");
        return;
    }

    // Get current time
    time_t now;
    time(&now);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // Remove newline character

    // Write the event with timestamp to the file
    fprintf(logfile, "[%s] %s\n", time_str, event);
    fclose(logfile);
    printf("Event logged: %s\n", event);
}

void display_events() {
    FILE *logfile = fopen("event_log.txt", "r");
    if (logfile == NULL) {
        fprintf(stderr, "Error opening log file!\n");
        return;
    }

    printf("\n----- Event Log -----\n");
    char buffer[MAX_EVENT_LENGTH];
    while (fgets(buffer, MAX_EVENT_LENGTH, logfile)) {
        printf("%s", buffer);
    }
    fclose(logfile);
}

int main() {
    char event[MAX_EVENT_LENGTH];
    int running = 1;

    printf("Welcome to the Event Logger!\n");

    while (running) {
        printf("Please enter an event (or type 'exit' to quit, 'display' to see events): ");
        fgets(event, MAX_EVENT_LENGTH, stdin);
        event[strcspn(event, "\n")] = 0; // Remove newline character

        if (strcmp(event, "exit") == 0) {
            running = 0; // Exit the loop
            printf("Exiting the program...\n");
        } else if (strcmp(event, "display") == 0) {
            display_events(); // Display all logged events
        } else if (strlen(event) > 0) {
            log_event(event); // Log the entered event
        } else {
            printf("Please enter a valid event!\n");
        }
    }

    return 0;
}