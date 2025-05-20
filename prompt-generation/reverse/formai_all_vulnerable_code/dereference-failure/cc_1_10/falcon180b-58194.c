//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *ip_address;
    char *request_method;
    char *request_url;
    char *response_code;
    char *user_agent;
} log_entry;

void log_entry_free(log_entry *entry) {
    if (entry->ip_address!= NULL) {
        free(entry->ip_address);
    }
    if (entry->request_method!= NULL) {
        free(entry->request_method);
    }
    if (entry->request_url!= NULL) {
        free(entry->request_url);
    }
    if (entry->response_code!= NULL) {
        free(entry->response_code);
    }
    if (entry->user_agent!= NULL) {
        free(entry->user_agent);
    }
    free(entry);
}

int parse_log_entry(char *line, log_entry *entry) {
    char *token;
    int num_tokens = 0;

    token = strtok(line, " ");
    while (token!= NULL) {
        if (num_tokens == 0) {
            entry->ip_address = strdup(token);
        } else if (num_tokens == 1) {
            entry->request_method = strdup(token);
        } else if (num_tokens == 2) {
            entry->request_url = strdup(token);
        } else if (num_tokens == 3) {
            entry->response_code = strdup(token);
        } else if (num_tokens == 4) {
            entry->user_agent = strdup(token);
        }
        num_tokens++;
        token = strtok(NULL, " ");
    }

    if (num_tokens!= 5) {
        log_entry_free(entry);
        return 0;
    }

    return 1;
}

void print_log_entry(log_entry *entry) {
    printf("IP address: %s\n", entry->ip_address);
    printf("Request method: %s\n", entry->request_method);
    printf("Request URL: %s\n", entry->request_url);
    printf("Response code: %s\n", entry->response_code);
    printf("User agent: %s\n\n", entry->user_agent);
}

int main(int argc, char *argv[]) {
    FILE *log_file;
    char line[MAX_LINE_LENGTH];
    log_entry entry;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        fprintf(stderr, "Error: could not open log file '%s'.\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, log_file)!= NULL) {
        if (parse_log_entry(line, &entry)) {
            print_log_entry(&entry);
        }
        log_entry_free(&entry);
    }

    fclose(log_file);

    return 0;
}