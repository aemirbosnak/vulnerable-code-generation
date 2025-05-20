//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

// Function to insert a node after a given node
struct Node* insertAfter(struct Node *head, int data, int after) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->data != after && temp->next != NULL) {
            temp = temp->next;
        }
        if (temp->data == after) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            printf("Node not found\n");
        }
    }
    return head;
}

// Function to delete a node from the beginning of the linked list
struct Node* deleteFromBeginning(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

// Function to delete a node from the end of the linked list
struct Node* deleteFromEnd(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node *temp = head;
        struct Node *prev;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == head) {
            head = NULL;
        } else {
            prev->next = NULL;
        }
        free(temp);
    }
    return head;
}

// Function to delete a node after a given node
struct Node* deleteAfter(struct Node *head, int after) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node *temp = head;
        while (temp->data != after && temp->next != NULL) {
            temp = temp->next;
        }
        if (temp->data == after) {
            if (temp->next == NULL) {
                printf("Node not found\n");
            } else {
                struct Node *toDelete = temp->next;
                temp->next = temp->next->next;
                free(toDelete);
            }
        } else {
            printf("Node not found\n");
        }
    }
    return head;
}

// Function to print the linked list
void printLinkedList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;

    // Inserting nodes into the linked list
    head = insertAtBeginning(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAfter(head, 30, 10);
    head = insertAfter(head, 40, 30);

    // Printing the linked list
    printf("Original linked list: ");
    printLinkedList(head);

    // Deleting nodes from the linked list
    head = deleteFromBeginning(head);
    head = deleteFromEnd(head);
    head = deleteAfter(head, 30);

    // Printing the linked list after deletions
    printf("Linked list after deletions: ");
    printLinkedList(head);

    return 0;
}