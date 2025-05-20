//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_INPUT_LENGTH 1000

// Cat language transformation rules
char* catLanguageTranslator(const char* input) {
    char* output = malloc(MAX_INPUT_LENGTH);
    output[0] = '\0'; // Start with an empty string
    char word[MAX_WORD_LENGTH];
    char* words[MAX_INPUT_LENGTH / 2]; // Estimate number of words in the input
    int wordCount = 0;
    
    // Tokenize input into words
    const char* start = input;
    while (*start) {
        while (isspace(*start)) start++; // Skip spaces
        char* end = word;
        while (*start && !isspace(*start) && (end - word) < MAX_WORD_LENGTH - 1) {
            *end++ = *start++;
        }
        *end = '\0'; // Null-terminate the word
        
        if (strlen(word) > 0) {
            words[wordCount++] = strdup(word); // Duplicate the word
        }
    }

    // Transform each word
    for (int i = 0; i < wordCount; i++) {
        if (words[i][0] == '\0') continue; // Skip empty words
        strcat(output, "meow "); // Start with 'meow'
        strcat(output, words[i]); // Append the original word
        strcat(output, " purrr "); // Add a purring sound
    }

    // Clean up allocated memory for words
    for (int i = 0; i < wordCount; i++) {
        free(words[i]);
    }

    return output;
}

int main() {
    char input[MAX_INPUT_LENGTH];

    // Welcome message
    printf("Welcome to the Cat Language Translator!\n");
    printf("Enter a sentence (max %d characters), and let the cats speak:\n", MAX_INPUT_LENGTH);

    // Get user input
    if (!fgets(input, MAX_INPUT_LENGTH, stdin)) {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }

    // Remove newline character if there is one
    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }

    // Translate to cat language
    char* catLanguageOutput = catLanguageTranslator(input);

    // Output the result
    printf("In Cat Language, your sentence is:\n");
    printf("%s\n", catLanguageOutput);

    // Clean up allocated memory
    free(catLanguageOutput);

    return EXIT_SUCCESS;
}