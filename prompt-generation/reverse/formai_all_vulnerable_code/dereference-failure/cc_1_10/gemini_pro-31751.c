//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *line;
    int line_num;
    int level;
    char *source;
    char *message;
} LogEntry;

LogEntry *parse_log_line(char *line, int line_num) {
    LogEntry *entry = malloc(sizeof(LogEntry));
    entry->line = strdup(line);
    entry->line_num = line_num;

    // Parse the log level
    char *level_str = strtok(line, ":");
    if (level_str == NULL) {
        entry->level = -1;
    } else {
        entry->level = atoi(level_str);
    }

    // Parse the source
    char *source = strtok(NULL, ":");
    if (source == NULL) {
        entry->source = NULL;
    } else {
        entry->source = strdup(source);
    }

    // Parse the message
    char *message = strtok(NULL, "\n");
    if (message == NULL) {
        entry->message = NULL;
    } else {
        entry->message = strdup(message);
    }

    return entry;
}

void print_log_entry(LogEntry *entry) {
    printf("Line %d: [%d] %s: %s\n", entry->line_num, entry->level, entry->source, entry->message);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <log file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening log file");
        return 1;
    }

    char line[1024];
    int line_num = 1;
    while (fgets(line, sizeof(line), fp) != NULL) {
        LogEntry *entry = parse_log_line(line, line_num);
        print_log_entry(entry);
        free(entry->line);
        free(entry->source);
        free(entry->message);
        free(entry);
        line_num++;
    }

    fclose(fp);

    return 0;
}