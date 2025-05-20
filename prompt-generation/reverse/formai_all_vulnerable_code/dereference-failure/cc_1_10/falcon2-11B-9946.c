//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* insertAtBeginning(struct node* head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

struct node* insertAtEnd(struct node* head, int data) {
    struct node* newNode = createNode(data);
    struct node* current = head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

struct node* insertAtPosition(struct node* head, int data, int position) {
    struct node* newNode = createNode(data);
    if (position == 0) {
        return insertAtBeginning(head, data);
    } else {
        struct node* current = head;
        for (int i = 1; i < position; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        return head;
    }
}

void printList(struct node* head) {
    struct node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void deleteNode(struct node** head, int data) {
    struct node* current = *head;
    struct node* prev = NULL;
    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with data %d not found in the list\n", data);
        return;
    }
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

void deleteList(struct node** head) {
    struct node* current = *head;
    while (current!= NULL) {
        struct node* temp = current->next;
        free(current);
        current = temp;
    }
    *head = NULL;
}

int main() {
    struct node* head = NULL;
    head = insertAtBeginning(head, 1);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 4);
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 6);
    printList(head);
    printf("\n");
    deleteNode(&head, 5);
    printList(head);
    deleteList(&head);
    return 0;
}