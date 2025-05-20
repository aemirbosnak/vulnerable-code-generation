//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_THEORIES 10
#define WORDS_COUNT 5
#define MIN_LENGTH 5
#define MAX_LENGTH 20

typedef struct {
    char *word;
    int length;
} Word;

Word theory_words[WORDS_COUNT];
char *conspiracy_theories[MAX_THEORIES];

void init_words() {
    for (int i = 0; i < WORDS_COUNT; i++) {
        theory_words[i].length = rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH;
        theory_words[i].word = malloc(theory_words[i].length + 1);
        for (int j = 0; j < theory_words[i].length; j++) {
            theory_words[i].word[j] = 'a' + rand() % 26;
        }
        theory_words[i].word[theory_words[i].length] = '\0';
    }
}

void generate_theory(char *theory, int length) {
    for (int i = 0; i < WORDS_COUNT; i++) {
        strcat(theory, theory_words[i].word);
        if (i != WORDS_COUNT - 1) {
            strcat(theory, " ");
        }
    }
    theory[length] = '\0';
}

void print_theory(char *theory) {
    printf("\nConspiracy Theory:\n%s\n", theory);
}

int main() {
    srand(time(NULL));
    init_words();
    for (int i = 0; i < MAX_THEORIES; i++) {
        char theory[100];
        int length = sizeof(theory) / sizeof(char);
        generate_theory(theory, length);
        conspiracy_theories[i] = malloc(strlen(theory) + 1);
        strcpy(conspiracy_theories[i], theory);
    }
    for (int i = 0; i < MAX_THEORIES; i++) {
        print_theory(conspiracy_theories[i]);
        free(conspiracy_theories[i]);
    }
    for (int i = 0; i < WORDS_COUNT; i++) {
        free(theory_words[i].word);
    }
    return 0;
}