//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_SIZE 1024

typedef struct {
    char ip[16];
    char method[8];
    char url[1024];
    char user_agent[1024];
    time_t timestamp;
} log_entry_t;

log_entry_t log_entries[MAX_LOG_ENTRIES];
int num_log_entries = 0;

void parse_log_entry(char* log_line) {
    char* token = strtok(log_line, " ");
    strcpy(log_entries[num_log_entries].ip, token);

    token = strtok(NULL, " ");
    strcpy(log_entries[num_log_entries].method, token);

    token = strtok(NULL, " ");
    strcpy(log_entries[num_log_entries].url, token);

    token = strtok(NULL, " ");
    strcpy(log_entries[num_log_entries].user_agent, token);

    log_entries[num_log_entries].timestamp = time(NULL);
    num_log_entries++;
}

void print_log_entries() {
    for (int i = 0; i < num_log_entries; i++) {
        printf("IP: %s\nMethod: %s\nURL: %s\nUser Agent: %s\nTimestamp: %ld\n\n",
               log_entries[i].ip, log_entries[i].method, log_entries[i].url, log_entries[i].user_agent, log_entries[i].timestamp);
    }
}

int main() {
    FILE* log_file = fopen("access.log", "r");

    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    char log_line[MAX_LOG_ENTRY_SIZE];
    while (fgets(log_line, MAX_LOG_ENTRY_SIZE, log_file)!= NULL) {
        parse_log_entry(log_line);
    }

    fclose(log_file);
    print_log_entries();

    return 0;
}