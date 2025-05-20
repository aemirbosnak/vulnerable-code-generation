//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Define a struct to represent a node in a linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a function to print a linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Define a function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Define a function to add a new node to the end of a linked list
struct Node* addNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
    return newNode;
}

// Define a function to remove a node from a linked list
struct Node* removeNode(struct Node** head, int data) {
    struct Node* current = *head;
    struct Node* prev = NULL;
    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }
    if (current!= NULL) {
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
    return *head;
}

// Define a function to reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node* current = head;
    struct Node* prev = NULL;
    while (current!= NULL) {
        struct Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

// Define a function to sort a linked list using bubble sort
struct Node* bubbleSort(struct Node* head) {
    struct Node* current = head;
    while (current->next!= NULL) {
        struct Node* temp = current->next;
        int compare = current->data;
        while (temp!= NULL) {
            if (temp->data < compare) {
                struct Node* swap = temp;
                temp = swap->next;
                swap->next = current;
                current->next = swap;
            }
            temp = temp->next;
        }
        current = current->next;
    }
    return head;
}

int main() {
    srand(time(NULL));
    struct Node* head = NULL;
    for (int i = 0; i < 10; i++) {
        head = addNode(&head, rand() % 100);
    }
    printList(head);
    head = reverseList(head);
    printList(head);
    head = bubbleSort(head);
    printList(head);
    return 0;
}