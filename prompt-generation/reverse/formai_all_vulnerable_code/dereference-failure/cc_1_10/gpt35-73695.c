//FormAI DATASET v1.0 Category: Data structures visualization ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void printList(struct node *head) {
    printf("[ ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("]\n");
}

void insert(struct node **head, int val) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

void delete(struct node **head, int val) {
    struct node *prev = NULL;
    struct node *current = *head;
    while (current != NULL) {
        if (current->data == val) {
            if (prev == NULL) {
                *head = current->next;
                free(current);
                return;
            } else {
                prev->next = current->next;
                free(current);
                return;
            }
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    struct node *head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    printf("Before delete: ");
    printList(head);
    delete(&head, 3);
    printf("After delete: ");
    printList(head);
    return 0;
}