//FormAI DATASET v1.0 Category: Linked list operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

/* define the struct for the Node */
struct Node {
    int data;
    struct Node *next;
};

/* define the functions for the operations */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertFront(struct Node **headRef, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

void insertEnd(struct Node **headRef, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = (*headRef);
    newNode->data = value;
    newNode->next = NULL;
    if ((*headRef) == NULL) {
        (*headRef) = newNode;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
    return;
}

void deleteKey(struct Node **headRef, int key) {
    struct Node *temp = (*headRef), *prev;

    if (temp != NULL && temp->data == key) {
        (*headRef) = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void deletePos(struct Node **headRef, int position) {
    if (*headRef == NULL) return;
    struct Node *temp = *headRef;
    if (position == 0) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    for(int i=0; temp!=NULL && i<position-1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

/* main program */
int main() {
    struct Node *head = NULL;
    insertFront(&head, 10);
    insertFront(&head, 20);
    insertFront(&head, 30);
    insertEnd(&head, 40);
    printList(head);
    deleteKey(&head, 20);
    deletePos(&head, 2);
    printList(head);
    return 0;
}