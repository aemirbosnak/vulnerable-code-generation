//FormAI DATASET v1.0 Category: Modern Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char* key;
    char* value;
} KeyValuePair;

typedef struct {
    int size;
    KeyValuePair* pairs;
} Dictionary;

Dictionary* createDictionary(int size) {
    Dictionary* dictionary = malloc(sizeof(Dictionary));
    dictionary->size = size;
    dictionary->pairs = calloc(size, sizeof(KeyValuePair));
    return dictionary;
}

void destroyDictionary(Dictionary* dictionary) {
    for(int i=0; i<dictionary->size; i++) {
        free(dictionary->pairs[i].key);
        free(dictionary->pairs[i].value);
    }
    free(dictionary->pairs);
    free(dictionary);
}

bool hasKey(Dictionary* dictionary, char* key) {
    for(int i=0; i<dictionary->size; i++) {
        if(strcmp(dictionary->pairs[i].key, key) == 0) {
            return true;
        }
    }
    return false;
}

char* getValue(Dictionary* dictionary, char* key) {
    for(int i=0; i<dictionary->size; i++) {
        if(strcmp(dictionary->pairs[i].key, key) == 0) {
            return dictionary->pairs[i].value;
        }
    }
    return NULL;
}

void setValue(Dictionary* dictionary, char* key, char* value) {
    for(int i=0; i<dictionary->size; i++) {
        if(strcmp(dictionary->pairs[i].key, key) == 0) {
            free(dictionary->pairs[i].value);
            dictionary->pairs[i].value = strdup(value);
            return;
        }
    }
    for(int i=0; i<dictionary->size; i++) {
        if(dictionary->pairs[i].key == NULL) {
            dictionary->pairs[i].key = strdup(key);
            dictionary->pairs[i].value = strdup(value);
            return;
        }
    }
}

void printDictionary(Dictionary* dictionary) {
    for(int i=0; i<dictionary->size; i++) {
        if(dictionary->pairs[i].key != NULL) {
            printf("%s: %s\n", dictionary->pairs[i].key, dictionary->pairs[i].value);
        }
    }
}

int main() {
    Dictionary* dictionary = createDictionary(10);
    setValue(dictionary, "name", "Alice");
    setValue(dictionary, "age", "25");
    printDictionary(dictionary);
    printf("%s\n", getValue(dictionary, "name"));
    printf("%s\n", getValue(dictionary, "age"));
    destroyDictionary(dictionary);
    return 0;
}