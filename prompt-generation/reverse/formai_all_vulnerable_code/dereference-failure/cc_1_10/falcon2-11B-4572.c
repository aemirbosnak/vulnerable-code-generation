//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to delete a node from the linked list
struct Node* deleteNode(struct Node* head, int data) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    if (temp!= NULL) {
        while (temp!= NULL && temp->data!= data) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Node not found in the list\n");
        } else {
            if (temp == head) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
        }
    }
    return head;
}

int main() {
    struct Node* head = NULL;
    head = insertAtBeginning(head, 5);
    head = insertAtBeginning(head, 10);
    head = insertAtEnd(head, 15);
    head = insertAtEnd(head, 20);

    printList(head);
    printf("Deleting 15\n");
    head = deleteNode(head, 15);
    printList(head);

    return 0;
}