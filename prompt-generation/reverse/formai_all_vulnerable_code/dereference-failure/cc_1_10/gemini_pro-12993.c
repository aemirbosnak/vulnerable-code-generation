//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random words
char *generate_word(int length) {
    char *word = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        word[i] = 'a' + rand() % 26;
    }
    word[length] = '\0';
    return word;
}

// Function to test typing speed
void test_typing_speed() {
    // Initialize variables
    int words_per_minute = 0;
    int characters_per_minute = 0;
    int errors = 0;
    int correct_words = 0;
    int total_words = 0;
    int total_characters = 0;
    int start_time = time(NULL);
    int end_time = 0;
    char input[100];

    // Generate random words
    char *words[100];
    for (int i = 0; i < 100; i++) {
        words[i] = generate_word(rand() % 10 + 1);
    }

    // Start the test
    printf("Start typing! You have 60 seconds.\n");
    while ((end_time = time(NULL)) < start_time + 60) {
        // Get input from user
        printf("Type the next word: %s\n", words[total_words]);
        scanf("%s", input);

        // Check if the input is correct
        if (strcmp(input, words[total_words]) == 0) {
            correct_words++;
        } else {
            errors++;
        }

        // Increment the total number of words and characters typed
        total_words++;
        total_characters += strlen(input);
    }

    // Calculate the results
    words_per_minute = correct_words * 60 / (end_time - start_time);
    characters_per_minute = total_characters * 60 / (end_time - start_time);

    // Print the results
    printf("Your typing speed is %d words per minute and %d characters per minute.\n", words_per_minute, characters_per_minute);
    printf("You made %d errors and typed %d words.\n", errors, total_words);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Test the typing speed
    test_typing_speed();

    return 0;
}