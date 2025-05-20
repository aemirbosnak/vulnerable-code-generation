//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

// Function to generate a random word
char* generate_word() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random word length
    int word_length = (rand() % MAX_WORD_LENGTH) + 1;

    // Create a buffer to store the word
    char* word = malloc(word_length + 1);

    // Generate the word
    for (int i = 0; i < word_length; i++) {
        word[i] = 'a' + (rand() % 26);
    }

    // Terminate the word with a null-terminator
    word[word_length] = '\0';

    // Return the word
    return word;
}

// Function to get the user's input
char* get_input() {
    // Create a buffer to store the input
    char* input = malloc(MAX_WORD_LENGTH + 1);

    // Get the input from the user
    scanf("%s", input);

    // Return the input
    return input;
}

// Function to compare two strings
int compare_strings(char* str1, char* str2) {
    // Compare the two strings
    int result = strcmp(str1, str2);

    // Return the result
    return result;
}

// Function to run the typing speed test
void run_test() {
    // Generate a random word
    char* word = generate_word();

    // Get the user's input
    char* input = get_input();

    // Compare the two strings
    int result = compare_strings(word, input);

    // Print the result
    if (result == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect!\n");
    }

    // Free the memory allocated for the word and the input
    free(word);
    free(input);
}

// Main function
int main() {
    // Run the typing speed test
    run_test();

    // Return 0
    return 0;
}