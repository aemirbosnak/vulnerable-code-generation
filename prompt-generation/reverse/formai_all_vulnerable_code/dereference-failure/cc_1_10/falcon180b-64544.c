//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

/* Define node structure */
typedef struct node {
    int data;
    struct node* next;
} Node;

/* Function prototypes */
Node* createNode(int data);
void addNode(Node** head, int data);
void deleteNode(Node** head, int data);
void printList(Node* head);

int main() {
    Node* head = NULL;

    /* Create a linked list */
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);

    /* Print the linked list */
    printList(head);

    /* Delete a node */
    deleteNode(&head, 2);

    /* Print the linked list again */
    printList(head);

    return 0;
}

/* Create a new node */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Add a node to the end of the list */
void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/* Delete a node from the list */
void deleteNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

/* Print the linked list */
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}