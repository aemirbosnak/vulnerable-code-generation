//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *ip;
    char *date;
    char *method;
    char *url;
    char *protocol;
    char *status_code;
    char *user_agent;
} log_entry;

log_entry parse_log_entry(char *line) {
    log_entry entry = {0};
    char *token;
    int num_tokens = 0;

    // Extract IP address
    token = strtok(line, " ");
    entry.ip = strdup(token);
    num_tokens++;

    // Extract date and time
    token = strtok(NULL, " ");
    entry.date = strdup(token);
    num_tokens++;

    // Extract request method
    token = strtok(NULL, " ");
    entry.method = strdup(token);
    num_tokens++;

    // Extract URL
    token = strtok(NULL, " ");
    entry.url = strdup(token);
    num_tokens++;

    // Extract HTTP protocol version
    token = strtok(NULL, " ");
    entry.protocol = strdup(token);
    num_tokens++;

    // Extract HTTP status code
    token = strtok(NULL, " ");
    entry.status_code = strdup(token);
    num_tokens++;

    // Extract user agent
    token = strtok(NULL, " ");
    entry.user_agent = strdup(token);
    num_tokens++;

    if (num_tokens!= 7) {
        printf("Error: Invalid log entry\n");
        exit(1);
    }

    return entry;
}

void print_log_entry(log_entry entry) {
    printf("IP: %s\n", entry.ip);
    printf("Date and time: %s\n", entry.date);
    printf("Request method: %s\n", entry.method);
    printf("URL: %s\n", entry.url);
    printf("HTTP protocol version: %s\n", entry.protocol);
    printf("HTTP status code: %s\n", entry.status_code);
    printf("User agent: %s\n", entry.user_agent);
}

int main() {
    FILE *file;
    char line[MAX_LINE_SIZE];
    log_entry entry;

    file = fopen("access.log", "r");
    if (file == NULL) {
        printf("Error: Could not open log file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        entry = parse_log_entry(line);
        print_log_entry(entry);
    }

    fclose(file);

    return 0;
}