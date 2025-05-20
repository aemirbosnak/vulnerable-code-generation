//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a node in a linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a node at the end of a linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Function to find the median of a linked list
double findMedian(Node* head) {
    // Calculate the total number of nodes in the list
    int totalNodes = 0;
    Node* current = head;
    while (current) {
        totalNodes++;
        current = current->next;
    }

    // If the list is even, the median is the average of the two middle nodes
    if (totalNodes % 2 == 0) {
        current = head;
        int middleNodes = totalNodes / 2;
        for (int i = 0; i < middleNodes - 1; i++) {
            current = current->next;
        }
        return (double)(current->data + current->next->data) / 2;
    }

    // If the list is odd, the median is the data of the middle node
    else {
        current = head;
        int middleNodes = (totalNodes - 1) / 2;
        for (int i = 0; i < middleNodes; i++) {
            current = current->next;
        }
        return (double)current->data;
    }
}

int main() {
    // Create a linked list
    Node* head = NULL;

    // Insert some nodes into the list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    // Find the median of the list
    double median = findMedian(head);

    // Print the median
    printf("The median of the list is: %.2f", median);

    return 0;
}