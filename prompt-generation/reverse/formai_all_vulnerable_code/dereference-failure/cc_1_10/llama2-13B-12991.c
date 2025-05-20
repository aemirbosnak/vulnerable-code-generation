//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LOG_SIZE 1024
#define MAX_WORDS 100

typedef struct log_entry {
    char *word;
    int frequency;
} log_entry_t;

typedef struct {
    log_entry_t entries[MAX_WORDS];
    int num_entries;
} log_t;

void add_log_entry(log_t *log, char *word, int frequency) {
    if (log->num_entries >= MAX_WORDS) {
        printf("Warning: Log is full, dropping oldest entry\n");
        log->entries[0].frequency = 0;
    }

    log->entries[log->num_entries].word = word;
    log->entries[log->num_entries].frequency = frequency;
    log->num_entries++;
}

void print_log(log_t *log) {
    int i;
    for (i = 0; i < log->num_entries; i++) {
        printf("%d: %s (%d)\n", i, log->entries[i].word, log->entries[i].frequency);
    }
}

int main() {
    log_t *log = malloc(sizeof(log_t));
    char word[MAX_LOG_SIZE];
    int frequency;

    while (1) {
        printf("Enter a word or 'quit' to stop: ");
        fgets(word, MAX_LOG_SIZE, stdin);
        if (strcmp(word, "quit") == 0) {
            break;
        }

        frequency = atoi(word);
        add_log_entry(log, word, frequency);
    }

    print_log(log);

    free(log);

    return 0;
}