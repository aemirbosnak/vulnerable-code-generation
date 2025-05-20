//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LOG_FILE "c_log.txt"
#define LINE_SIZE 256

typedef struct {
    int pid;
    char function[128];
    char file[128];
    char level[8];
    char message[1024];
} log_entry;

void parse_log_line(char *line, log_entry *entry) {
    char *token;
    sscanf(line, "%d %[^:]: %s %s %s", &entry->pid, entry->level, entry->function, entry->file);
    int pos = strlen(entry->function) + strlen(entry->file) + 2;
    token = strtok(line + pos, ": ");
    strcpy(entry->message, token);
}

int main() {
    FILE *log_file;
    log_entry entry;
    char line[LINE_SIZE];
    int total_entries = 0;

    log_file = fopen(LOG_FILE, "r");

    if (log_file == NULL) {
        perror("Error opening log file");
        return 1;
    }

    while (fgets(line, LINE_SIZE, log_file)) {
        parse_log_line(line, &entry);

        printf("\nPID: %d\nFunction: %s\nFile: %s\nLevel: %s\nMessage: %s\n", entry.pid, entry.function, entry.file, entry.level, entry.message);

        total_entries++;
    }

    fclose(log_file);
    printf("\nTotal entries: %d\n", total_entries);

    return 0;
}