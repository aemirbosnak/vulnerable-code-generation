//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

// Hash function
int hash(const char* key) {
    int hash_value = 0;
    for (int i = 0; key[i]!= '\0'; i++) {
        hash_value += key[i];
    }
    return hash_value;
}

// Linked List Node
typedef struct node {
    char key[MAX_SIZE];
    struct node* next;
} Node;

// Linked List
Node* head = NULL;

// Insertion function
void insert(const char* key) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->key, key);

    if (head == NULL) {
        head = new_node;
    } else {
        Node* current = head;
        Node* prev = NULL;
        while (current!= NULL) {
            if (strcmp(current->key, key) < 0) {
                if (prev == NULL) {
                    head = new_node;
                } else {
                    prev->next = new_node;
                }
                break;
            }
            prev = current;
            current = current->next;
        }
    }
}

// Search function
int search(const char* key) {
    Node* current = head;
    while (current!= NULL) {
        if (strcmp(current->key, key) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    insert("apple");
    insert("banana");
    insert("cherry");
    insert("date");

    printf("Search for 'apple': %d\n", search("apple"));
    printf("Search for 'banana': %d\n", search("banana"));
    printf("Search for 'cherry': %d\n", search("cherry"));
    printf("Search for 'date': %d\n", search("date"));

    return 0;
}