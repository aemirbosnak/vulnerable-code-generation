//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 100003
#define HASH_FUNCTION(x) ((x % TABLE_SIZE) + (x < 0 ? TABLE_SIZE : 0))

typedef struct Node {
    int key;
    char *value;
    struct Node *next;
} Node;

Node *hash_table[TABLE_SIZE] = {0};

void hash_table_insert(int key, char *value) {
    int index = HASH_FUNCTION(key);
    Node *new_node = malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = strdup(value);
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

Node *hash_table_search(int key) {
    int index = HASH_FUNCTION(key);
    Node *current = hash_table[index];

    while (current != NULL && current->key != key) {
        current = current->next;
    }

    return current;
}

void print_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            continue;
        }

        Node *current = hash_table[i];
        printf("Index: %d, Key: %d, Value: %s\n", i, current->key, current->value);
        while (current->next != NULL) {
            current = current->next;
            printf("Index: %d, Key: %d, Value: %s\n", i, current->key, current->value);
        }
    }
}

int main() {
    hash_table_insert(1, "Apple");
    hash_table_insert(2, "Banana");
    hash_table_insert(3, "Cherry");
    hash_table_insert(4, "Durian");
    hash_table_insert(5, "Elderberry");
    hash_table_insert(5, "Fig"); // Overwrite Elderberry with Fig
    hash_table_insert(6, "Grape");
    hash_table_insert(7, "Honeydew");
    hash_table_insert(8, "Iceberg");
    hash_table_insert(8, "Jackfruit"); // Overwrite Iceberg with Jackfruit

    print_hash_table();

    Node *search_result = hash_table_search(5); // Search for Fig
    if (search_result != NULL) {
        printf("Search successful: Key = %d, Value = %s\n", search_result->key, search_result->value);
    } else {
        printf("Search failed.\n");
    }

    free(search_result->value);
    free(search_result);

    return 0;
}