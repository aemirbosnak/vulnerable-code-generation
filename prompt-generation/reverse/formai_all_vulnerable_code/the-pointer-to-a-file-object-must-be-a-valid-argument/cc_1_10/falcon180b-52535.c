//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100

// Function to check if a word is in the dictionary
bool is_word(char* word) {
    FILE* dictionary = fopen("dictionary.txt", "r");
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, dictionary)!= NULL) {
        char* dictionary_word = strtok(line, "\n");
        if (strcmp(dictionary_word, word) == 0) {
            fclose(dictionary);
            return true;
        }
    }
    fclose(dictionary);
    return false;
}

// Function to suggest corrections for a misspelled word
void suggest_corrections(char* word) {
    char corrected_word[MAX_WORD_LENGTH];
    strcpy(corrected_word, word);
    char* current_char = corrected_word;
    while (*current_char!= '\0') {
        if (isalpha(*current_char)) {
            int i = 0;
            while (i < strlen(corrected_word) && isalpha(corrected_word[i])) {
                i++;
            }
            if (i == strlen(corrected_word)) {
                *current_char = tolower(*current_char);
            }
        }
        current_char++;
    }
    printf("Did you mean: %s?\n", corrected_word);
}

// Function to spell check a sentence
void spell_check(char* sentence) {
    char* word = strtok(sentence, " ");
    while (word!= NULL) {
        if (!is_word(word)) {
            suggest_corrections(word);
        }
        word = strtok(NULL, " ");
    }
}

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);
    spell_check(sentence);
    return 0;
}