//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_LINES 1000000
#define MAX_LINE_LENGTH 1024

// Struct to hold log data
typedef struct {
    char ip[16];
    char date[32];
    char method[16];
    char url[256];
    int status_code;
} LogEntry;

// Function to parse a log line and fill in a LogEntry struct
void parse_log_line(char* line, LogEntry* entry) {
    char* token = strtok(line, " ");
    strcpy(entry->ip, token);

    token = strtok(NULL, " ");
    strcpy(entry->date, token);

    token = strtok(NULL, " ");
    strcpy(entry->method, token);

    token = strtok(NULL, " ");
    strcpy(entry->url, token);

    entry->status_code = atoi(strtok(NULL, " "));
}

// Function to write a LogEntry struct to a CSV file
void write_csv_entry(FILE* csv_file, LogEntry* entry) {
    fprintf(csv_file, "%s,%s,%s,%s,%d\n", entry->ip, entry->date, entry->method, entry->url, entry->status_code);
}

// Function to filter log entries based on IP address
int filter_by_ip(LogEntry* entry, char* ip_filter) {
    return strcmp(entry->ip, ip_filter) == 0;
}

// Function to filter log entries based on status code
int filter_by_status_code(LogEntry* entry, int status_code_filter) {
    return entry->status_code == status_code_filter;
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <log_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE* log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    FILE* csv_file = fopen(argv[2], "w");
    if (csv_file == NULL) {
        printf("Error opening output file.\n");
        fclose(log_file);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    LogEntry entry;

    // Read the first line to get the column names for the CSV file
    fgets(line, MAX_LINE_LENGTH, log_file);
    parse_log_line(line, &entry);

    fprintf(csv_file, "IP Address,Date,Method,URL,Status Code\n");

    // Read the rest of the log file and write to CSV file
    while (fgets(line, MAX_LINE_LENGTH, log_file)!= NULL) {
        parse_log_line(line, &entry);
        if (filter_by_ip(&entry, "192.168.1.1")) { // Filter by IP address
            write_csv_entry(csv_file, &entry);
        }
    }

    fclose(log_file);
    fclose(csv_file);

    return 0;
}