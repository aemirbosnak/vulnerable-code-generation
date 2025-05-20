//FormAI DATASET v1.0 Category: Data structures visualization ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *ptr = *head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void displayList(Node *head) {
    printf("\nLinked List: ");
    Node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    Node *head = NULL;
    int choice, data;

    do {
        printf("\n\n---- MENU ----");
        printf("\n1. Insert a node");
        printf("\n2. Display the list");
        printf("\n3. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter data to insert: ");
                scanf("%d", &data);
                insertNode(&head, data);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice. Choose from 1-3.");
        }
    } while(choice != 3);

    return 0;
}