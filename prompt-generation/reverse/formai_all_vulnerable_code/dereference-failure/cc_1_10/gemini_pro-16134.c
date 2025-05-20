//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LEN 100

// Function to generate a random word
char *generate_word() {
    char *word = malloc(MAX_LEN);
    int len = rand() % MAX_LEN + 1;
    for (int i = 0; i < len; i++) {
        word[i] = (rand() % 26) + 'a';
    }
    word[len] = '\0';
    return word;
}

// Function to get the user input
char *get_input() {
    char *input = malloc(MAX_LEN);
    printf("Enter the word: ");
    scanf("%s", input);
    return input;
}

// Function to compare the user input with the generated word
int compare_words(char *word, char *input) {
    return strcmp(word, input) == 0;
}

// Function to print the results
void print_results(int correct, int incorrect, double wpm) {
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);
    printf("WPM: %.2f\n", wpm);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a list of random words
    char *words[MAX_WORDS];
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i] = generate_word();
    }

    // Get the user input for each word
    char *inputs[MAX_WORDS];
    for (int i = 0; i < MAX_WORDS; i++) {
        inputs[i] = get_input();
    }

    // Compare the user input with the generated words
    int correct = 0;
    int incorrect = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (compare_words(words[i], inputs[i])) {
            correct++;
        } else {
            incorrect++;
        }
    }

    // Calculate the WPM
    double wpm = (correct / 5.0) * 60.0;

    // Print the results
    print_results(correct, incorrect, wpm);

    // Free the allocated memory
    for (int i = 0; i < MAX_WORDS; i++) {
        free(words[i]);
        free(inputs[i]);
    }

    return 0;
}