//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000 // Maximum number of log entries

struct log_entry {
    char ip[16];
    char date[20];
    char time[8];
    char url[100];
};

void read_log_file(struct log_entry entries[], int *num_entries) {
    FILE *fp;
    char line[1024];
    int i = 0;

    fp = fopen("access.log", "r");
    if (fp == NULL) {
        printf("Error opening log file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        struct log_entry entry;
        char *ip, *date, *time, *url;

        if (i >= MAX_LOG_ENTRIES) {
            printf("Log file is too large\n");
            fclose(fp);
            exit(1);
        }

        ip = strtok(line, " ");
        date = strtok(NULL, " ");
        time = strtok(NULL, " ");
        url = strtok(NULL, " ");

        strcpy(entry.ip, ip);
        strcpy(entry.date, date);
        strcpy(entry.time, time);
        strcpy(entry.url, url);

        entries[i] = entry;
        i++;
    }

    *num_entries = i;
    fclose(fp);
}

void print_log_entries(struct log_entry entries[], int num_entries) {
    int i;

    for (i = 0; i < num_entries; i++) {
        printf("%-15s %-20s %-8s %s\n", entries[i].ip, entries[i].date, entries[i].time, entries[i].url);
    }
}

int main() {
    struct log_entry entries[MAX_LOG_ENTRIES];
    int num_entries;

    read_log_file(entries, &num_entries);
    print_log_entries(entries, num_entries);

    return 0;
}