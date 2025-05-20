//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: satisfied
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
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
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

    // Create a linked list with the numbers 1 to 10
    for (int i = 1; i <= 10; i++) {
        head = newNode(i);
        if (i == 10) {
            head->next = NULL;
        } else {
            head->next = newNode(i + 1);
        }
    }

    // Print the linked list
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    // Find the middle node of the linked list
    struct Node* middle = findMiddle(head);

    // Print the middle node
    printf("%d\n", middle->data);

    return 0;
}