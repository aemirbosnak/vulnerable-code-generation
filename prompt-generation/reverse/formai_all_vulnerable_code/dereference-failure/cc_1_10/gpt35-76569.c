//FormAI DATASET v1.0 Category: System event logger ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

/* This program is a sophisticated event logger system that can log system events in a formatted way 
to a file or to the console */

// The log type enumeration
enum log_type {
    INFO = 1,
    WARNING = 2,
    ERROR = 3
};

// The log structure that contains the log information
typedef struct {
    time_t timestamp;
    enum log_type type;
    char message[100];
} log_t;

// The logging function 
void log_event(enum log_type type, char* message) {
    // Allocate space for the log entries
    log_t* log_entry = (log_t*)malloc(sizeof(log_t));

    // Set the log information
    log_entry->timestamp = time(NULL);
    log_entry->type = type;
    strcpy(log_entry->message, message);

    // Open the log file
    FILE* log_file = fopen("log.txt", "a");
    if (log_file == NULL) {
        printf("Failed to open the log file.\n");
    } 
    else {
        // Write the log entry to the log file in the following format:
        // timestamp | type | message
        switch (type) {
            case INFO:
                fprintf(log_file, "%ld | INFO | %s\n", log_entry->timestamp, log_entry->message);
                break;
            case WARNING:
                fprintf(log_file, "%ld | WARNING | %s\n", log_entry->timestamp, log_entry->message);
                break;
            case ERROR:
                fprintf(log_file, "%ld | ERROR | %s\n", log_entry->timestamp, log_entry->message);
                break;
            default:
                break;
        }

        // Close the log file
        fclose(log_file);
    }

    // Print the log information to the console in the following format:
    // timestamp | type | message
    switch (type) {
        case INFO:
            printf("%ld | INFO | %s\n", log_entry->timestamp, log_entry->message);
            break;
        case WARNING:
            printf("%ld | WARNING | %s\n", log_entry->timestamp, log_entry->message);
            break;
        case ERROR:
            printf("%ld | ERROR | %s\n", log_entry->timestamp, log_entry->message);
            break;
        default:
            break;
    }

    // Free the allocated memory
    free(log_entry);
}

int main() {
    // Log an information message
    log_event(INFO, "Starting the application...");

    // Log a warning message
    log_event(WARNING, "The system is running low on memory.");

    // Log an error message
    log_event(ERROR, "Failed to connect to the database.");

    return 0;
}