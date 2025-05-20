//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char *key;
    char *value;
} kv_pair;

typedef struct {
    kv_pair *pairs;
    int size;
} kv_dict;

kv_dict *dict_create() {
    kv_dict *dict = (kv_dict *)malloc(sizeof(kv_dict));
    dict->pairs = NULL;
    dict->size = 0;
    return dict;
}

void dict_destroy(kv_dict *dict) {
    int i;
    for (i = 0; i < dict->size; i++) {
        free(dict->pairs[i].key);
        free(dict->pairs[i].value);
    }
    free(dict->pairs);
    free(dict);
}

int dict_set(kv_dict *dict, char *key, char *value) {
    kv_pair *pair = (kv_pair *)malloc(sizeof(kv_pair));
    pair->key = strdup(key);
    pair->value = strdup(value);
    dict->pairs = (kv_pair *)realloc(dict->pairs, sizeof(kv_pair) * (dict->size + 1));
    dict->pairs[dict->size++] = *pair;
    return 0;
}

char *dict_get(kv_dict *dict, char *key) {
    int i;
    for (i = 0; i < dict->size; i++) {
        if (strcmp(dict->pairs[i].key, key) == 0) {
            return dict->pairs[i].value;
        }
    }
    return NULL;
}

int main() {
    kv_dict *dict = dict_create();
    dict_set(dict, "hello", "world");
    dict_set(dict, "name", "Alice");
    char *value = dict_get(dict, "hello");
    printf("%s\n", value);
    dict_destroy(dict);
    return 0;
}