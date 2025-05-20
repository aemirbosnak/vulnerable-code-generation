//LLAMA2-13B DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_STR_LEN 1024
#define MAX_NUM_GUESS 10

typedef struct {
    char *word;
    int len;
} word_t;

void generate_word(word_t *word) {
    int i, j, len;
    char c;

    len = rand() % 10 + 1;
    word->len = len;

    for (i = 0; i < len; i++) {
        c = 'a' + (rand() % 26);
        word->word[i] = c;
    }
}

int guess_word(word_t *word, char *guess) {
    int i, j;

    for (i = 0; i < word->len; i++) {
        if (guess[i] != word->word[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    word_t word;
    char guess[MAX_STR_LEN];

    srand(time(NULL));

    generate_word(&word);

    printf("Guess a word: ");
    fgets(guess, MAX_STR_LEN, stdin);

    if (guess_word(&word, guess)) {
        printf("You guessed it! The word was: %s\n", word.word);
    } else {
        printf("You didn't guess it... try again!\n");
    }

    return 0;
}