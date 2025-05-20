//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100
#define MAX_LOG_ENTRY_LENGTH 100

struct log_entry {
    char ip[16];
    char method[10];
    char url[100];
    char user_agent[100];
};

void log_request(struct log_entry *entry) {
    printf("Logged request:\n");
    printf("IP: %s\n", entry->ip);
    printf("Method: %s\n", entry->method);
    printf("URL: %s\n", entry->url);
    printf("User-Agent: %s\n", entry->user_agent);
}

int main() {
    FILE *log_file;
    char log_entry_buffer[MAX_LOG_ENTRY_LENGTH];
    struct log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    log_file = fopen("access.log", "r");

    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        return 1;
    }

    while (fgets(log_entry_buffer, MAX_LOG_ENTRY_LENGTH, log_file)!= NULL) {
        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Error: maximum number of log entries reached.\n");
            fclose(log_file);
            return 1;
        }

        struct log_entry *entry = &log_entries[num_entries];
        num_entries++;

        char *token = strtok(log_entry_buffer, " ");
        strcpy(entry->ip, token);

        token = strtok(NULL, " ");
        strcpy(entry->method, token);

        token = strtok(NULL, " ");
        strcpy(entry->url, token);

        token = strtok(NULL, " ");
        strcpy(entry->user_agent, token);
    }

    fclose(log_file);

    printf("Number of log entries: %d\n", num_entries);

    for (int i = 0; i < num_entries; i++) {
        log_request(&log_entries[i]);
    }

    return 0;
}