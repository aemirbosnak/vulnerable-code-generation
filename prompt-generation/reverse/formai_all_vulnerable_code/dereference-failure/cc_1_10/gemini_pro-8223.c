//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int words_per_minute;
int accuracy;

// Function to generate a random word
char *generate_word() {
    // Array of possible words
    char *words[] = {"apocalypse", "survival", "scavenger", "raider", "mutant", "radiation", "wasteland", "ruins", "hope", "humanity"};

    // Get a random index
    int index = rand() % 10;

    // Return the word at the random index
    return words[index];
}

// Function to get user input
char *get_user_input() {
    // Allocate memory for the user input
    char *input = (char *)malloc(100 * sizeof(char));

    // Get the user input
    printf("Type the word: ");
    scanf("%s", input);

    // Return the user input
    return input;
}

// Function to calculate words per minute
void calculate_words_per_minute(int time) {
    // Calculate words per minute
    words_per_minute = 60 / time;
}

// Function to calculate accuracy
void calculate_accuracy(char *word, char *input) {
    // Compare the word and the input
    int correct = strcmp(word, input) == 0;

    // Calculate accuracy
    accuracy = correct * 100;
}

// Function to print the results
void print_results() {
    // Print the words per minute
    printf("Words per minute: %d\n", words_per_minute);

    // Print the accuracy
    printf("Accuracy: %d\%\n", accuracy);
}

// Main function
int main() {
    // Initialize the random seed
    srand(time(NULL));

    // Generate a random word
    char *word = generate_word();

    // Get the user input
    char *input = get_user_input();

    // Calculate the time taken to type the word
    int time = clock();

    // Calculate words per minute and accuracy
    calculate_words_per_minute(time);
    calculate_accuracy(word, input);

    // Print the results
    print_results();

    // Free the allocated memory
    free(input);

    return 0;
}