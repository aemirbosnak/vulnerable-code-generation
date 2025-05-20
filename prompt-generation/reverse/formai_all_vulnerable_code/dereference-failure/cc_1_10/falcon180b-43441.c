//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *ip_address;
    char *date_time;
    char *request_method;
    char *request_url;
    char *user_agent;
    int status_code;
} log_entry_t;

log_entry_t *parse_log_entry(char *log_line) {
    log_entry_t *entry = malloc(sizeof(log_entry_t));

    char *token = strtok(log_line, " ");
    entry->ip_address = strdup(token);

    token = strtok(NULL, " ");
    entry->date_time = strdup(token);

    token = strtok(NULL, " ");
    entry->request_method = strdup(token);

    token = strtok(NULL, " ");
    entry->request_url = strdup(token);

    token = strtok(NULL, " ");
    entry->user_agent = strdup(token);

    token = strtok(NULL, " ");
    entry->status_code = atoi(token);

    return entry;
}

void print_log_entry(log_entry_t *entry) {
    printf("IP Address: %s\n", entry->ip_address);
    printf("Date/Time: %s\n", entry->date_time);
    printf("Request Method: %s\n", entry->request_method);
    printf("Request URL: %s\n", entry->request_url);
    printf("User Agent: %s\n", entry->user_agent);
    printf("Status Code: %d\n\n", entry->status_code);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    char log_line[MAX_LINE_LENGTH];
    while (fgets(log_line, MAX_LINE_LENGTH, log_file)!= NULL) {
        log_entry_t *entry = parse_log_entry(log_line);
        print_log_entry(entry);
        free(entry->ip_address);
        free(entry->date_time);
        free(entry->request_method);
        free(entry->request_url);
        free(entry->user_agent);
        free(entry);
    }

    fclose(log_file);
    return 0;
}