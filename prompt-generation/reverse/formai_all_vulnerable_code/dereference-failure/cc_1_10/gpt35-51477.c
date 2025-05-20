//FormAI DATASET v1.0 Category: Log analysis ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LogEntry {
    char date[11];
    char time[9];
    char ip[16];
    char method[10];
    char path[100];
    char protocol[10];
    int status;
};

void printLogEntry(struct LogEntry entry) {
    printf("%s %s %s %s %s %s %d\n", entry.date, entry.time, entry.ip, entry.method, entry.path, entry.protocol, entry.status);
}

int main() {
    FILE *fp = fopen("access.log", "r");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }
    char line[256];
    struct LogEntry entry;
    while (fgets(line, sizeof(line), fp)) {
        char *tok;
        char *saveptr;
        tok = strtok_r(line, " ", &saveptr);
        strncpy(entry.ip, tok, sizeof(entry.ip));
        tok = strtok_r(NULL, " ", &saveptr);
        tok = strtok_r(NULL, " ", &saveptr);
        strncpy(entry.date, tok+1, sizeof(entry.date)-1);
        tok = strtok_r(NULL, " ", &saveptr);
        strncpy(entry.time, tok+1, sizeof(entry.time)-1);
        tok = strtok_r(NULL, " ", &saveptr);
        strncpy(entry.method, tok+1, sizeof(entry.method)-1);
        tok = strtok_r(NULL, " ", &saveptr);
        strncpy(entry.path, tok, sizeof(entry.path)-1);
        tok = strtok_r(NULL, " ", &saveptr);
        strncpy(entry.protocol, tok+1, sizeof(entry.protocol)-1);
        tok = strtok_r(NULL, " ", &saveptr);
        tok = strtok_r(NULL, " ", &saveptr);
        entry.status = atoi(tok);

        printLogEntry(entry);
    }
    fclose(fp);

    return 0;
}