//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 256

typedef struct {
    char ip[16];
    char date[32];
    char time[32];
    char request[MAX_LOG_ENTRY_LENGTH];
    int status_code;
    int bytes_sent;
} LogEntry;

void parse_log_entry(char* log_line, LogEntry* entry) {
    char* token = strtok(log_line, " ");
    if (token == NULL) {
        return;
    }
    strcpy(entry->ip, token);

    token = strtok(NULL, " ");
    strcpy(entry->date, token);

    token = strtok(NULL, " ");
    strcpy(entry->time, token);

    token = strtok(NULL, " ");
    strcpy(entry->request, token);

    token = strtok(NULL, " ");
    entry->status_code = atoi(token);

    token = strtok(NULL, " ");
    entry->bytes_sent = atoi(token);
}

int compare_log_entries(const void* a, const void* b) {
    const LogEntry* entry_a = (const LogEntry*)a;
    const LogEntry* entry_b = (const LogEntry*)b;

    if (entry_a->status_code > entry_b->status_code) {
        return -1;
    } else if (entry_a->status_code < entry_b->status_code) {
        return 1;
    } else {
        return 0;
    }
}

void print_log_entry(LogEntry* entry) {
    printf("IP: %s\n", entry->ip);
    printf("Date: %s\n", entry->date);
    printf("Time: %s\n", entry->time);
    printf("Request: %s\n", entry->request);
    printf("Status Code: %d\n", entry->status_code);
    printf("Bytes Sent: %d\n\n", entry->bytes_sent);
}

int main() {
    FILE* log_file = fopen("access.log", "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    LogEntry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    char log_line[MAX_LOG_ENTRY_LENGTH];
    while (fgets(log_line, MAX_LOG_ENTRY_LENGTH, log_file)!= NULL) {
        if (num_entries >= MAX_LOG_ENTRIES) {
            break;
        }

        parse_log_entry(log_line, &log_entries[num_entries]);
        num_entries++;
    }

    fclose(log_file);

    qsort(log_entries, num_entries, sizeof(LogEntry), compare_log_entries);

    for (int i = 0; i < num_entries; i++) {
        print_log_entry(&log_entries[i]);
    }

    return 0;
}