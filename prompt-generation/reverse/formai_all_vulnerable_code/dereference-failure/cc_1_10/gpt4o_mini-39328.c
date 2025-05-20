//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 256
#define MAX_LOG_ENTRIES 1000

typedef struct {
    time_t timestamp;
    char log_level[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

void parse_log_line(const char *line, LogEntry *entry) {
    struct tm tm;
    char *token = strtok(line, " ");
    strptime(token, "%Y-%m-%d", &tm);
    entry->timestamp = mktime(&tm);

    token = strtok(NULL, " "); // Log level
    strcpy(entry->log_level, token);

    token = strtok(NULL, " "); // Log message
    strcpy(entry->message, token);
    
    while ((token = strtok(NULL, " ")) != NULL) {
        strcat(entry->message, " ");
        strcat(entry->message, token);
    }
}

void load_log_file(const char *filename, LogEntry *logs, int *log_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open log file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    *log_count = 0;

    while (fgets(line, sizeof(line), file) && *log_count < MAX_LOG_ENTRIES) {
        parse_log_line(line, &logs[*log_count]);
        (*log_count)++;
    }

    fclose(file);
}

void print_log_summary(LogEntry *logs, int log_count) {
    int info_count = 0, warning_count = 0, error_count = 0;

    for (int i = 0; i < log_count; i++) {
        if (strcmp(logs[i].log_level, "INFO") == 0) {
            info_count++;
        } else if (strcmp(logs[i].log_level, "WARNING") == 0) {
            warning_count++;
        } else if (strcmp(logs[i].log_level, "ERROR") == 0) {
            error_count++;
        }
    }

    printf("Log Summary:\n");
    printf("Total INFO log entries: %d\n", info_count);
    printf("Total WARNING log entries: %d\n", warning_count);
    printf("Total ERROR log entries: %d\n", error_count);
}

void print_logs_by_level(LogEntry *logs, int log_count, const char *level) {
    printf("\nLogs with level %s:\n", level);
    for (int i = 0; i < log_count; i++) {
        if (strcmp(logs[i].log_level, level) == 0) {
            char buffer[26];
            struct tm* tm_info;

            tm_info = localtime(&logs[i].timestamp);
            strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
            printf("%s [%s]: %s\n", buffer, logs[i].log_level, logs[i].message);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    LogEntry logs[MAX_LOG_ENTRIES];
    int log_count = 0;

    load_log_file(argv[1], logs, &log_count);
    print_log_summary(logs, log_count);

    print_logs_by_level(logs, log_count, "INFO");
    print_logs_by_level(logs, log_count, "WARNING");
    print_logs_by_level(logs, log_count, "ERROR");

    return EXIT_SUCCESS;
}