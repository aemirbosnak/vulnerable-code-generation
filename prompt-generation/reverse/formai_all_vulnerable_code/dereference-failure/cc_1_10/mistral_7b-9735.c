//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE_MAX 4096
#define FIELD_DELIM " "
#define FIELD_SIZE 128

typedef struct {
    char ip[FIELD_SIZE];
    char method[FIELD_SIZE];
    char url[FIELD_SIZE];
    char status[FIELD_SIZE];
} LogEntry;

int parse_log_line(char *line, LogEntry *entry) {
    char *token;
    int field_index = 0;

    token = strtok(line, FIELD_DELIM);
    strcpy(entry->ip, token);

    token = strtok(NULL, FIELD_DELIM);
    strcpy(entry->method, token);

    token = strtok(NULL, FIELD_DELIM);
    strcpy(entry->url, token);

    token = strtok(NULL, FIELD_DELIM);
    strcpy(entry->status, token);

    if (token != NULL) { // handle malformed log lines
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[LINE_MAX];
    LogEntry entry;

    if (argc != 2) {
        printf("Usage: %s <logfile>\n", argv[0]);
        return -1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    while (fgets(line, LINE_MAX, fp) != NULL) {
        if (parse_log_line(line, &entry) < 0) {
            printf("Malformed log line: %s\n", line);
            continue;
        }

        printf("IP: %s\tMethod: %s\tURL: %s\tStatus: %s\n",
               entry.ip, entry.method, entry.url, entry.status);
    }

    fclose(fp);
    return 0;
}