//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_LINE 256

typedef struct {
    char ip[20];
    char date[20];
    char time[20];
    char request[50];
    char status[10];
    char size[10];
} log_entry;

void read_log_file(log_entry entries[], int *num_entries) {
    FILE *fp;
    char line[MAX_LOG_LINE];
    char *token;
    int i = 0;

    fp = fopen("access.log", "r");
    if (fp == NULL) {
        printf("Error: could not open log file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LOG_LINE, fp)!= NULL) {
        if (i >= MAX_LOG_ENTRIES) {
            printf("Error: log file too large.\n");
            exit(1);
        }

        token = strtok(line, " ");
        strcpy(entries[i].ip, token);

        token = strtok(NULL, " ");
        strcpy(entries[i].date, token);

        token = strtok(NULL, " ");
        strcpy(entries[i].time, token);

        token = strtok(NULL, " ");
        strcpy(entries[i].request, token);

        token = strtok(NULL, " ");
        strcpy(entries[i].status, token);

        token = strtok(NULL, " ");
        strcpy(entries[i].size, token);

        i++;
    }

    *num_entries = i;
    fclose(fp);
}

void print_log_entries(log_entry entries[], int num_entries) {
    int i;

    for (i = 0; i < num_entries; i++) {
        printf("IP: %s\n", entries[i].ip);
        printf("Date: %s\n", entries[i].date);
        printf("Time: %s\n", entries[i].time);
        printf("Request: %s\n", entries[i].request);
        printf("Status: %s\n", entries[i].status);
        printf("Size: %s\n\n", entries[i].size);
    }
}

int main() {
    log_entry entries[MAX_LOG_ENTRIES];
    int num_entries;

    read_log_file(entries, &num_entries);
    print_log_entries(entries, num_entries);

    return 0;
}