//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// function to generate a random word
char* generateWord() {
    int length = rand() % 10 + 3;
    char* word = malloc(length + 1);

    for (int i = 0; i < length; i++) {
        word[i] = 'a' + rand() % 26;
    }

    word[length] = '\0';
    return word;
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Type the following words as quickly and accurately as possible:\n\n");

    for (int i = 0; i < 10; i++) {
        char* word = generateWord();
        printf("%s ", word);
        free(word);
    }

    printf("\n\nType the words above and press enter when finished.\n");

    char input[100];
    fgets(input, 100, stdin);
    int input_length = strlen(input);
    int correct_words = 0;
    int total_words = 10;

    // convert input to lowercase
    for (int i = 0; i < input_length - 1; i++) {
        input[i] = tolower(input[i]);
    }

    // split input into words
    char* word = strtok(input, " ");
    while (word != NULL) {
        // remove newline character if it exists
        if (word[strlen(word) - 1] == '\n') {
            word[strlen(word) - 1] = '\0';
        }

        if (strcmp(word, "") != 0) {
            // compare word to generated word
            if (strcmp(word, generateWord()) == 0) {
                correct_words++;
            }
        }

        word = strtok(NULL, " ");
    }

    printf("\nYou typed %d out of %d words correctly.\n", correct_words, total_words);
    printf("Your typing speed is %.2f words per minute.\n\n", (float)correct_words / (input_length / 5) * 60);

    return 0;
}