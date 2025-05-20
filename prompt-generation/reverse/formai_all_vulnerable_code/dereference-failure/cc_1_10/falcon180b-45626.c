//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000000

typedef struct {
    char *ip_address;
    char *date_time;
    char *method;
    char *request_url;
    int status_code;
} log_entry;

log_entry *entries;
int num_entries;

void initialize() {
    entries = (log_entry *)malloc(sizeof(log_entry) * MAX_NUM_LINES);
    num_entries = 0;
}

void cleanup() {
    for (int i = 0; i < num_entries; i++) {
        free(entries[i].ip_address);
        free(entries[i].date_time);
        free(entries[i].method);
        free(entries[i].request_url);
    }
    free(entries);
}

void parse_line(char *line) {
    char *ip_address = strtok(line, " ");
    char *date_time = strtok(NULL, " ");
    char *method = strtok(NULL, " ");
    char *request_url = strtok(NULL, " ");
    int status_code = atoi(strtok(NULL, " "));

    log_entry entry = {.ip_address = strdup(ip_address),.date_time = strdup(date_time),.method = strdup(method),.request_url = strdup(request_url),.status_code = status_code};
    entries[num_entries] = entry;
    num_entries++;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s %s %s %d\n", entries[i].ip_address, entries[i].date_time, entries[i].method, entries[i].request_url, entries[i].status_code);
    }
}

int main() {
    initialize();

    FILE *file = fopen("access.log", "r");
    if (file == NULL) {
        printf("Unable to open file\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        parse_line(line);
        if (num_entries >= MAX_NUM_LINES) {
            printf("Maximum number of lines reached\n");
            break;
        }
    }

    fclose(file);

    print_entries();

    cleanup();

    return 0;
}