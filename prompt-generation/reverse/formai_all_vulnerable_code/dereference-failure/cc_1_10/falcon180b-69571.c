//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 256

typedef struct {
    char ip[16];
    char date_time[32];
    char request[MAX_LOG_ENTRY_LENGTH];
    int response_code;
} log_entry;

int main(int argc, char **argv) {
    FILE *log_file;
    char line[MAX_LOG_ENTRY_LENGTH];
    char delimiter[] = " ";
    log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    log_file = fopen("access.log", "r");

    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LOG_ENTRY_LENGTH, log_file)!= NULL) {
        char *token = strtok(line, delimiter);
        strcpy(log_entries[num_entries].ip, token);

        token = strtok(NULL, delimiter);
        strcpy(log_entries[num_entries].date_time, token);

        token = strtok(NULL, delimiter);
        strcpy(log_entries[num_entries].request, token);

        token = strtok(NULL, delimiter);
        log_entries[num_entries].response_code = atoi(token);

        num_entries++;

        if (num_entries == MAX_LOG_ENTRIES) {
            break;
        }
    }

    fclose(log_file);

    printf("Number of log entries: %d\n", num_entries);

    for (int i = 0; i < num_entries; i++) {
        printf("IP: %s\n", log_entries[i].ip);
        printf("Date and time: %s\n", log_entries[i].date_time);
        printf("Request: %s\n", log_entries[i].request);
        printf("Response code: %d\n\n", log_entries[i].response_code);
    }

    return 0;
}