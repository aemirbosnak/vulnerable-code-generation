//MISTRAL-7B DATASET v1.0 Category: Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 101

typedef struct Node {
    char key[21];
    int value;
    struct Node *next;
} Node;

Node *hash_table[TABLE_SIZE];

int hash_func(char *key) {
    int hash = 0;
    for (int i = 0; key[i]; i++) {
        hash += key[i];
    }
    return hash % TABLE_SIZE;
}

Node *create_node(char *key, int value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    strcpy(new_node->key, key);
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void add_element(char *key, int value) {
    int index = hash_func(key);
    Node *new_node = create_node(key, value);

    if (!hash_table[index]) {
        hash_table[index] = new_node;
    } else {
        Node *current = hash_table[index];
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
}

Node *search_element(char *key) {
    int index = hash_func(key);
    Node *current = hash_table[index];

    while (current && strcmp(current->key, key) != 0) {
        current = current->next;
    }

    return current;
}

void remove_element(char *key) {
    int index = hash_func(key);
    Node **current = &hash_table[index];

    if (*current && strcmp((*current)->key, key) == 0) {
        Node *to_remove = *current;
        *current = (*current)->next;
        free(to_remove);
    } else {
        while (*current && (*current)->next && strcmp((*current)->next->key, key) != 0) {
            current = &((*current)->next);
        }

        if (!(*current) || !(*current)->next) {
            printf("Element not found.\n");
            return;
        }

        Node *to_remove = (*current)->next;
        (*current)->next = (*current)->next->next;
        free(to_remove);
    }
}

int main() {
    add_element("apple", 5);
    add_element("banana", 10);
    add_element("orange", 15);

    Node *found_node = search_element("banana");
    if (found_node) {
        printf("Found node with key 'banana': value = %d\n", found_node->value);
    }

    remove_element("banana");

    Node *not_found_node = search_element("banana");
    if (!not_found_node) {
        printf("Node not found.\n");
    }

    return 0;
}