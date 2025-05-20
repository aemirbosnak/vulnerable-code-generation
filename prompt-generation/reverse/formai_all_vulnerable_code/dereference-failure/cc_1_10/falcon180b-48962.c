//Falcon-180B DATASET v1.0 Category: System event logger ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LOG_SIZE 1000
#define LOG_FILE "event.log"
#define LOG_PERMISSION 0644

typedef struct {
    time_t timestamp;
    char event[100];
} LogEntry;

void log_event(const char* event) {
    FILE* log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        fprintf(stderr, "Error: Could not open log file\n");
        exit(1);
    }

    LogEntry entry;
    strncpy(entry.event, event, sizeof(entry.event));
    entry.timestamp = time(NULL);

    fwrite(&entry, sizeof(LogEntry), 1, log_file);

    fclose(log_file);
}

void read_log(void) {
    FILE* log_file = fopen(LOG_FILE, "r");
    if (log_file == NULL) {
        fprintf(stderr, "Error: Could not open log file\n");
        exit(1);
    }

    LogEntry entry;
    while (fread(&entry, sizeof(LogEntry), 1, log_file) == 1) {
        printf("%s - %s\n", ctime(&entry.timestamp), entry.event);
    }

    fclose(log_file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [event]\n", argv[0]);
        return 1;
    }

    const char* event = argv[1];
    log_event(event);
    printf("Event logged: %s\n", event);

    return 0;
}