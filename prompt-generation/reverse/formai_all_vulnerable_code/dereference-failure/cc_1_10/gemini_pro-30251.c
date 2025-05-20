//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define LOG_FILE "/dev/null"
#define MAX_LOG_SIZE 1024

static int log_fd = -1;

void init_logger() {
    if (log_fd == -1) {
        log_fd = open(LOG_FILE, O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (log_fd == -1) {
            perror("Failed to open log file");
            exit(1);
        }
    }
}

void log_event(const char *event) {
    if (log_fd == -1) {
        init_logger();
    }

    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0';

    char message[MAX_LOG_SIZE];
    snprintf(message, MAX_LOG_SIZE, "%s: %s\n", timestamp, event);

    write(log_fd, message, strlen(message));
}

int main() {
    init_logger();

    log_event("Radio transmission received from unknown source");
    log_event("Scavenged supplies from abandoned building");
    log_event("Encountered hostile raiders, firefight ensued");
    log_event("Reached safe house, preparing for the night");

    close(log_fd);

    return 0;
}