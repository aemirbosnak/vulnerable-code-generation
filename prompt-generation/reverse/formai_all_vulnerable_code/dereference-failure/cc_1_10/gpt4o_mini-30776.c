//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define MAX_WORDS 50

// Function Declarations
void translate_to_alien(char *input, char *output);
void convert_word_to_alien(char *word, char *alien_word);
void convert_character_to_alien(char c, char *alien_char);
void to_lower_case(char *str);

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];

    printf("Welcome to the C Alien Language Translator!\n");
    printf("Enter a sentence to translate (up to %d characters):\n", MAX_LENGTH);
    
    // Read input from user
    if (fgets(input, MAX_LENGTH, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    
    // Replace newline character with null terminator
    input[strcspn(input, "\n")] = '\0';

    // Translate input to alien language
    translate_to_alien(input, output);
    
    // Show translated output
    printf("Translated sentence in Alien Language:\n%s\n", output);

    return 0;
}

// Function to translate the entire input string to alien language
void translate_to_alien(char *input, char *output) {
    char *word;
    char alien_word[MAX_LENGTH] = "";
    output[0] = '\0'; // Initialize output

    // Convert input string to lowercase for consistency
    to_lower_case(input);

    // Tokenize the input into words
    word = strtok(input, " ");
    while (word != NULL) {
        convert_word_to_alien(word, alien_word);
        strcat(output, alien_word);
        strcat(output, " "); // Add space after each translated word
        word = strtok(NULL, " ");
    }
    output[strlen(output) - 1] = '\0'; // Remove last space
}

// Function to convert a word to alien language
void convert_word_to_alien(char *word, char *alien_word) {
    char alien_char[3];
    alien_word[0] = '\0'; // Initialize alien_word

    for (int i = 0; i < strlen(word); i++) {
        convert_character_to_alien(word[i], alien_char);
        strcat(alien_word, alien_char); // Append converted character
    }
}

// Function to convert a standard character to alien language equivalent
void convert_character_to_alien(char c, char *alien_char) {
    switch (c) {
        case 'a': strcpy(alien_char, "α"); break;
        case 'b': strcpy(alien_char, "β"); break;
        case 'c': strcpy(alien_char, "γ"); break;
        case 'd': strcpy(alien_char, "δ"); break;
        case 'e': strcpy(alien_char, "ε"); break;
        case 'f': strcpy(alien_char, "ζ"); break;
        case 'g': strcpy(alien_char, "η"); break;
        case 'h': strcpy(alien_char, "θ"); break;
        case 'i': strcpy(alien_char, "ι"); break;
        case 'j': strcpy(alien_char, "κ"); break;
        case 'k': strcpy(alien_char, "λ"); break;
        case 'l': strcpy(alien_char, "μ"); break;
        case 'm': strcpy(alien_char, "ν"); break;
        case 'n': strcpy(alien_char, "ξ"); break;
        case 'o': strcpy(alien_char, "ο"); break;
        case 'p': strcpy(alien_char, "π"); break;
        case 'q': strcpy(alien_char, "ρ"); break;
        case 'r': strcpy(alien_char, "σ"); break;
        case 's': strcpy(alien_char, "τ"); break;
        case 't': strcpy(alien_char, "υ"); break;
        case 'u': strcpy(alien_char, "φ"); break;
        case 'v': strcpy(alien_char, "χ"); break;
        case 'w': strcpy(alien_char, "ψ"); break;
        case 'x': strcpy(alien_char, "ω"); break;
        case 'y': strcpy(alien_char, "ζυ"); break;  // Example mapping
        case 'z': strcpy(alien_char, "ια"); break;  // Example mapping
        case ' ': strcpy(alien_char, " "); break;   // Space remains space
        default: strcpy(alien_char, "?"); break;    // Unknown characters
    }
}

// Function to convert a string to lowercase
void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}