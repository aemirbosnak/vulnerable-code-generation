//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: satisfied
#include <stdio.h>
#include <string.h>

// Define the Cat Language dictionary
char *cat_dict[] = {
    "meow", "food",
    "purr", "happy",
    "hiss", "angry",
    "chirp", "excited",
    "trill", "content",
    "yowl", "pain",
    "mew", "kitten",
    "mutter", "disapproval",
    "chatter", "annoyance",
    "scream", "fear"
};

// Translate a string from English to Cat Language
char *translate_to_cat(char *english) {
    // Allocate memory for the translated string
    char *cat_str = malloc(strlen(english) * 2 + 1);

    // Initialize the translated string
    cat_str[0] = '\0';

    // Iterate over the English string
    for (int i = 0; i < strlen(english); i++) {
        // Find the corresponding Cat Language word
        for (int j = 0; j < sizeof(cat_dict) / sizeof(char *); j += 2) {
            if (strcmp(english + i, cat_dict[j]) == 0) {
                // Append the Cat Language word to the translated string
                strcat(cat_str, cat_dict[j + 1]);
                i += strlen(cat_dict[j]) - 1;
                break;
            }
        }
    }

    // Return the translated string
    return cat_str;
}

// Translate a string from Cat Language to English
char *translate_to_english(char *cat_str) {
    // Allocate memory for the translated string
    char *english_str = malloc(strlen(cat_str) * 2 + 1);

    // Initialize the translated string
    english_str[0] = '\0';

    // Iterate over the Cat Language string
    for (int i = 0; i < strlen(cat_str); i++) {
        // Find the corresponding English word
        for (int j = 0; j < sizeof(cat_dict) / sizeof(char *); j += 2) {
            if (strcmp(cat_str + i, cat_dict[j + 1]) == 0) {
                // Append the English word to the translated string
                strcat(english_str, cat_dict[j]);
                i += strlen(cat_dict[j + 1]) - 1;
                break;
            }
        }
    }

    // Return the translated string
    return english_str;
}

// Main function
int main() {
    // Get the English string from the user
    char english_str[100];
    printf("Enter an English string: ");
    gets(english_str);

    // Translate the English string to Cat Language
    char *cat_str = translate_to_cat(english_str);

    // Print the Cat Language string
    printf("Cat Language: %s\n", cat_str);

    // Translate the Cat Language string back to English
    char *english_str2 = translate_to_english(cat_str);

    // Print the translated English string
    printf("Translated English: %s\n", english_str2);

    // Free the allocated memory
    free(cat_str);
    free(english_str2);

    return 0;
}