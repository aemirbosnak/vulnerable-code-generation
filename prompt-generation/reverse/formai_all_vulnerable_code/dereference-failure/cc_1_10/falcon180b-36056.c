//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define WORD_LENGTH_MIN 4
#define WORD_LENGTH_MAX 10

int main() {
    srand(time(NULL));

    int num_words = rand() % MAX_WORDS + 1;
    char **words = malloc(sizeof(char *) * num_words);

    for (int i = 0; i < num_words; i++) {
        int word_length = rand() % (WORD_LENGTH_MAX - WORD_LENGTH_MIN + 1) + WORD_LENGTH_MIN;
        words[i] = malloc(sizeof(char) * word_length);

        for (int j = 0; j < word_length; j++) {
            words[i][j] = rand() % 26 + 'a';
        }
    }

    int score = 0;
    int time_left = 60;
    int num_correct = 0;

    printf("Welcome to the C Typing Speed Test!\n");
    printf("You will have %d seconds to type as many words as possible.\n", time_left);

    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);

        int word_length = strlen(words[i]);
        int num_chars_typed = 0;

        while (num_chars_typed < word_length) {
            char c = getchar();

            if (c == words[i][num_chars_typed]) {
                num_chars_typed++;
            } else {
                num_chars_typed = 0;
            }

            if (num_chars_typed == word_length) {
                num_correct++;
            }
        }

        score += word_length;
    }

    free(words);

    printf("\nTime is up! Your score is %d and you got %d words correct.\n", score, num_correct);

    return 0;
}