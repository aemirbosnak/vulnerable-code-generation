//LLAMA2-13B DATASET v1.0 Category: Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 100
#define MIN_LENGTH 5

// Function to generate a random word
char *generate_word(void) {
    char *word = malloc(MAX_LENGTH * sizeof(char));
    int i = 0;

    while (i < MAX_LENGTH) {
        word[i] = 'a' + (rand() % 26);
        i++;
    }

    return word;
}

// Function to print a word and ask the user for input
void print_word_and_ask_for_input(char *word) {
    printf("%s\n", word);
    printf("Enter a word: ");
    fgets(NULL, 0, stdin);
}

int main(void) {
    // Generate a random word
    char *word = generate_word();

    // Print the word and ask for input
    print_word_and_ask_for_input(word);

    // Get the user's input
    char user_input[MAX_LENGTH];
    fgets(user_input, MAX_LENGTH, stdin);

    // Check if the user's input is valid
    if (strlen(user_input) < MIN_LENGTH || strlen(user_input) > MAX_LENGTH) {
        printf("Invalid input. Please enter a word between %d and %d characters long.\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }

    // If the user's input is valid, print it and generate a new random word
    printf("You entered: %s\n", user_input);
    word = generate_word();
    print_word_and_ask_for_input(word);

    return 0;
}