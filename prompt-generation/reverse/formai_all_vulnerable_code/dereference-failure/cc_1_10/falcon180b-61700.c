//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10
#define WORD_LENGTH 10

typedef struct {
    char word[WORD_LENGTH];
    int length;
} Word;

void generate_words(Word words[]) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        int length = rand() % WORD_LENGTH + 1;
        char *word = (char *) malloc(length + 1);
        int j;
        for (j = 0; j < length; j++) {
            word[j] = rand() % 26 + 'a';
        }
        word[j] = '\0';
        strcpy(words[i].word, word);
        words[i].length = length;
        free(word);
    }
}

int main() {
    Word words[MAX_WORDS];
    generate_words(words);

    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        printf("Word %d: %s\n", i + 1, words[i].word);
    }

    int correct_words = 0;
    char input[WORD_LENGTH];
    int j;
    for (i = 0; i < MAX_WORDS; i++) {
        printf("Type word %d: ", i + 1);
        scanf("%s", input);
        if (strcasecmp(input, words[i].word) == 0) {
            correct_words++;
        }
        else {
            printf("Incorrect\n");
        }
    }

    printf("You typed %d out of %d words correctly.\n", correct_words, MAX_WORDS);

    return 0;
}