//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Knight {
    int value;
    struct Knight *next;
};

// Function to create a new node with a given value
struct Knight *createNode(int value) {
    struct Knight *newNode = malloc(sizeof(struct Knight));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void enlist(struct Knight *list, int value) {
    struct Knight *newNode = createNode(value);
    newNode->next = list;
    list = newNode;
}

// Function to insert a node at the end of the list
void enlist_tail(struct Knight *list, int value) {
    struct Knight *newNode = createNode(value);
    if (list == NULL) {
        list = newNode;
    } else {
        list->next = newNode;
    }
}

// Function to remove the first node from the list
struct Knight *delist(struct Knight *list) {
    if (list == NULL) {
        return NULL;
    }
    struct Knight *temp = list->next;
    free(list);
    return temp;
}

// Function to traverse the list
void listTraverse(struct Knight *list) {
    if (list == NULL) {
        return;
    }
    printf("%d ", list->value);
    listTraverse(list->next);
}

int main() {
    struct Knight *list = NULL;

    // Insert some nodes
    enlist(list, 10);
    enlist(list, 20);
    enlist_tail(list, 30);

    // Remove the first node
    struct Knight *removedNode = delist(list);
    printf("Removed node: %d\n", removedNode->value);

    // Traverse the list
    listTraverse(list);

    return 0;
}