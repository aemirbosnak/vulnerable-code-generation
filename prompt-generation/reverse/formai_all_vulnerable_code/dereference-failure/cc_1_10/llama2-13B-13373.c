//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with a given value
struct Node* newNode(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to reverse the linked list
struct Node* reverseList(struct Node* head) {
    struct Node* current = head;
    struct Node* previous = NULL;

    while (current != NULL) {
        struct Node* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}

// Function to find the middle node of the linked list
struct Node* findMiddle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head->next->next;

    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main() {
    struct Node* head = NULL;

    // Create a list with the following nodes: 1, 2, 3, 4, 5
    head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    // Print the list
    printList(head);

    // Reverse the list
    head = reverseList(head);

    // Find the middle node of the list
    struct Node* middle = findMiddle(head);

    // Print the middle node
    printf("Middle node: %d\n", middle->data);

    return 0;
}