//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_LOG_ENTRIES 100
#define SUSPICIOUS_THRESHOLD 5

typedef struct {
    char timestamp[20];
    char username[20];
    char activity[50];
} LogEntry;

// List of simulated log entries
LogEntry logEntries[MAX_LOG_ENTRIES];
int logCount = 0;

// Function prototypes
void generateLogEntry(const char *username, const char *activity);
void analyzeLogs();
void alert(const char *message);

int main() {
    // Seeding random number generator
    srand(time(NULL));
    
    // Simulate log entry generation
    const char *activities[] = {
        "login success",
        "login failure",
        "access sensitive file",
        "logout",
        "file upload",
        "file delete"
    };
    
    const char *usernames[] = {
        "alice",
        "bob",
        "charlie",
        "dave"
    };
    
    for (int i = 0; i < MAX_LOG_ENTRIES; i++) {
        int randUsername = rand() % 4;
        int randActivity = rand() % 6;
        
        generateLogEntry(usernames[randUsername], activities[randActivity]);
        
        // Mimic some delay in log generation
        usleep(100000); // Sleep for 100 milliseconds
    }
    
    analyzeLogs();
    
    return 0;
}

void generateLogEntry(const char *username, const char *activity) {
    if (logCount >= MAX_LOG_ENTRIES) {
        return; // Log is full
    }
    
    // Get current time
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    snprintf(logEntries[logCount].timestamp, sizeof(logEntries[logCount].timestamp), 
             "%02d:%02d:%02d", tm_struct->tm_hour, tm_struct->tm_min, tm_struct->tm_sec);
    
    strncpy(logEntries[logCount].username, username, sizeof(logEntries[logCount].username));
    strncpy(logEntries[logCount].activity, activity, sizeof(logEntries[logCount].activity));
    logCount++;
}

void analyzeLogs() {
    int failedLogins = 0;
    int sensitiveAccesses = 0;
    
    for (int i = 0; i < logCount; i++) {
        if (strstr(logEntries[i].activity, "login failure")) {
            failedLogins++;
        }
        if (strstr(logEntries[i].activity, "access sensitive file")) {
            sensitiveAccesses++;
        }
    }
    
    if (failedLogins > SUSPICIOUS_THRESHOLD) {
        char message[100];
        snprintf(message, sizeof(message), "ALERT: %d failed login attempts detected!", failedLogins);
        alert(message);
    }
    
    if (sensitiveAccesses > SUSPICIOUS_THRESHOLD) {
        char message[100];
        snprintf(message, sizeof(message), "ALERT: %d accesses to sensitive files detected!", sensitiveAccesses);
        alert(message);
    }
}

void alert(const char *message) {
    // A simple print statement for facsimile alert
    printf("%s\n", message);
}