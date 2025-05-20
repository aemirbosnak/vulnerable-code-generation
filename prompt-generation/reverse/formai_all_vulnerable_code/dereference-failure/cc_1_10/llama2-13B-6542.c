//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 100
#define MAX_LOG_LEN 1000

// Define a struct to hold log data
typedef struct {
    char timestamp[20];
    char log_level[10];
    char message[MAX_STR_LEN];
} log_data_t;

// Function to generate a unique log message
void generate_log_message(log_data_t *log_data, int log_level) {
    char *log_message = NULL;

    // Generate a random timestamp
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    strftime(log_data->timestamp, sizeof(log_data->timestamp), "%Y-%m-%d %H:%M:%S", &ts);

    // Generate a random log level
    log_level = (log_level + 1) % 4;
    strcpy(log_data->log_level, log_level == 1 ? "DEBUG" :
                    log_level == 2 ? "INFO" :
                    log_level == 3 ? "WARNING" : "ERROR");

    // Generate a random message
    int message_len = (rand() % 100) + 1;
    log_message = malloc(message_len);
    for (int i = 0; i < message_len; i++) {
        log_message[i] = (rand() % 26) + 'a';
    }
    strcpy(log_data->message, log_message);

    // Free the log message
    free(log_message);
}

// Function to print the log message
void print_log(log_data_t *log_data) {
    printf("%s [%s] %s\n", log_data->timestamp, log_data->log_level, log_data->message);
}

int main() {
    // Create an array of log data
    log_data_t log_data[5];

    // Initialize the log data
    for (int i = 0; i < 5; i++) {
        generate_log_message(&log_data[i], i % 2 ? 1 : 2);
    }

    // Print the log messages
    for (int i = 0; i < 5; i++) {
        print_log(&log_data[i]);
    }

    return 0;
}