//FormAI DATASET v1.0 Category: System event logger ; Style: Ken Thompson
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void log_event(char* category, char* message);
void print_logs();

char** logs;
int num_logs = 0;

int main()
{
    logs = malloc(1000 * sizeof(char*)); // Allocate memory for logs

    log_event("System", "Started program"); // Example log event

    printf("Program running...\n");

    log_event("User", "Clicked button");

    print_logs();

    return 0;
}

void log_event(char* category, char* message)
{
    time_t current_time;
    char* c_time_string;

    current_time = time(NULL); // Get current time
    c_time_string = ctime(&current_time); // Convert time to string

    int log_length = strlen(category) + strlen(message) + strlen(c_time_string) + 4; // Calculate length of log string

    char* log = malloc(log_length * sizeof(char)); // Allocate memory for log string

    sprintf(log, "[%s] %s: %s", c_time_string, category, message); // Format log string

    logs[num_logs] = log; // Store log string in logs array
    num_logs++;
}

void print_logs()
{
    printf("Logs:\n");

    for(int i = 0; i < num_logs; i++)
    {
        printf("%s", logs[i]); // Print log string
    }
}