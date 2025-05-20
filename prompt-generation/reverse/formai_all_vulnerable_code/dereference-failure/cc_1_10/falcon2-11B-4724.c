//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Structure for the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Structure for the linked list
struct List {
    struct Node* head;
};

// Function to initialize the linked list
void initList(struct List* list) {
    list->head = NULL;
}

// Function to add a new index to the linked list
void addIndex(struct List* list, int index) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = index;
    newNode->next = list->head;
    list->head = newNode;
}

// Function to remove an index from the linked list
void removeIndex(struct List* list, int index) {
    struct Node* current = list->head;
    struct Node* prev = NULL;
    
    while (current!= NULL && current->data!= index) {
        prev = current;
        current = current->next;
    }
    
    if (current!= NULL && current->data == index) {
        prev->next = current->next;
        free(current);
    }
}

// Function to search for an index in the linked list
int searchIndex(struct List* list, int index) {
    struct Node* current = list->head;
    
    while (current!= NULL && current->data!= index) {
        current = current->next;
    }
    
    if (current!= NULL && current->data == index) {
        return 1;
    }
    
    return 0;
}

int main() {
    // Initialize the linked list
    struct List list;
    initList(&list);
    
    // Add indexes to the linked list
    addIndex(&list, 10);
    addIndex(&list, 20);
    addIndex(&list, 30);
    
    // Remove an index from the linked list
    removeIndex(&list, 20);
    
    // Search for an index in the linked list
    int index = searchIndex(&list, 10);
    
    if (index == 1) {
        printf("Index found: %d\n", index);
    } else {
        printf("Index not found\n");
    }
    
    return 0;
}