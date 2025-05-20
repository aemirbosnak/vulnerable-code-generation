//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define maximum length of input string
#define MAX_LENGTH 1000

// Function prototypes
void translate(char*);
int isVowel(char);

int main() {
    char input[MAX_LENGTH];

    printf("Enter a string to translate into Cat language: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Translate input string
    translate(input);

    return 0;
}

// Function to translate input string into Cat language
void translate(char* input) {
    char* output = malloc(sizeof(char) * strlen(input) + 1);
    int i = 0;

    // Loop through each character in the input string
    while (input[i]) {
        if (isVowel(input[i])) {
            // If the character is a vowel, replace it with "meow"
            strcat(output, "meow ");
        } else {
            // Otherwise, add the character to the output string
            strcat(output, &input[i]);
        }
        i++;
    }

    printf("Cat translation: %s\n", output);
    free(output);
}

// Function to check if a character is a vowel
int isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return 1;
    } else {
        return 0;
    }
}