//FormAI DATASET v1.0 Category: Log analysis ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LINE_LENGTH 500

struct log_entry {
    char datetime[20];
    char level[10];
    char message[MAX_LINE_LENGTH];
};

void parse_log_entries(char *filename, struct log_entry *entries, int *num_entries);
void print_logs(struct log_entry *entries, int num_entries, char *level_filter);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: log_analysis <log_file> <filter_level>\n");
        exit(1);
    }

    char *filename = argv[1];
    char *level_filter = argv[2];

    struct log_entry entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    parse_log_entries(filename, entries, &num_entries);
    print_logs(entries, num_entries, level_filter);

    return 0;
}

void parse_log_entries(char *filename, struct log_entry *entries, int *num_entries) {
    FILE *log_file = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, log_file) && *num_entries < MAX_LOG_ENTRIES) {
        char *date = strtok(line, " ");
        char *time = strtok(NULL, " ");
        sprintf(entries[*num_entries].datetime, "%s %s", date, time);

        char *level = strtok(NULL, " ");
        strcpy(entries[*num_entries].level, level);

        char *message = strtok(NULL, "\n");
        strcpy(entries[*num_entries].message, message);

        (*num_entries)++;
    }

    fclose(log_file);
}

void print_logs(struct log_entry *entries, int num_entries, char *level_filter) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].level, level_filter) == 0) {
            printf("%s %s %s\n", entries[i].datetime, entries[i].level, entries[i].message);
        }
    }
}