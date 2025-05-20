//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 1024

struct log_entry {
    char timestamp[32];
    char ip[16];
    char method[8];
    char url[256];
    int status_code;
};

int main() {
    FILE *log_file;
    char log_filename[32] = "access.log";
    struct log_entry entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    log_file = fopen(log_filename, "r");
    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        return 1;
    }

    while (fgets(entries[num_entries].timestamp, sizeof(entries[num_entries].timestamp), log_file)!= NULL) {
        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Error: log file is too large.\n");
            fclose(log_file);
            return 1;
        }

        char *token = strtok(entries[num_entries].timestamp, " ");
        strcpy(entries[num_entries].ip, token);
        token = strtok(NULL, " ");
        strcpy(entries[num_entries].method, token);
        token = strtok(NULL, " ");
        strcpy(entries[num_entries].url, token);
        sscanf(token, "%d", &entries[num_entries].status_code);

        num_entries++;
    }

    fclose(log_file);

    printf("Number of log entries: %d\n", num_entries);

    int total_requests = 0;
    int total_successful_requests = 0;
    int total_failed_requests = 0;

    for (int i = 0; i < num_entries; i++) {
        if (entries[i].status_code >= 200 && entries[i].status_code < 400) {
            total_successful_requests++;
        } else {
            total_failed_requests++;
        }
        total_requests++;
    }

    double success_rate = (double)total_successful_requests / total_requests * 100.0;
    printf("Success rate: %.2f%%\n", success_rate);

    return 0;
}