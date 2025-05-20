//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define WORD_LENGTH 5
#define NUM_WORDS 10

char words[NUM_WORDS][WORD_LENGTH] = {"cat", "dog", "pig", "cow", "sheep", "chicken", "duck", "goose", "turkey", "penguin"};
int word_index = 0;

void get_word() {
    printf("Type the following word: ");
    for (int i = 0; i < WORD_LENGTH; i++) {
        printf("*");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int score = 0;
    int correct_words = 0;
    int incorrect_words = 0;
    int time_left = 60;

    printf("Welcome to the C Typing Speed Test!\n");
    printf("You have 60 seconds to type as many words as possible.\n");
    printf("Each correct word is worth 1 point, and each incorrect word will cost you 1 point.\n");
    printf("Are you ready? Press enter to begin.\n");
    getchar();

    while (time_left > 0) {
        get_word();
        char input[WORD_LENGTH + 1];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, words[word_index]) == 0) {
            correct_words++;
            score++;
        } else {
            incorrect_words++;
            score--;
        }
        word_index = (word_index + 1) % NUM_WORDS;
        time_left--;
    }

    printf("\nTime's up! You typed %d words correctly and %d words incorrectly.\n", correct_words, incorrect_words);
    printf("Your final score is %d points.\n", score);

    if (score >= 0) {
        printf("Congratulations, you passed the C Typing Speed Test!\n");
    } else {
        printf("Sorry, you did not pass the C Typing Speed Test.\n");
    }

    return 0;
}