//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteAtBeginning(struct Node** head) {
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(struct Node** head) {
    struct Node* current = *head;
    while (current->next->next!= NULL) {
        current = current->next;
    }
    struct Node* temp = current->next;
    current->next = NULL;
    free(temp);
}

int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 15);
    insertAtEnd(&head, 20);
    printList(head);
    printf("\n");

    deleteAtBeginning(&head);
    deleteAtEnd(&head);
    printList(head);

    return 0;
}