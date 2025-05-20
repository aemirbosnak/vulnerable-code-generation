//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>

// Node of a linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of a linked list
struct Node *insertAtBeginning(struct Node *head, int data) {
    struct Node *node = createNode(data);
    node->next = head;
    return node;
}

// Function to insert a node at the end of a linked list
struct Node *insertAtEnd(struct Node *head, int data) {
    struct Node *node = createNode(data);
    if (head == NULL) {
        return node;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
        return head;
    }
}

// Function to delete a node from a linked list
struct Node *deleteNode(struct Node *head, int data) {
    if (head == NULL) {
        return NULL;
    } else if (head->data == data) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL && temp->next->data != data) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            return head;
        } else {
            struct Node *toDelete = temp->next;
            temp->next = toDelete->next;
            free(toDelete);
            return head;
        }
    }
}

// Function to print a linked list
void printLinkedList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to find the middle element of a linked list
struct Node *findMiddleElement(struct Node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct Node *slow = head;
    struct Node *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to reverse a linked list
struct Node *reverseLinkedList(struct Node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    // Create a linked list
    struct Node *head = NULL;
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    // Print the linked list
    printLinkedList(head);

    // Find the middle element of the linked list
    struct Node *middleElement = findMiddleElement(head);
    printf("Middle element of the linked list: %d\n", middleElement->data);

    // Reverse the linked list
    head = reverseLinkedList(head);

    // Print the reversed linked list
    printLinkedList(head);

    // Delete a node from the linked list
    head = deleteNode(head, 20);

    // Print the linked list
    printLinkedList(head);

    return 0;
}