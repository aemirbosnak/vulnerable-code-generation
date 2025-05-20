//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

struct log_entry {
    char ip[16];
    char date[20];
    char time[10];
    char request[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *log_file;
    char log_line[MAX_ENTRY_LENGTH];
    struct log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    log_file = fopen("example.log", "r");

    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        return 1;
    }

    while (fgets(log_line, MAX_ENTRY_LENGTH, log_file)!= NULL) {
        struct log_entry entry;
        char *token;
        int i = 0;

        // Parse IP address
        token = strtok(log_line, " ");
        strcpy(entry.ip, token);

        // Parse date and time
        token = strtok(NULL, " ");
        strcpy(entry.date, token);
        token = strtok(NULL, " ");
        strcpy(entry.time, token);

        // Parse request
        token = strtok(NULL, " ");
        strcpy(entry.request, token);

        log_entries[num_entries] = entry;
        num_entries++;
    }

    fclose(log_file);

    // Sort entries by IP address
    for (int i = 0; i < num_entries - 1; i++) {
        for (int j = i + 1; j < num_entries; j++) {
            if (strcmp(log_entries[i].ip, log_entries[j].ip) > 0) {
                struct log_entry temp = log_entries[i];
                log_entries[i] = log_entries[j];
                log_entries[j] = temp;
            }
        }
    }

    // Print sorted entries
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s %s %s\n", log_entries[i].ip, log_entries[i].date, log_entries[i].time, log_entries[i].request);
    }

    return 0;
}