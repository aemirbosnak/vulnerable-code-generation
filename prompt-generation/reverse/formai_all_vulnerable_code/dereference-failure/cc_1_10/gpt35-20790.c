//FormAI DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYS 10
#define KEY_LENGTH 20
#define VALUE_LENGTH 100

typedef struct {
    char key[KEY_LENGTH];
    char value[VALUE_LENGTH];
} KeyValue;

typedef struct {
    KeyValue *key_value;
    int count;
} Bucket;

typedef struct {
    Bucket *buckets;
    int size;
} Index;

Index *create_index(int size) {
    Index *index = (Index *) malloc(sizeof(Index));
    index->buckets = (Bucket *) malloc(sizeof(Bucket) * size);
    index->size = size;
    int i;
    for (i = 0; i < size; i++) {
        index->buckets[i].key_value = NULL;
        index->buckets[i].count = 0;
    }
    return index;
}

int hash_code(char *key) {
    int i, sum;
    sum = 0;
    for (i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % MAX_KEYS;
}

void add_key_value(Index *index, char *key, char *value) {
    int index_position = hash_code(key);
    Bucket *bucket = &(index->buckets[index_position]);
    if (bucket->key_value == NULL) {
        bucket->key_value = (KeyValue *) malloc(sizeof(KeyValue));
        bucket->count = 1;
    } else {
        bucket->count++;
        bucket->key_value = (KeyValue *) realloc(bucket->key_value, sizeof(KeyValue) * bucket->count);
    }
    KeyValue *key_value = &(bucket->key_value[bucket->count - 1]);
    strncpy(key_value->key, key, KEY_LENGTH);
    strncpy(key_value->value, value, VALUE_LENGTH);
}

int main() {
    Index *index = create_index(MAX_KEYS);

    add_key_value(index, "apple", "a fruit");
    add_key_value(index, "banana", "a fruit");
    add_key_value(index, "carrot", "a vegetable");
    add_key_value(index, "dog", "an animal");

    printf("Index size: %d\n", index->size);
    printf("Bucket size: %d\n", sizeof(Bucket));
    printf("Bucket key value size: %d\n", sizeof(KeyValue));

    int i, j;
    for (i = 0; i < index->size; i++) {
        Bucket bucket = index->buckets[i];
        if (bucket.key_value == NULL) {
            printf("Bucket %d is empty\n", i);
        } else {
            printf("Bucket %d:\n", i);
            for (j = 0; j < bucket.count; j++) {
                KeyValue *key_value = &(bucket.key_value[j]);
                printf("\t%s => %s\n", key_value->key, key_value->value);
            }
        }
    }

    return 0;
}