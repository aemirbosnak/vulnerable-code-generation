//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_INPUT_LENGTH 1024

// Define the number of words in the test
#define NUM_WORDS 100

// Define the minimum and maximum word lengths
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 10

// Define the minimum and maximum typing speed
#define MIN_TYPING_SPEED 20
#define MAX_TYPING_SPEED 100

// Declare the array of words
char *words[NUM_WORDS];

// Declare the input string
char input[MAX_INPUT_LENGTH];

// Declare the start and end times
time_t start_time, end_time;

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate the array of words
    for (int i = 0; i < NUM_WORDS; i++) {
        // Generate a random word length
        int word_length = rand() % (MAX_WORD_LENGTH - MIN_WORD_LENGTH + 1) + MIN_WORD_LENGTH;

        // Allocate memory for the word
        words[i] = malloc(sizeof(char) * word_length + 1);

        // Generate the word
        for (int j = 0; j < word_length; j++) {
            words[i][j] = 'a' + rand() % 26;
        }

        // Terminate the word with a null character
        words[i][word_length] = '\0';
    }

    // Print the instructions
    printf("Instructions:\n");
    printf("Type the following words as quickly and accurately as possible:\n");
    for (int i = 0; i < NUM_WORDS; i++) {
        printf("%s\n", words[i]);
    }

    // Start the timer
    start_time = time(NULL);

    // Get the input string from the user
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Stop the timer
    end_time = time(NULL);

    // Calculate the elapsed time
    double elapsed_time = difftime(end_time, start_time);

    // Calculate the typing speed
    double typing_speed = (double)strlen(input) / elapsed_time * 60;

    // Print the typing speed
    printf("Your typing speed is: %.2f words per minute\n", typing_speed);

    // Free the memory allocated for the words
    for (int i = 0; i < NUM_WORDS; i++) {
        free(words[i]);
    }

    return 0;
}