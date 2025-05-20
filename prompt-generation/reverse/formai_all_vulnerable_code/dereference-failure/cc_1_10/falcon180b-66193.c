//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define MAX_ENTRIES 1000

typedef struct {
    char ip[16];
    char date[20];
    char time[10];
    char request[100];
    char status[10];
} log_entry;

int main() {
    FILE *logfile;
    char line[1024];
    char *token;
    log_entry entries[MAX_ENTRIES];
    int num_entries = 0;

    logfile = fopen("access.log", "r");
    if (logfile == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), logfile)!= NULL) {
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

    fclose(logfile);

    printf("IP\tDate\tTime\tRequest\tStatus\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%-15s %-20s %-9s %-30s %-10s\n", entries[i].ip, entries[i].date, entries[i].time, entries[i].request, entries[i].status);
    }

    return 0;
}