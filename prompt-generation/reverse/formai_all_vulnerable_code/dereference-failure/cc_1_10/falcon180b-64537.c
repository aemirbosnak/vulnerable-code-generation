//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOGS 100
#define MAX_WORD_LENGTH 100

struct log_entry {
    char ip_address[MAX_WORD_LENGTH];
    char date_and_time[MAX_WORD_LENGTH];
    char request_type[MAX_WORD_LENGTH];
    char requested_page[MAX_WORD_LENGTH];
};

void parse_log_file(char *filename, struct log_entry logs[MAX_LOGS]) {
    FILE *fp;
    int count = 0;
    char line[MAX_WORD_LENGTH];

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        char *token;
        int i = 0;

        // Extract IP address
        token = strtok(line, " ");
        strcpy(logs[count].ip_address, token);

        // Extract date and time
        token = strtok(NULL, " ");
        strcpy(logs[count].date_and_time, token);

        // Extract request type
        token = strtok(NULL, " ");
        strcpy(logs[count].request_type, token);

        // Extract requested page
        token = strtok(NULL, " ");
        strcpy(logs[count].requested_page, token);

        count++;
    }

    fclose(fp);
}

void print_log_entries(struct log_entry logs[MAX_LOGS], int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("IP address: %s\n", logs[i].ip_address);
        printf("Date and time: %s\n", logs[i].date_and_time);
        printf("Request type: %s\n", logs[i].request_type);
        printf("Requested page: %s\n\n", logs[i].requested_page);
    }
}

int main() {
    char filename[MAX_WORD_LENGTH];
    struct log_entry logs[MAX_LOGS];
    int count = 0;

    printf("Enter log file name: ");
    scanf("%s", filename);

    parse_log_file(filename, logs);
    print_log_entries(logs, count);

    return 0;
}