//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_WORDS 100
#define WORD_LENGTH 10

// Function to generate a random word
char *generate_word() {
    char *word = malloc(WORD_LENGTH + 1);
    for (int i = 0; i < WORD_LENGTH; i++) {
        word[i] = (char) (rand() % 26 + 97);
    }
    word[WORD_LENGTH] = '\0';
    return word;
}

// Function to print the words on the screen
void print_words(char **words) {
    for (int i = 0; i < NUM_WORDS; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

// Function to get the user's input
char *get_input() {
    char *input = malloc(NUM_WORDS * WORD_LENGTH + 1);
    scanf("%s", input);
    return input;
}

// Function to compare the user's input to the original words
int compare_input(char **words, char *input) {
    int errors = 0;
    for (int i = 0; i < NUM_WORDS; i++) {
        if (strcmp(words[i], input) != 0) {
            errors++;
        }
    }
    return errors;
}

// Function to calculate the typing speed
double calculate_speed(int errors, time_t start_time, time_t end_time) {
    double time_taken = difftime(end_time, start_time);
    double speed = (NUM_WORDS - errors) / time_taken;
    return speed;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate the words
    char **words = malloc(NUM_WORDS * sizeof(char *));
    for (int i = 0; i < NUM_WORDS; i++) {
        words[i] = generate_word();
    }

    // Print the words on the screen
    print_words(words);

    // Get the user's input
    char *input = get_input();

    // Compare the user's input to the original words
    int errors = compare_input(words, input);

    // Calculate the typing speed
    time_t start_time = time(NULL);
    time_t end_time = time(NULL);
    double speed = calculate_speed(errors, start_time, end_time);

    // Print the results
    printf("Errors: %d\n", errors);
    printf("Typing speed: %.2f words per minute\n", speed);

    // Free the allocated memory
    for (int i = 0; i < NUM_WORDS; i++) {
        free(words[i]);
    }
    free(words);
    free(input);

    return 0;
}