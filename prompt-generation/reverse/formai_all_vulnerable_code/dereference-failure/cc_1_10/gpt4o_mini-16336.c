//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char event[100];
    char time[20];
} LogEntry;

typedef struct {
    LogEntry *entries;
    int count;
    int capacity;
} Log;

Log* create_log(int capacity) {
    Log *log = (Log *)malloc(sizeof(Log));
    log->count = 0;
    log->capacity = capacity;
    log->entries = (LogEntry *)malloc(sizeof(LogEntry) * capacity);
    return log;
}

void destroy_log(Log *log) {
    free(log->entries);
    free(log);
}

void log_event(Log *log, const char *event, const char *time) {
    if (log->count >= log->capacity) {
        log->capacity *= 2;
        log->entries = (LogEntry *)realloc(log->entries, sizeof(LogEntry) * log->capacity);
    }
    strncpy(log->entries[log->count].event, event, sizeof(log->entries[log->count].event));
    strncpy(log->entries[log->count].time, time, sizeof(log->entries[log->count].time));
    log->count++;
}

void display_log(Log *log) {
    printf("\nOh, what a tangled web we weave...\n");
    printf("Behold the log of our tragic tale:\n");
    for (int i = 0; i < log->count; i++) {
        printf("At %s, %s did happen.\n", log->entries[i].time, log->entries[i].event);
    }
    printf("Alas, 'tis but a shadow of what might have been.\n");
}

void analyze_log(Log *log) {
    if (log->count == 0) {
        printf("\nNo events to analyze, sweet sorrow.\n");
        return;
    }

    printf("\nLet us delve deeper into this darkened tale of woe:\n");
    for (int i = 0; i < log->count; i++) {
        if (strstr(log->entries[i].event, "love")) {
            printf("A love that bloomed in the darkness: %s\n", log->entries[i].event);
        } else if (strstr(log->entries[i].event, "death")) {
            printf("A sorrowful end met in cruel fate: %s\n", log->entries[i].event);
        } else {
            printf("An ordinary event: %s\n", log->entries[i].event);
        }
    }
}

int main() {
    Log *log = create_log(5);

    log_event(log, "Romeo meets Juliet", "At dusk");
    log_event(log, "A ball where hearts are lost", "Evening glow");
    log_event(log, "Their love defies the night", "Midnight's embrace");
    log_event(log, "A heart is broken, and death approaches", "Dawn's betrayal");
    log_event(log, "A potion taken, a tragic mistake", "Fateful moment");
    
    display_log(log);
    analyze_log(log);

    destroy_log(log);
    return 0;
}