//FormAI DATASET v1.0 Category: System event logger ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the struct for each event log entry
typedef struct {
    char timestamp[50];
    char system_name[50];
    char event_type[30];
    char message[100];
} EventLogEntry;

int main() {

    // Initialize the current time and date variable
    time_t current_time;
    char *ctime_str;

    // Get the current time and date
    current_time = time(NULL);
    ctime_str = ctime(&current_time);

    // Remove newline character from ctime_str
    ctime_str[strlen(ctime_str)-1] = '\0';

    // Initialize the event log entry array
    EventLogEntry event_log[100];

    // Define the system name
    char system_name[50] = "CyberSystem001";

    // Define the event types
    char* event_types[4] = {"INFO", "WARNING", "ERROR", "CRITICAL"};

    // Define the messages for each event type
    char* info_msg = "System is running normally";
    char* warning_msg = "System temperature is increasing";
    char* error_msg = "System has encountered an error and needs to be restarted";
    char* critical_msg = "System has crashed and needs immediate attention";

    // Seed the random number generator
    srand(time(NULL));

    // Generate 50 random event log entries
    for (int i = 0; i < 50; i++) {

        // Get the random event type and corresponding message
        int rand_event_type = rand() % 4;
        char* event_type = event_types[rand_event_type];
        char* message;

        if (rand_event_type == 0) {
            message = info_msg;
        } else if (rand_event_type == 1) {
            message = warning_msg;
        } else if (rand_event_type == 2) {
            message = error_msg;
        } else {
            message = critical_msg;
        }

        // Create the event log entry
        EventLogEntry new_entry;
        strcpy(new_entry.timestamp, ctime_str);
        strcpy(new_entry.system_name, system_name);
        strcpy(new_entry.event_type, event_type);
        strcpy(new_entry.message, message);

        // Add the event log entry to the array
        event_log[i] = new_entry;

    }

    // Print the event log entries to the console
    printf("=== SYSTEM EVENT LOG ===\n");
    for (int i = 0; i < 50; i++) {
        printf("[%s] [%s] %s: %s\n", event_log[i].timestamp, event_log[i].system_name, event_log[i].event_type, event_log[i].message);
    }

    return 0;
}