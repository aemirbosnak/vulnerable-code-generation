//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *ip;
    char *date;
    char *time;
    char *method;
    char *url;
    char *protocol;
    int status_code;
} LogEntry;

LogEntry *parse_log_entry(char *line) {
    LogEntry *entry = malloc(sizeof(LogEntry));
    char *token = strtok(line, " ");
    entry->ip = strdup(token);

    token = strtok(NULL, " ");
    entry->date = strdup(token);

    token = strtok(NULL, " ");
    entry->time = strdup(token);

    token = strtok(NULL, " ");
    entry->method = strdup(token);

    token = strtok(NULL, " ");
    entry->url = strdup(token);

    token = strtok(NULL, " ");
    entry->protocol = strdup(token);

    char *status_str = strtok(NULL, " ");
    entry->status_code = atoi(status_str);

    return entry;
}

void print_log_entry(LogEntry *entry) {
    printf("IP: %s\n", entry->ip);
    printf("Date: %s\n", entry->date);
    printf("Time: %s\n", entry->time);
    printf("Method: %s\n", entry->method);
    printf("URL: %s\n", entry->url);
    printf("Protocol: %s\n", entry->protocol);
    printf("Status Code: %d\n\n", entry->status_code);
}

int main() {
    FILE *log_file = fopen("access.log", "r");

    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, log_file)!= NULL) {
        LogEntry *entry = parse_log_entry(line);
        print_log_entry(entry);
        free(entry->ip);
        free(entry->date);
        free(entry->time);
        free(entry->method);
        free(entry->url);
        free(entry->protocol);
        free(entry);
    }

    fclose(log_file);

    return 0;
}