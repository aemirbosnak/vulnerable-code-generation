//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random word
char* generate_word(int length) {
    char* word = malloc(length + 1);

    for (int i = 0; i < length; i++) {
        word[i] = 'a' + rand() % 26;
    }

    word[length] = '\0';
    return word;
}

// Function to test the user's typing speed
void test_typing_speed() {
    // Generate a random word
    char* word = generate_word(10);

    // Start the timer
    clock_t start = clock();

    // Prompt the user to type the word
    printf("Type the following word: %s\n", word);

    // Get the user's input
    char input[11];
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken to type the word
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the typing speed in words per minute
    double words_per_minute = 60 / time_taken;

    // Print the results
    printf("You typed the word in %.2f seconds.\n", time_taken);
    printf("Your typing speed is %.2f words per minute.\n", words_per_minute);

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