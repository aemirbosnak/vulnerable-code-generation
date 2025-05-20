//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct log_entry {
    char *ip_address;
    char *url;
    char *method;
    int status_code;
    char *user_agent;
};

struct log_entry *log_entry_parse(char *line) {
    struct log_entry *entry = malloc(sizeof(struct log_entry));
    char *token;
    int i = 0;

    token = strtok(line, " ");
    while (token!= NULL) {
        switch (i) {
            case 0:
                entry->ip_address = strdup(token);
                break;
            case 1:
                entry->url = strdup(token);
                break;
            case 2:
                entry->method = strdup(token);
                break;
            case 3:
                entry->status_code = atoi(token);
                break;
            case 4:
                entry->user_agent = strdup(token);
                break;
            default:
                break;
        }
        token = strtok(NULL, " ");
        i++;
    }

    return entry;
}

void log_entry_print(struct log_entry *entry) {
    printf("IP Address: %s\n", entry->ip_address);
    printf("URL: %s\n", entry->url);
    printf("Method: %s\n", entry->method);
    printf("Status Code: %d\n", entry->status_code);
    printf("User Agent: %s\n\n", entry->user_agent);
}

void log_file_analyze(char *filename) {
    FILE *file;
    char line[1024];
    struct log_entry *entry;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        entry = log_entry_parse(line);
        log_entry_print(entry);
        free(entry->ip_address);
        free(entry->url);
        free(entry->method);
        free(entry->user_agent);
        free(entry);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    log_file_analyze(argv[1]);

    return 0;
}