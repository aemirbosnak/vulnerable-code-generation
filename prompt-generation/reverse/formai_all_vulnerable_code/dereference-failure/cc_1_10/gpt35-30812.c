//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1024

typedef struct {
    char *ip;
    char *date;
    char *time;
    char *action;
} LogEntry;

void parseLogLine(char *line, LogEntry *entry) {
    char *tok;
    int i = 0;

    tok = strtok(line, " ");
    while (tok != NULL) {
        if (i == 0) {
            entry->ip = tok;
        } else if (i == 3) {
            entry->date = tok;
        } else if (i == 4) {
            entry->time = tok;
        } else if (i == 5) {
            entry->action = tok;
        }
        tok = strtok(NULL, " ");
        i++;
    }
}

int main(int argc, char **argv) {
    char filename[MAXLEN];
    char line[MAXLEN];
    LogEntry entry;
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <logfile>\n", argv[0]);
        exit(1);
    }

    strcpy(filename, argv[1]);

    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Cannot open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAXLEN, fp)) {
        parseLogLine(line, &entry);
        if (strcmp(entry.action, "LOGIN_FAILED") == 0) {
            printf("Intrusion alert: %s failed to login at %s %s\n", entry.ip, entry.date, entry.time);
        }
    }

    fclose(fp);
    return 0;
}