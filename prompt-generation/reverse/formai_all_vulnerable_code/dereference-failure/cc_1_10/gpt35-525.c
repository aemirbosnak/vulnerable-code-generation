//FormAI DATASET v1.0 Category: Log analysis ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_FIELDS 6

typedef struct log_entry {
    char date[20];
    char time[20];
    char severity[20];
    char thread[20];
    char message[500];
} log_entry;

log_entry *parse_entry(char *line) {
    log_entry *entry = (log_entry*) malloc(sizeof(log_entry));
    char *field;
    int i = 0;
    field = strtok(line, " ");
    while (field && i < MAX_FIELDS) {
        switch (i) {
            case 0: strcpy(entry->date, field); break;
            case 1: strcpy(entry->time, field); break;
            case 2: strcpy(entry->severity, field); break;
            case 3: strcpy(entry->thread, field); break;
            default: strcat(entry->message, field); strcat(entry->message, " "); break;
        }
        field = strtok(NULL, " ");
        i++;
    }
    return entry;
}

int main(int argc, char **argv) {
    FILE *fp;
    char line[MAX_LINE];
    log_entry *entry;
    int entry_count = 0, error_count = 0, warning_count = 0;
    float error_percentage, warning_percentage;

    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }

    while(fgets(line, MAX_LINE, fp) != NULL) {
        entry = parse_entry(line);
        entry_count++;
        if (strcmp(entry->severity, "ERROR") == 0) {
            error_count++;
        } else if (strcmp(entry->severity, "WARNING") == 0) {
            warning_count++;
        }
        free(entry);
    }
    fclose(fp);

    error_percentage = ((float)error_count / entry_count) * 100;
    warning_percentage = ((float)warning_count / entry_count) * 100;

    printf("Total log entries: %d\n", entry_count);
    printf("Error count: %d (%.2f%%)\n", error_count, error_percentage);
    printf("Warning count: %d (%.2f%%)\n", warning_count, warning_percentage);

    return 0;
}