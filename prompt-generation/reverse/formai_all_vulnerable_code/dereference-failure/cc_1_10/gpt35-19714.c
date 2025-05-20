//FormAI DATASET v1.0 Category: Sorting ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a node in our linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to insert a node at the beginning of a linked list
void insertAtBeginning(Node** head, int data) {
    // Allocate memory for a new node
    Node* newNode = (Node*)malloc(sizeof(Node));

    // Set the data for the new node
    newNode->data = data;

    // Set the next pointer for the new node
    newNode->next = *head;

    // Set the head to point to the new node
    *head = newNode;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* cur = head;

    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    printf("\n");
}

// Function to swap two nodes in a linked list
void swapNodes(Node** head, int x, int y) {
    // If x and y are the same, no need to swap
    if (x == y) return;

    // Find the nodes with x and y values
    Node* prevX = NULL;
    Node* curX = *head;
    while (curX != NULL && curX->data != x) {
        prevX = curX;
        curX = curX->next;
    }

    Node* prevY = NULL;
    Node* curY = *head;
    while (curY != NULL && curY->data != y) {
        prevY = curY;
        curY = curY->next;
    }

    // If either x or y is not found, no swap can happen
    if (curX == NULL || curY == NULL) return;

    // If the previous node of x is not null, set its next pointer to y
    if (prevX != NULL) prevX->next = curY;
    else *head = curY;

    // If the previous node of y is not null, set its next pointer to x
    if (prevY != NULL) prevY->next = curX;
    else *head = curX;

    // Swap the next pointers for the two nodes
    Node* temp = curX->next;
    curX->next = curY->next;
    curY->next = temp;
}

// Function to sort a linked list using bubble sort
void bubbleSort(Node** head) {
    // Get the length of the linked list
    int len = 0;
    Node* cur = *head;
    while (cur != NULL) {
        len++;
        cur = cur->next;
    }

    // Sort the linked list using bubble sort
    for (int i = 0; i < len - 1; i++) {
        Node* prevNode = *head;
        Node* curNode = (*head)->next;
        for (int j = 0; j < len - i - 1; j++) {
            if (prevNode->data > curNode->data) {
                swapNodes(head, prevNode->data, curNode->data);
                Node* temp = prevNode;
                prevNode = curNode;
                curNode = temp;
            }

            prevNode = prevNode->next;
            curNode = curNode->next;
        }
    }
}

int main() {
    // Generate a linked list with random integers
    Node* head = NULL;
    for (int i = 0; i < 10; i++) {
        int randNum = rand() % 100 + 1;
        insertAtBeginning(&head, randNum);
    }

    // Print the unsorted linked list
    printf("Unsorted Linked List:\n");
    printLinkedList(head);

    // Sort the linked list using bubble sort
    bubbleSort(&head);

    // Print the sorted linked list
    printf("Sorted Linked List:\n");
    printLinkedList(head);

    return 0;
}