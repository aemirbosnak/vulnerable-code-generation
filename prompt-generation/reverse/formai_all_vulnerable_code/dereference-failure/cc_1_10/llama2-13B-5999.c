//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>

// Structure to represent a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given value
struct Node* newNode(int x) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = x;
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

// Function to perform addition operation on two linked lists
struct Node* addLists(struct Node* head1, struct Node* head2) {
    struct Node* current1 = head1, *current2 = head2, *newHead = NULL;
    int carry = 0;

    // Perform addition of corresponding elements
    while (current1 != NULL && current2 != NULL) {
        int sum = current1->data + current2->data + carry;
        carry = (sum / 10) % 10;
        sum %= 10;
        newHead = newNode(sum);
        newHead->next = current1;
        current1 = current1->next;
        current2 = current2->next;
    }

    // Handle remaining elements
    if (current1 != NULL) {
        newHead->next = current1;
    } else if (current2 != NULL) {
        newHead->next = current2;
    }

    return newHead;
}

int main() {
    struct Node* head1 = newNode(1), *head2 = newNode(2), *head3 = NULL;

    // Create a list with the elements 1, 2, 3
    head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);

    // Perform addition operation
    head3 = addLists(head1, head2);

    // Print the result
    printList(head3);

    return 0;
}