//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define WORD_LENGTH_MIN 3
#define WORD_LENGTH_MAX 10
#define SENTENCE "For never was a story of more woe than this of Juliet and her Romeo."

void generate_random_word(char *word, int length) {
    for (int i = 0; i < length; i++) {
        word[i] = rand() % 26 + 'a';
    }
    word[length] = '\0';
}

int main() {
    srand(time(NULL));
    char words[MAX_WORDS][WORD_LENGTH_MAX];
    int num_words = 0;
    int total_correct_words = 0;
    int total_incorrect_words = 0;

    printf("Welcome to the Romeo and Juliet Typing Speed Test!\n");
    printf("Type the following sentence as quickly and accurately as possible:\n\n");
    printf("%s\n", SENTENCE);

    while (num_words < MAX_WORDS) {
        int word_length = rand() % (WORD_LENGTH_MAX - WORD_LENGTH_MIN + 1) + WORD_LENGTH_MIN;
        char *word = (char *)malloc(word_length + 1);
        generate_random_word(word, word_length);
        printf("%s ", word);
        fflush(stdout);

        char input[100];
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(word, input) == 0) {
            total_correct_words++;
        } else {
            total_incorrect_words++;
        }

        if (total_correct_words + total_incorrect_words == num_words * 2) {
            break;
        }

        num_words++;
    }

    printf("\nTest complete!\n");
    printf("You typed %d words correctly and %d words incorrectly.\n", total_correct_words, total_incorrect_words);

    return 0;
}