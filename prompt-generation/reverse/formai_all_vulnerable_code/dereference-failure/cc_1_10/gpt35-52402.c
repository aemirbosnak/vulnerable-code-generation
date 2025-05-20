//FormAI DATASET v1.0 Category: Linked list operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

/* Define the basic node structure */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Initialize a new empty linked list */
Node *head = NULL;

/* Function to add a node to the end of the list */
void append(int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

/* Function to insert a node at a given position */
void insert(int data, int position) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;

    if (position < 0) {
        printf("Invalid position: %d\n", position);
        return;
    }

    if (position == 0 || head == NULL) {
        newNode->next = head;
        head = newNode;
    } else {
        Node *current = head;
        int i = 0;
        while (i < position - 1 && current->next != NULL) {
            current = current->next;
            i++;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

/* Function to delete the node at a given position */
void delete(int position) {
    if (position < 0 || head == NULL) {
        printf("Invalid position: %d\n", position);
        return;
    }

    if (position == 0) {
        Node *temp = head;
        head = head->next;
        free(temp);
    } else {
        Node *current = head;
        int i = 0;
        while (i < position - 1 && current->next != NULL) {
            current = current->next;
            i++;
        }
        if (current->next == NULL) {
            printf("Invalid position: %d\n", position);
            return;
        }
        Node *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

/* Function to print the contents of the list */
void printList() {
    printf("List contents: ");
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    /* Demonstrate the various linked list operations */
    append(1);
    append(2);
    append(3);
    printList();

    insert(4, 1);
    insert(5, 5);
    printList();

    delete(2);
    delete(4);
    delete(0);
    printList();

    return 0;
}