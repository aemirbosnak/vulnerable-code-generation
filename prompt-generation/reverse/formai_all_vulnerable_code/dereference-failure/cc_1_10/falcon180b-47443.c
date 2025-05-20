//Falcon-180B DATASET v1.0 Category: System event logger ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOG_ENTRIES 100

typedef struct {
    char* message;
    time_t timestamp;
} log_entry_t;

log_entry_t log_entries[MAX_LOG_ENTRIES];
int next_entry_index = 0;

void log_message(const char* message) {
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    char timestamp_str[32];
    strftime(timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S", tm);

    log_entry_t new_entry = {
       .message = strdup(message),
       .timestamp = now
    };

    if (next_entry_index >= MAX_LOG_ENTRIES) {
        next_entry_index = 0;
    }

    log_entries[next_entry_index++] = new_entry;

    printf("[%s] %s\n", timestamp_str, message);
}

void print_log() {
    for (int i = 0; i < MAX_LOG_ENTRIES; ++i) {
        log_entry_t entry = log_entries[i % MAX_LOG_ENTRIES];
        if (entry.message!= NULL) {
            printf("[%s] %s\n", ctime(&entry.timestamp), entry.message);
        }
    }
}

int main() {
    srand(time(NULL));

    int num_messages = rand() % 50 + 1;
    for (int i = 0; i < num_messages; ++i) {
        char* message = malloc(1024);
        sprintf(message, "Message %d", i + 1);
        log_message(message);
        free(message);
    }

    print_log();

    return 0;
}