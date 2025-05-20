//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1024
#define MAX_LINE_LENGTH 512

typedef struct {
    char *timestamp;
    char *message;
} log_entry_t;

void parse_log(const char *log_file_path) {
    FILE *file = fopen(log_file_path, "r");
    if (!file) {
        perror("Failed to open log file");
        return;
    }

    char buffer[MAX_LOG_SIZE];
    while (fgets(buffer, MAX_LINE_LENGTH, file)) {
        // Parse timestamp
        char *timestamp = strtok(buffer, " ");
        if (!timestamp) {
            break;
        }
        log_entry_t *entry = malloc(sizeof(log_entry_t));
        entry->timestamp = timestamp;

        // Parse message
        char *message = strtok(NULL, "\n");
        if (!message) {
            break;
        }
        entry->message = message;

        // Print log entry
        printf("[%s] %s\n", entry->timestamp, entry->message);
    }

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <log_file_path>\n", argv[0]);
        return 1;
    }

    parse_log(argv[1]);
    return 0;
}