//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: careful
// LinkedList.c - Example of a simple linked list in C.

#include <stdio.h>
#include <stdlib.h>

// A linked list node.
typedef struct ListNode_t {
    int data;
    struct ListNode_t* next;
} ListNode;

// Create a new linked list node.
ListNode* createListNode(int data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if (node == NULL) {
        fprintf(stderr, "Error allocating memory for linked list node.\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Insert a new node at the end of the linked list.
void insertNode(ListNode** head, int data) {
    ListNode* newNode = createListNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        ListNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Print the linked list.
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Delete the linked list.
void deleteLinkedList(ListNode** head) {
    ListNode* current = *head;
    while (current != NULL) {
        ListNode* next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

// Main function.
int main() {
    // Create a linked list.
    ListNode* head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    // Print the linked list.
    printLinkedList(head);

    // Delete the linked list.
    deleteLinkedList(&head);

    return 0;
}