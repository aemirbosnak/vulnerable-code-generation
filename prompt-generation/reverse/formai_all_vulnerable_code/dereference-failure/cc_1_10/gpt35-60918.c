//FormAI DATASET v1.0 Category: System event logger ; Style: brave
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void log_event(char* event_name, char* event_description);

int main()
{
    char event_name[MAX_LENGTH];
    char event_description[MAX_LENGTH];

    printf("Welcome to the C System Event Logger!\n");
    printf("------------------------------------\n");

    printf("Please enter the name of the event:\n");
    fgets(event_name, MAX_LENGTH, stdin);

    printf("Please enter a description of the event:\n");
    fgets(event_description, MAX_LENGTH, stdin);

    log_event(event_name, event_description);

    return 0;
}

void log_event(char* event_name, char* event_description)
{
    // Get current time
    time_t current_time;
    char* c_time_string;
    current_time = time(NULL);
    c_time_string = ctime(&current_time);
    c_time_string[strlen(c_time_string) - 1] = '\0'; // Remove newline character

    // Open the event log file
    FILE *event_log_file;
    event_log_file = fopen("event_log.txt", "a");
    if (event_log_file == NULL)
    {
        printf("Error: Could not open event log file.\n");
        return;
    }

    // Write the event to the event log file
    fprintf(event_log_file, "%s: %s\n%s\n\n", c_time_string, event_name, event_description);

    // Close the event log file
    fclose(event_log_file);

    printf("Event successfully logged to event_log.txt!\n");
}