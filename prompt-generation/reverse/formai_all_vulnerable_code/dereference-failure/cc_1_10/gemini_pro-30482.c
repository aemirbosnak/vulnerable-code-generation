//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

// Function to generate a random word
char *generate_word(int length) {
    char *word = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        word[i] = 'a' + rand() % 26;
    }
    word[length] = '\0';
    return word;
}

// Function to print a word with a delay
void print_word(char *word, int delay) {
    for (int i = 0; i < strlen(word); i++) {
        printf("%c", word[i]);
        fflush(stdout);
        usleep(delay * 1000);
    }
}

// Function to get the user's input
char *get_input() {
    char *input = malloc(MAX_WORD_LENGTH + 1);
    scanf("%s", input);
    return input;
}

// Function to check if the user's input matches the word
int check_input(char *word, char *input) {
    return strcmp(word, input) == 0;
}

// Function to calculate the user's typing speed
int calculate_speed(int words, int time) {
    return words * 60 / time;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a list of random words
    char *words[MAX_WORDS];
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i] = generate_word(MAX_WORD_LENGTH);
    }

    // Start the timer
    clock_t start = clock();

    // Print the first word and get the user's input
    print_word(words[0], 100);
    char *input = get_input();

    // Check the user's input and calculate the typing speed
    int speed = calculate_speed(1, clock() - start);

    // Print the typing speed
    printf("Your typing speed is %d words per minute.\n", speed);

    // Free the allocated memory
    for (int i = 0; i < MAX_WORDS; i++) {
        free(words[i]);
    }
    free(input);

    return 0;
}