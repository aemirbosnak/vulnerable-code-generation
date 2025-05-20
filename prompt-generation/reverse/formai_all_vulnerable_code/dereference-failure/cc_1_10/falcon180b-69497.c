//Falcon-180B DATASET v1.0 Category: System event logger ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENT_LENGTH 256
#define MAX_EVENTS 1000

// Event structure
typedef struct {
    char message[MAX_EVENT_LENGTH];
    time_t timestamp;
} Event;

// Function prototypes
void log_event(const char* message);
void print_log(FILE* log_file);

int main() {
    FILE* log_file = fopen("event_log.txt", "w");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    srand(time(NULL));
    int num_events = rand() % MAX_EVENTS + 1;

    for (int i = 0; i < num_events; i++) {
        char* event_type = (char*) malloc(10 * sizeof(char));
        sprintf(event_type, "Event %d", i + 1);
        log_event(event_type);
        free(event_type);
    }

    fclose(log_file);
    return 0;
}

void log_event(const char* message) {
    time_t current_time = time(NULL);
    struct tm* time_info = localtime(&current_time);
    char time_buffer[80];
    strftime(time_buffer, 80, "%Y-%m-%d %H:%M:%S", time_info);

    Event event;
    strncpy(event.message, message, MAX_EVENT_LENGTH);
    event.timestamp = current_time;

    FILE* log_file = fopen("event_log.txt", "a");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return;
    }

    fprintf(log_file, "%s - %s\n", time_buffer, event.message);
    fclose(log_file);
}

void print_log(FILE* log_file) {
    char line[MAX_EVENT_LENGTH];
    while (fgets(line, MAX_EVENT_LENGTH, log_file)!= NULL) {
        printf("%s", line);
    }
}