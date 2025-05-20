//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 256

// Function prototypes
void display_help();
char* alien_translate(const char *input);
char* reverse_string(const char *str);
void to_uppercase(char *str);

int main() {
    char input[MAX_LENGTH];
    char *translated;

    printf("Welcome to the C Alien Language Translator!\n");
    display_help();

    while (1) {
        printf("\nEnter a phrase to translate (or type 'exit' to quit): ");
        fgets(input, MAX_LENGTH, stdin);

        // Remove the newline character from the input
        input[strcspn(input, "\n")] = 0; 

        if (strcmp(input, "exit") == 0) {
            printf("Thank you for using the translator! Goodbye!\n");
            break;
        }
        
        translated = alien_translate(input);
        printf("Translated Phrase: %s\n", translated);
        free(translated);
    }

    return 0;
}

// Function to display help and usage instructions
void display_help() {
    printf("How to use this translator:\n");
    printf("1. Type a sentence or phrase you want to translate.\n");
    printf("2. The translator will process the input and return the alien equivalent.\n");
    printf("3. Type 'exit' to leave the translator.\n");
}

// Function to translate input into alien language
char* alien_translate(const char *input) {
    size_t len = strlen(input);
    char *translated = (char *)malloc(len * 2 + 1); // Allocate memory for translation
    if (translated == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    char *ptr = translated;
    const char *alien_sounds[] = {"Zorp", "Blip", "Gleep", "Worp", "Bing"}; // Alien sound mappings
    const char *default_sound = "Geez"; // Default sound for unknown characters
    int index;

    for (size_t i = 0; i < len; i++) {
        // Example translation logic based on character
        if (input[i] >= 'a' && input[i] <= 'z') {
            index = input[i] - 'a';
            sprintf(ptr, "%s ", alien_sounds[index % 5]); // Cycle through 5 sounds
            ptr += strlen(ptr);
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            index = input[i] - 'A';
            sprintf(ptr, "%s ", alien_sounds[index % 5]);
            to_uppercase(ptr - strlen(alien_sounds[index % 5])); // Uppercase for alien sounds
            ptr += strlen(ptr);
        } else {
            sprintf(ptr, "%s ", default_sound);
            ptr += strlen(default_sound) + 1;
        }
    }
    
    *ptr = '\0'; // Null-terminate the translated string
    return translated;
}

// Function to reverse a string
char* reverse_string(const char *str) {
    size_t len = strlen(str);
    char *rev = (char *)malloc(len + 1);
    if (rev == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }
    rev[len] = '\0';
    return rev;
}

// Function to convert string to uppercase
void to_uppercase(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}