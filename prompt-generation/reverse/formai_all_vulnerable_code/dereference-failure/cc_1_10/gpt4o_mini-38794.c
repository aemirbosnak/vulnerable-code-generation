//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_LENGTH 256

typedef enum {
    LOGIN,
    LOGOUT,
    FILE_ACCESS,
    FILE_MODIFY,
    SYSTEM_ERROR
} EventType;

const char* eventTypeToString(EventType type) {
    switch (type) {
        case LOGIN: return "LOGIN";
        case LOGOUT: return "LOGOUT";
        case FILE_ACCESS: return "FILE_ACCESS";
        case FILE_MODIFY: return "FILE_MODIFY";
        case SYSTEM_ERROR: return "SYSTEM_ERROR";
        default: return "UNKNOWN_EVENT";
    }
}

void logEvent(EventType eventType, const char *description) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }

    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline

    fprintf(file, "[%s] - %s: %s\n", timestamp, eventTypeToString(eventType), description);
    fclose(file);
}

void performLogin(const char *username) {
    char message[MAX_EVENT_LENGTH];
    snprintf(message, sizeof(message), "User '%s' logged in.", username);
    logEvent(LOGIN, message);
}

void performLogout(const char *username) {
    char message[MAX_EVENT_LENGTH];
    snprintf(message, sizeof(message), "User '%s' logged out.", username);
    logEvent(LOGOUT, message);
}

void logFileAccess(const char *filename) {
    char message[MAX_EVENT_LENGTH];
    snprintf(message, sizeof(message), "Accessed file '%s'.", filename);
    logEvent(FILE_ACCESS, message);
}

void logFileModify(const char *filename) {
    char message[MAX_EVENT_LENGTH];
    snprintf(message, sizeof(message), "Modified file '%s'.", filename);
    logEvent(FILE_MODIFY, message);
}

void logSystemError(const char *errorMessage) {
    char message[MAX_EVENT_LENGTH];
    snprintf(message, sizeof(message), "System error: %s", errorMessage);
    logEvent(SYSTEM_ERROR, message);
}

void clearLog() {
    FILE *file = fopen(LOG_FILE, "w");
    if (file == NULL) {
        perror("Unable to clear log file");
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

void displayLog() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Unable to read log file");
        return;
    }

    char line[MAX_EVENT_LENGTH];
    printf("Event Log:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

int main() {
    int choice;
    char input[100];

    clearLog(); // Start with a clean slate
    printf("Welcome to the Creative Event Logger!\n");

    while (1) {
        printf("\n1. Log In\n");
        printf("2. Log Out\n");
        printf("3. Access File\n");
        printf("4. Modify File\n");
        printf("5. Log System Error\n");
        printf("6. Display Log\n");
        printf("7. Clear Log\n");
        printf("8. Exit\n");
        printf("Select an option (1-8): ");
        fgets(input, sizeof(input), stdin);
        choice = atoi(input);

        switch (choice) {
            case 1:
                printf("Enter your username: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove trailing newline
                performLogin(input);
                break;

            case 2:
                printf("Enter your username: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove trailing newline
                performLogout(input);
                break;

            case 3:
                printf("Enter filename to access: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove trailing newline
                logFileAccess(input);
                break;

            case 4:
                printf("Enter filename to modify: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove trailing newline
                logFileModify(input);
                break;

            case 5:
                printf("Describe the error: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove trailing newline
                logSystemError(input);
                break;

            case 6:
                displayLog();
                break;

            case 7:
                clearLog();
                printf("Log cleared successfully.\n");
                break;

            case 8:
                printf("Exiting the event logger. Goodbye!\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}