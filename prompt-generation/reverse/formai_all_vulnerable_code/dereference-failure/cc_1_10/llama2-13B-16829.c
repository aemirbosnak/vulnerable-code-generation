//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 50

// Declare a magic spellbook with a bunch of spells to check for
struct spell {
    const char *name;
    const char *definition;
};

// Define some spells to check for
struct spell spells[] = {
    {"abracadabra", "a word used by wizards to cast a spell"},
    {"hocuspocus", "a phrase used by wizards to focus their magic"},
    {"magicmissile", "a spell that shoots a magical projectile at an enemy"},
    {"flyingcarpet", "a spell that summons a flying carpet to take you on a wild ride"},
    {"invisiblity", "a spell that makes the caster invisible"},
};

// Declare a function to check if a word is a valid spell
int is_spell(const char *word) {
    // Iterate through the list of spells and check if the word is a match
    for (int i = 0; i < sizeof(spells) / sizeof(spells[0]); i++) {
        if (strcmp(word, spells[i].name) == 0) {
            return 1;
        }
    }
    return 0;
}

// Declare a function to check the spelling of a word
int check_spelling(const char *word) {
    // Iterate through the letters of the word and check if they are correct
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] != toupper(word[i])) {
            return 0;
        }
    }
    return 1;
}

// Declare a function to check the sentence for spelling errors
int check_sentence(const char *sentence) {
    // Iterate through the words in the sentence and check if they are spelled correctly
    for (int i = 0; i < strlen(sentence); i++) {
        if (!check_spelling(sentence[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // Prompt the user to enter a sentence
    printf("Enter a sentence to check for spelling errors:\n");
    char sentence[MAX_SENTENCE_LENGTH];
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Check the sentence for spelling errors
    if (!check_sentence(sentence)) {
        printf("Oops! I found a spelling error in your sentence!\n");
    } else {
        printf("Well done! Your sentence is spelled correctly!\n");
    }

    // Ask the user to enter a word to check for spelling
    printf("Enter a word to check for spelling:\n");
    char word[MAX_WORD_LENGTH];
    fgets(word, MAX_WORD_LENGTH, stdin);

    // Check if the word is a valid spell
    if (is_spell(word)) {
        printf("Oh my! I think you've cast a spell! Well done, wizard!\n");
    } else {
        printf("That's not a valid spell. Try again, young wizard.\n");
    }

    return 0;
}