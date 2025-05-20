//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_LINE_LEN 1024
#define MAX_LOG_FILE_SIZE 1024 * 1024 * 10

typedef struct {
    char *file;
    size_t file_size;
    size_t line_count;
    size_t max_line_len;
} log_file_t;

log_file_t *log_files = NULL;
size_t log_files_count = 0;

void log_file_add(const char *file_path) {
    log_file_t *new_file = malloc(sizeof(log_file_t));
    new_file->file = strdup(file_path);
    new_file->file_size = 0;
    new_file->line_count = 0;
    new_file->max_line_len = 0;

    if (log_files_count == 0) {
        log_files = malloc(sizeof(log_file_t));
        log_files[0] = *new_file;
    } else {
        log_files = realloc(log_files, (log_files_count + 1) * sizeof(log_file_t));
        log_files[log_files_count] = *new_file;
    }

    log_files_count++;
}

void log_file_read(const char *file_path) {
    log_file_t *file = malloc(sizeof(log_file_t));
    file->file = strdup(file_path);
    file->file_size = 0;
    file->line_count = 0;
    file->max_line_len = 0;

    FILE *file_ptr = fopen(file_path, "r");
    if (file_ptr == NULL) {
        perror("Failed to open log file");
        return;
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, file_ptr) != NULL) {
        size_t line_len = strlen(line);
        if (line_len > file->max_line_len) {
            file->max_line_len = line_len;
        }
        file->line_count++;
    }

    fclose(file_ptr);
}

void log_file_analyze(const char *file_path) {
    log_file_t *file = malloc(sizeof(log_file_t));
    file->file = strdup(file_path);
    file->file_size = 0;
    file->line_count = 0;
    file->max_line_len = 0;

    FILE *file_ptr = fopen(file_path, "r");
    if (file_ptr == NULL) {
        perror("Failed to open log file");
        return;
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, file_ptr) != NULL) {
        size_t line_len = strlen(line);
        if (line_len > file->max_line_len) {
            file->max_line_len = line_len;
        }
        file->line_count++;
    }

    fclose(file_ptr);

    // Calculate the log file size
    file_ptr = fopen(file_path, "r");
    if (file_ptr == NULL) {
        perror("Failed to open log file");
        return;
    }
    long file_size = ftell(file_ptr);
    fclose(file_ptr);
    file->file_size = file_size;

    // Print the log file analysis
    printf("Log file %s\n", file->file);
    printf("  File size: %ld bytes\n", file->file_size);
    printf("  Line count: %zu\n", file->line_count);
    printf("  Max line len: %zu\n", file->max_line_len);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file_path>\n", argv[0]);
        return 1;
    }

    log_file_add(argv[1]);

    for (size_t i = 1; i < argc; i++) {
        log_file_read(argv[i]);
    }

    for (size_t i = 0; i < log_files_count; i++) {
        log_file_analyze(log_files[i].file);
    }

    return 0;
}