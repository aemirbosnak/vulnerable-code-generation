//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 1000

// A magical structure to hold our dictionary
typedef struct {
    char words[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int count;
} Dictionary;

// Function to create a new dictionary
Dictionary* create_dictionary() {
    Dictionary* dict = (Dictionary*)malloc(sizeof(Dictionary));
    dict->count = 0;
    return dict;
}

// Function to add a word into the dictionary
void add_word(Dictionary* dict, const char* word) {
    if (dict->count < DICTIONARY_SIZE) {
        strcpy(dict->words[dict->count], word);
        dict->count++;
    }
}

// Function to check if a word exists in the dictionary
int check_word(Dictionary* dict, const char* word) {
    for (int i = 0; i < dict->count; i++) {
        if (strcasecmp(dict->words[i], word) == 0) {
            return 1; // The word is found!
        }
    }
    return 0; // The word was lost in the forest of words!
}

// Function to load the dictionary with some enchanting words
void load_dictionary(Dictionary* dict) {
    // A few magical words to keep our dictionary lively
    char* sample_words[] = {
        "enchant", "wonder", "magical", "spell", "dream", 
        "adventure", "fantasy", "forest", "fable", "myth",
        "journey", "whimsical", "spellbound", "charm", "serendipity"
    };
    for (int i = 0; i < sizeof(sample_words) / sizeof(sample_words[0]); i++) {
        add_word(dict, sample_words[i]);
    }
}

// Function to release the memory of the dictionary
void destroy_dictionary(Dictionary* dict) {
    free(dict);
}

// A spell checker function that casts its checking wand!
void check_spelling(Dictionary* dict) {
    char input[MAX_WORD_LENGTH];
    printf("Speak your words (type 'exit' to end the incantation):\n");

    while (1) {
        printf("> ");
        scanf("%s", input);

        if (strcasecmp(input, "exit") == 0) {
            printf("Ending the spell-checking journey... Farewell!\n");
            break;
        }

        if (check_word(dict, input)) {
            printf("✔️ '%s' is a magical word!\n", input);
        } else {
            printf("❌ '%s' is not found in the enchanted dictionary!\n", input);
        }
    }
}

int main() {
    // A tale begins!
    printf("Welcome to the Enchanted Spell Checker!\n");
    Dictionary* dictionary = create_dictionary();

    // Load our enchanted words into the dictionary
    load_dictionary(dictionary);

    // Let the spell-checking commence!
    check_spelling(dictionary);

    // Clean up after our magical adventure
    destroy_dictionary(dictionary);

    return 0;
}