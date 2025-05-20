//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MIN_LENGTH 10

struct log {
    char *message;
    time_t timestamp;
};

typedef struct log log_t;

void log_add(log_t *log, char *message);
void log_print(log_t *log);

int main() {
    log_t *log = malloc(sizeof(log_t));
    log->message = malloc(MAX_LENGTH);
    log->timestamp = time(NULL);

    log_add(log, "Starting program...");
    log_add(log, "Opening file...");
    log_add(log, "Reading data...");
    log_add(log, "Closing file...");
    log_add(log, "Program completed.");

    log_print(log);

    free(log->message);
    free(log);

    return 0;
}

void log_add(log_t *log, char *message) {
    int len = strlen(message) + 1;

    if (len > MAX_LENGTH) {
        log->message = realloc(log->message, len);
        strcpy(log->message, message);
    } else if (len < MIN_LENGTH) {
        log->message = realloc(log->message, len + 1);
        strcpy(log->message, message);
    } else {
        strncat(log->message, message, len);
    }
}

void log_print(log_t *log) {
    printf("Log entries:\n");
    printf("Timestamp: %s\n", ctime(&log->timestamp));
    printf("Message: %s\n", log->message);
}