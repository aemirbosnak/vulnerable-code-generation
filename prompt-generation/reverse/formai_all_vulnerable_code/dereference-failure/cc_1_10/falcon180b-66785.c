//Falcon-180B DATASET v1.0 Category: Database querying ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE_LEN 100

// Node structure for linked list implementation
typedef struct node {
    char *key;
    char *value;
    struct node *next;
} Node;

// Linked list implementation
Node *head = NULL;

// Function to add a key-value pair to the database
void add_pair(char *key, char *value) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node *curr = head;
        while (curr->next!= NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

// Function to query the database for a specific key
char *query_key(char *key) {
    Node *curr = head;
    while (curr!= NULL) {
        if (strcmp(curr->key, key) == 0) {
            return curr->value;
        }
        curr = curr->next;
    }
    return NULL;
}

// Function to print all key-value pairs in the database
void print_pairs() {
    Node *curr = head;
    while (curr!= NULL) {
        printf("%s: %s\n", curr->key, curr->value);
        curr = curr->next;
    }
}

int main() {
    // Add some key-value pairs to the database
    add_pair("name", "John");
    add_pair("age", "30");
    add_pair("city", "New York");

    // Query the database for a specific key
    char *value = query_key("age");
    if (value!= NULL) {
        printf("Age: %s\n", value);
    }

    // Print all key-value pairs in the database
    print_pairs();

    return 0;
}