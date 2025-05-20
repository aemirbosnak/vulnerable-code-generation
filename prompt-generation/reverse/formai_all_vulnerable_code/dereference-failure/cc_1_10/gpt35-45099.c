//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000 //maximum lines for input file
#define MAX_CHARS 100 //maximum length of a line

struct LogEntry {
    char src[MAX_CHARS]; //source IP address
    char dest[MAX_CHARS]; //destination IP address
    char time[MAX_CHARS]; //timestamp
    char message[MAX_CHARS]; //log message
};

void parseLogEntry(char* line, struct LogEntry* entry) {
    char* token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
        switch (i) {
            case 0:
                strcpy(entry->time, token);
                break;
            case 1:
                strcpy(entry->src, token);
                break;
            case 2:
                strcpy(entry->dest, token);
                break;
            default:
                strcat(entry->message, token);
                strcat(entry->message, " ");
                break;
        }
        i++;
        token = strtok(NULL, " ");
    }
}

int main(int argc, char *argv[]) {
    char filename[MAX_CHARS];
    if (argc > 1) {
        strcpy(filename, argv[1]);
    } else {
        printf("Please enter the name of the log file: ");
        fgets(filename, MAX_CHARS, stdin);
        filename[strlen(filename) - 1] = '\0'; //remove newline character
    }

    FILE* logfile = fopen(filename, "r");
    if (!logfile) {
        printf("Could not open file '%s'\n", filename);
        exit(1);
    }

    struct LogEntry entries[MAX_LINES];
    int num_entries = 0;

    char line[MAX_CHARS];
    while (fgets(line, MAX_CHARS, logfile) != NULL) {
        parseLogEntry(line, &entries[num_entries]);
        num_entries++;
    }

    fclose(logfile);

    //Intrusion detection logic goes here
    //For example, we could check for repeated failed login attempts from the same IP address within a short time period

    return 0;
}