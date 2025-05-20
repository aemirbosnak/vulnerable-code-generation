//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000
#define MAX_DICTIONARY_SIZE 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool isCorrect;
} SpellCheckerWord;

typedef struct {
    SpellCheckerWord *words;
    int numWords;
} SpellCheckerDictionary;

SpellCheckerDictionary *createDictionary() {
    SpellCheckerDictionary *dict = malloc(sizeof(SpellCheckerDictionary));
    dict->numWords = 0;
    dict->words = malloc(MAX_WORDS * sizeof(SpellCheckerWord));
    return dict;
}

void addWordToDictionary(SpellCheckerDictionary *dict, char *word) {
    if (dict->numWords >= MAX_WORDS) {
        printf("Dictionary is full! Cannot add more words.\n");
        return;
    }
    strcpy(dict->words[dict->numWords].word, word);
    dict->words[dict->numWords].isCorrect = true;
    dict->numWords++;
}

bool isCorrect(SpellCheckerDictionary *dict, char *word) {
    int i = 0;
    while (i < dict->numWords && strcmp(dict->words[i].word, word)!= 0) {
        i++;
    }
    if (i == dict->numWords) {
        return false;
    }
    return dict->words[i].isCorrect;
}

void suggestCorrections(SpellCheckerDictionary *dict, char *word) {
    int i = 0;
    while (i < dict->numWords && strcmp(dict->words[i].word, word)!= 0) {
        i++;
    }
    if (i == dict->numWords) {
        printf("No suggestions found.\n");
        return;
    }
    printf("Did you mean %s?\n", dict->words[i].word);
}

int main() {
    SpellCheckerDictionary *dict = createDictionary();
    char word[MAX_WORD_LENGTH];
    char *correctWord = "correct";
    char *incorrectWord = "incorrect";
    char *suggestionWord = "suggestion";

    addWordToDictionary(dict, correctWord);
    addWordToDictionary(dict, incorrectWord);
    addWordToDictionary(dict, suggestionWord);

    printf("Checking %s...\n", correctWord);
    if (isCorrect(dict, correctWord)) {
        printf("%s is correct.\n", correctWord);
    } else {
        suggestCorrections(dict, correctWord);
    }

    printf("Checking %s...\n", incorrectWord);
    if (isCorrect(dict, incorrectWord)) {
        printf("%s is correct.\n", incorrectWord);
    } else {
        suggestCorrections(dict, incorrectWord);
    }

    printf("Checking %s...\n", suggestionWord);
    if (isCorrect(dict, suggestionWord)) {
        printf("%s is correct.\n", suggestionWord);
    } else {
        suggestCorrections(dict, suggestionWord);
    }

    free(dict->words);
    free(dict);
    return 0;
}