//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alien dictionary
char alien_dict[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,?!:;\"";

// English dictionary
char english_dict[] = "etaoinshrdlcumwfgypbvkjxqzETAOINSHRDL CUMWFGYPBVKJXQZ0123456789.,?!:;\"";

// Alien to English translation function
char* alien_to_english(char* alien_text) {
    int alien_len = strlen(alien_text);
    char* english_text = malloc(alien_len + 1);

    for (int i = 0; i < alien_len; i++) {
        char alien_char = alien_text[i];
        int alien_index = strchr(alien_dict, alien_char) - alien_dict;

        if (alien_index >= 0) {
            english_text[i] = english_dict[alien_index];
        } else {
            english_text[i] = alien_char;
        }
    }

    english_text[alien_len] = '\0';

    return english_text;
}

// English to Alien translation function
char* english_to_alien(char* english_text) {
    int english_len = strlen(english_text);
    char* alien_text = malloc(english_len + 1);

    for (int i = 0; i < english_len; i++) {
        char english_char = english_text[i];
        int english_index = strchr(english_dict, english_char) - english_dict;

        if (english_index >= 0) {
            alien_text[i] = alien_dict[english_index];
        } else {
            alien_text[i] = english_char;
        }
    }

    alien_text[english_len] = '\0';

    return alien_text;
}

// Main function
int main() {
    // Get the input text
    char* input_text = NULL;
    size_t input_len = 0;
    getline(&input_text, &input_len, stdin);

    // Translate the text
    char* translated_text = NULL;
    if (strchr(input_text, ' ') != NULL) {
        translated_text = english_to_alien(input_text);
    } else {
        translated_text = alien_to_english(input_text);
    }

    // Print the translated text
    printf("%s", translated_text);

    // Free the allocated memory
    free(input_text);
    free(translated_text);

    return 0;
}