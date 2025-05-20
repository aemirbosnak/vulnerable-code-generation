//Gemma-7B DATASET v1.0 Category: System event logger ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_MAX_SIZE 1024
#define LOG_FILE "event_log.txt"

typedef struct EventLogEntry {
    char timestamp[26];
    char event_name[256];
    char event_details[LOG_MAX_SIZE];
} EventLogEntry;

EventLogEntry events[LOG_MAX_SIZE] = {0};

int next_event_index = 0;

void log_event(char *event_name, char *event_details) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    events[next_event_index].timestamp[0] = tm->tm_hour;
    events[next_event_index].timestamp[1] = tm->tm_min;
    events[next_event_index].timestamp[2] = tm->tm_sec;

    strcpy(events[next_event_index].event_name, event_name);
    strcpy(events[next_event_index].event_details, event_details);

    next_event_index++;

    if (next_event_index >= LOG_MAX_SIZE) {
        next_event_index = 0;
    }
}

int main() {
    log_event("Coffee brewed", "A pot of strong coffee was brewed.");
    log_event("Cat played with", "A fluffy cat named Luna played with a ball of yarn.");
    log_event("Pizza eaten", "A delicious pizza was devoured.");

    FILE *log_file = fopen(LOG_FILE, "w");

    for (int i = 0; i < next_event_index; i++) {
        fprintf(log_file, "Time: %s, Event: %s, Details: %s\n", events[i].timestamp, events[i].event_name, events[i].event_details);
    }

    fclose(log_file);

    return 0;
}