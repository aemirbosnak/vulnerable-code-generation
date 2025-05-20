//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256
#define DICTIONARY_SIZE 5

typedef struct {
    char *english;
    char *alien;
} Translation;

Translation dictionary[DICTIONARY_SIZE] = {
    {"hello", "glxthor"},
    {"world", "narith"},
    {"detective", "srothk"},
    {"mystery", "blorvak"},
    {"case", "thramon"}
};

// Function to convert a word to its alien language equivalent, if available
char* translate_to_alien(const char *word) {
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (strcmp(word, dictionary[i].english) == 0) {
            return dictionary[i].alien;
        }
    }
    return word; // If no translation found, return the original word
}

// Function to process the input text and translate it to alien language
void translate_input(const char *input, char *output) {
    char word[MAX_LENGTH];
    int j = 0, output_index = 0;

    for (int i = 0; ; i++) {
        // Check for end of string or a whitespace character
        if (input[i] == ' ' || input[i] == '\0') {
            word[j] = '\0'; // Null-terminate the current word
            char *translated_word = translate_to_alien(word);
            while (*translated_word) {
                output[output_index++] = *translated_word++;
            }
            if (input[i] == ' ') {
                output[output_index++] = ' '; // Preserve the space
            }
            j = 0; // Reset current word index
        } else {
            word[j++] = input[i]; // Accumulate the characters of the word
        }
        if (input[i] == '\0') {
            break; // Exit on end of string
        }
    }
    output[output_index] = '\0'; // Null-terminate the output string
}

// A function to simulate the investigation of the translated sentences
void investigate_translation(const char *input) {
    char *translated_output = (char *)malloc(MAX_LENGTH * sizeof(char));
    translate_input(input, translated_output);
    
    printf("Sherlock Holmes: \"The original message was: %s\"\n", input);
    printf("Sherlock Holmes: \"In alien tongue, it reveals: %s\"\n", translated_output);
    
    // Analyzing the translated output
    if (strstr(translated_output, "glxthor") != NULL) {
        printf("Sherlock Holmes: \"'Glxthor' indicates a greeting, we are being welcomed into another realm.\"\n");
    }
    if (strstr(translated_output, "blorvak") != NULL) {
        printf("Sherlock Holmes: \"The presence of 'Blorvak' suggests there is a mystery to unravel, my dear Watson.\"\n");
    }
    if (strstr(translated_output, "thramon") != NULL) {
        printf("Sherlock Holmes: \"'Thramon' points to a case we must investigate with urgency!\"\n");
    }

    free(translated_output); // Free dynamically allocated memory
}

int main() {
    char input[MAX_LENGTH];

    printf("Welcome to the Sherlock Holmes Alien Language Translator!\n");
    printf("Please enter a sentence in English to translate to the alien language:\n");

    // Read input from the user
    if (fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = 0; // Remove the newline character
        investigate_translation(input);
    } else {
        printf("Failed to read input. Please try again.\n");
    }

    return 0;
}