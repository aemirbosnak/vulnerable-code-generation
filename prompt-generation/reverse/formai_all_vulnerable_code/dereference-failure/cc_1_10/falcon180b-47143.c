//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

void addNode(struct Node** head, int data);
void printList(struct Node* node);
void reverseList(struct Node** head);
void sortList(struct Node** head);

int main() {
    struct Node* head = NULL;

    // Adding nodes
    addNode(&head, 5);
    addNode(&head, 3);
    addNode(&head, 7);
    addNode(&head, 1);
    addNode(&head, 9);

    // Printing the original list
    printf("Original List:\n");
    printList(head);

    // Reversing the list
    reverseList(&head);

    // Printing the reversed list
    printf("\nReversed List:\n");
    printList(head);

    // Sorting the list
    sortList(&head);

    // Printing the sorted list
    printf("\nSorted List:\n");
    printList(head);

    return 0;
}

void addNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* curr = *head;

    while (curr!= NULL) {
        struct Node* next = curr->next; // Save the next node
        curr->next = prev; // Reverse the link
        prev = curr; // Move to the next pair of nodes
        curr = next;
    }

    *head = prev; // Update the head of the reversed list
}

void sortList(struct Node** head) {
    struct Node* curr = *head;
    while (curr!= NULL && curr->next!= NULL) {
        if (curr->data > curr->next->data) {
            int tempData = curr->data;
            curr->data = curr->next->data;
            curr->next->data = tempData;
        }
        curr = curr->next;
    }
}