//FormAI DATASET v1.0 Category: Linked list operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

// Function to create a new node and returns pointer to it
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of linked list
void append(struct LinkedList* ll, int data) {
    struct Node* newNode = createNode(data);

    if(ll->head == NULL) {
        ll->head = newNode;     
        return;
    }

    struct Node* last = ll->head;
    while(last->next != NULL)
        last = last->next;

    last->next = newNode;
}

// Function to add a node at the beginning of linked list
void prepend(struct LinkedList* ll, int data) {
    struct Node* newNode = createNode(data);

    newNode->next = ll->head;
    ll->head = newNode;
}

// Function to print entire linked list
void printLinkedList(struct LinkedList* ll) {
    struct Node* node = ll->head;
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to delete first occurrence of given data from linked list
void deleteNode(struct LinkedList* ll, int data) {
    struct Node* temp = ll->head;
    struct Node* prev = NULL;

    if(temp != NULL && temp->data == data) {
        ll->head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

int main() {
    struct LinkedList ll = { NULL };

    // Appending nodes to linked list
    printf("Appending nodes to linked list:\n");
    append(&ll, 1);
    append(&ll, 2);
    append(&ll, 3);
    append(&ll, 4);
    append(&ll, 5);
    printLinkedList(&ll);

    // Prepending nodes to linked list
    printf("Prepending nodes to linked list:\n");
    prepend(&ll, 0);
    prepend(&ll, -1);
    printLinkedList(&ll);

    // Deleting a node from linked list
    printf("Deleting node from linked list:\n");
    deleteNode(&ll, 3);
    printLinkedList(&ll);

    return 0;
}