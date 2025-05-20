//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Test duration in seconds
#define TEST_DURATION 60

// Word list
static char *words[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog", "is", "a", "mammal", "that", "lives", "on", "land"};
#define NUM_WORDS (sizeof(words) / sizeof(char *))

// Initialize random number generator
void init_rand() {
    srand(time(NULL));
}

// Generate a random word
char *get_random_word() {
    return words[rand() % NUM_WORDS];
}

// Get user input
char *get_user_input() {
    char *input = malloc(1024);
    scanf("%s", input);
    return input;
}

// Compare user input to target word
int compare_input(char *input, char *target) {
    return strcmp(input, target);
}

// Calculate typing speed
int calculate_speed(int num_words, int test_duration) {
    return (num_words * 60) / test_duration;
}

// Print test results
void print_results(int num_words, int test_duration, int speed) {
    printf("Number of words typed: %d\n", num_words);
    printf("Test duration: %d seconds\n", test_duration);
    printf("Typing speed: %d words per minute\n", speed);
}

int main() {
    // Initialize random number generator
    init_rand();

    // Start timer
    time_t start_time = time(NULL);

    // Initialize variables
    int num_words = 0;
    int correct_words = 0;
    char *target_word;

    // Loop until time runs out
    while (difftime(time(NULL), start_time) < TEST_DURATION) {
        // Generate a random word
        target_word = get_random_word();

        // Get user input
        char *input = get_user_input();

        // Compare user input to target word
        if (compare_input(input, target_word) == 0) {
            correct_words++;
        }

        // Free memory allocated for user input
        free(input);

        // Increment number of words typed
        num_words++;
    }

    // Calculate typing speed
    int speed = calculate_speed(correct_words, TEST_DURATION);

    // Print test results
    print_results(num_words, TEST_DURATION, speed);

    return 0;
}