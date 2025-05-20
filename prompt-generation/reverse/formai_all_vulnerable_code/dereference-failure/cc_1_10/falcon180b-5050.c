//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *ip;
    char *date_time;
    char *request;
    char *response_code;
    char *response_size;
} log_entry;

log_entry *parse_log_line(char *line) {
    log_entry *entry = malloc(sizeof(log_entry));
    char *token;
    int i = 0;

    token = strtok(line, " ");
    while (token!= NULL) {
        switch (i) {
            case 0:
                entry->ip = strdup(token);
                break;
            case 1:
                entry->date_time = strdup(token);
                break;
            case 2:
                entry->request = strdup(token);
                break;
            case 3:
                entry->response_code = strdup(token);
                break;
            case 4:
                entry->response_size = strdup(token);
                break;
            default:
                break;
        }
        i++;
        token = strtok(NULL, " ");
    }

    return entry;
}

void print_log_entry(log_entry *entry) {
    printf("ip: %s\ndate_time: %s\nrequest: %s\nresponse_code: %s\nresponse_size: %s\n",
           entry->ip, entry->date_time, entry->request, entry->response_code, entry->response_size);
}

int main() {
    char line[MAX_LINE_LENGTH];
    log_entry *entry;
    FILE *log_file;

    log_file = fopen("access.log", "r");
    if (log_file == NULL) {
        printf("error: could not open log file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, log_file)!= NULL) {
        entry = parse_log_line(line);
        print_log_entry(entry);
        free(entry->ip);
        free(entry->date_time);
        free(entry->request);
        free(entry->response_code);
        free(entry->response_size);
        free(entry);
    }

    fclose(log_file);

    return 0;
}