//FormAI DATASET v1.0 Category: Linked list operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Initialize an empty linked list
Node* initializeList(void) {
    return NULL;
}

// Insert an element at the beginning of the linked list
Node* insertBegin(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

// Insert an element at the end of the linked list
Node* insertEnd(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

// Insert an element at a given position in the linked list
Node* insertPosition(Node* head, int pos, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        int i;
        for (i = 1; i < pos - 1 && current != NULL; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    return head;
}

// Delete the first element of the linked list
Node* deleteBegin(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

// Delete the last element of the linked list
Node* deleteEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        Node* current = head;
        Node* prev = NULL;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        free(current);
    }
    return head;
}

// Delete an element at a given position in the linked list
Node* deletePosition(Node* head, int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        Node* current = head;
        Node* prev = NULL;
        int i;
        for (i = 1; i < pos && current != NULL; i++) {
            prev = current;
            current = current->next;
        }
        if (current == NULL) {
            printf("Position not found!\n");
        } else if (prev == NULL) {
            head = head->next;
            free(current);
        } else {
            prev->next = current->next;
            free(current);
        }
    }
    return head;
}

// Display the contents of the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        printf("List: ");
        Node* current = head;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Main function
int main(void) {
    Node* head = initializeList();

    head = insertBegin(head, 5);
    head = insertEnd(head, 10);
    head = insertPosition(head, 2, 7);

    displayList(head);

    head = deleteBegin(head);
    head = deleteEnd(head);
    head = deletePosition(head, 2);

    displayList(head);

    return 0;
}