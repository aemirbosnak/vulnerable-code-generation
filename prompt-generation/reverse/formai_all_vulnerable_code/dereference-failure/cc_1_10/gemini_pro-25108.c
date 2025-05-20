//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LEN 100

// Function to generate a random word
char *generate_word() {
    char *word;
    int len = rand() % MAX_LEN + 1;
    word = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        word[i] = (rand() % 26) + 'a';
    }
    word[len] = '\0';
    return word;
}

// Function to generate a list of words
char **generate_words(int num_words) {
    char **words = malloc(num_words * sizeof(char *));
    for (int i = 0; i < num_words; i++) {
        words[i] = generate_word();
    }
    return words;
}

// Function to print a list of words
void print_words(char **words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

// Function to get the user's input
char *get_input() {
    char *input;
    size_t len = 0;
    getline(&input, &len, stdin);
    return input;
}

// Function to compare the user's input to the list of words
int compare_input(char *input, char **words, int num_words) {
    int correct = 0;
    char **input_words = malloc(num_words * sizeof(char *));
    char *input_word = strtok(input, " ");
    for (int i = 0; i < num_words; i++) {
        input_words[i] = input_word;
        input_word = strtok(NULL, " ");
    }
    for (int i = 0; i < num_words; i++) {
        if (strcmp(input_words[i], words[i]) == 0) {
            correct++;
        }
    }
    return correct;
}

// Function to calculate the user's WPM
int calculate_wpm(int correct, int num_words, int time) {
    return (correct * 60) / time;
}

// Function to run the typing speed test
void run_test() {
    char **words = generate_words(MAX_WORDS);
    print_words(words, MAX_WORDS);
    time_t start = time(NULL);
    char *input = get_input();
    time_t end = time(NULL);
    int correct = compare_input(input, words, MAX_WORDS);
    int wpm = calculate_wpm(correct, MAX_WORDS, end - start);
    printf("WPM: %d\n", wpm);
}

int main() {
    srand(time(NULL));
    run_test();
    return 0;
}