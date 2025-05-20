//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: invasive
#include <stdio.h>
#include <string.h>

// Alien language dictionary
struct alien_dict {
    char alien_word[20];
    char english_word[20];
};

// Initialize the dictionary
struct alien_dict dictionary[] = {
    {"glox", "hello"},
    {"blith", "goodbye"},
    {"zarg", "friend"},
    {"ploof", "enemy"},
    {"frump", "food"},
    {"grax", "water"},
    {"quux", "fire"},
    {"wibble", "ice"},
    {"flarb", "rock"},
    {"quark", "tree"}
};

// Translate a single word from Alien to English
char *alien_to_english(const char *alien_word) {
    int i;
    for (i = 0; i < sizeof(dictionary) / sizeof(struct alien_dict); i++) {
        if (strcmp(alien_word, dictionary[i].alien_word) == 0) {
            return dictionary[i].english_word;
        }
    }

    // Return NULL if the word is not found in the dictionary
    return NULL;
}

// Translate a sentence from Alien to English
char *alien_to_english_sentence(const char *alien_sentence) {
    char *english_sentence = malloc(strlen(alien_sentence) * sizeof(char));
    int i, j;

    // Split the sentence into words
    char *words[100];
    int num_words = 0;
    char *word = strtok(alien_sentence, " ");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Translate each word
    for (i = 0; i < num_words; i++) {
        char *english_word = alien_to_english(words[i]);
        if (english_word != NULL) {
            strcat(english_sentence, english_word);
            strcat(english_sentence, " ");
        }
    }

    // Remove the trailing space
    if (strlen(english_sentence) > 0) {
        english_sentence[strlen(english_sentence) - 1] = '\0';
    }

    return english_sentence;
}

int main() {
    // Get the Alien sentence from the user
    char alien_sentence[100];
    printf("Enter an Alien sentence: ");
    scanf("%s", alien_sentence);

    // Translate the sentence
    char *english_sentence = alien_to_english_sentence(alien_sentence);

    // Print the translation
    printf("English translation: %s\n", english_sentence);

    // Free the allocated memory
    free(english_sentence);

    return 0;
}