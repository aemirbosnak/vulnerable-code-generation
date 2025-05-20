//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Donald Knuth
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 100000
#define TRUE 1
#define FALSE 0

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency *words;
    int size;
} Dictionary;

Dictionary *CreateDictionary() {
    Dictionary *dict = (Dictionary *) malloc(sizeof(Dictionary));
    dict->words = (WordFrequency *) malloc(MAX_DICTIONARY_SIZE * sizeof(WordFrequency));
    dict->size = 0;
    return dict;
}

void AddWord(Dictionary *dict, char *word) {
    int i;
    for (i = 0; i < dict->size; i++) {
        if (strcmp(dict->words[i].word, word) == 0) {
            dict->words[i].frequency++;
            return;
        }
    }
    strcpy(dict->words[dict->size].word, word);
    dict->words[dict->size].frequency = 1;
    dict->size++;
}

int WordExists(Dictionary *dict, char *word) {
    int i;
    for (i = 0; i < dict->size; i++) {
        if (strcmp(dict->words[i].word, word) == 0) {
            return TRUE;
        }
    }
    return FALSE;
}

int main() {
    FILE *inputFile, *outputFile;
    char inputLine[MAX_WORD_LENGTH], word[MAX_WORD_LENGTH];
    Dictionary dict = *CreateDictionary();
    inputFile = fopen("input.txt", "r");
    outputFile = fopen("output.txt", "w");
    while (fgets(inputLine, MAX_WORD_LENGTH, inputFile)!= NULL) {
        char *ptr = strtok(inputLine, " ");
        while (ptr!= NULL) {
            if (isalpha(ptr[0])) {
                strcpy(word, ptr);
                if (!WordExists(&dict, word)) {
                    AddWord(&dict, word);
                }
            }
            ptr = strtok(NULL, " ");
        }
    }
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}