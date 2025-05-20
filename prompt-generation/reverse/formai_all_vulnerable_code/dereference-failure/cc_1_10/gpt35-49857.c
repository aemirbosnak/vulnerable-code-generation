//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100
#define MAX_DICTIONARY_ENTRIES 10

/*
 * Struct for holding translation dictionary entries.
 */
typedef struct TranslationEntry {
    char* c_cat_word;
    char* english_translation;
} TranslationEntry;

/*
 * Function to translate a single word according to the provided dictionary.
 * Returns the translated word.
 */
char* translate_word(char* c_cat_word, TranslationEntry* dictionary, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(c_cat_word, dictionary[i].c_cat_word) == 0) {
            return dictionary[i].english_translation;
        }
    }
    return "UNTRANSLATABLE";
}

/*
 * Function to translate a complete sentence according to the provided dictionary.
 * Returns the translated sentence.
 */
char* translate_sentence(char* c_cat_sentence, TranslationEntry* dictionary, int num_entries) {
    char* token = strtok(c_cat_sentence, " ");
    char* translation = malloc(sizeof(char) * MAX_BUFFER_SIZE);
    memset(translation, 0, MAX_BUFFER_SIZE);

    while (token != NULL) {
        strcat(translation, translate_word(token, dictionary, num_entries));
        strcat(translation, " ");
        token = strtok(NULL, " ");
    }

    return translation;
}

/*
 * Main function to run the translator program.
 */
int main() {
    // Define and initialize dictionary entries.
    TranslationEntry dictionary[MAX_DICTIONARY_ENTRIES] = {
        {"meow", "hello"},
        {"purr", "goodbye"},
        {"hiss", "sorry"},
        {"kitten", "child"},
        {"feline", "cat"},
        {"litter", "cats"},
        {"mouse", "toy"},
        {"fish", "food"},
        {"nap", "sleep"},
        {"hunt", "play"}
    };

    // Get user input.
    char* c_cat_sentence = malloc(sizeof(char) * MAX_BUFFER_SIZE);
    printf("Enter a sentence in C Cat language:\n");
    fgets(c_cat_sentence, MAX_BUFFER_SIZE, stdin);

    // Remove newline character from input.
    if (c_cat_sentence[strlen(c_cat_sentence) - 1] == '\n') {
        c_cat_sentence[strlen(c_cat_sentence) - 1] = '\0';
    }

    // Translate sentence and print result.
    char* english_sentence = translate_sentence(c_cat_sentence, dictionary, MAX_DICTIONARY_ENTRIES);
    printf("In English, that means: %s\n", english_sentence);

    return 0;
}