//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define WORD_LENGTH 30

char *words[MAX_WORDS];

void generate_words(void) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        words[i] = malloc(WORD_LENGTH * sizeof(char));
        int j;
        for (j = 0; j < WORD_LENGTH; j++) {
            words[i][j] = 'a' + (rand() % 26);
        }
        words[i][WORD_LENGTH] = '\0';
    }
}

int main() {
    srand(time(NULL));
    generate_words();

    printf("\nWelcome to the C Typing Speed Test!\n");
    printf("I am grateful you are here to test your typing skills.\n");
    printf("Here are some words for you to type as fast as you can:\n");

    int i, j;
    for (i = 0; i < MAX_WORDS; i++) {
        printf("\n%s", words[i]);
        char user_input[WORD_LENGTH];
        scanf("%s", user_input);
        for (j = 0; j < WORD_LENGTH; j++) {
            if (user_input[j] != words[i][j]) {
                printf("\nIncorrect! Please try again.\n");
                i--;
                break;
            }
        }
        if (j < WORD_LENGTH) {
            printf("\nIncorrect! Please try again.\n");
            i--;
        } else {
            printf("\nWell done! Next word.\n");
        }
    }

    printf("\nCongratulations! You have successfully typed all the words.\n");
    printf("Your typing speed will be calculated and displayed shortly.\n");

    clock_t start = clock();
    for (i = 0; i < MAX_WORDS; i++) {
        free(words[i]);
    }
    clock_t end = clock();
    double typing_speed = (double)(end - start) / CLOCKS_PER_SEC * 60;
    printf("\nYour typing speed is %.2f words per minute.\n", typing_speed);

    for (i = 0; i < MAX_WORDS; i++) {
        free(words[i]);
    }

    return 0;
}