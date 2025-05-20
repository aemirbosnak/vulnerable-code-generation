//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Structure to store a word and its occurrences
typedef struct {
    char word[MAX_WORD_LENGTH];
    int occurrences;
} WordCount;

int loadDictionary(const char *filename, WordCount **dictionary);
void checkSpelling(const char *inputFile, WordCount *dictionary, int wordCount);
void toLowerCase(char *str);
int isWordInDictionary(const char *word, WordCount *dictionary, int wordCount);
void printMisspelledWords(const char *filename, WordCount *dictionary, int wordCount);

int main() {
    printf("🎉 Welcome to the Cheerful C Spell Checker! 🎉\n");

    const char *dictFile = "dictionary.txt";
    WordCount *dictionary = NULL;
    int wordCount = loadDictionary(dictFile, &dictionary);

    if (wordCount == -1) {
        printf("Oops! There was a problem loading the dictionary. Please check the file.\n");
        return 1;
    }

    printf("Hooray! Loaded %d words from the dictionary.\n", wordCount);
    
    const char *inputFile = "input.txt";
    checkSpelling(inputFile, dictionary, wordCount);

    // Clean up
    free(dictionary);
    printf("Thank you for using the Cheerful C Spell Checker! 🎈\n");
    
    return 0;
}

int loadDictionary(const char *filename, WordCount **dictionary) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return -1;
    }
    
    *dictionary = malloc(MAX_WORDS * sizeof(WordCount));
    int wordCount = 0;

    while (fscanf(file, "%s", (*dictionary)[wordCount].word) != EOF) {
        (*dictionary)[wordCount].occurrences = 0; // Initialize occurrences to 0
        wordCount++;
        if (wordCount >= MAX_WORDS) {
            break;
        }
    }

    fclose(file);
    return wordCount;
}

void checkSpelling(const char *inputFile, WordCount *dictionary, int wordCount) {
    FILE *file = fopen(inputFile, "r");
    if (!file) {
        printf("Oops! Can't find the input file. Please check the file name.\n");
        return;
    }

    char word[MAX_WORD_LENGTH];
    printf("Let's check the spelling of words from %s! 📝\n", inputFile);
    
    while (fscanf(file, "%s", word) != EOF) {
        toLowerCase(word);
        if (!isWordInDictionary(word, dictionary, wordCount)) {
            printf("😱 Misspelled word found: %s\n", word);
            // Increment occurrence for misspelled word
            for (int i = 0; i < wordCount; i++) {
                if (strcmp(dictionary[i].word, word) == 0) {
                    dictionary[i].occurrences++;
                }
            }
        }
    }
    
    fclose(file);
    printMisspelledWords(inputFile, dictionary, wordCount);
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isWordInDictionary(const char *word, WordCount *dictionary, int wordCount) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return 1; // Word found in dictionary
        }
    }
    return 0; // Word not found
}

void printMisspelledWords(const char *filename, WordCount *dictionary, int wordCount) {
    printf("Let's summarize the misspelled words found in %s! 📜\n", filename);

    int hasMisspelled = 0;
    for (int i = 0; i < wordCount; i++) {
        if (dictionary[i].occurrences > 0) {
            printf("🔴 Word: %s, Occurrences: %d\n", dictionary[i].word, dictionary[i].occurrences);
            hasMisspelled = 1;
        }
    }

    if (!hasMisspelled) {
        printf("🎉 All words are spelled correctly! 🎉\n");
    } else {
        printf("Please check the above words and correct them. Happy writing! 🖋️\n");
    }
}