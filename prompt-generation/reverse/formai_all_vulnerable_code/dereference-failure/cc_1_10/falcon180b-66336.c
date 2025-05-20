//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VAL_LENGTH 1000
#define MAX_NUM_KEYS 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char val[MAX_VAL_LENGTH];
} key_val;

typedef struct {
    int num_keys;
    key_val keys[MAX_NUM_KEYS];
} db_index;

db_index* create_db_index() {
    db_index* index = (db_index*) malloc(sizeof(db_index));
    index->num_keys = 0;
    return index;
}

void add_key_val_to_db_index(db_index* index, char* key, char* val) {
    if (index->num_keys >= MAX_NUM_KEYS) {
        printf("Error: Index is full.\n");
        return;
    }

    strcpy(index->keys[index->num_keys].key, key);
    strcpy(index->keys[index->num_keys].val, val);
    index->num_keys++;
}

void print_db_index(db_index* index) {
    for (int i = 0; i < index->num_keys; i++) {
        printf("Key: %s, Value: %s\n", index->keys[i].key, index->keys[i].val);
    }
}

int main() {
    db_index* index = create_db_index();

    add_key_val_to_db_index(index, "Name", "John");
    add_key_val_to_db_index(index, "Age", "25");
    add_key_val_to_db_index(index, "City", "New York");

    print_db_index(index);

    return 0;
}