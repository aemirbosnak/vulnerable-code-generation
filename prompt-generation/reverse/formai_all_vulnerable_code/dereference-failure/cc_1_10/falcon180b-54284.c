//Falcon-180B DATASET v1.0 Category: System event logger ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

struct event {
    char *message;
    time_t timestamp;
};

int main() {
    FILE *logfile;
    struct event events[MAX_EVENTS];
    int num_events = 0;
    char filename[50];
    time_t current_time;

    // Get current time
    time(&current_time);

    // Format current time as string
    char *timestamp_str = ctime(&current_time);

    // Remove newline character from timestamp string
    timestamp_str[strlen(timestamp_str) - 1] = '\0';

    // Create log file name with timestamp
    sprintf(filename, "log_%s.txt", timestamp_str);

    // Open log file for writing
    logfile = fopen(filename, "w");
    if (logfile == NULL) {
        printf("Error: could not open log file.\n");
        exit(1);
    }

    // Loop until user enters "quit"
    while (1) {
        printf("Enter message to log (or type 'quit' to exit): ");
        fgets(events[num_events].message, 100, stdin);

        // Check if user wants to quit
        if (strcmp(events[num_events].message, "quit") == 0) {
            break;
        }

        // Increment number of events
        num_events++;

        // Check if maximum number of events has been reached
        if (num_events == MAX_EVENTS) {
            printf("Error: maximum number of events (%d) has been reached.\n", MAX_EVENTS);
            exit(1);
        }

        // Log event to file
        fprintf(logfile, "%s: %s\n", timestamp_str, events[num_events - 1].message);
    }

    // Close log file
    fclose(logfile);

    return 0;
}