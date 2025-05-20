//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Define the structure of a node */
typedef struct node {
    int data;
    struct node *next;
} Node;

/* Function prototypes */
int isEmpty(Node *head);
void addNode(Node **head, int data);
void deleteNode(Node **head, int data);
void printList(Node *head);

/* Main function */
int main() {
    Node *head = NULL;

    /* Add nodes */
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);

    /* Print list */
    printList(head);

    /* Delete nodes */
    deleteNode(&head, 2);
    deleteNode(&head, 4);

    /* Print list */
    printList(head);

    return 0;
}

/* Check if the list is empty */
int isEmpty(Node *head) {
    if (head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

/* Add a node to the list */
void addNode(Node **head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

/* Delete a node from the list */
void deleteNode(Node **head, int data) {
    Node *temp = *head;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    Node *next = temp->next;
    free(temp);
    temp = next;
}

/* Print the list */
void printList(Node *head) {
    Node *temp = head;

    if (head == NULL) {
        printf("Empty list.\n");
        return;
    }

    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}