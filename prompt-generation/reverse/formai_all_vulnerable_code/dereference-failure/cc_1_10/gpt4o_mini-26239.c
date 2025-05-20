//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a simple dictionary entry
typedef struct {
    char* word;
    char* definition;
} DictionaryEntry;

// Function to create a new dictionary entry
DictionaryEntry* createEntry(const char* word, const char* definition) {
    DictionaryEntry* entry = (DictionaryEntry*)malloc(sizeof(DictionaryEntry));
    if (!entry) {
        perror("Failed to allocate memory for dictionary entry");
        return NULL;
    }
    
    entry->word = (char*)malloc(strlen(word) + 1);
    entry->definition = (char*)malloc(strlen(definition) + 1);

    if (!entry->word || !entry->definition) {
        perror("Failed to allocate memory for word or definition");
        free(entry->word);
        free(entry->definition);
        free(entry);
        return NULL;
    }

    strcpy(entry->word, word);
    strcpy(entry->definition, definition);

    return entry;
}

// Function to free the memory allocated for a dictionary entry
void freeEntry(DictionaryEntry* entry) {
    if (entry) {
        free(entry->word);
        free(entry->definition);
        free(entry);
    }
}

// Function to create a simple dictionary
typedef struct {
    DictionaryEntry** entries;
    size_t size;
} Dictionary;

// Function to initialize a dictionary
Dictionary* createDictionary() {
    Dictionary* dict = (Dictionary*)malloc(sizeof(Dictionary));
    if (!dict) {
        perror("Failed to allocate memory for dictionary");
        return NULL;
    }
    
    dict->size = 0;
    dict->entries = NULL;

    return dict;
}

// Function to add an entry to the dictionary
void addEntry(Dictionary* dict, const char* word, const char* definition) {
    dict->entries = (DictionaryEntry**)realloc(dict->entries, (dict->size + 1) * sizeof(DictionaryEntry*));
    if (!dict->entries) {
        perror("Failed to reallocate memory for dictionary entries");
        return;
    }

    DictionaryEntry* newEntry = createEntry(word, definition);
    if (newEntry) {
        dict->entries[dict->size] = newEntry;
        dict->size++;
    }
}

// Function to print the dictionary entries
void printDictionary(Dictionary* dict) {
    for (size_t i = 0; i < dict->size; i++) {
        printf("%s: %s\n", dict->entries[i]->word, dict->entries[i]->definition);
    }
}

// Free memory allocated for the dictionary
void freeDictionary(Dictionary* dict) {
    if (dict) {
        for (size_t i = 0; i < dict->size; i++) {
            freeEntry(dict->entries[i]);
        }
        free(dict->entries);
        free(dict);
    }
}

int main() {
    Dictionary* myDictionary = createDictionary();
    if (!myDictionary) {
        return EXIT_FAILURE;
    }

    addEntry(myDictionary, "memory", "the faculty by which the mind stores and remembers information");
    addEntry(myDictionary, "pointer", "a variable that stores the memory address of another variable");
    addEntry(myDictionary, "dynamic", "characterized by constant change, activity, or progress");

    printf("My Dictionary:\n");
    printDictionary(myDictionary);

    // Clean up memory at the end
    freeDictionary(myDictionary);

    return EXIT_SUCCESS;
}