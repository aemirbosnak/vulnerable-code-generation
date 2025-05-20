//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    printf("The list is: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to find the middle node of the linked list
struct Node* findMiddle(struct Node* head) {
    // Base case: if the list has only one node, return that node
    if (head->next == NULL) {
        return head;
    }

    // Find the middle node by recursively traversing the list
    struct Node* slow = head;
    struct Node* fast = head->next->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
    // Create a list with some nodes
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    // Print the list
    printList(head);

    // Find the middle node of the list
    struct Node* middle = findMiddle(head);

    // Print the middle node
    printf("The middle node is: %d\n", middle->data);

    return 0;
}