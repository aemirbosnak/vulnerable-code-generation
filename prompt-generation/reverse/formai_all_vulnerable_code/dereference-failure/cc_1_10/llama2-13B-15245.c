//LLAMA2-13B DATASET v1.0 Category: System event logger ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_LOG_SIZE 1024
#define MAX_LOG_COUNT 1000

typedef struct log_entry {
    char timestamp[20];
    char level[10];
    char message[100];
} log_entry_t;

log_entry_t logs[MAX_LOG_COUNT];
int log_count = 0;

void log_message(const char* level, const char* message) {
    char timestamp[20];
    time_t now = time(NULL);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));

    log_entry_t new_log;
    strcpy(new_log.timestamp, timestamp);
    strcpy(new_log.level, level);
    strcpy(new_log.message, message);

    if (log_count >= MAX_LOG_COUNT) {
        // If the log buffer is full, start overwriting the oldest entries
        int i = 0;
        while (i < MAX_LOG_COUNT && logs[i].timestamp[0] != '\0') {
            logs[i].timestamp[0] = '\0';
            logs[i].level[0] = '\0';
            logs[i].message[0] = '\0';
            i++;
        }
        log_count = 0;
    }

    logs[log_count] = new_log;
    log_count++;
}

int main() {
    log_message("INFO", "Starting up...");
    log_message("DEBUG", "Initializing system...");
    log_message("WARNING", "Watch out for bugs!");
    log_message("ERROR", "Oh no, a critical error has occurred!");

    return 0;
}