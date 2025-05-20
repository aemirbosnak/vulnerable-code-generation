//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 1000

struct log_entry {
    time_t timestamp;
    char message[MAX_LOG_ENTRY_LENGTH];
};

int main() {
    FILE *log_file = fopen("log.txt", "r");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    struct log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, log_file))!= -1) {
        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Error: Reached maximum number of log entries.\n");
            exit(1);
        }

        struct log_entry entry;
        strptime(line, "%Y-%m-%d %T", &(entry.timestamp));
        strncpy(entry.message, line + strlen(line) - 1, MAX_LOG_ENTRY_LENGTH);
        log_entries[num_entries] = entry;
        num_entries++;
    }

    fclose(log_file);

    printf("Log Analysis:\n");
    printf("==============\n");

    printf("Total number of log entries: %d\n", num_entries);

    printf("\nLog entries sorted by date:\n");
    for (int i = num_entries - 1; i >= 0; i--) {
        printf("%s: %s\n", ctime(&(log_entries[i].timestamp)), log_entries[i].message);
    }

    return 0;
}