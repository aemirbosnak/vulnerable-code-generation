//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
int size = 0;

// Function to add a node at the end of the linked list
void addNode(int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        Node *ptr = head;
        while (ptr->next!= NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }

    size++;
}

// Function to search for a node in the linked list
Node *searchNode(int data) {
    Node *ptr = head;
    while (ptr!= NULL) {
        if (ptr->data == data) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

// Function to print the linked list
void printList() {
    Node *ptr = head;
    while (ptr!= NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Function to delete a node from the linked list
void deleteNode(int data) {
    Node *ptr = head;
    Node *prev = NULL;

    while (ptr!= NULL && ptr->data!= data) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Node not found\n");
        return;
    }

    if (prev == NULL) {
        head = head->next;
    } else {
        prev->next = ptr->next;
    }
    free(ptr);
    size--;
}

// Main function to test the linked list functions
int main() {
    addNode(5);
    addNode(10);
    addNode(15);
    addNode(20);
    addNode(25);

    printf("Linked list: ");
    printList();

    Node *found = searchNode(15);
    if (found!= NULL) {
        printf("Found node: %d\n", found->data);
    } else {
        printf("Node not found\n");
    }

    deleteNode(15);

    printf("Linked list after deleting node 15: ");
    printList();

    return 0;
}