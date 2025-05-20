//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct Word {
    char word[WORD_LENGTH];
    int count;
} Word;

void count_words(char *line, Word words[]) {
    int current_word = 0;
    bool in_word = false;
    for (int i = 0; line[i] != '\0'; i++) {
        char c = line[i];
        if (isspace(c)) {
            if (in_word) {
                words[current_word].count++;
                in_word = false;
            }
            if (i > 0 && !isspace(line[i-1])) {
                current_word++;
            }
        } else {
            if (!in_word) {
                strncpy(words[current_word].word, &c, WORD_LENGTH);
                words[current_word].count = 1;
                in_word = true;
            }
        }
    }
    if (in_word) {
        words[current_word].count++;
    }
}

int main() {
    char line[1024];
    Word words[MAX_WORDS];
    int num_words = 0;

    printf("***** Happy Word Counter *****\n");
    printf("------------------------------\n");

    while (fgets(line, sizeof(line), stdin) != NULL) {
        count_words(line, words);
        num_words = (num_words < MAX_WORDS) ? num_words + 1 : MAX_WORDS;
    }

    printf("\n***** Word Count Results *****\n");
    printf("------------------------------\n");

    for (int i = 0; i < num_words; i++) {
        printf("%s : %d\n", words[i].word, words[i].count);
    }

    return 0;
}