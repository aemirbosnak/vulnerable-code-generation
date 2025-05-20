//FormAI DATASET v1.0 Category: System event logger ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define MAX_EVENT_MSG_LENGTH 256
#define MAX_LOG_MSG_LENGTH 512
#define MAX_NUM_LOGS 100

// Define struct for log entry
typedef struct log_entry {
    char timestamp[20];
    char event_name[MAX_EVENT_MSG_LENGTH];
    char log_msg[MAX_LOG_MSG_LENGTH];
} log_entry;

// Define global variables
int num_logs = 0;
log_entry logs[MAX_NUM_LOGS];

// Function to add log entry
void add_log_entry(char* event_name, char* log_msg) {
    // Get current time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    // Format timestamp string
    char timestamp[20];
    sprintf(timestamp, "%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    // Add log entry to array
    strcpy(logs[num_logs].timestamp, timestamp);
    strcpy(logs[num_logs].event_name, event_name);
    strcpy(logs[num_logs].log_msg, log_msg);
    num_logs++;
}

// Function to print all log entries
void print_logs() {
    printf("Timestamp | Event Name | Log Message\n");
    for (int i = 0; i < num_logs; i++) {
        printf("%s | %s | %s\n", logs[i].timestamp, logs[i].event_name, logs[i].log_msg);
    }
}

// Main function
int main() {
    // Add some example log entries
    add_log_entry("System Startup", "The system has been started.");
    add_log_entry("User Login", "User john_doe has logged in.");
    add_log_entry("Error", "Unable to connect to database.");
    add_log_entry("User Logout", "User john_doe has logged out.");
    add_log_entry("System Shutdown", "The system is shutting down.");
    // Print all log entries
    print_logs();
    return 0;
}