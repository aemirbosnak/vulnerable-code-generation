//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LOG_LEN 1024
#define MAX_ENTRIES 100

typedef struct log_entry {
    char timestamp[20];
    char IP[15];
    char method[10];
    char status[10];
    int response_code;
} log_entry_t;

int main(void) {
    log_entry_t log[MAX_ENTRIES];
    size_t i, j;
    size_t log_len = 0;
    char *ptr;

    // Read the log file
    FILE *file = fopen("peaceful_log.txt", "r");
    if (!file) {
        printf("Error: Unable to open log file\n");
        return 1;
    }

    // Read the log entries
    while (fgets(log[log_len].timestamp, sizeof(log[log_len].timestamp), file) != NULL) {
        log_len++;
        if (log_len == MAX_ENTRIES) {
            break;
        }

        // Extract the IP and method from the log entry
        char *token = strtok(log[log_len - 1].timestamp, " ");
        strcpy(log[log_len].IP, token);
        token = strtok(NULL, " ");
        strcpy(log[log_len].method, token);

        // Extract the status and response code from the log entry
        token = strtok(NULL, " ");
        strcpy(log[log_len].status, token);
        token = strtok(NULL, " ");
        log[log_len].response_code = atoi(token);

        // Check for peaceful requests
        if (strcmp(log[log_len].status, "200 OK") == 0) {
            // Increment the peaceful request count
            log[log_len].response_code++;
        }
    }

    // Calculate the peaceful request percentage
    for (i = 0; i < log_len; i++) {
        if (log[i].response_code == 200) {
            log[i].response_code++;
            log[i].response_code = (log[i].response_code * 100) / log_len;
            printf("Peaceful requests: %d%%\n", log[i].response_code);
        }
    }

    // Print the log entries
    for (i = 0; i < log_len; i++) {
        printf("Log Entry: %s %s %s %d %d\n", log[i].timestamp, log[i].IP, log[i].method, log[i].response_code, log[i].status);
    }

    // Close the log file
    fclose(file);

    return 0;
}