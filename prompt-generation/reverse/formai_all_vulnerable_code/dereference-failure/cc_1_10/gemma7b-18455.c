//Gemma-7B DATASET v1.0 Category: System event logger ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1024
#define LOG_FILE_NAME "event.log"

typedef struct EventLogEntry {
    char timestamp[26];
    char event_name[256];
    char event_details[MAX_LOG_SIZE];
} EventLogEntry;

EventLogEntry event_log[MAX_LOG_SIZE];

int event_log_index = 0;

void log_event(char *event_name, char *event_details) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    event_log[event_log_index].timestamp[0] = tm->tm_hour;
    event_log[event_log_index].timestamp[1] = tm->tm_min;
    event_log[event_log_index].timestamp[2] = tm->tm_sec;
    event_log[event_log_index].event_name[0] = '\0';
    strcpy(event_log[event_log_index].event_name, event_name);
    event_log[event_log_index].event_details[0] = '\0';
    strcpy(event_log[event_log_index].event_details, event_details);

    event_log_index++;

    if (event_log_index >= MAX_LOG_SIZE) {
        event_log_index = 0;
        FILE *fp = fopen(LOG_FILE_NAME, "w");
        fprintf(fp, "Event Log:\n");
        for (int i = 0; i < MAX_LOG_SIZE; i++) {
            fprintf(fp, "Timestamp: %s, Event Name: %s, Event Details: %s\n", event_log[i].timestamp, event_log[i].event_name, event_log[i].event_details);
        }
        fclose(fp);
    }
}

int main() {
    log_event("System Boot", "System started successfully.");
    log_event("User Login", "John Doe logged in.");
    log_event("Application Launch", "Word Processing application launched.");
    log_event("Document Save", "Document saved as 'mydoc.doc'.");

    return 0;
}