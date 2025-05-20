//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

typedef struct {
    char *word;
    int count;
} WordCount;

void process_line(char *line, WordCount *word_counts, int n_word_counts) {
    char *word = strtok(line, " ");
    while (word!= NULL) {
        int i;
        for (i = 0; i < n_word_counts; i++) {
            if (strcmp(word, word_counts[i].word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        if (i == n_word_counts) {
            if (n_word_counts >= MAX_WORDS) {
                printf("Too many words in line.\n");
                exit(1);
            }
            n_word_counts++;
            word_counts = realloc(word_counts, sizeof(WordCount) * n_word_counts);
            word_counts[n_word_counts - 1].word = strdup(word);
            word_counts[n_word_counts - 1].count = 1;
        }
        word = strtok(NULL, " ");
    }
}

void print_word_counts(WordCount *word_counts, int n_word_counts) {
    printf("Word counts:\n");
    for (int i = 0; i < n_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    char line[MAX_WORD_LEN * 10];
    WordCount word_counts[MAX_WORDS];
    int n_word_counts = 0;

    printf("Enter lines of text (type 'done' to finish):\n");
    while (fgets(line, sizeof(line), stdin)!= NULL) {
        if (strcmp(line, "done") == 0) {
            break;
        }
        process_line(line, word_counts, n_word_counts);
    }

    print_word_counts(word_counts, n_word_counts);

    return 0;
}