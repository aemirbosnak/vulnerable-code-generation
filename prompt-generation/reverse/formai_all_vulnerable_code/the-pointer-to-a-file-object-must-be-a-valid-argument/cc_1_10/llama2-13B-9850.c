//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LOG_SIZE 1024*1024
#define MAX_LINE_SIZE 512

struct log_entry {
    time_t timestamp;
    char *message;
    int severity;
};

typedef struct log_entry log_entry_t;

static void parse_log_line(char *line, log_entry_t *entry) {
    char *timestamp_str = strtok(line, " ");
    char *message_str = strtok(NULL, " ");
    char *severity_str = strtok(NULL, " ");

    entry->timestamp = strtol(timestamp_str, NULL, 10);
    entry->message = message_str;
    entry->severity = atoi(severity_str);
}

static void log_analysis(char *log_file_name) {
    FILE *log_file = fopen(log_file_name, "r");
    char buffer[MAX_LINE_SIZE];
    log_entry_t entry;

    while (fgets(buffer, MAX_LINE_SIZE, log_file) != NULL) {
        parse_log_line(buffer, &entry);

        if (entry.severity >= 5) { // ignore log messages with severity less than 5
            printf("[%d] %s\n", entry.timestamp, entry.message);
        }
    }

    fclose(log_file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <log_file_name>\n", argv[0]);
        return 1;
    }

    log_analysis(argv[1]);

    return 0;
}