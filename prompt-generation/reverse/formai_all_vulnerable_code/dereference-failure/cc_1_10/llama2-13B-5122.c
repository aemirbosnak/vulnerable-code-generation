//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_LOG_SIZE 1024*1024
#define MAX_LINE_LENGTH 1024

typedef struct {
    int error_count;
    int warning_count;
    int successful_count;
} log_stats_t;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    char* log_file = argv[1];
    int fd = open(log_file, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open log file");
        return 2;
    }

    log_stats_t* stats = malloc(sizeof(log_stats_t));
    stats->error_count = 0;
    stats->warning_count = 0;
    stats->successful_count = 0;

    char buffer[MAX_LINE_LENGTH];
    size_t bytes_read;
    while ((bytes_read = read(fd, buffer, MAX_LINE_LENGTH)) > 0) {
        buffer[bytes_read] = '\0';

        if (strncmp(buffer, "error:", 5) == 0) {
            stats->error_count++;
        } else if (strncmp(buffer, "warning:", 7) == 0) {
            stats->warning_count++;
        } else {
            stats->successful_count++;
        }
    }

    close(fd);

    // Print the log statistics
    printf("Log Statistics:\n");
    printf("Errors: %d\n", stats->error_count);
    printf("Warnings: %d\n", stats->warning_count);
    printf("Successful requests: %d\n", stats->successful_count);

    free(stats);

    return 0;
}