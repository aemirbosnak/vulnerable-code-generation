//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_WORDS 10
#define WORD_LENGTH 40
#define NUM_CHARS 26
#define MAX_TRIES 3
#define DELAY 100000

typedef struct Word {
    char word[WORD_LENGTH];
    int score;
} Word;

void print_word(const char *word) {
    for (int i = 0; i < WORD_LENGTH; ++i) {
        if (word[i] == '\0') {
            printf(" |\n");
            break;
        }
        if (isalpha(word[i])) {
            printf("%c%c", word[i], i % 5 == 0 ? '\n' : ' ');
        } else {
            printf("_%c%c", word[i], i % 5 == 0 ? '\n' : ' ');
        }
    }
}

void generate_words(Word words[]) {
    for (int i = 0; i < NUM_WORDS; ++i) {
        char *word = malloc(WORD_LENGTH * sizeof(char));
        for (int j = 0; j < WORD_LENGTH; ++j) {
            word[j] = (rand() % NUM_CHARS) + 'a';
        }
        strcpy(words[i].word, word);
        words[i].score = 0;
    }
}

int main() {
    srand(time(NULL));
    Word words[NUM_WORDS];
    generate_words(words);

    for (int i = 0; i < NUM_WORDS; ++i) {
        printf("\nAttempting to type word %d:\n", i + 1);
        print_word(words[i].word);
        char input[WORD_LENGTH];
        int tries = 0;

        while (tries < MAX_TRIES && strcmp(words[i].word, input)) {
            fgets(input, WORD_LENGTH, stdin);
            input[strlen(input) - 1] = '\0';
            printf("Incorrect. Please try again.\n");
            print_word(words[i].word);
            ++tries;
            usleep(DELAY);
        }

        if (tries < MAX_TRIES) {
            words[i].score += tries * 10;
            printf("Congratulations! You typed word %d correctly in %d tries.\n", i + 1, tries);
        } else {
            printf("Sorry, you have reached the maximum number of tries for word %d.\n", i + 1);
        }

        print_word(words[i].word);
        printf("Your score for word %d is: %d\n", i + 1, words[i].score);
    }

    free(words);

    return 0;
}