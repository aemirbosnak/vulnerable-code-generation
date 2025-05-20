//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOG_FILE "event_log.txt"
#define BUFFER_SIZE 256

typedef enum {
    INFO,
    WARNING,
    ERROR
} LogLevel;

const char *logLevelNames[] = { "INFO", "WARNING", "ERROR" };

void logEvent(LogLevel level, const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Failed to open log file");
        return;
    }

    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    // Removing the newline character added by ctime
    timestamp[strlen(timestamp) - 1] = '\0';

    fprintf(file, "[%s] [%s]: %s\n", timestamp, logLevelNames[level], message);
    fclose(file);
}

void displayMenu() {
    printf("Event Logger Menu:\n");
    printf("1. Log Information\n");
    printf("2. Log Warning\n");
    printf("3. Log Error\n");
    printf("4. Display Logs\n");
    printf("5. Exit\n");
}

void displayLogs() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Failed to open log file");
        return;
    }

    char buffer[BUFFER_SIZE];
    printf("Event Logs:\n");
    while (fgets(buffer, BUFFER_SIZE, file)) {
        printf("%s", buffer);
    }
    fclose(file);
}

void logUserInput(LogLevel level) {
    char input[BUFFER_SIZE];
    
    printf("Enter your message: ");
    if (fgets(input, BUFFER_SIZE, stdin) != NULL) {
        // Removing the newline character
        input[strcspn(input, "\n")] = 0;
        logEvent(level, input);
    }
}

int main() {
    int choice;

    // Creating an empty log file if it doesn't exist
    FILE *file = fopen(LOG_FILE, "a");
    if (file) {
        fclose(file);
    } else {
        perror("Failed to create log file");
    }

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        switch (choice) {
        case 1:
            logUserInput(INFO);
            break;
        case 2:
            logUserInput(WARNING);
            break;
        case 3:
            logUserInput(ERROR);
            break;
        case 4:
            displayLogs();
            break;
        case 5:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}