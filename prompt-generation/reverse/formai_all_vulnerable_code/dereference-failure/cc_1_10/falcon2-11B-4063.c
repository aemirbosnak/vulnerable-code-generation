//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the linked list node structure
struct Node {
    char key[20];
    int value;
    struct Node* next;
};

// Function to create a new node and insert it into the linked list
struct Node* create_node(char* key, int value) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    strcpy(new_node->key, key);
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Function to search for a key in the linked list and return its value
int search(struct Node* head, char* key) {
    struct Node* current = head;
    while (current!= NULL && strcmp(current->key, key)!= 0) {
        current = current->next;
    }
    return (current == NULL)? -1 : current->value;
}

// Function to insert a new node with the given key and value into the linked list
void insert(struct Node** head, char* key, int value) {
    struct Node* new_node = create_node(key, value);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct Node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Function to print the linked list
void print_list(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("Key: %s, Value: %d\n", current->key, current->value);
        current = current->next;
    }
}

// Main function
int main() {
    struct Node* head = NULL;
    insert(&head, "apple", 100);
    insert(&head, "banana", 200);
    insert(&head, "orange", 300);
    insert(&head, "kiwi", 400);
    insert(&head, "grape", 500);

    print_list(head);

    int search_value = search(head, "banana");
    printf("Value for key 'banana': %d\n", search_value);

    return 0;
}