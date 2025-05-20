//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LOG_ENTRIES 100000
#define MAX_WORD_LENGTH 100

struct log_entry {
    char ip_address[16];
    char date_time[24];
    char request_url[MAX_WORD_LENGTH];
    int response_code;
};

struct log_entry log_entries[MAX_LOG_ENTRIES];
int num_entries = 0;

void parse_log_entry(char* line) {
    char* token;
    int i = 0;

    // Extract IP address
    token = strtok(line, " ");
    strcpy(log_entries[num_entries].ip_address, token);
    i++;

    // Extract date and time
    token = strtok(NULL, " ");
    strcpy(log_entries[num_entries].date_time, token);
    i++;

    // Extract request URL
    while (i < MAX_WORD_LENGTH && (token = strtok(NULL, " "))!= NULL) {
        strcat(log_entries[num_entries].request_url, token);
        strcat(log_entries[num_entries].request_url, " ");
        i++;
    }

    // Extract response code
    log_entries[num_entries].response_code = atoi(strtok(NULL, "\n"));

    num_entries++;
}

int main() {
    FILE* log_file;
    char line[512];
    int i;

    log_file = fopen("access.log", "r");

    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    num_entries = 0;

    while (fgets(line, sizeof(line), log_file)!= NULL) {
        parse_log_entry(line);
    }

    fclose(log_file);

    printf("Number of log entries: %d\n", num_entries);

    for (i = 0; i < num_entries; i++) {
        printf("IP Address: %s\n", log_entries[i].ip_address);
        printf("Date and Time: %s\n", log_entries[i].date_time);
        printf("Request URL: %s\n", log_entries[i].request_url);
        printf("Response Code: %d\n\n", log_entries[i].response_code);
    }

    return 0;
}