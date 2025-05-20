//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LOG_FILE "event.log"

typedef struct {
    time_t timestamp;
    int level;
    char message[1024];
} LogEntry;

void log_message(int level, const char *message) {
    struct tm *timeinfo;
    time_t now;
    int fd;
    LogEntry entry;

    now = time(NULL);
    timeinfo = localtime(&now);

    if ((fd = open(LOG_FILE, O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0) {
        perror("Could not open log file");
        exit(EXIT_FAILURE);
    }

    entry.timestamp = now;
    entry.level = level;
    strcpy(entry.message, asctime(timeinfo));
    strcat(entry.message, ": ");
    strcat(entry.message, message);

    write(fd, &entry, sizeof(LogEntry));
    fsync(fd);
    close(fd);
}

void error_log(const char *message) {
    log_message(1, message);
}

void info_log(const char *message) {
    log_message(0, message);
}

int main(int argc, char **argv) {
    int i;

    for (i = 0; i < 10; i++) {
        info_log("System is running normally.");
        sleep(1);
    }

    error_log("Unexpected error occurred!");

    return 0;
}