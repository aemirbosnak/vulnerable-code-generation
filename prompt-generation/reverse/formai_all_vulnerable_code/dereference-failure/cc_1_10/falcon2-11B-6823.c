//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *key;
    char *value;
    struct node *next;
} node;

node *head = NULL;

void add_node(char *key, char *value) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node *curr = head;
        while (curr->next!= NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

void search_node(char *key) {
    node *curr = head;
    while (curr!= NULL) {
        if (strcmp(curr->key, key) == 0) {
            printf("Key: %s\n", curr->key);
            printf("Value: %s\n", curr->value);
            return;
        }
        curr = curr->next;
    }
    printf("Key not found.\n");
}

int main() {
    add_node("apple", "red");
    add_node("banana", "yellow");
    add_node("orange", "orange");

    search_node("apple");
    search_node("banana");
    search_node("orange");

    return 0;
}