//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// Function to generate a random word
char *generate_word() {
    // Array of possible characters
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    // Length of the generated word
    int word_length = rand() % 20 + 1;

    // Allocate memory for the word
    char *word = malloc(word_length + 1);

    // Generate the word
    for (int i = 0; i < word_length; i++) {
        word[i] = alphabet[rand() % 26];
    }

    // Terminate the word with a null character
    word[word_length] = '\0';

    // Return the word
    return word;
}

// Function to test the user's typing speed
void test_typing_speed() {
    // Generate a random word
    char *word = generate_word();

    // Get the start time
    time_t start_time = time(NULL);

    // Prompt the user to type the word
    printf("Type the following word: %s\n", word);

    // Get the user's input
    char input[100];
    scanf("%s", input);

    // Get the end time
    time_t end_time = time(NULL);

    // Calculate the typing speed
    double typing_speed = (double)(strlen(word)) / (end_time - start_time);

    // Print the typing speed
    printf("Your typing speed is: %.2f words per minute\n", typing_speed);

    // Free the memory allocated for the word
    free(word);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Test the user's typing speed
    test_typing_speed();

    return 0;
}