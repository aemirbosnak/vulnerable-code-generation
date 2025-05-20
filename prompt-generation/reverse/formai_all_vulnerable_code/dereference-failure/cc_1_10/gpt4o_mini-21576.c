//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_LINE 256
#define MAX_LOG_FILES 10

typedef struct {
    time_t timestamp;
    char level[10];
    char message[MAX_LOG_LINE];
} LogEntry;

void parse_log_entry(const char *line, LogEntry *entry) {
    char time_str[20];
    
    // Assumed log line format: "YYYY-MM-DD HH:MM:SS [level] message"
    sscanf(line, "%19s %19s [%9s] %[^\n]", time_str, time_str + 19, entry->level, entry->message);
    
    struct tm tm;
    strptime(time_str, "%Y-%m-%d %H:%M:%S", &tm);
    entry->timestamp = mktime(&tm);
}

void display_log_entry(const LogEntry *entry) {
    char time_buf[26];
    struct tm *tm_info;

    tm_info = localtime(&entry->timestamp);
    strftime(time_buf, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    
    printf("%s [%s] %s\n", time_buf, entry->level, entry->message);
}

void display_logs(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open log file");
        return;
    }

    char line[MAX_LOG_LINE];
    while (fgets(line, sizeof(line), file)) {
        LogEntry entry;
        parse_log_entry(line, &entry);
        display_log_entry(&entry);
    }

    fclose(file);
}

void save_log(const char *filename, const LogEntry *entry) {
    FILE *file = fopen(filename, "a");
    if (!file) {
        perror("Could not open log file for appending");
        return;
    }
    
    // Write log entry in expected format
    char time_buf[26];
    strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", localtime(&entry->timestamp));
    fprintf(file, "%s [%s] %s\n", time_buf, entry->level, entry->message);
    
    fclose(file);
}

void clear_log(const char *filename) {
    if (remove(filename) == 0) {
        printf("Log file cleared: %s\n", filename);
    } else {
        perror("Failed to clear log file");
    }
}

void display_help() {
    printf("Log Manager Help:\n");
    printf("Usage:\n");
    printf("  <command> <parameters>\n");
    printf("\nCommands:\n");
    printf("  display <filename>    - Display logs from the specified file.\n");
    printf("  save <filename> <level> <message> - Save a new log with specified level and message.\n");
    printf("  clear <filename>      - Clear the specified log file.\n");
    printf("  help                  - Display this help information.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        display_help();
        return 1;
    }

    const char *command = argv[1];

    if (strcmp(command, "display") == 0 && argc == 3) {
        display_logs(argv[2]);
    } else if (strcmp(command, "save") == 0 && argc == 5) {
        LogEntry entry;
        entry.timestamp = time(NULL);
        strncpy(entry.level, argv[2], sizeof(entry.level) - 1);
        strncpy(entry.message, argv[3], sizeof(entry.message) - 1);
        save_log(argv[4], &entry);
    } else if (strcmp(command, "clear") == 0 && argc == 3) {
        clear_log(argv[2]);
    } else if (strcmp(command, "help") == 0) {
        display_help();
    } else {
        fprintf(stderr, "Invalid command or parameters.\n");
        display_help();
        return 1;
    }

    return 0;
}