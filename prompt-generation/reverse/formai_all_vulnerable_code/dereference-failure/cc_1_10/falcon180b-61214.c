//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_SIZE 1024
#define MAX_REQUEST_URLS 1000
#define MAX_REQUEST_URLS_SIZE 2048

typedef struct {
    char ip[16];
    char date[32];
    char time[32];
    char request[MAX_REQUEST_URLS_SIZE];
    char status[32];
} log_entry_t;

int num_entries = 0;
log_entry_t entries[MAX_LOG_ENTRIES];

int read_log_file(FILE *fp) {
    char line[MAX_LOG_ENTRY_SIZE];
    char *token;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_entries == MAX_LOG_ENTRIES) {
            printf("Error: Maximum number of log entries reached.\n");
            return -1;
        }
        token = strtok(line, " ");
        strcpy(entries[num_entries].ip, token);
        token = strtok(NULL, " ");
        strcpy(entries[num_entries].date, token);
        token = strtok(NULL, " ");
        strcpy(entries[num_entries].time, token);
        token = strtok(NULL, " ");
        strcpy(entries[num_entries].request, token);
        token = strtok(NULL, " ");
        strcpy(entries[num_entries].status, token);
        num_entries++;
    }
    return 0;
}

void print_entries() {
    printf("IP\tDate\tTime\tRequest\tStatus\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\t%s\t%s\t%s\n", entries[i].ip, entries[i].date, entries[i].time, entries[i].request, entries[i].status);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return -1;
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Cannot open log file.\n");
        return -1;
    }
    if (read_log_file(fp)!= 0) {
        fclose(fp);
        return -1;
    }
    fclose(fp);
    print_entries();
    return 0;
}