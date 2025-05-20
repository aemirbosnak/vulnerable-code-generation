//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "system_log.txt"
#define TEMP_FILE "temp_log.txt"
#define SUSPICIOUS_PATTERN "failed password"
#define MAX_LINE_LENGTH 256

// Function prototypes
void logEvent(const char *event);
void checkForIntrusions();
void notifyUser(const char *message);

// Main function
int main() {
    // Simulate logging events
    logEvent("User John logged in.");
    logEvent("User John attempted to change password.");
    logEvent("User John " SUSPICIOUS_PATTERN " attempt.");
    logEvent("User Alice logged out.");
    
    // Check for intrusions
    checkForIntrusions();

    return 0;
}

// Function to log events to the system log file
void logEvent(const char *event) {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        perror("Failed to open log file");
        return;
    }
    
    // Get current time
    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // Remove newline

    fprintf(file, "[%s] %s\n", time_str, event);
    fclose(file);
}

// Function to check for suspicious patterns in the log file
void checkForIntrusions() {
    FILE *file = fopen(LOG_FILE, "r");
    if (!file) {
        perror("Failed to open log file");
        return;
    }

    FILE *tempFile = fopen(TEMP_FILE, "w");
    if (!tempFile) {
        perror("Failed to create temporary file");
        fclose(file);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int suspiciousFound = 0;

    while (fgets(line, sizeof(line), file)) {
        // Check for suspicious activity
        if (strstr(line, SUSPICIOUS_PATTERN) != NULL) {
            notifyUser("Suspicious activity detected!");
            suspiciousFound = 1;
        }
        fprintf(tempFile, "%s", line);
    }

    fclose(file);
    fclose(tempFile);

    // Optionally replace the original log with the temp file
    remove(LOG_FILE);
    rename(TEMP_FILE, LOG_FILE);

    if (!suspiciousFound) {
        printf("No suspicious activities detected.\n");
    }
}

// Function to notify user of a potential intrusion
void notifyUser(const char *message) {
    printf("%s\n", message);
    // Additional notification mechanisms can be added (e.g., email, SMS)
}