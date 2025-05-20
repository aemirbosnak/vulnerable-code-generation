//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 256
#define LOG_FILE "server.log"
#define TIMESTAMP_LEN 20

typedef struct LogEntry {
    char timestamp[TIMESTAMP_LEN];
    char level[10];
    char message[MAX_LEN];
} LogEntry;

void get_current_timestamp(char *buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", tm_info);
}

void log_message(const char *level, const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        perror("Could not open log file");
        return;
    }
    LogEntry entry;
    get_current_timestamp(entry.timestamp, sizeof(entry.timestamp));
    strncpy(entry.level, level, sizeof(entry.level));
    strncpy(entry.message, message, sizeof(entry.message));
    
    fprintf(file, "%s [%s]: %s\n", entry.timestamp, entry.level, entry.message);
    fclose(file);
}

void read_logs() {
    FILE *file = fopen(LOG_FILE, "r");
    if (!file) {
        perror("Could not open log file");
        return;
    }
    char line[MAX_LEN + TIMESTAMP_LEN + 20];
    
    printf("=== Log Entries ===\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void clear_logs() {
    if (remove(LOG_FILE) == 0) {
        printf("Log file cleared successfully.\n");
    } else {
        perror("Could not clear log file");
    }
}

void filter_logs(const char *level) {
    FILE *file = fopen(LOG_FILE, "r");
    if (!file) {
        perror("Could not open log file");
        return;
    }
    
    char line[MAX_LEN + TIMESTAMP_LEN + 20];
    printf("=== Filtered Log Entries - Level: %s ===\n", level);
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, level)) {
            printf("%s", line);
        }
    }
    fclose(file);
}

void usage() {
    printf("Usage:\n");
    printf("  log <level> <message>   - Log a message with the specified level (INFO, WARN, ERROR)\n");
    printf("  read                    - Read and display logs\n");
    printf("  clear                   - Clear the log file\n");
    printf("  filter <level>          - Filter logs by level (INFO, WARN, ERROR)\n");
    printf("  help                    - Display this help message\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        usage();
        return 1;
    }

    if (strcmp(argv[1], "log") == 0 && argc == 4) {
        log_message(argv[2], argv[3]);
    } else if (strcmp(argv[1], "read") == 0) {
        read_logs();
    } else if (strcmp(argv[1], "clear") == 0) {
        clear_logs();
    } else if (strcmp(argv[1], "filter") == 0 && argc == 3) {
        filter_logs(argv[2]);
    } else {
        usage();
    }

    return 0;
}