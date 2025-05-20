//Falcon-180B DATASET v1.0 Category: System event logger ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOG_FILE "event.log"
#define MAX_LOG_SIZE 1000000 // 1 MB

typedef struct {
    time_t timestamp;
    char event[256];
} event_t;

FILE *log_file;
event_t *event_buffer;
int event_count;

void init_logger() {
    log_file = fopen(LOG_FILE, "w");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }
    event_buffer = malloc(MAX_LOG_SIZE * sizeof(event_t));
    if (event_buffer == NULL) {
        printf("Error: Could not allocate memory for event buffer.\n");
        exit(1);
    }
    event_count = 0;
}

void log_event(const char *event) {
    if (event_count >= MAX_LOG_SIZE) {
        printf("Warning: Event buffer is full. Discarding new events.\n");
        return;
    }
    event_buffer[event_count].timestamp = time(NULL);
    strncpy(event_buffer[event_count].event, event, 256);
    event_count++;
}

void write_log_to_file() {
    if (event_count == 0) {
        printf("No events logged.\n");
        return;
    }
    fprintf(log_file, "Timestamp\tEvent\n");
    for (int i = 0; i < event_count; i++) {
        fprintf(log_file, "%ld\t%s\n", event_buffer[i].timestamp, event_buffer[i].event);
    }
    fclose(log_file);
    printf("Log written to file.\n");
}

int main() {
    init_logger();

    log_event("Program started");
    sleep(1);
    log_event("User logged in");
    sleep(2);
    log_event("File uploaded");
    sleep(3);
    log_event("Database query executed");

    write_log_to_file();

    return 0;
}