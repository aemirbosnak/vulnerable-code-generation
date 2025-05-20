//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Global variables
int total_words = 0;
int correct_words = 0;
time_t start_time;
time_t end_time;

// Function to generate random words
char *generate_random_word(int length) {
    char *word = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        word[i] = 'a' + rand() % 26;
    }
    word[length] = '\0';
    return word;
}

// Function to get user input
char *get_user_input() {
    char *input = malloc(100);
    scanf("%s", input);
    return input;
}

// Function to check if the user input is correct
int check_word(char *word1, char *word2) {
    if (strcmp(word1, word2) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to start the typing test
void start_test() {
    // Generate a random word
    char *word = generate_random_word(5);

    // Display the word on the screen
    printf("%s\n", word);

    // Get user input
    char *input = get_user_input();

    // Check if the user input is correct
    int is_correct = check_word(word, input);

    // Update the global variables
    total_words++;
    if (is_correct) {
        correct_words++;
    }

    // Free the memory
    free(word);
    free(input);
}

// Function to end the typing test
void end_test() {
    // Calculate the typing speed
    double typing_speed = (double)correct_words / (double)(end_time - start_time) * 60;

    // Display the typing speed on the screen
    printf("Your typing speed is %.2f words per minute.\n", typing_speed);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Start the timer
    start_time = time(NULL);

    // Start the typing test
    for (int i = 0; i < 100; i++) {
        start_test();
    }

    // End the timer
    end_time = time(NULL);

    // End the typing test
    end_test();

    return 0;
}