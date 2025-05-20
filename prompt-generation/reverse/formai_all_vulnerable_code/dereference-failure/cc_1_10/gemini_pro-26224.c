//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORDS_TO_TYPE 100
#define WORD_LENGTH 10

// Function to generate a random word of length WORD_LENGTH
char* generate_word() {
    char* word = malloc(sizeof(char) * (WORD_LENGTH + 1));
    for (int i = 0; i < WORD_LENGTH; i++) {
        word[i] = 'a' + rand() % 26;
    }
    word[WORD_LENGTH] = '\0';
    return word;
}

// Function to display the words to be typed
void display_words(char** words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

// Function to check if the user's input matches the word
int check_input(char* input, char* word) {
    return strcmp(input, word) == 0;
}

// Function to get the user's input
char* get_input() {
    char* input = malloc(sizeof(char) * (WORD_LENGTH + 1));
    scanf("%s", input);
    return input;
}

// Function to calculate the typing speed
double calculate_speed(int num_words, double time_taken) {
    return (num_words * WORD_LENGTH) / time_taken;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate the words to be typed
    char** words = malloc(sizeof(char*) * WORDS_TO_TYPE);
    for (int i = 0; i < WORDS_TO_TYPE; i++) {
        words[i] = generate_word();
    }

    // Display the words to be typed
    display_words(words, WORDS_TO_TYPE);

    // Start the timer
    clock_t start_time = clock();

    // Get the user's input for each word
    char* input;
    int num_correct = 0;
    for (int i = 0; i < WORDS_TO_TYPE; i++) {
        input = get_input();
        if (check_input(input, words[i])) {
            num_correct++;
        }
        free(input);
    }

    // Stop the timer
    clock_t end_time = clock();

    // Calculate the time taken
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate the typing speed
    double speed = calculate_speed(num_correct, time_taken);

    // Display the typing speed
    printf("Your typing speed is: %.2f words per minute\n", speed);

    // Free the allocated memory
    for (int i = 0; i < WORDS_TO_TYPE; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}