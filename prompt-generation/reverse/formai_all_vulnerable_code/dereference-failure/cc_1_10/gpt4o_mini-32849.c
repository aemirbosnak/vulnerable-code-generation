//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

typedef struct {
    char english[50];
    char alien[50];
} DictionaryEntry;

typedef struct {
    DictionaryEntry *entries;
    size_t size;
    size_t capacity;
} Dictionary;

void initDictionary(Dictionary *dict) {
    dict->size = 0;
    dict->capacity = 10;
    dict->entries = (DictionaryEntry *)malloc(dict->capacity * sizeof(DictionaryEntry));
}

void freeDictionary(Dictionary *dict) {
    free(dict->entries);
}

void addEntry(Dictionary *dict, const char *english, const char *alien) {
    if (dict->size >= dict->capacity) {
        dict->capacity *= 2;
        dict->entries = (DictionaryEntry *)realloc(dict->entries, dict->capacity * sizeof(DictionaryEntry));
    }
    strcpy(dict->entries[dict->size].english, english);
    strcpy(dict->entries[dict->size].alien, alien);
    dict->size++;
}

const char* translate(Dictionary *dict, const char *word) {
    for (size_t i = 0; i < dict->size; i++) {
        if (strcmp(dict->entries[i].english, word) == 0) {
            return dict->entries[i].alien;
        }
    }
    return NULL;
}

void loadDictionary(Dictionary *dict, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char english[50], alien[50];
    while (fscanf(file, "%49s %49s", english, alien) == 2) {
        addEntry(dict, english, alien);
    }
    fclose(file);
}

void printDictionary(Dictionary *dict) {
    printf("=== Alien Language Dictionary ===\n");
    for (size_t i = 0; i < dict->size; i++) {
        printf("%s -> %s\n", dict->entries[i].english, dict->entries[i].alien);
    }
}

void translateText(Dictionary *dict, const char *input) {
    char word[MAX_LENGTH];
    char *token = strtok(input, " ");
    while (token != NULL) {
        const char *translation = translate(dict, token);
        if (translation != NULL) {
            printf("%s ", translation);
        } else {
            printf("%s ", token); // Print original if no translation found
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}


int main() {
    Dictionary dict;
    initDictionary(&dict);

    // Load the dictionary from a file
    loadDictionary(&dict, "alien_language.txt");

    // Print the loaded dictionary
    printDictionary(&dict);

    char input[MAX_LENGTH];
    printf("Enter a sentence to translate into Alien Language:\n");
    fgets(input, MAX_LENGTH, stdin);
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    printf("Translation:\n");
    translateText(&dict, input);

    freeDictionary(&dict);
    return 0;
}