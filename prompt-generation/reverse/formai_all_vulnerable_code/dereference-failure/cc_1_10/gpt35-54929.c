//FormAI DATASET v1.0 Category: System event logger ; Style: Claude Shannon
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOGS 100
#define MAX_LENGTH 100

// Custom struct to hold log information
typedef struct {
    char timestamp[50];
    char severity[10];
    char message[MAX_LENGTH];
} Log;

// Function to log an event with given severity and message
void log_event(char* severity, char* message){
    // Check if logs array is allocated
    static Log *logs = NULL;
    if(logs == NULL){
        logs = (Log*) malloc(MAX_LOGS * sizeof(Log));
    }

    // Get current timestamp
    time_t curr_time;
    struct tm* time_info;
    time(&curr_time);
    time_info = localtime(&curr_time);

    // Format timestamp and log message
    char timestamp[50];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", time_info);

    // Create new log object
    Log new_log;
    strcpy(new_log.timestamp, timestamp);
    strcpy(new_log.severity, severity);
    strcpy(new_log.message, message);

    // Insert new log into logs array
    static int num_logs = 0;
    logs[num_logs++] = new_log;

    // Check if logs array is full and print to console
    if(num_logs >= MAX_LOGS){
        printf("\nEvent logger - MAX LOGS REACHED!\n");

        // Print all logs
        for(int i = 0; i < MAX_LOGS; i++){
            printf("%s %s: %s\n", logs[i].timestamp, logs[i].severity, logs[i].message);
        }

        // Reset logs array
        num_logs = 0;
        free(logs);
        logs = NULL;
    }
}

// Main function to test event logger
int main(){
    log_event("INFO", "Program started.");
    log_event("WARNING", "Memory usage high.");
    log_event("ERROR", "Could not open file.");
    log_event("INFO", "Program ended normally.");

    return 0;
}