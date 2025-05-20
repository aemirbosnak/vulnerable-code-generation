//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000
#define MAX_NUM_KEYS 100
#define MAX_NUM_VALUES 1000

typedef struct {
    char *key;
    char *value;
} key_value;

int num_keys = 0;
int num_values = 0;
key_value *key_value_array = NULL;

void initialize_key_value_array() {
    key_value_array = (key_value *) malloc(MAX_NUM_KEYS * sizeof(key_value));
    for (int i = 0; i < MAX_NUM_KEYS; i++) {
        key_value_array[i].key = NULL;
        key_value_array[i].value = NULL;
    }
    num_keys = 0;
    num_values = 0;
}

void add_key_value(char *key, char *value) {
    if (num_keys == MAX_NUM_KEYS) {
        printf("Error: Maximum number of keys reached.\n");
        return;
    }
    if (num_values == MAX_NUM_VALUES) {
        printf("Error: Maximum number of values reached.\n");
        return;
    }
    key_value_array[num_keys].key = (char *) malloc(strlen(key) + 1);
    strcpy(key_value_array[num_keys].key, key);
    key_value_array[num_keys].value = (char *) malloc(strlen(value) + 1);
    strcpy(key_value_array[num_keys].value, value);
    num_keys++;
    num_values++;
}

void print_key_value_array() {
    for (int i = 0; i < num_keys; i++) {
        printf("Key: %s, Value: %s\n", key_value_array[i].key, key_value_array[i].value);
    }
}

int main() {
    initialize_key_value_array();
    add_key_value("apple", "red");
    add_key_value("banana", "yellow");
    add_key_value("cherry", "red");
    print_key_value_array();
    return 0;
}