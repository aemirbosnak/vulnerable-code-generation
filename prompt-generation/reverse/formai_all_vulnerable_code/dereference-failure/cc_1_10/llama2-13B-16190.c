//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_COUNT 100

typedef struct {
    char *word;
    int count;
} word_t;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *log_file = fopen(argv[1], "r");
    if (!log_file) {
        perror("Failed to open log file");
        return 2;
    }

    word_t *word_frequencies = calloc(MAX_WORD_COUNT, sizeof(word_t));
    int line_count = 0;
    int longest_line = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file)) {
        line_count++;
        int word_count = 0;
        char *word = strtok(line, " ");
        while (word) {
            word_count++;
            word_frequencies[word_count].word = word;
            word_frequencies[word_count].count++;
            word = strtok(NULL, " ");
        }
        if (word_count > longest_line) {
            longest_line = word_count;
        }
    }

    printf("Log file statistics:\n");
    printf("  Number of lines: %d\n", line_count);
    printf("  Longest line: %d words\n", longest_line);

    int i;
    for (i = 0; i < MAX_WORD_COUNT; i++) {
        if (word_frequencies[i].count > 0) {
            printf("  %s (%d times)\n", word_frequencies[i].word, word_frequencies[i].count);
        }
    }

    free(word_frequencies);
    fclose(log_file);
    return 0;
}