//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void addNode(struct Node** head, int data);
void deleteNode(struct Node** head, int data);
void printList(struct Node* head);

int main() {
    struct Node* head = NULL;

    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    printf("Original List:\n");
    printList(head);

    deleteNode(&head, 3);

    printf("\nAfter deleting 3:\n");
    printList(head);

    deleteNode(&head, 1);

    printf("\nAfter deleting 1:\n");
    printList(head);

    deleteNode(&head, 5);

    printf("\nAfter deleting 5:\n");
    printList(head);

    deleteNode(&head, 2);

    printf("\nAfter deleting 2:\n");
    printList(head);

    deleteNode(&head, 4);

    printf("\nAfter deleting 4:\n");
    printList(head);

    return 0;
}

void addNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

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

void printList(struct Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}