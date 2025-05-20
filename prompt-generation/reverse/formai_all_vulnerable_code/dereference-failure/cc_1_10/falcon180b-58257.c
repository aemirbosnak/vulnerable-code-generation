//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 1000
#define MAX_ENTRIES 1000

// Node structure for linked list
typedef struct node {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
    struct node *next;
} Node;

// Linked list
Node *head = NULL;

// Function to insert a new entry
void insert(char *key, char *value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->key, key);
    strcpy(new_node->value, value);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to search for a key
Node *search(char *key) {
    Node *temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->key, key) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to delete an entry
void delete(char *key) {
    Node *temp = head;
    Node *prev = NULL;

    while (temp!= NULL) {
        if (strcmp(temp->key, key) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

// Function to print the database
void print_database() {
    Node *temp = head;
    while (temp!= NULL) {
        printf("Key: %s, Value: %s\n", temp->key, temp->value);
        temp = temp->next;
    }
}

// Main function
int main() {
    insert("Name", "John");
    insert("Age", "25");
    insert("Address", "New York");

    print_database();

    Node *result = search("Age");
    if (result!= NULL) {
        printf("Value for Age: %s\n", result->value);
    } else {
        printf("No entry found for Age\n");
    }

    delete("Age");

    print_database();

    return 0;
}