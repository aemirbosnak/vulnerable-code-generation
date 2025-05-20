//FormAI DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// struct representing a node for our database indexing system
typedef struct Node {
    int id;
    char* name;
    struct Node* next;
} Node;

// function for inserting a new record into the database
void insert(Node** index, int id, char* name) {
    Node* node = (Node*) malloc(sizeof(Node)); // allocate memory for new node
    node->id = id;
    node->name = (char*) malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(node->name, name);
    node->next = NULL;

    // search for correct position to insert new node
    if (*index == NULL) {
        // if index is empty, set new node as head
        *index = node;
    } else {
        Node* curr = *index;
        Node* prev = NULL;
        while (curr != NULL && strcmp(curr->name, name) < 0) {
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL) {
            node->next = *index;
            *index = node;
        } else {
            prev->next = node;
            node->next = curr;
        }
    }
}

// function for searching for a record in the database
Node* search(Node* index, char* name) {
    Node* curr = index;
    while (curr != NULL && strcmp(curr->name, name) != 0) {
        curr = curr->next;
    }
    return curr;
}

// function for deleting a record from the database
void delete(Node** index, char* name) {
    Node* curr = *index;
    Node* prev = NULL;
    while (curr != NULL && strcmp(curr->name, name) != 0) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Record not found.\n");
        return;
    }
    if (prev == NULL) {
        *index = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr->name);
    free(curr);
}

// function for printing all records in the database
void print(Node* index) {
    Node* curr = index;
    while (curr != NULL) {
        printf("ID: %d, Name: %s\n", curr->id, curr->name);
        curr = curr->next;
    }
}

int main() {
    Node* index = NULL; // create empty index

    // insert some records
    insert(&index, 1, "John");
    insert(&index, 2, "Mary");
    insert(&index, 3, "Bob");
    insert(&index, 4, "Alice");

    // search for a record
    Node* record = search(index, "Bob");
    if (record != NULL) {
        printf("Record found: ID: %d, Name: %s\n", record->id, record->name);
    } else {
        printf("Record not found.\n");
    }

    // delete a record
    delete(&index, "Mary");

    // print all records
    printf("All records:\n");
    print(index);

    return 0;
}