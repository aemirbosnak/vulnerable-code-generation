//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 10000
#define MAX_LINE_SIZE 1024

typedef struct {
    char *ip;
    char *method;
    char *path;
    char *version;
    int status_code;
    char *timestamp;
} log_entry;

void parse_log_entry(char *line, log_entry *entry) {
    char *token = strtok(line, " ");
    entry->ip = strdup(token);

    token = strtok(NULL, " ");
    entry->method = strdup(token);

    token = strtok(NULL, " ");
    entry->path = strdup(token);

    token = strtok(NULL, " ");
    entry->version = strdup(token);

    token = strtok(NULL, " ");
    entry->status_code = atoi(token);

    token = strtok(NULL, " ");
    entry->timestamp = strdup(token);
}

void print_log_entry(log_entry *entry) {
    printf("IP: %s\n", entry->ip);
    printf("Method: %s\n", entry->method);
    printf("Path: %s\n", entry->path);
    printf("Version: %s\n", entry->version);
    printf("Status Code: %d\n", entry->status_code);
    printf("Timestamp: %s\n\n", entry->timestamp);
}

void analyze_log_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    log_entry entry;
    char line[MAX_LINE_SIZE];
    int num_entries = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        parse_log_entry(line, &entry);
        print_log_entry(&entry);
        num_entries++;

        if (num_entries >= MAX_LOG_SIZE) {
            printf("Reached maximum number of log entries (%d).\n", MAX_LOG_SIZE);
            break;
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        exit(1);
    }

    analyze_log_file(argv[1]);
    return 0;
}