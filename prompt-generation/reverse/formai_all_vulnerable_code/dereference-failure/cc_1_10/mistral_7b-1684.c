//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define LOG_FILE "event.log"
#define MAX_EVENT_LEN 256
#define MAX_LEVELS 5

typedef struct {
    char name[32];
    int level;
} LogLevel;

LogLevel levels[MAX_LEVELS] = {
    {"DEBUG", 1},
    {"INFO", 2},
    {"WARNING", 3},
    {"ERROR", 4},
    {"FATAL", 5}
};

void log_event(char *event, int level) {
    int fd = open(LOG_FILE, O_APPEND | O_WRONLY);
    if (fd < 0) {
        perror("Failed to open log file");
        return;
    }

    for (int i = 0; i < MAX_LEVELS; i++) {
        if (level <= levels[i].level) {
            time_t current_time = time(NULL);
            struct tm *time_info = localtime(&current_time);

            char timestamp[64];
            strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", time_info);

            char log_line[MAX_EVENT_LEN];
            snprintf(log_line, sizeof(log_line), "%s [%s] %s\n", timestamp, levels[i].name, event);

            write(fd, log_line, strlen(log_line));
            break;
        }
    }

    close(fd);
}

int main() {
    // Configure logging levels
    log_event("Program started", 2);

    // Your application code goes here
    int x = 5;
    int y = 10;

    if (x > y) {
        log_event("x is greater than y", 1);
    } else {
        log_event("x is less than or equal to y", 0);
    }

    // Other application logic here

    log_event("Program ended", 0);
    return 0;
}