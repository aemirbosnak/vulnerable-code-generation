//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct log_entry {
    char word[100];
    int count;
} LogEntry;

void read_log_file(const char *filename, int *num_entries, LogEntry **entries) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    *num_entries = 0;
    *entries = malloc(sizeof(LogEntry) * 1000);
    if (*entries == NULL) {
        fprintf(stderr, "Error allocating memory for log entries\n");
        exit(1);
    }

    char line[1000];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '\0')
            continue; // empty line or comment

        char *word = strtok(line, " \t\n\r");
        while (word!= NULL) {
            LogEntry *entry = &(*entries)[(*num_entries)++];
            strcpy(entry->word, word);
            entry->count = 0;

            word = strtok(NULL, " \t\n\r");
        }
    }

    fclose(file);
}

void print_word_counts(LogEntry *entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %d\n", entries[i].word, entries[i].count);
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <log file>\n", argv[0]);
        return 1;
    }

    int num_entries;
    LogEntry *entries = NULL;
    read_log_file(argv[1], &num_entries, &entries);

    print_word_counts(entries, num_entries);
    free(entries);
    return 0;
}