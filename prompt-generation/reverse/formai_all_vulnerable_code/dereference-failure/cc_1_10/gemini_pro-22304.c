//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define N_WORDS 100
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 10

// Generate a random word of length between MIN_WORD_LENGTH and MAX_WORD_LENGTH
char *generate_word() {
    int length = rand() % (MAX_WORD_LENGTH - MIN_WORD_LENGTH + 1) + MIN_WORD_LENGTH;
    char *word = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        word[i] = 'a' + rand() % 26;
    }
    word[length] = '\0';
    return word;
}

// Generate a list of N_WORDS random words
char **generate_words() {
    char **words = malloc(N_WORDS * sizeof(char *));
    for (int i = 0; i < N_WORDS; i++) {
        words[i] = generate_word();
    }
    return words;
}

// Free the memory allocated for the list of words
void free_words(char **words) {
    for (int i = 0; i < N_WORDS; i++) {
        free(words[i]);
    }
    free(words);
}

// Print the list of words
void print_words(char **words) {
    for (int i = 0; i < N_WORDS; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

// Get the user's input
char *get_input() {
    char *input = malloc(N_WORDS * MAX_WORD_LENGTH);
    scanf("%s", input);
    return input;
}

// Check if the user's input matches the list of words
int check_input(char **words, char *input) {
    int correct = 0;
    char **input_words = malloc(N_WORDS * sizeof(char *));
    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL) {
        input_words[i++] = token;
        token = strtok(NULL, " ");
    }
    for (int i = 0; i < N_WORDS; i++) {
        if (strcmp(words[i], input_words[i]) == 0) {
            correct++;
        }
    }
    free(input_words);
    return correct;
}

// Calculate the user's typing speed
double calculate_speed(int correct, double time) {
    return correct / time * 60;
}

// Print the user's results
void print_results(int correct, double time, double speed) {
    printf("You typed %d words correctly in %.2f seconds.\n", correct, time);
    printf("Your typing speed is %.2f words per minute.\n", speed);
}

int main() {
    srand(time(NULL));

    // Generate a list of random words
    char **words = generate_words();

    // Print the list of words
    print_words(words);

    // Get the user's input
    char *input = get_input();

    // Check if the user's input matches the list of words
    int correct = check_input(words, input);

    // Calculate the user's typing speed
    double time = clock() / (double)CLOCKS_PER_SEC;
    double speed = calculate_speed(correct, time);

    // Print the user's results
    print_results(correct, time, speed);

    // Free the memory allocated for the list of words and the user's input
    free_words(words);
    free(input);

    return 0;
}