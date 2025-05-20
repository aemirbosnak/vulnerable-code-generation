//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given value
struct Node* newNode(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

// Function to add a node to the beginning of the linked list
void addNode(struct Node** head_ref, int value) {
    struct Node* new_node = newNode(value);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to add a node to the end of the linked list
void addNodeTail(struct Node** head_ref, int value) {
    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode(value);
}

// Function to get the average of the nodes in the linked list
double getAverage(struct Node* head) {
    int sum = 0;
    struct Node* current = head;
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    return (double)sum / (current - head);
}

// Function to get the standard deviation of the nodes in the linked list
double getStandardDeviation(struct Node* head) {
    int sum = 0;
    struct Node* current = head;
    double avg = getAverage(head);
    while (current != NULL) {
        sum += (current->data - avg)*(current->data - avg);
        current = current->next;
    }
    return sqrt(sum / (current - head));
}

int main() {
    struct Node* head = NULL;

    // Example usage of the linked list operations
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNodeTail(&head, 4);
    addNodeTail(&head, 5);

    // Calculate the average and standard deviation of the linked list
    double avg = getAverage(head);
    double stddev = getStandardDeviation(head);

    printf("Average: %f\n", avg);
    printf("Standard Deviation: %f\n", stddev);

    return 0;
}