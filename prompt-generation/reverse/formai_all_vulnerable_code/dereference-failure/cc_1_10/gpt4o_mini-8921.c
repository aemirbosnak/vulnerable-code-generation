//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a word translation
typedef struct {
    char *english;
    char *alien;
} Translation;

// Define a list of translations
Translation dictionary[] = {
    {"hello", "grox"},
    {"world", "tharg"},
    {"friend", "zork"},
    {"alien", "tykron"},
    {"language", "bloop"},
    {"computer", "kree"},
    {"universe", "snarg"},
    {"program", "mork"},
    {"code", "blip"},
    {"translate", "florp"},
    {"yes", "naf"},
    {"no", "zuul"},
    {"please", "ork"},
    {"thank you", "vree"},
    {"goodbye", "squob"}
};

// Function to translate a word
char* translate_word(const char* word) {
    for (int i = 0; i < sizeof(dictionary) / sizeof(dictionary[0]); i++) {
        if (strcmp(word, dictionary[i].english) == 0) {
            return dictionary[i].alien;
        }
    }
    return NULL; // Return NULL if no translation found
}

// Function to translate an entire sentence
void translate_sentence(const char *sentence) {
    char *token;
    char *sentence_copy = malloc(strlen(sentence) + 1);
    strcpy(sentence_copy, sentence);
    
    token = strtok(sentence_copy, " ");
    while (token != NULL) {
        char *translation = translate_word(token);
        if (translation != NULL) {
            printf("%s ", translation);
        } else {
            printf("%s ", token); // Print the original word if no translation is found
        }
        token = strtok(NULL, " ");
    }
    free(sentence_copy);
}

int main() {
    char input[256];

    printf("Welcome to the Alien Language Translator!\n");
    printf("Enter a sentence in English to translate to Alien language:\n");
    
    while (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove newline character from input if present
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "quit") == 0) {
            printf("Exiting the translator. Goodbye!\n");
            break;
        }

        printf("Translation: ");
        translate_sentence(input);
        printf("\nEnter another sentence (or type 'quit' to exit):\n");
    }

    return 0;
}