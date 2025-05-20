//FormAI DATASET v1.0 Category: Log analysis ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINES 1000
#define MAX_LOG_LINE_LEN 500

typedef enum {INFO, WARNING, ERROR} log_level;

typedef struct {
    char* message;
    log_level level;
} log_entry;

log_entry* parse_log(char* file_name, int* num_entries);
void print_log(log_entry* log, int num_entries);
void filter_log(log_entry* log, int* num_entries, log_level level);

int main() {
    int num_entries;
    log_entry* log = parse_log("log_file.txt", &num_entries);
    if (!log) {
        printf("Error: Unable to parse log file.");
        exit(1);
    }
    printf("Total log entries: %d\n", num_entries);
    print_log(log, num_entries);

    printf("Filtering for ERROR level log entries...\n");
    filter_log(log, &num_entries, ERROR);
    printf("Total ERROR level log entries: %d\n", num_entries);
    print_log(log, num_entries);

    free(log);
    return 0;
}

log_entry* parse_log(char* file_name, int* num_entries) {
    FILE* log_file = fopen(file_name, "r");
    if (!log_file) {
        printf("Error: Unable to open log file '%s'\n", file_name);
        return NULL;
    }

    log_entry* log = (log_entry*) malloc(MAX_LOG_LINES * sizeof(log_entry));
    char line[MAX_LOG_LINE_LEN];
    int i = 0;
    while (fgets(line, MAX_LOG_LINE_LEN, log_file)) {
        char* message = (char*) malloc(strlen(line) * sizeof(char));
        log_level level;
        // Determine log level
        if (strstr(line, "INFO")) {
            level = INFO;
        } else if (strstr(line, "WARNING")) {
            level = WARNING;
        } else if (strstr(line, "ERROR")) {
            level = ERROR;
        } else {
            printf("Error: Invalid log level in line %d\n", i+1);
            return NULL;
        }
        // Copy message to log entry
        char* start = strchr(line, ']') + 2;
        char* end = strchr(line, '\n');
        int len = end - start;
        strncpy(message, start, len);
        message[len] = '\0';
        log[i++] = (log_entry) {message, level};
    }
    *num_entries = i;
    fclose(log_file);
    return log;
}

void print_log(log_entry* log, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("[%s] %s\n", (log[i].level == INFO) ? "INFO" :
                                                (log[i].level == WARNING) ? "WARNING" : "ERROR",
                                                log[i].message);
    }
}

void filter_log(log_entry* log, int* num_entries, log_level level) {
    int count = 0;
    for (int i = 0; i < *num_entries; i++) {
        if (log[i].level == level) {
            log[count++] = log[i];
        }
    }
    *num_entries = count;
}