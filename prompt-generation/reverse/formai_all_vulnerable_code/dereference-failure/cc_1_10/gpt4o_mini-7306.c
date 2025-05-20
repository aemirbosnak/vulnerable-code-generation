//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256

// Function prototypes
void greet();
char* to_cat_language(const char* str);
void free_memory(char*);

int main() {
    char input[MAX_LENGTH];

    greet();

    while (1) {
        printf("Enter a sentence (or type 'exit' to quit): ");
        fgets(input, MAX_LENGTH, stdin);
        
        // Remove the newline character from input
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            break;
        }

        char* cat_translation = to_cat_language(input);
        printf("Cat Language: %s\n\n", cat_translation);
        free_memory(cat_translation);
    }

    return 0;
}

void greet() {
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Transform your sentences into the purr-fect Cat Language.\n");
}

char* to_cat_language(const char* str) {
    size_t length = strlen(str);
    char* translated = malloc(length * 4); // Allocate memory for worst-case (extra length for 'meow')
    if (!translated) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    size_t j = 0; 
    for (size_t i = 0; i < length; ++i) {
        // Adding 'meow' for vowels
        if (strchr("aeiouAEIOU", str[i]) != NULL) {
            strcpy(&translated[j], "meow");
            j += 4;
        } else if (isalpha(str[i])) {
            // Adding the original character with an added 'purr'
            translated[j++] = str[i];
            strcpy(&translated[j], "purr");
            j += 4;
        } else {
            // Non alphabet characters remain unchanged
            translated[j++] = str[i];
        }
    }
    translated[j] = '\0'; // Null-terminate the string
    return translated;
}

void free_memory(char* ptr) {
    // Free allocated memory
    if (ptr) {
        free(ptr);
    }
}