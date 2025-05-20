//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char* user;
    char* host;
    char* time;
    char* action;
} log_entry;

log_entry* parse_log_entry(char* entry) {
    log_entry* result = (log_entry*)malloc(sizeof(log_entry));
    char* fields[4];

    char* field = strtok(entry, " ");
    result->user = strdup(field);
    field = strtok(NULL, " ");
    result->host = strdup(field);
    field = strtok(NULL, " ");
    result->time = strdup(field);
    field = strtok(NULL, " ");
    result->action = strdup(field);

    return result;
}

int main() {
    FILE* logfile = fopen("log.txt", "r");
    if (logfile == NULL) {
        perror("Error opening log file");
        return 1;
    }

    log_entry* log_entries = (log_entry*)malloc(sizeof(log_entry));
    log_entries->user = strdup("");
    log_entries->host = strdup("");
    log_entries->time = strdup("");
    log_entries->action = strdup("");

    char entry[256];
    while (fgets(entry, sizeof(entry), logfile)) {
        log_entry* parsed_entry = parse_log_entry(entry);
        if (strcmp(parsed_entry->action, "login") == 0) {
            log_entries->user = parsed_entry->user;
            log_entries->host = parsed_entry->host;
            log_entries->time = parsed_entry->time;
        }
        free(parsed_entry);
    }

    printf("User: %s\n", log_entries->user);
    printf("Host: %s\n", log_entries->host);
    printf("Time: %s\n", log_entries->time);

    free(log_entries);
    fclose(logfile);
    return 0;
}