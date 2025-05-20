//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_WORD_LENGTH 20
#define MAX_LINES 100

struct word {
    char *word;
    int count;
};

struct line {
    char *line;
    int len;
    struct word *words;
};

int main() {
    struct line lines[MAX_LINES];
    int i, j, words_count = 0;
    char buffer[1024];

    // Read input from standard input
    for (i = 0; i < MAX_LINES; i++) {
        fgets(buffer, 1024, stdin);
        lines[i].line = buffer;
        lines[i].len = strlen(buffer);
        words_count = 0;

        // Count words in the current line
        for (j = 0; j < lines[i].len; j++) {
            if (isalpha(buffer[j])) {
                char *word = strndup(buffer + j, 1);
                if (words_count < MAX_WORD_LENGTH) {
                    words_count++;
                    lines[i].words = realloc(lines[i].words, (words_count * sizeof(struct word)) + sizeof(struct word));
                    lines[i].words[words_count - 1] = (struct word) { .word = word, .count = 1 };
                } else {
                    printf("Warning: Word exceeds maximum length of %d characters.\n", MAX_WORD_LENGTH);
                }
            }
        }
    }

    // Print word count for each line
    for (i = 0; i < MAX_LINES; i++) {
        printf("%d words in line %d:\n", lines[i].words->count, i + 1);
        for (j = 0; j < words_count; j++) {
            printf("  %s (%d)\n", lines[i].words->word, lines[i].words->count);
        }
    }

    return 0;
}