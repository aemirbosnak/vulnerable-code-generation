//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 100
#define WORD_LENGTH 30
#define LINE_LENGTH 80

// Function to generate random words
char* generate_random_word(void) {
    char* word = malloc(WORD_LENGTH * sizeof(char));

    for (int i = 0; i < WORD_LENGTH; i++) {
        word[i] = 'a' + rand() % 26;
    }

    word[WORD_LENGTH] = '\0';
    return word;
}

int main(void) {
    srand(time(NULL));
    int score = 0;
    int total_words = 0;
    int line_width = LINE_LENGTH - 12;

    printf("\n\n** Welcome to the C Typing Speed Test **\n");
    printf("----------------------------------------\n");

    while (1) {
        total_words++;

        // Generate a random word
        char* word = generate_random_word();

        // Print the word with some padding
        printf("\nType the following word '%s' as fast as you can (press enter when done):", word);
        for (int i = 0; i < line_width - strlen(word) - 14; i++) {
            printf(" ");
        }
        printf("|");

        // Get user input
        char user_input[WORD_LENGTH];
        fgets(user_input, sizeof(user_input), stdin);
        user_input[strcspn(user_input, "\n")] = '\0';

        // Compare user input with the generated word
        if (strcmp(word, user_input) == 0) {
            score++;
            printf("\nCorrect! Your current score is %d.\n", score);
        } else {
            printf("\nIncorrect! The correct answer was '%s'. Try again.\n", word);
        }

        free(word);

        // Wait for some time before generating the next word
        int delay = rand() % 3000 + 2000;
        printf("\nPress enter to continue in %d milliseconds...\n", delay / 1000);
        getchar();
        fflush(stdin);
        sleep(delay / 1000.0);
    }

    printf("\nYour final score is %d. Good job!", score);

    return 0;
}