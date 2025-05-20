//FormAI DATASET v1.0 Category: System event logger ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get current time as string
void get_current_time(char *buffer) {
    time_t now = time(NULL);
    strftime(buffer, 25, "%Y-%m-%d %H:%M:%S", localtime(&now));
}

// Define a struct to hold event log data
typedef struct {
    char *timestamp;
    char *severity;
    char *message;
} event_log_t;

// Function to initialize a new event log instance
event_log_t *new_event_log(char *severity, char *message) {
    event_log_t *log = malloc(sizeof(event_log_t));
    log->timestamp = malloc(25 * sizeof(char));
    get_current_time(log->timestamp);
    log->severity = severity;
    log->message = message;
    return log;
}

// Function to write event log to file
void write_event_log(event_log_t *log) {
    FILE *fp;
    fp = fopen("event.log", "a+");
    fprintf(fp, "%s - %s: %s\n", log->timestamp, log->severity, log->message);
    fclose(fp);
}

int main() {
    // Create new event logs
    event_log_t *info_log = new_event_log("INFO", "Application started");
    event_log_t *warn_log = new_event_log("WARNING", "Database connection lost");
    event_log_t *err_log = new_event_log("ERROR", "Failed to process user request");

    // Write event logs to file
    write_event_log(info_log);
    write_event_log(warn_log);
    write_event_log(err_log);

    // Clean up memory allocation
    free(info_log->timestamp);
    free(info_log);
    free(warn_log->timestamp);
    free(warn_log);
    free(err_log->timestamp);
    free(err_log);

    return 0;
}