//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct node {
    char item[20];
    struct node* next;
};

void insertAtTail(struct node** head, char item[]) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->item, item);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void traverse(struct node* head) {
    if (head) {
        printf("%s ", head->item);
        traverse(head->next);
    }
}

void findItem(struct node* head, char item[]) {
    if (head) {
        if (strcmp(head->item, item) == 0) {
            printf("Item found: %s\n", head->item);
        } else {
            findItem(head->next, item);
        }
    }
}

int main() {
    struct node* head = NULL;
    insertAtTail(&head, "Apple");
    insertAtTail(&head, "Banana");
    insertAtTail(&head, "Orange");
    insertAtTail(&head, "Mango");
    insertAtTail(&head, "Grapes");

    traverse(head);
    findItem(head, "Banana");

    return 0;
}