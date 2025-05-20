//Falcon-180B DATASET v1.0 Category: System event logger ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LOG_FILE "event.log"
#define MAX_LOG_SIZE 1024 * 1024 * 10 // 10 MB

typedef struct {
    time_t timestamp;
    char event[256];
} LogEntry;

void log_event(const char* event) {
    time_t now = time(NULL);
    struct tm tm = *localtime(&now);
    char timestamp[32];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", &tm);

    LogEntry entry = {
       .timestamp = now,
       .event = event
    };

    FILE* log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file: %s\n", LOG_FILE);
        return;
    }

    fprintf(log_file, "%s - %s\n", timestamp, entry.event);
    fclose(log_file);
}

int main() {
    int log_fd = open(LOG_FILE, O_RDWR | O_CREAT, 0644);
    if (log_fd == -1) {
        fprintf(stderr, "Error creating log file: %s\n", LOG_FILE);
        return 1;
    }

    struct stat log_stat;
    if (fstat(log_fd, &log_stat) == -1) {
        fprintf(stderr, "Error getting log file status: %s\n", LOG_FILE);
        return 1;
    }

    if (log_stat.st_size >= MAX_LOG_SIZE) {
        fprintf(stderr, "Log file reached maximum size, truncating...\n");
        if (ftruncate(log_fd, 0) == -1) {
            fprintf(stderr, "Error truncating log file: %s\n", LOG_FILE);
            return 1;
        }
    }

    log_event("Program started");

    // Add more log events here...

    log_event("Program ended");

    close(log_fd);
    return 0;
}