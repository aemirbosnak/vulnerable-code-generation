//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 1000

typedef struct {
    char *ip;
    char *date;
    char *time;
    char *request;
} log_entry_t;

typedef struct {
    log_entry_t **entries;
    int num_entries;
} log_t;

int log_init(log_t *log) {
    log->entries = (log_entry_t **)malloc(MAX_LOG_ENTRIES * sizeof(log_entry_t *));
    if (log->entries == NULL) {
        return 0;
    }
    log->num_entries = 0;
    return 1;
}

int log_add_entry(log_t *log, char *ip, char *date, char *time, char *request) {
    log_entry_t *entry = (log_entry_t *)malloc(sizeof(log_entry_t));
    if (entry == NULL) {
        return 0;
    }
    entry->ip = strdup(ip);
    entry->date = strdup(date);
    entry->time = strdup(time);
    entry->request = strdup(request);
    log->entries[log->num_entries] = entry;
    log->num_entries++;
    return 1;
}

int log_print_entries(log_t *log) {
    int i;
    for (i = 0; i < log->num_entries; i++) {
        printf("IP: %s\nDate: %s\nTime: %s\nRequest: %s\n\n",
               log->entries[i]->ip,
               log->entries[i]->date,
               log->entries[i]->time,
               log->entries[i]->request);
    }
    return 1;
}

int log_free(log_t *log) {
    int i;
    for (i = 0; i < log->num_entries; i++) {
        free(log->entries[i]->ip);
        free(log->entries[i]->date);
        free(log->entries[i]->time);
        free(log->entries[i]->request);
        free(log->entries[i]);
    }
    free(log->entries);
    return 1;
}

int main() {
    log_t log;
    log_init(&log);
    log_add_entry(&log, "192.168.1.1", "2022-01-01", "12:00:00", "GET / HTTP/1.1");
    log_add_entry(&log, "192.168.1.2", "2022-01-01", "12:01:00", "POST /login HTTP/1.1");
    log_print_entries(&log);
    log_free(&log);
    return 0;
}