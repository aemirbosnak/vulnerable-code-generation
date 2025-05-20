//FormAI DATASET v1.0 Category: Data structures visualization ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// define a structure called node
typedef struct node {
    int data;
    struct node *next;
} Node;

// function to create a new node
Node *createNode(int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to add a node at the end of the list
void addNode(Node **head, int data) {
    Node *newNode = createNode(data);
    Node *temp = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// function to print the list
void printList(Node *head) {
    Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// function to delete a node at a given position
void deleteNode(Node **head, int position) {
    if (*head == NULL) {
        return;
    }
    Node *temp = *head;
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        return;
    }
    Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

int main() {
    Node *head = NULL;

    addNode(&head, 3);
    addNode(&head, 5);
    addNode(&head, 9);
    addNode(&head, 8);

    printList(head);   // List: 3 5 9 8

    deleteNode(&head, 1);

    printList(head);   // List: 3 9 8

    return 0;
}