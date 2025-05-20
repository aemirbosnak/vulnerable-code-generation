//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a Watsonian Alien Language Translator
typedef struct {
    char **dictionary; // An array of strings to store the translations
    int size;          // The number of words in the dictionary
} Translator;

// A function to create a new Watsonian Alien Language Translator
Translator *create_translator(char **dictionary, int size) {
    Translator *translator = malloc(sizeof(Translator));
    translator->dictionary = dictionary;
    translator->size = size;
    return translator;
}

// A function to translate a word from Watsonian Alien Language to English
char *translate_word(Translator *translator, char *word) {
    for (int i = 0; i < translator->size; i++) {
        if (strcmp(translator->dictionary[i], word) == 0) {
            return translator->dictionary[i + 1];
        }
    }
    return NULL;
}

// A function to translate a sentence from Watsonian Alien Language to English
char *translate_sentence(Translator *translator, char *sentence) {
    char *translated_sentence = malloc(strlen(sentence) + 1);
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        char *translation = translate_word(translator, word);
        if (translation != NULL) {
            strcat(translated_sentence, translation);
            strcat(translated_sentence, " ");
        } else {
            strcat(translated_sentence, word);
            strcat(translated_sentence, " ");
        }
        word = strtok(NULL, " ");
    }
    translated_sentence[strlen(translated_sentence) - 1] = '\0';
    return translated_sentence;
}

// A function to print the contents of a Watsonian Alien Language Translator
void print_translator(Translator *translator) {
    for (int i = 0; i < translator->size; i++) {
        printf("%s -> %s\n", translator->dictionary[i], translator->dictionary[i + 1]);
    }
}

// The main function
int main() {
    // Create a Watsonian Alien Language Translator
    char *dictionary[] = {"aba", "and", "ala", "the", "amu", "of", "ana", "in"};
    Translator *translator = create_translator(dictionary, 4);

    // Print the contents of the translator
    print_translator(translator);

    // Translate a sentence from Watsonian Alien Language to English
    char *sentence = "aba ala amu ana";
    char *translated_sentence = translate_sentence(translator, sentence);

    // Print the translated sentence
    printf("Translated sentence: %s\n", translated_sentence);

    return 0;
}