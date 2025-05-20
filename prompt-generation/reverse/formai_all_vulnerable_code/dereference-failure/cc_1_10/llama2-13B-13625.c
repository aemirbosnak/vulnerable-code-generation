//LLAMA2-13B DATASET v1.0 Category: System event logger ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_LENGTH 1024
#define MAX_LOG_COUNT 1000

typedef struct log_entry {
    char timestamp[20];
    char level[10];
    char message[1024];
} log_entry_t;

log_entry_t logs[MAX_LOG_COUNT];
int log_count = 0;

void log_init(void) {
    time_t now = time(NULL);
    strftime(logs[0].timestamp, sizeof(logs[0].timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));
    logs[0].level[0] = 'I'; // Info level by default
    logs[0].message[0] = '\0';
}

void log_append(const char *level, const char *message) {
    char *timestamp = NULL;
    char *message_copy = NULL;

    // Get current timestamp and message
    time_t now = time(NULL);
    strftime(timestamp, sizeof(logs[0].timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));
    message_copy = strdup(message);

    // Append log entry
    log_count++;
    if (log_count >= MAX_LOG_COUNT) {
        // Warn user if log count exceeds maximum limit
        printf("WARNING: Log count exceeds maximum limit (%d > %d).\n", log_count, MAX_LOG_COUNT);
    }
    strcat(logs[log_count - 1].message, message_copy);
    free(message_copy);

    // Set level of current log entry
    if (strcmp(level, "I") == 0) {
        logs[log_count - 1].level[0] = 'I'; // Info level
    } else if (strcmp(level, "W") == 0) {
        logs[log_count - 1].level[0] = 'W'; // Warning level
    } else if (strcmp(level, "E") == 0) {
        logs[log_count - 1].level[0] = 'E'; // Error level
    }
}

void log_print(void) {
    int i = 0;

    // Print log entries in reverse order
    for (i = log_count - 1; i >= 0; i--) {
        printf("%d. %s %s %s\n", i + 1, logs[i].level, logs[i].timestamp, logs[i].message);
    }
}

int main(void) {
    log_init();

    // Example log messages
    log_append("I", "Starting program");
    log_append("W", "Found potential issue");
    log_append("E", "Fatal error occurred");

    log_print();

    return 0;
}