//LLAMA2-13B DATASET v1.0 Category: Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 100
#define SYMBOLS 5

// Define a struct to represent a sentence
struct sentence {
    char *text;
    size_t length;
};

// Function to generate a sentence
struct sentence generate_sentence(void) {
    char symbols[SYMBOLS];
    for (size_t i = 0; i < SYMBOLS; i++) {
        symbols[i] = 'a' + (rand() % (('z' - 'a') + 1));
    }
    char *text = malloc(sizeof(char) * (strlen(symbols) + 1));
    for (size_t i = 0; i < strlen(symbols); i++) {
        text[i] = symbols[i];
    }
    text[strlen(symbols)] = '\0';
    struct sentence s = {text, strlen(text)};
    return s;
}

// Function to print the sentence
void print_sentence(struct sentence s) {
    printf("%s\n", s.text);
}

int main(void) {
    // Generate a sentence
    struct sentence sentence = generate_sentence();

    // Print the sentence
    print_sentence(sentence);

    // Generate another sentence
    sentence = generate_sentence();

    // Print the second sentence
    print_sentence(sentence);

    return 0;
}