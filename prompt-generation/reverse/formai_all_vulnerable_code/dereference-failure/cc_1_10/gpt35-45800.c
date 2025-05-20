//FormAI DATASET v1.0 Category: Data structures visualization ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void insertAtBeginning(struct node** head, int val) {
    struct node* newNode = createNode(val);

    newNode->next = *head;
    *head = newNode;

    printf("Inserted %d at the beginning.\n", val);
    printList(*head);
}

void insertAtEnd(struct node** head, int val) {
    struct node* newNode = createNode(val);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node* current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    printf("Inserted %d at the end.\n", val);
    printList(*head);
}

void deleteFromBeginning(struct node** head) {
    if (*head == NULL) {
        printf("List is already empty!");
    } else {
        struct node* temp = *head;

        *head = (*head)->next;
        free(temp);

        printf("Deleted from the beginning.\n");
        printList(*head);
    }
}

void deleteFromEnd(struct node** head) {
    if (*head == NULL) {
        printf("List is already empty!");
    } else {
        struct node* current = *head;
        struct node* previous = NULL;

        while (current->next) {
            previous = current;
            current = current->next;
        }

        if (previous == NULL) {
            *head = NULL;
        } else {
            previous->next = NULL;
        }

        free(current);

        printf("Deleted from the end.\n");
        printList(*head);
    }
}

int main() {
    struct node* head = NULL;

    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 20);

    deleteFromBeginning(&head);
    deleteFromEnd(&head);

    return 0;
}