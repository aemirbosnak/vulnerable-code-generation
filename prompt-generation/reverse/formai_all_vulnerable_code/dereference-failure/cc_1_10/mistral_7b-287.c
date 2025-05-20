//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define WORD_COUNT 10
#define WORD_LENGTH 30
#define BUFFER_SIZE 1024

char *words[WORD_COUNT];
char input[BUFFER_SIZE];

void init_words() {
    int i;
    for (i = 0; i < WORD_COUNT; i++) {
        words[i] = malloc(WORD_LENGTH * sizeof(char));
        if (words[i] == NULL) {
            printf("Error: Could not allocate memory for words.\n");
            exit(1);
        }
        sprintf(words[i], "%s%s%s", "The quick brown fox jumps over the", "lazy dog.", "");
    }
}

int main() {
    int i, score = 0;
    clock_t start, end;

    init_words();

    printf("Welcome to the C Typing Speed Test!\n");
    printf("Type the following words as fast as you can:\n");

    for (i = 0; i < WORD_COUNT; i++) {
        printf("\nWord %d: %s", i + 1, words[i]);
        fgets(input, BUFFER_SIZE, stdin);

        if (strncmp(input, words[i], strlen(words[i])) == 0) {
            score += strlen(words[i]);
            printf("Correct! You typed '%s' correctly.\n", words[i]);
        } else {
            printf("Incorrect! Please try again.\n");
        }

        usleep(500000); // Add a delay between words to simulate typing
    }

    start = clock();
    printf("\nTyping finished. Your score is: %d characters.\n", score);
    end = clock();

    double typing_speed = ((double) score / (double) (end - start)) * 60;
    printf("Your typing speed is: %.2f characters per minute.\n", typing_speed);

    for (i = 0; i < WORD_COUNT; i++) {
        free(words[i]);
    }

    return 0;
}