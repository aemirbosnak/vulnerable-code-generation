//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void addNode(struct node** headRef, int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*headRef == NULL) {
        newNode->next = newNode;
        *headRef = newNode;
    } else {
        struct node* lastNode = *headRef;
        while (lastNode->next!= *headRef) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        newNode->next = *headRef;
    }
}

void printList(struct node* head) {
    struct node* currentNode = head;
    do {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    } while (currentNode!= head);
}

int main() {
    struct node* head = NULL;
    int choice, data;

    do {
        printf("\n");
        printf("1. Add node\n");
        printf("2. Print list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printf("List: ");
                printList(head);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}