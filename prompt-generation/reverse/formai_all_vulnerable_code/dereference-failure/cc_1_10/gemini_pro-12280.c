//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Configure test settings
#define TEST_DURATION 60 // Test duration in seconds
#define NUM_WORDS 100 // Number of words to type
#define MIN_WORD_LENGTH 3 // Minimum word length
#define MAX_WORD_LENGTH 10 // Maximum word length

// Function to generate a random word
char *generate_word() {
    // Generate a random word length
    int word_length = rand() % (MAX_WORD_LENGTH - MIN_WORD_LENGTH + 1) + MIN_WORD_LENGTH;

    // Allocate memory for the word
    char *word = malloc(word_length + 1);

    // Generate random letters
    for (int i = 0; i < word_length; i++) {
        word[i] = 'a' + rand() % 26;
    }

    // Terminate the word with a null character
    word[word_length] = '\0';

    return word;
}

// Function to run the typing speed test
void run_test() {
    // Generate test words
    char **words = malloc(NUM_WORDS * sizeof(char *));
    for (int i = 0; i < NUM_WORDS; i++) {
        words[i] = generate_word();
    }

    // Start the timer
    time_t start_time = time(NULL);

    // Prompt the user to start typing
    printf("Start typing! Press Enter to finish.\n");

    // Get the user's input
    char input[NUM_WORDS * MAX_WORD_LENGTH];
    fgets(input, NUM_WORDS * MAX_WORD_LENGTH, stdin);

    // Stop the timer
    time_t end_time = time(NULL);

    // Calculate the elapsed time
    double elapsed_time = difftime(end_time, start_time);

    // Calculate the number of words typed
    int num_words_typed = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        num_words_typed++;
        token = strtok(NULL, " ");
    }

    // Calculate the typing speed
    double typing_speed = num_words_typed / elapsed_time;

    // Display the results
    printf("Words typed: %d\n", num_words_typed);
    printf("Elapsed time: %.2f seconds\n", elapsed_time);
    printf("Typing speed: %.2f words per minute\n", typing_speed * 60);

    // Free the allocated memory
    for (int i = 0; i < NUM_WORDS; i++) {
        free(words[i]);
    }
    free(words);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Run the typing speed test
    run_test();

    return 0;
}