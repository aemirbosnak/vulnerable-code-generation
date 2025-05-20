//FormAI DATASET v1.0 Category: Log analysis ; Style: visionary
//This program is a unique log analysis tool that uses advanced algorithms
//to identify anomalies in log data and presents them in a clear and concise way.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum length of log entries and the maximum number of entries to analyze
#define MAX_LINE_LENGTH 300
#define MAX_ENTRIES 1000

// Define a struct for holding log entries
typedef struct log_entry {
    char* date;
    char* time;
    char* module;
    char* level;
    char* message;
} log_entry;

// Define a struct for holding analysis results
typedef struct analysis_result {
    int num_errors;
    int num_warnings;
    log_entry* errors[MAX_ENTRIES];
    log_entry* warnings[MAX_ENTRIES];
} analysis_result;

// Function to read log entries from a file and store them in an array
int read_log_file(const char* filename, log_entry* entries[]) {
    FILE* fp;
    char line[MAX_LINE_LENGTH];
    int num_entries = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file %s\n", filename);
        return -1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL && num_entries < MAX_ENTRIES) {
        log_entry* entry = (log_entry*) malloc(sizeof(log_entry));
        entry->date = strtok(line, " ");
        entry->time = strtok(NULL, " ");
        entry->module = strtok(NULL, ":");
        entry->level = strtok(NULL, ":");
        entry->message = strtok(NULL, "\n");
        entries[num_entries++] = entry;
    }

    fclose(fp);
    return num_entries;
}

// Function to analyze log entries for errors and warnings
void analyze_log_entries(log_entry* entries[], int num_entries, analysis_result* result) {
    for (int i = 0; i < num_entries; i++) {
        log_entry* entry = entries[i];
        if (strcmp(entry->level, "ERROR") == 0) {
            result->errors[result->num_errors++] = entry;
        } else if (strcmp(entry->level, "WARNING") == 0) {
            result->warnings[result->num_warnings++] = entry;
        }
    }
}

// Function to print analysis results
void print_analysis_result(analysis_result* result) {
    printf("Number of errors: %d\n", result->num_errors);
    for (int i = 0; i < result->num_errors; i++) {
        log_entry* entry = result->errors[i];
        printf("%s %s %s %s %s\n", entry->date, entry->time, entry->module, entry->level, entry->message);
    }
    printf("\nNumber of warnings: %d\n", result->num_warnings);
    for (int i = 0; i < result->num_warnings; i++) {
        log_entry* entry = result->warnings[i];
        printf("%s %s %s %s %s\n", entry->date, entry->time, entry->module, entry->level, entry->message);
    }
}

// Main function
int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <log file>\n", argv[0]);
        exit(1);
    }

    log_entry* entries[MAX_ENTRIES];
    int num_entries = read_log_file(argv[1], entries);
    if (num_entries == -1) {
        exit(1);
    }

    analysis_result result;
    result.num_errors = 0;
    result.num_warnings = 0;
    analyze_log_entries(entries, num_entries, &result);

    print_analysis_result(&result);

    return 0;
}