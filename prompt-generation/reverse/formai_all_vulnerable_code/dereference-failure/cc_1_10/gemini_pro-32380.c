//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

// Generate a random word of length n
char* generate_word(int n) {
    char* word = malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; i++) {
        word[i] = 'a' + rand() % 26;
    }
    word[n] = '\0';
    return word;
}

// Generate a list of n random words
char** generate_words(int n) {
    char** words = malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        words[i] = generate_word(rand() % MAX_WORD_LENGTH + 1);
    }
    return words;
}

// Print a list of n words
void print_words(char** words, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

// Get the user's input
char* get_input() {
    char* input = malloc(sizeof(char) * MAX_WORD_LENGTH);
    scanf("%s", input);
    return input;
}

// Check if the user's input matches the word
int check_input(char* input, char* word) {
    return strcmp(input, word) == 0;
}

// Get the accuracy of the user's input
double get_accuracy(int correct, int total) {
    return (double)correct / total;
}

// Get the speed of the user's input
double get_speed(int correct, double time) {
    return (double)correct / time;
}

// Print the results of the test
void print_results(double accuracy, double speed) {
    printf("Accuracy: %.2f%%\n", accuracy * 100);
    printf("Speed: %.2f words per minute\n", speed * 60);
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a list of 100 random words
    char** words = generate_words(MAX_WORDS);

    // Print the words
    print_words(words, MAX_WORDS);

    // Get the start time
    clock_t start = clock();

    // Get the user's input for each word
    int correct = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        char* input = get_input();
        if (check_input(input, words[i])) {
            correct++;
        }
    }

    // Get the end time
    clock_t end = clock();

    // Calculate the time taken
    double time = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the accuracy and speed
    double accuracy = get_accuracy(correct, MAX_WORDS);
    double speed = get_speed(correct, time);

    // Print the results
    print_results(accuracy, speed);

    // Free the memory
    for (int i = 0; i < MAX_WORDS; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}