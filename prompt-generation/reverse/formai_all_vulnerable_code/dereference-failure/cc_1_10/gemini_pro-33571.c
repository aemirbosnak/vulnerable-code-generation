//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define WORDS 1000
#define LEN 20

// Function to generate random words
char* generate_word() {
    char* word = malloc(LEN * sizeof(char));
    int len = rand() % (LEN - 1) + 1;
    for (int i = 0; i < len; i++) {
        word[i] = 'a' + rand() % 26;
    }
    word[len] = '\0';
    return word;
}

// Function to print the words
void print_words(char** words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

// Function to get the user's input
char* get_input() {
    char* input = malloc(LEN * sizeof(char));
    scanf("%s", input);
    return input;
}

// Function to check if the user's input is correct
int is_correct(char* input, char* word) {
    return strcmp(input, word) == 0;
}

// Function to calculate the accuracy
float calculate_accuracy(int num_correct, int num_words) {
    return (float) num_correct / num_words * 100;
}

// Function to calculate the speed
float calculate_speed(int num_words, float time) {
    return (float) num_words / time * 60;
}

// Function to run the test
void run_test() {
    // Generate the words
    char** words = malloc(WORDS * sizeof(char*));
    for (int i = 0; i < WORDS; i++) {
        words[i] = generate_word();
    }

    // Print the words
    print_words(words, WORDS);

    // Get the user's input
    char* input;
    int num_correct = 0;
    float start_time = time(NULL);
    for (int i = 0; i < WORDS; i++) {
        input = get_input();
        if (is_correct(input, words[i])) {
            num_correct++;
        }
    }
    float end_time = time(NULL);
    float time = end_time - start_time;

    // Calculate the accuracy and speed
    float accuracy = calculate_accuracy(num_correct, WORDS);
    float speed = calculate_speed(WORDS, time);

    // Print the results
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Speed: %.2f words/minute\n", speed);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Run the test
    run_test();

    return 0;
}