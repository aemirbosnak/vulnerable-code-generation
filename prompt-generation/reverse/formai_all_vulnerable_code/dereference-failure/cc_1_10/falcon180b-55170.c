//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_SIZE 1000000
#define MAX_LINE_SIZE 1000
#define MAX_WORD_SIZE 100

struct log_entry {
    char *ip_address;
    char *date_time;
    char *request_method;
    char *request_uri;
    int response_code;
};

struct log_entry *parse_log_entry(char *line) {
    struct log_entry *entry = malloc(sizeof(struct log_entry));
    char *token = strtok(line, " ");
    entry->ip_address = token;
    token = strtok(NULL, " ");
    entry->date_time = token;
    token = strtok(NULL, " ");
    entry->request_method = token;
    token = strtok(NULL, " ");
    entry->request_uri = token;
    token = strtok(NULL, " ");
    entry->response_code = atoi(token);
    return entry;
}

void print_log_entry(struct log_entry *entry) {
    printf("IP Address: %s\n", entry->ip_address);
    printf("Date/Time: %s\n", entry->date_time);
    printf("Request Method: %s\n", entry->request_method);
    printf("Request URI: %s\n", entry->request_uri);
    printf("Response Code: %d\n", entry->response_code);
}

int main(int argc, char *argv[]) {
    FILE *log_file;
    char log_line[MAX_LINE_SIZE];
    struct log_entry *entry;
    int total_entries = 0;
    int error_entries = 0;

    if (argc < 2) {
        printf("Please provide a log file as an argument.\n");
        return 1;
    }

    log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    while (fgets(log_line, MAX_LINE_SIZE, log_file)!= NULL) {
        total_entries++;
        entry = parse_log_entry(log_line);
        if (entry == NULL) {
            error_entries++;
            continue;
        }
        print_log_entry(entry);
        free(entry);
    }

    fclose(log_file);

    printf("Total Entries: %d\n", total_entries);
    printf("Error Entries: %d\n", error_entries);

    return 0;
}