//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LOG_SIZE 1024*1024
#define MAX_LOG_FILES 10

typedef struct {
    char *filename;
    size_t size;
    size_t written;
    off_t offset;
} log_file_t;

static log_file_t log_files[MAX_LOG_FILES];
static size_t log_file_count = 0;

void log_init(void) {
    log_file_count = 0;
    memset(log_files, 0, sizeof(log_files));
}

void log_append(const char *message) {
    size_t len = strlen(message);
    off_t offset = ftell(stdout);
    fwrite(message, 1, len, stdout);
    fflush(stdout);
    log_files[log_file_count].written += len;
    log_files[log_file_count].offset = offset;
    log_file_count++;
    if (log_file_count == MAX_LOG_FILES) {
        log_file_count = 0;
    }
}

void log_flush(void) {
    for (size_t i = 0; i < log_file_count; i++) {
        log_files[i].written += write(fileno(stdout), log_files[i].filename + log_files[i].written, log_files[i].size - log_files[i].written);
        if (log_files[i].written < log_files[i].size) {
            log_files[i].offset = ftell(stdout);
        }
    }
}

void log_rotate(void) {
    for (size_t i = 0; i < log_file_count; i++) {
        if (log_files[i].written > log_files[i].size) {
            // Rotate the log file
            char *new_file = malloc(log_files[i].size * 2);
            size_t new_file_size = log_files[i].size * 2;
            memcpy(new_file, log_files[i].filename, log_files[i].written);
            log_files[i].filename = new_file;
            log_files[i].written = 0;
            log_files[i].size = new_file_size;
            free(log_files[i].filename);
        }
    }
}

int main(void) {
    log_init();

    // Log some messages
    log_append("Starting program...\n");
    log_append("Doing some work...\n");
    log_append("Finishing up...\n");

    // Rotate the log files
    log_rotate();

    // Flush the logs
    log_flush();

    return 0;
}