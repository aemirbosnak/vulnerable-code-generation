//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100 // Maximum input length for the program

// Structure to hold the translation mappings
struct TranslationMapping {
    char* c_input;
    char* cat_translation;
};

// Function to perform the translation
char* performTranslation(char* input, struct TranslationMapping* mappings, int num_mappings) {
    char* translation = calloc(MAX_INPUT_LENGTH, sizeof(char)); // Allocate memory for the translation
    
    // Loop through the input string character by character
    for (int i = 0; i < strlen(input); i++) {
        char current_char = tolower(input[i]);
        int found_mapping = 0;
        
        // Loop through the mapping table and see if the character has a translation
        for (int j = 0; j < num_mappings; j++) {
            if (strcmp(mappings[j].c_input, &current_char) == 0) {
                strcat(translation, mappings[j].cat_translation); // Concatenate the translation with the output string
                found_mapping = 1;
                break;
            }
        }
        
        if (!found_mapping) {
            char current_char_str[2] = {current_char, '\0'}; // Convert the character to a string
            strcat(translation, current_char_str); // Concatenate the original character with the output string
        }
    }
    
    return translation;
}

// Main function
int main() {
    // Define the translation mappings
    struct TranslationMapping mappings[] = {
        {"a", "mew "},
        {"b", "meow "},
        {"c", "purr "},
        {"d", "hiss "},
        {"e", "screech "},
        {NULL, NULL} // Sentry value to terminate the mappings table
    };
    
    char input[MAX_INPUT_LENGTH]; // Input buffer
    printf("Enter an input string to translate to Cat Language: ");
    fgets(input, MAX_INPUT_LENGTH, stdin); // Get input from user
    
    // Remove newline character from input string
    input[strcspn(input, "\n")] = 0;
    
    char* translation = performTranslation(input, mappings, 5); // Perform the translation
    
    printf("Cat Language Translation: %s\n", translation); // Print the translation
    free(translation); // Free up the memory allocated for the translation
    
    return 0;
}