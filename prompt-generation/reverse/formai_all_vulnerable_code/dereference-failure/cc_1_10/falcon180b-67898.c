//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_LOG_SIZE 1000000
#define MAX_LOG_ENTRY_SIZE 1024

typedef struct {
    char ip[16];
    char date[20];
    char time[10];
    char request[MAX_LOG_ENTRY_SIZE];
    int status_code;
} log_entry;

void parse_log_entry(char* log_line, log_entry* entry) {
    char* token = strtok(log_line, " ");
    strcpy(entry->ip, token);

    token = strtok(NULL, " ");
    strcpy(entry->date, token);

    token = strtok(NULL, " ");
    strcpy(entry->time, token);

    token = strtok(NULL, " ");
    strcpy(entry->request, token);

    token = strtok(NULL, " ");
    entry->status_code = atoi(token);
}

int compare_log_entries(const void* a, const void* b) {
    const log_entry* entry_a = (const log_entry*)a;
    const log_entry* entry_b = (const log_entry*)b;

    if (entry_a->status_code == entry_b->status_code) {
        return 0;
    }

    return entry_a->status_code < entry_b->status_code? -1 : 1;
}

int main() {
    FILE* log_file = fopen("access.log", "r");
    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        exit(1);
    }

    log_entry log_entries[MAX_LOG_SIZE];
    int num_entries = 0;

    char log_line[MAX_LOG_ENTRY_SIZE];
    while (fgets(log_line, MAX_LOG_ENTRY_SIZE, log_file)!= NULL) {
        parse_log_entry(log_line, &log_entries[num_entries]);
        num_entries++;
    }

    fclose(log_file);

    qsort(log_entries, num_entries, sizeof(log_entry), compare_log_entries);

    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", log_entries[i].ip, log_entries[i].request);
    }

    return 0;
}