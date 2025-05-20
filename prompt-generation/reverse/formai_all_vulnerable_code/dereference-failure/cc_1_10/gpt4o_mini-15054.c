//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_LOG_ENTRIES 100
#define LOG_FILE "activity.log"

typedef struct {
    char timestamp[20];
    char action[50];
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];
int logCount = 0;

// Function to record a log entry
void logActivity(const char *action) {
    if (logCount >= MAX_LOG_ENTRIES) {
        printf("Log is full! Unable to log: %s\n", action);
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    snprintf(logEntries[logCount].timestamp, sizeof(logEntries[logCount].timestamp), 
             "%04d-%02d-%02d %02d:%02d:%02d", 
             t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, 
             t->tm_hour, t->tm_min, t->tm_sec);
    strncpy(logEntries[logCount].action, action, sizeof(logEntries[logCount].action) - 1);
    logEntries[logCount].action[sizeof(logEntries[logCount].action) - 1] = '\0';
    logCount++;
}

// Function to print log entries
void printLogs() {
    if (logCount == 0) {
        printf("No logs recorded.\n");
        return;
    }

    printf("Activity Logs:\n");
    for (int i = 0; i < logCount; i++) {
        printf("[%s] %s\n", logEntries[i].timestamp, logEntries[i].action);
    }
}

// Function to write logs to a file
void writeLogsToFile() {
    FILE *file = fopen(LOG_FILE, "w");
    if (!file) {
        perror("Error opening log file");
        return;
    }

    for (int i = 0; i < logCount; i++) {
        fprintf(file, "[%s] %s\n", logEntries[i].timestamp, logEntries[i].action);
    }

    fclose(file);
    printf("Logs written to %s successfully!\n", LOG_FILE);
}

// Function to simulate detecting an intrusion
void detectIntrusion() {
    // Simulate some simple conditions that denote an intrusion
    // In a real system, this would be more complex and more robust
    srand(time(NULL));
    int intrusionDetected = rand() % 2; // Randomly simulate an intrusion

    if (intrusionDetected) {
        logActivity("Intrusion detected! Immediate action required.");
        printf("🚨 Intrusion Alert! 🚨 Action Logged.\n");
    } else {
        logActivity("No intrusion detected. System is secure.");
        printf("All clear! No intrusions found. 🌟\n");
    }
}

int main() {
    printf("🔥 Welcome to the Exciting C Intrusion Detection System! 🔥\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Check for Intrusion\n");
        printf("2. Print Logs\n");
        printf("3. Write Logs to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Checking for intrusions...\n");
                detectIntrusion();
                break;
            case 2:
                printLogs();
                break;
            case 3:
                writeLogsToFile();
                break;
            case 4:
                printf("Exiting the Intrusion Detection System. Goodbye! 👋\n");
                exit(0);
            default:
                printf("Invalid option! Please try again. 🙄\n");
        }
        sleep(1); // Pause for a moment
    }

    return 0;
}