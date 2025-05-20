//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the Cat Language dictionary
const char *cat_dictionary[] = {
    "meow", "food",
    "purr", "water",
    "hiss", "outside",
    "chirp", "play",
    "meow meow", "I love you",
    "purr purr", "I'm happy",
    "hiss hiss", "I'm angry",
    "chirp chirp", "I'm excited",
    "meow meow meow", "I'm hungry",
    "purr purr purr", "I'm sleepy",
    "hiss hiss hiss", "I'm scared",
    "chirp chirp chirp", "I'm curious"
};

// Translate a string from Cat Language to English
char *cat_to_english(char *cat_string) {
    // Split the Cat Language string into individual words
    char *words[10];
    int num_words = 0;
    char *word = strtok(cat_string, " ");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Translate each word from Cat Language to English
    char *english_string = malloc(100 * sizeof(char));
    english_string[0] = '\0';
    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < sizeof(cat_dictionary) / sizeof(char *); j += 2) {
            if (strcmp(words[i], cat_dictionary[j]) == 0) {
                strcat(english_string, cat_dictionary[j + 1]);
                strcat(english_string, " ");
                break;
            }
        }
    }

    // Return the translated string
    return english_string;
}

// Translate a string from English to Cat Language
char *english_to_cat(char *english_string) {
    // Split the English string into individual words
    char *words[10];
    int num_words = 0;
    char *word = strtok(english_string, " ");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Translate each word from English to Cat Language
    char *cat_string = malloc(100 * sizeof(char));
    cat_string[0] = '\0';
    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < sizeof(cat_dictionary) / sizeof(char *); j += 2) {
            if (strcmp(words[i], cat_dictionary[j + 1]) == 0) {
                strcat(cat_string, cat_dictionary[j]);
                strcat(cat_string, " ");
                break;
            }
        }
    }

    // Return the translated string
    return cat_string;
}

// Main function
int main() {
    // Get the Cat Language string from the user
    char cat_string[100];
    printf("Enter a string in Cat Language: ");
    gets(cat_string);

    // Translate the Cat Language string to English
    char *english_string = cat_to_english(cat_string);
    printf("English translation: %s\n", english_string);

    // Translate the English string back to Cat Language
    char *cat_string2 = english_to_cat(english_string);
    printf("Cat Language translation: %s\n", cat_string2);

    // Free the allocated memory
    free(english_string);
    free(cat_string2);

    return 0;
}