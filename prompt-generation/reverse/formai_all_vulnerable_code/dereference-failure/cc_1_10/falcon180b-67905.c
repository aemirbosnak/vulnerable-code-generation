//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DICT_SIZE 1000

// Struct to store dictionary entries
typedef struct {
    char *key;
    int value;
} DictEntry;

// Struct to represent a dictionary
typedef struct {
    DictEntry *entries;
    int size;
    int capacity;
} Dictionary;

// Function to create a new dictionary
Dictionary* dict_create() {
    Dictionary *dict = malloc(sizeof(Dictionary));
    dict->entries = malloc(MAX_DICT_SIZE * sizeof(DictEntry));
    dict->size = 0;
    dict->capacity = MAX_DICT_SIZE;
    return dict;
}

// Function to destroy a dictionary
void dict_destroy(Dictionary *dict) {
    free(dict->entries);
    free(dict);
}

// Function to add an entry to the dictionary
void dict_add(Dictionary *dict, char *key, int value) {
    if (dict->size == dict->capacity) {
        dict->capacity *= 2;
        dict->entries = realloc(dict->entries, dict->capacity * sizeof(DictEntry));
    }
    dict->entries[dict->size].key = strdup(key);
    dict->entries[dict->size].value = value;
    dict->size++;
}

// Function to look up a value in the dictionary
int dict_lookup(Dictionary *dict, char *key) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->entries[i].key, key) == 0) {
            return dict->entries[i].value;
        }
    }
    return -1;
}

// Function to encode a string using the dictionary
char* dict_encode(Dictionary *dict, char *input) {
    char *output = malloc(strlen(input) + 1);
    int pos = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (dict_lookup(dict, input + i)!= -1) {
            sprintf(output + pos, "%d", dict_lookup(dict, input + i));
            pos += 2;
        } else {
            output[pos++] = input[i];
        }
    }
    output[pos] = '\0';
    return output;
}

// Function to decode a string using the dictionary
char* dict_decode(Dictionary *dict, char *input) {
    char *output = malloc(strlen(input) * 2 + 1);
    int pos = 0;
    while (input[pos]!= '\0') {
        if (isdigit(input[pos])) {
            int value = input[pos] - '0';
            DictEntry *entry = dict_lookup(dict, "");
            if (entry!= NULL) {
                sprintf(output + pos * 2, "%c", entry->key[value]);
            } else {
                output[pos * 2] = input[pos];
            }
            pos++;
        } else {
            output[pos * 2] = input[pos];
            pos++;
        }
    }
    output[pos * 2] = '\0';
    return output;
}

// Function to print a dictionary
void dict_print(Dictionary *dict) {
    for (int i = 0; i < dict->size; i++) {
        printf("%s -> %d\n", dict->entries[i].key, dict->entries[i].value);
    }
}

int main() {
    Dictionary *dict = dict_create();
    dict_add(dict, "hello", 1);
    dict_add(dict, "world", 2);
    dict_add(dict, "foo", 3);
    dict_add(dict, "bar", 4);
    dict_print(dict);
    char *encoded = dict_encode(dict, "hello world foo bar");
    printf("Encoded: %s\n", encoded);
    char *decoded = dict_decode(dict, encoded);
    printf("Decoded: %s\n", decoded);
    dict_destroy(dict);
    return 0;
}