//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LOG_SIZE 1000
#define MAX_LINE_SIZE 100

typedef struct {
    char log_name[MAX_LINE_SIZE];
    char log_time[MAX_LINE_SIZE];
    char log_level[MAX_LINE_SIZE];
    char log_message[MAX_LINE_SIZE];
} LogEntry;

void parse_log_entry(const char* line, LogEntry* entry) {
    int len = strlen(line);
    int i = 0;
    char* token;

    entry->log_name[0] = '\0';
    entry->log_time[0] = '\0';
    entry->log_level[0] = '\0';
    entry->log_message[0] = '\0';

    while (i < len) {
        token = strtok_r(line, " \t\n", &line);
        if (token!= NULL) {
            switch (i) {
                case 0:
                    strcpy(entry->log_name, token);
                    break;
                case 1:
                    strcpy(entry->log_time, token);
                    break;
                case 2:
                    strcpy(entry->log_level, token);
                    break;
                case 3:
                    strcpy(entry->log_message, token);
                    break;
            }
            i++;
        }
    }
}

void print_log_entry(const LogEntry* entry) {
    printf("%s (%s) - %s: %s\n", entry->log_name, entry->log_time, entry->log_level, entry->log_message);
}

void print_log(const char* filename, const char* format) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    int log_size = 0;
    char log[MAX_LOG_SIZE];
    LogEntry entry;

    while (fgets(log, MAX_LOG_SIZE, stdin)!= NULL) {
        log_size++;
        parse_log_entry(log, &entry);
        if (strlen(entry.log_name) > 0 && strcmp(entry.log_name, "R") == 0) {
            if (strcmp(entry.log_level, "ERROR") == 0) {
                printf("O Romeo, Romeo, wherefore art thou Romeo?\n");
            } else if (strcmp(entry.log_level, "WARNING") == 0) {
                printf("What light through yonder window breaks? It is the east, and Juliet is the sun.\n");
            } else if (strcmp(entry.log_level, "INFO") == 0) {
                printf("Gallop apace, my soul! The chariot of night draws near.\n");
            } else if (strcmp(entry.log_level, "DEBUG") == 0) {
                printf("I am not Romeo, but I bear him love.\n");
            }
        }

        fprintf(file, format, entry.log_name, entry.log_time, entry.log_level, entry.log_message);
        print_log_entry(&entry);
        fflush(file);
    }

    fclose(file);
    printf("Total logs: %d\n", log_size);
}

int main() {
    print_log("romeo.log", "%s (%s) - %s: %s");
    return 0;
}