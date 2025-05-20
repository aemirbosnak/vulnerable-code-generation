//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 1024

typedef struct log_entry {
    char *date;
    char *time;
    char *level;
    char *message;
} log_entry;

log_entry *parse_log_entry(char *line) {
    log_entry *entry = malloc(sizeof(log_entry));
    char *p = line;

    entry->date = p;
    p = strchr(p, ' ');
    if (p == NULL) {
        free(entry);
        return NULL;
    }
    *p++ = '\0';

    entry->time = p;
    p = strchr(p, ' ');
    if (p == NULL) {
        free(entry);
        return NULL;
    }
    *p++ = '\0';

    entry->level = p;
    p = strchr(p, ' ');
    if (p == NULL) {
        free(entry);
        return NULL;
    }
    *p++ = '\0';

    entry->message = p;

    return entry;
}

void print_log_entry(log_entry *entry) {
    printf("%s %s %s %s\n", entry->date, entry->time, entry->level, entry->message);
}

void free_log_entry(log_entry *entry) {
    free(entry->date);
    free(entry->time);
    free(entry->level);
    free(entry->message);
    free(entry);
}

void analyze_log_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    char line[LINE_SIZE];
    while (fgets(line, LINE_SIZE, file) != NULL) {
        log_entry *entry = parse_log_entry(line);
        if (entry != NULL) {
            print_log_entry(entry);
            free_log_entry(entry);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    analyze_log_file(argv[1]);

    return EXIT_SUCCESS;
}