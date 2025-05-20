//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Linked list node
struct Node {
    int data;
    struct Node* next;
};

// Linked list head
struct Node* head = NULL;

// Function to print linked list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    struct Node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node from the list
void deleteNode(int data) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found in the list\n", data);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

// Function to reverse the linked list
void reverseList() {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Function to search for a node in the list
void searchNode(int data) {
    struct Node* temp = head;

    while (temp!= NULL) {
        if (temp->data == data) {
            printf("Node with data %d found in the list\n", data);
            return;
        }
        temp = temp->next;
    }
    printf("Node with data %d not found in the list\n", data);
}

int main() {
    insertAtBeginning(100);
    insertAtBeginning(200);
    insertAtBeginning(300);
    insertAtEnd(400);
    insertAtEnd(500);
    searchNode(200);
    searchNode(300);
    searchNode(600);
    deleteNode(500);
    reverseList();
    printList(head);

    return 0;
}