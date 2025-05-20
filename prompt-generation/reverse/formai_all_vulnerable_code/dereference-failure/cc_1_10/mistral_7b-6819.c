//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 15
#define NUM_WORDS 20
#define MAX_TRIES 3

const char *word_list[] = {
    "apple",
    "banana",
    "cherry",
    "date",
    "fig",
    "grape",
    "kiwi",
    "lemon",
    "mango",
    "orange",
    "pineapple",
    "quince",
    "strawberry",
    "tangerine",
    "uvas",
    "watermelon",
    "xigua",
    "yellow",
    "zucchini"
};

int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

char *generate_random_word(void) {
    int len = rand_num(MIN_WORD_LENGTH, MAX_WORD_LENGTH);
    char *word = malloc(len + 1);
    for (int i = 0; i < len; ++i)
        word[i] = 'a' + rand_num(0, 25);
    word[len] = '\0';
    return word;
}

void print_word(const char *word) {
    for (int i = 0; word[i]; ++i)
        putchar(word[i]);
    putchar(' ');
}

void test_word(const char *word, int tries) {
    char guess[MAX_WORD_LENGTH + 1];
    for (int i = 0; i < tries; ++i) {
        printf("Attempt %d: ", i + 1);
        fflush(stdout);
        scanf("%s", guess);
        if (!strcmp(guess, word)) {
            printf("Congratulations! You typed the word '%s' correctly.\n", word);
            free(word);
            return;
        }
        printf("Incorrect! Please try again.\n");
        free(word);
        word = generate_random_word();
    }
    printf("Sorry, you failed to type the word correctly after %d attempts.\n", tries);
    free(word);
    exit(EXIT_FAILURE);
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < NUM_WORDS; ++i) {
        const char *word = word_list[rand_num(0, NUM_WORDS - 1)];
        test_word(word, MAX_TRIES);
    }
    return EXIT_SUCCESS;
}