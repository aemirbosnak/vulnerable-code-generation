//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define LOG_FILE "event_log.txt"

typedef struct {
    int event_id;
    char event_type[50];
    char event_description[200];
    time_t event_timestamp;
} EventLogEntry;

void create_log_file() {
    int fd;
    if ((fd = open(LOG_FILE, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0) {
        perror("Error creating log file");
        exit(EXIT_FAILURE);
    }
    close(fd);
}

void log_event(int event_id, char* event_type, char* event_description) {
    EventLogEntry entry;
    time_t current_time;
    int fd;

    entry.event_id = event_id;
    strcpy(entry.event_type, event_type);
    strcpy(entry.event_description, event_description);
    current_time = time(NULL);
    entry.event_timestamp = current_time;

    if ((fd = open(LOG_FILE, O_RDWR | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }

    fseek(fd, 0, SEEK_END);
    if (fwrite(&entry, sizeof(EventLogEntry), 1, fd) != 1) {
        perror("Error writing to log file");
        exit(EXIT_FAILURE);
    }

    fclose(fd);
}

int main() {
    int id;
    char type[50];
    char description[200];

    create_log_file();

    while (1) {
        sleep(1);
        id = rand() % 100 + 1;
        strcpy(type, "Event Type: Unknown");
        sprintf(description, "Event Description: Random event #%d", id);
        log_event(id, type, description);
        printf("Event #%d logged: %s\n", id, description);
    }

    return 0;
}