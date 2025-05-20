//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LOG_LINE 256
#define MAX_LOG_FILES 10
#define MAX_LOG_TYPE 16

typedef struct {
    char type[MAX_LOG_TYPE];
    char message[MAX_LOG_LINE];
    char timestamp[20];
} LogEntry;

typedef struct {
    LogEntry *entries;
    int size;
    int capacity;
} LogFile;

LogFile* create_log_file(int capacity) {
    LogFile *log_file = (LogFile *)malloc(sizeof(LogFile));
    log_file->entries = (LogEntry *)malloc(sizeof(LogEntry) * capacity);
    log_file->size = 0;
    log_file->capacity = capacity;
    return log_file;
}

void free_log_file(LogFile *log_file) {
    free(log_file->entries);
    free(log_file);
}

void add_log_entry(LogFile *log_file, const char *type, const char *message) {
    if (log_file->size < log_file->capacity) {
        snprintf(log_file->entries[log_file->size].type, MAX_LOG_TYPE, "%s", type);
        snprintf(log_file->entries[log_file->size].message, MAX_LOG_LINE, "%s", message);
        snprintf(log_file->entries[log_file->size].timestamp, 20, "%ld", time(NULL));
        log_file->size++;
    } else {
        printf("Log file capacity reached. Cannot add more entries.\n");
    }
}

void display_log_entries(const LogFile *log_file) {
    for (int i = 0; i < log_file->size; i++) {
        printf("[%s] [%s]: %s\n", log_file->entries[i].timestamp, log_file->entries[i].type, log_file->entries[i].message);
    }
}

int parse_log_file(const char *filename, LogFile *log_file) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open log file: %s\n", filename);
        return -1;
    }
    
    char line[MAX_LOG_LINE];
    while (fgets(line, sizeof(line), file)) {
        char type[MAX_LOG_TYPE], message[MAX_LOG_LINE];
        sscanf(line, "[%[^]]] [%[^]]]: %[^\n]", type, message);
        add_log_entry(log_file, type, message);
    }
    
    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <logfile1> <logfile2> ... \n", argv[0]);
        return EXIT_FAILURE;
    }

    LogFile *log_files[MAX_LOG_FILES];
    int log_file_count = 0;

    for (int i = 1; i < argc && log_file_count < MAX_LOG_FILES; i++) {
        log_files[log_file_count] = create_log_file(100);
        if (parse_log_file(argv[i], log_files[log_file_count]) == -1) {
            continue;
        }
        log_file_count++;
    }

    printf("Combined Logs:\n");
    for (int i = 0; i < log_file_count; i++) {
        display_log_entries(log_files[i]);
        free_log_file(log_files[i]);
    }

    return EXIT_SUCCESS;
}