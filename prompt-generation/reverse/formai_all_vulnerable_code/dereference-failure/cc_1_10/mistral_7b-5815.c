//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct Word {
    char *word;
    int count;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

bool is_alphanumeric(char c) {
    return (isalpha(c) || isdigit(c) || c == '_');
}

char *next_word(char *line) {
    char *word_start = line;
    char c;

    while (isspace(*line) && *line != '\0') {
        line++;
    }

    if (*line == '\0') {
        return NULL;
    }

    while (is_alphanumeric(c = *line)) {
        if (c == '_') {
            line++;
            if (!is_alphanumeric(*line)) {
                *word_start = '\0';
                return word_start;
            }
        } else {
            line++;
        }

        *word_start++ = c;
    }

    *word_start = '\0';

    return word_start;
}

void add_word(char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }

    Word new_word = {strdup(word), 1};
    words[num_words++] = new_word;
}

void print_results() {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
        free(words[i].word);
    }
}

int main() {
    char line[1024];

    while (fgets(line, sizeof(line), stdin) != NULL) {
        char *word = next_word(line);
        if (word != NULL) {
            add_word(word);
        }
    }

    print_results();

    return 0;
}