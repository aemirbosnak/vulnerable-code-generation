//FormAI DATASET v1.0 Category: System event logger ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Defining structure "log_event" to store the events
struct log_event {
    char time_stamp[50];
    char event[100];
};

// Function to write the event to the log file
void write_to_log(struct log_event event) {
    FILE *log_file;
    
    // Opening log file in append mode
    log_file = fopen("system_events.log", "a");

    // Checking if the file is opened successfully
    if (log_file == NULL) {
        printf("Error opening log file!");
        exit(1);
    }

    // Writing event to the log file
    fprintf(log_file, "%s\t%s\n", event.time_stamp, event.event);

    // Closing the log file
    fclose(log_file);
}

// Function to get the current time and date
void get_time(char *time_string) {
    time_t current_time;
    struct tm *local_time;

    // Getting the current time
    current_time = time(NULL);

    // Converting it to local time and storing it in a struct
    local_time = localtime(&current_time);

    // Formatting the time string
    strftime(time_string, 50, "[%m/%d/%Y %H:%M:%S]", local_time);
}

int main() {
    char event_string[100];
    struct log_event event;

    printf("Enter the event: ");

    // Reading the event from the user
    scanf("%[^\n]%*c", event_string);

    // Generating the time stamp for the event
    get_time(event.time_stamp);

    // Copying the event and time stamp to the log object
    strcpy(event.event, event_string);

    // Writing the event to the log file
    write_to_log(event);

    printf("Event logged successfully!");

    return 0;
}