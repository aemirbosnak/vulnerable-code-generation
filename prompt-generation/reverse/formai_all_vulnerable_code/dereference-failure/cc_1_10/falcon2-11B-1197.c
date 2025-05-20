//Falcon2-11B DATASET v1.0 Category: Searching algorithm ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* insert(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
    return (*head);
}

struct node* delete(struct node** head, int data) {
    struct node* temp = *head;
    struct node* prev = NULL;
    struct node* current = *head;

    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return *head;
    }

    if (prev == NULL) {
        *head = current->next;
        free(current);
        return *head;
    }

    prev->next = current->next;
    free(current);
    return *head;
}

void printList(struct node* head) {
    struct node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 7);
    insert(&head, 8);
    insert(&head, 9);

    printList(head);
    printf("Deleting 6\n");
    delete(&head, 6);
    printList(head);

    printf("Deleting 3\n");
    delete(&head, 3);
    printList(head);

    printf("Deleting 8\n");
    delete(&head, 8);
    printList(head);

    printf("Deleting 4\n");
    delete(&head, 4);
    printList(head);

    return 0;
}