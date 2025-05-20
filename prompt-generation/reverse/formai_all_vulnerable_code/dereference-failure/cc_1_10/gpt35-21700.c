//FormAI DATASET v1.0 Category: Educational ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1000

typedef struct {
    char* key;
    char* value;
} Entry;

typedef struct {
    Entry** table;
    int size;
} Dictionary;

unsigned int hash(char* str) {
    unsigned int hashVal = 0;
    while (*str != '\0') {
        hashVal = (hashVal << 5) + *str++;
    }
    return hashVal % TABLE_SIZE;
}

Dictionary* newDictionary(int size) {
    Dictionary* dict = (Dictionary*) malloc(sizeof(Dictionary));
    dict->table = (Entry**) calloc(size, sizeof(Entry*));
    dict->size = size;
    return dict;
}

void freeDictionary(Dictionary* dict) {
    for (int i = 0; i < dict->size; i++) {
        if (dict->table[i] != NULL) {
            free(dict->table[i]->key);
            free(dict->table[i]->value);
            free(dict->table[i]);
        }
    }
    free(dict->table);
    free(dict);
}

Entry* newEntry(char* key, char* value) {
    Entry* entry = (Entry*) malloc(sizeof(Entry));
    entry->key = (char*) malloc(strlen(key) + 1);
    strcpy(entry->key, key);
    entry->value = (char*) malloc(strlen(value) + 1);
    strcpy(entry->value, value);
    return entry;
}

void put(Dictionary* dict, char* key, char* value) {
    Entry* entry = newEntry(key, value);
    int index = hash(key);

    for (int i = 0, j = 1; i < dict->size; i++, j++) {
        if (i == index) continue;
        if (dict->table[i] == NULL) {
            dict->table[i] = entry;
            return;
        }

        int k = (index + j*j) % dict->size;
        if (dict->table[k] == NULL) {
            dict->table[k] = entry;
            return;
        }
    }

    printf("Dictionary full. Unable to add entry.\n");
}

char* get(Dictionary* dict, char* key) {
    int index = hash(key);

    for (int i = 0, j = 1; i < dict->size; i++, j++) {
        if (i == index) continue;
        if (dict->table[i] == NULL) return NULL;

        int k = (index + j*j) % dict->size;
        if (dict->table[k] == NULL) return NULL;
        if (strcmp(dict->table[k]->key, key) == 0) {
            return dict->table[k]->value;
        }
    }

    return NULL;
}

int main() {
    Dictionary* dict = newDictionary(TABLE_SIZE);
    put(dict, "apple", "A sweet fruit");
    put(dict, "banana", "A yellow fruit");
    put(dict, "cherry", "A red fruit");

    char* val = get(dict, "banana");
    if (val != NULL) {
        printf("Value for 'banana': %s\n", val);
    } else {
        printf("No value for 'banana'.\n");
    }

    freeDictionary(dict);
    return 0;
}