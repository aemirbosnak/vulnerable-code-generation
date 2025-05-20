//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 100
#define MAX_VAL_LEN 1000
#define MAX_NUM_KEYS 100

typedef struct {
    char* key;
    char* val;
} KeyVal;

typedef struct {
    KeyVal* keys;
    int num_keys;
} Index;

Index* create_index() {
    Index* index = (Index*) malloc(sizeof(Index));
    index->keys = (KeyVal*) malloc(MAX_NUM_KEYS * sizeof(KeyVal));
    index->num_keys = 0;
    return index;
}

void destroy_index(Index* index) {
    for (int i = 0; i < index->num_keys; i++) {
        free(index->keys[i].key);
        free(index->keys[i].val);
    }
    free(index->keys);
    free(index);
}

void add_key_val(Index* index, char* key, char* val) {
    if (index->num_keys >= MAX_NUM_KEYS) {
        printf("Error: Index is full.\n");
        return;
    }

    KeyVal* new_key_val = (KeyVal*) malloc(sizeof(KeyVal));
    new_key_val->key = strdup(key);
    new_key_val->val = strdup(val);

    index->keys[index->num_keys++] = *new_key_val;
}

char* get_val_by_key(Index* index, char* key) {
    for (int i = 0; i < index->num_keys; i++) {
        if (strcmp(index->keys[i].key, key) == 0) {
            return index->keys[i].val;
        }
    }
    return NULL;
}

int main() {
    Index* index = create_index();

    add_key_val(index, "apple", "red");
    add_key_val(index, "banana", "yellow");
    add_key_val(index, "cherry", "red");

    char* val_by_key_apple = get_val_by_key(index, "apple");
    printf("Value by key 'apple': %s\n", val_by_key_apple);

    destroy_index(index);

    return 0;
}