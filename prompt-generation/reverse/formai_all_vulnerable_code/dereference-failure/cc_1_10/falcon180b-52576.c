//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_SIZE 256

typedef struct {
    char ip[16];
    char date[20];
    char method[10];
    char url[256];
    int status_code;
} log_entry;

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <log_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    log_entry entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    char line[MAX_LOG_ENTRY_SIZE];
    while (fgets(line, MAX_LOG_ENTRY_SIZE, log_file)!= NULL) {
        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Maximum number of log entries reached.\n");
            break;
        }

        char *token = strtok(line, " ");
        if (token == NULL) {
            continue;
        }

        strcpy(entries[num_entries].ip, token);
        token = strtok(NULL, " ");
        strcpy(entries[num_entries].date, token);
        token = strtok(NULL, " ");
        strcpy(entries[num_entries].method, token);
        token = strtok(NULL, " ");
        strcpy(entries[num_entries].url, token);
        entries[num_entries].status_code = atoi(token);

        num_entries++;
    }

    fclose(log_file);
    fclose(output_file);

    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    fprintf(output_file, "IP\tDate\tMethod\tURL\tStatus Code\n");
    for (int i = 0; i < num_entries; i++) {
        fprintf(output_file, "%s\t%s\t%s\t%s\t%d\n", entries[i].ip, entries[i].date, entries[i].method, entries[i].url, entries[i].status_code);
    }

    fclose(output_file);

    return 0;
}