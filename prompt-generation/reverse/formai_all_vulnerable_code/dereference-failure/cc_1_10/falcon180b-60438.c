//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

// Define the data structure for the dictionary
typedef struct {
    char word[MAX_STRING_LENGTH];
    char translation[MAX_STRING_LENGTH];
} DictionaryEntry;

// Define the data structure for the dictionary
typedef struct {
    int size;
    int capacity;
    DictionaryEntry* entries;
} Dictionary;

// Function to initialize the dictionary
void initDictionary(Dictionary* dict) {
    dict->size = 0;
    dict->capacity = 10;
    dict->entries = (DictionaryEntry*)malloc(dict->capacity * sizeof(DictionaryEntry));
}

// Function to add a word and its translation to the dictionary
void addWord(Dictionary* dict, char* word, char* translation) {
    if (dict->size >= dict->capacity) {
        dict->capacity *= 2;
        dict->entries = (DictionaryEntry*)realloc(dict->entries, dict->capacity * sizeof(DictionaryEntry));
    }

    strcpy(dict->entries[dict->size].word, word);
    strcpy(dict->entries[dict->size].translation, translation);

    dict->size++;
}

// Function to search for a word in the dictionary
int searchDictionary(Dictionary* dict, char* word) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->entries[i].word, word) == 0) {
            return i;
        }
    }

    return -1;
}

// Function to print the dictionary
void printDictionary(Dictionary* dict) {
    printf("Dictionary:\n");
    for (int i = 0; i < dict->size; i++) {
        printf("%s -> %s\n", dict->entries[i].word, dict->entries[i].translation);
    }
}

// Function to translate a sentence
void translateSentence(Dictionary* dict, char* sentence) {
    char* word = strtok(sentence, " ");
    while (word!= NULL) {
        int index = searchDictionary(dict, word);
        if (index!= -1) {
            printf("%s ", dict->entries[index].translation);
        } else {
            printf("%s ", word);
        }

        word = strtok(NULL, " ");
    }
}

int main() {
    Dictionary dict;
    initDictionary(&dict);

    addWord(&dict, "cat", "gato");
    addWord(&dict, "dog", "perro");
    addWord(&dict, "hello", "hola");

    printDictionary(&dict);

    translateSentence(&dict, "Hello, how are you, my dear cat?");

    return 0;
}