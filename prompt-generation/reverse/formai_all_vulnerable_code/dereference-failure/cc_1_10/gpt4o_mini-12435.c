//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define LOG_FILE "system_events.log"
#define MAX_EVENT_LENGTH 256

void log_event(const char *event_message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }

    time_t current_time;
    char *c_time_string;

    // Get the current time
    current_time = time(NULL);
    if (current_time == ((time_t)-1)) {
        perror("Failure to obtain the current time");
        fclose(log_file);
        exit(EXIT_FAILURE);
    }

    // Convert to local time format
    c_time_string = ctime(&current_time);
    if (c_time_string == NULL) {
        perror("Failure to convert the current time");
        fclose(log_file);
        exit(EXIT_FAILURE);
    }

    // Strip newline character from c_time_string
    c_time_string[strcspn(c_time_string, "\n")] = 0;

    // Write the log entry
    fprintf(log_file, "[%s] %s\n", c_time_string, event_message);
    fclose(log_file);
}

void simulate_events() {
    const char *events[] = {
        "System booted successfully.",
        "User logged in.",
        "File opened: /etc/passwd",
        "File system check initiated.",
        "Network connection established.",
        "User logged out.",
        "System shutting down.",
        "Kernel updated successfully.",
        "Disk space checked: 70% free.",
        "Service started: apache2."
    };
    
    size_t number_of_events = sizeof(events) / sizeof(events[0]);
    for (size_t i = 0; i < number_of_events; i++) {
        log_event(events[i]);
        sleep(1);  // Wait for 1 second before logging the next event
    }
}

void display_logs() {
    FILE *log_file = fopen(LOG_FILE, "r");
    if (log_file == NULL) {
        perror("Unable to open log file for reading");
        exit(EXIT_FAILURE);
    }

    char line[MAX_EVENT_LENGTH];
    printf("Event Log:\n");
    while (fgets(line, sizeof(line), log_file) != NULL) {
        printf("%s", line);
    }
    fclose(log_file);
}

void clear_logs() {
    if (remove(LOG_FILE) != 0) {
        perror("Error deleting log file");
    } else {
        printf("Log file cleared.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nSystem Event Logger\n");
        printf("1. Simulate Events\n");
        printf("2. Display Logs\n");
        printf("3. Clear Logs\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                simulate_events();
                break;
            case 2:
                display_logs();
                break;
            case 3:
                clear_logs();
                break;
            case 4:
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option, try again.\n");
        }
    }

    return 0;
}