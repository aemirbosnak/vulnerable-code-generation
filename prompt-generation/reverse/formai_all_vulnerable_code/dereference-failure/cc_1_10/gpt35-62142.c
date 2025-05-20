//FormAI DATASET v1.0 Category: Data structures visualization ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// A struct to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// A struct to represent the linked list
struct LinkedList {
    struct Node* head;
    int size;
};

// Function to create a new node with a given data value
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the beginning of the linked list
void addToFront(struct LinkedList* ll, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = ll->head;
    ll->head = newNode;
    ll->size++;
}

// Function to delete a node with the given data value from the linked list
void deleteNode(struct LinkedList* ll, int data) {
    struct Node* prev = NULL;
    struct Node* curr = ll->head;

    while (curr != NULL) {
        if (curr->data == data) {
            if (prev == NULL) {
                ll->head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            ll->size--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// Function to print the linked list
void printList(struct LinkedList* ll) {
    struct Node* curr = ll->head;
    printf("Linked List: ");
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    struct LinkedList ll = { NULL, 0 };
    addToFront(&ll, 5);
    addToFront(&ll, 3);
    addToFront(&ll, 1);
    printList(&ll);
    deleteNode(&ll, 3);
    printList(&ll);
    return 0;
}