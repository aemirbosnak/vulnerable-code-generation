//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_ENTRIES 1000

struct log_entry {
    char ip_address[16];
    char date_time[32];
    char request_type[8];
    char requested_file[256];
    int response_code;
};

int main() {
    FILE *log_file;
    char log_line[512];
    int num_entries = 0;
    struct log_entry entries[MAX_LOG_ENTRIES];

    log_file = fopen("example.log", "r");

    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    while (fgets(log_line, sizeof(log_line), log_file)!= NULL) {
        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Error: Log file contains more than %d entries.\n", MAX_LOG_ENTRIES);
            exit(1);
        }

        char *ip_address = strtok(log_line, " ");
        char *date_time = strtok(NULL, " ");
        char *request_type = strtok(NULL, " ");
        char *requested_file = strtok(NULL, " ");
        int response_code = atoi(strtok(NULL, " "));

        strcpy(entries[num_entries].ip_address, ip_address);
        strcpy(entries[num_entries].date_time, date_time);
        strcpy(entries[num_entries].request_type, request_type);
        strcpy(entries[num_entries].requested_file, requested_file);
        entries[num_entries].response_code = response_code;

        num_entries++;
    }

    fclose(log_file);

    printf("Number of log entries: %d\n", num_entries);

    for (int i = 0; i < num_entries; i++) {
        printf("Entry %d:\n", i + 1);
        printf("IP Address: %s\n", entries[i].ip_address);
        printf("Date and Time: %s\n", entries[i].date_time);
        printf("Request Type: %s\n", entries[i].request_type);
        printf("Requested File: %s\n", entries[i].requested_file);
        printf("Response Code: %d\n\n", entries[i].response_code);
    }

    return 0;
}