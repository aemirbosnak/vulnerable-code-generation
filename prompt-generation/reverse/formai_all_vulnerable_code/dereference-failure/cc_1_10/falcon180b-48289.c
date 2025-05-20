//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
void addNode(Node** head, int data);
void deleteNode(Node** head, int data);
void printList(Node* head);
void reverseList(Node** head);
void sortList(Node** head);

int main() {
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);
    addNode(&head, 50);

    // Print the original list
    printf("Original List:\n");
    printList(head);

    // Delete a node from the list
    deleteNode(&head, 30);

    // Print the updated list
    printf("\nList after deleting node with data 30:\n");
    printList(head);

    // Reverse the list
    reverseList(&head);

    // Print the reversed list
    printf("\nReversed List:\n");
    printList(head);

    // Sort the list in ascending order
    sortList(&head);

    // Print the sorted list
    printf("\nSorted List:\n");
    printList(head);

    return 0;
}

// Function to add a node to the list
void addNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

// Function to delete a node from the list
void deleteNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

// Function to reverse the list
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;

    while (current!= NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

// Function to sort the list in ascending order
void sortList(Node** head) {
    Node* temp = *head;
    int swapped;

    do {
        swapped = 0;
        while (temp!= NULL) {
            Node* next = temp->next;
            if (temp->data > temp->next->data) {
                int tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;
                swapped = 1;
            }
            temp = next;
        }
        temp = *head;
    } while (swapped);
}