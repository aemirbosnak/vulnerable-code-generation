//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of log entries that can be stored
#define MAX_LOG_ENTRIES 1000

// Define the structure of a log entry
typedef struct {
    char ip[16]; // IP address of the client
    char date[20]; // Date and time of the request
    char url[100]; // Requested URL
} log_entry;

// Function to compare two log entries based on their IP addresses
int compare_log_entries(const void* a, const void* b) {
    const log_entry* entry1 = (const log_entry*)a;
    const log_entry* entry2 = (const log_entry*)b;
    return strcmp(entry1->ip, entry2->ip);
}

// Function to parse a log entry from a string
log_entry parse_log_entry(char* log_line) {
    log_entry entry;
    char* token = strtok(log_line, " ");
    strcpy(entry.ip, token);
    token = strtok(NULL, " ");
    strcpy(entry.date, token);
    token = strtok(NULL, " ");
    strcpy(entry.url, token);
    return entry;
}

// Function to sort the log entries by IP address
void sort_log_entries(log_entry* entries, int num_entries) {
    qsort(entries, num_entries, sizeof(log_entry), compare_log_entries);
}

// Function to print the log entries
void print_log_entries(log_entry* entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n", entries[i].ip);
    }
}

int main() {
    FILE* log_file = fopen("logfile.txt", "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    log_entry* entries = malloc(MAX_LOG_ENTRIES * sizeof(log_entry));
    int num_entries = 0;

    char log_line[200];
    while (fgets(log_line, sizeof(log_line), log_file)!= NULL) {
        log_entry entry = parse_log_entry(log_line);
        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Maximum number of log entries reached.\n");
            break;
        }
        entries[num_entries++] = entry;
    }

    fclose(log_file);

    sort_log_entries(entries, num_entries);
    printf("Sorted log entries:\n");
    print_log_entries(entries, num_entries);

    free(entries);
    return 0;
}