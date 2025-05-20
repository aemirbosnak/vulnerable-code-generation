//Code Llama-13B DATASET v1.0 Category: Log analysis ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LOG_LENGTH 1024
#define MAX_LOG_ENTRIES 100

// Structure to hold log data
typedef struct {
    char log_id[MAX_LOG_LENGTH];
    char log_message[MAX_LOG_LENGTH];
    int log_level;
    int log_count;
} log_entry;

// Function to parse log file and extract data
void parse_log_file(char *log_file, log_entry *log_data, int *num_entries) {
    FILE *fp = fopen(log_file, "r");
    char line[MAX_LOG_LENGTH];
    int i = 0;
    while (fgets(line, MAX_LOG_LENGTH, fp)) {
        // Parse log line and extract data
        char *token = strtok(line, " ");
        strcpy(log_data[i].log_id, token);
        token = strtok(NULL, " ");
        strcpy(log_data[i].log_message, token);
        token = strtok(NULL, " ");
        log_data[i].log_level = atoi(token);
        log_data[i].log_count = 1;
        i++;
    }
    *num_entries = i;
    fclose(fp);
}

// Function to calculate statistical data
void calculate_statistics(log_entry *log_data, int num_entries) {
    // Calculate total log count
    int total_log_count = 0;
    for (int i = 0; i < num_entries; i++) {
        total_log_count += log_data[i].log_count;
    }
    printf("Total log count: %d\n", total_log_count);

    // Calculate log levels
    int log_levels[5] = {0};
    for (int i = 0; i < num_entries; i++) {
        log_levels[log_data[i].log_level]++;
    }
    printf("Log levels:\n");
    for (int i = 0; i < 5; i++) {
        printf("Level %d: %d\n", i, log_levels[i]);
    }

    // Calculate average log count per level
    int avg_log_count[5] = {0};
    for (int i = 0; i < 5; i++) {
        avg_log_count[i] = log_levels[i] / total_log_count;
    }
    printf("Average log count per level:\n");
    for (int i = 0; i < 5; i++) {
        printf("Level %d: %.2f\n", i, avg_log_count[i]);
    }
}

int main() {
    // Parse log file and extract data
    log_entry log_data[MAX_LOG_ENTRIES];
    int num_entries;
    parse_log_file("log.txt", log_data, &num_entries);

    // Calculate statistical data
    calculate_statistics(log_data, num_entries);

    return 0;
}