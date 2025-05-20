//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: genius
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
    struct Node* node1 = newNode(1);
    struct Node* node2 = newNode(2);
    struct Node* node3 = newNode(3);
    struct Node* node4 = newNode(4);

    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    printList(head);

    head = reverseList(head);
    printList(head);

    struct Node* middle = findMiddle(head);
    printf("Middle node: %d\n", middle->data);

    return 0;
}