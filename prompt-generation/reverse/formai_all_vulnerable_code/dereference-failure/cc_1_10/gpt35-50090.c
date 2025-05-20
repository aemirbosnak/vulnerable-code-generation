//FormAI DATASET v1.0 Category: Spell checking ; Style: complete
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50 // Maximum length of a word in the dictionary

char *dictionary[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "indigo", "jujube", "kiwi", "lemon", "mango", "nectarine", "orange", "pear", "quince", "raspberry", "strawberry", "tangerine", "ume", "vanilla", "watermelon", "xigua", "yellowberry", "zucchini"}; // Example dictionary of words to check against

bool isWordInDictionary(char *word, int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return true;
        }
    }
    return false;
}

char *formatWord(char *word) {
    int len = strlen(word);
    char *formattedWord = malloc(len * sizeof(char)); // Dynamic allocation of memory for formatted word
    for (int i = 0; i < len; i++) {
        formattedWord[i] = tolower(word[i]);
    }
    return formattedWord;
}

int main() {
    char input[MAX_WORD_LEN];
    int dictSize = sizeof(dictionary) / sizeof(dictionary[0]);
    while (true) {
        printf("Enter a word to spell check (type 'exit' to quit): ");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        char *formattedInput = formatWord(input);
        bool isInDictionary = isWordInDictionary(formattedInput, dictSize);
        if (isInDictionary) {
            printf("%s is spelled correctly!\n", input);
        } else {
            printf("%s is misspelled. Did you mean ", input);
            for (int i = 0; i < dictSize; i++) {
                char *formattedDictionaryWord = formatWord(dictionary[i]);
                int matchLength = strlen(formattedDictionaryWord) < MAX_WORD_LEN ? strlen(formattedDictionaryWord) : MAX_WORD_LEN; // Ensure we're only comparing up to the max word length
                if (strncmp(formattedDictionaryWord, formattedInput, matchLength) == 0) { // Compare the input word to each word in the dictionary
                    printf("%s? ", dictionary[i]);
                }
                free(formattedDictionaryWord); // Free dynamically allocated memory for temp formatted dictionary word
            }
            printf("\n");
        }
        free(formattedInput); // Free dynamically allocated memory for formatted input word
    }
    return 0;
}