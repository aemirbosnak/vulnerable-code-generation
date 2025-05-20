//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createList() {
    Node* head = (Node*) malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    Node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteAtBeginning(Node** head) {
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(Node** head) {
    Node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = NULL;
    free(current);
}

int main() {
    Node* head = createList();
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printf("List before deletion: ");
    Node* current = head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\n");
    deleteAtEnd(&head);
    printf("List after deletion: ");
    current = head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\n");
    deleteAtBeginning(&head);
    printf("List after deletion: ");
    current = head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\n");
    return 0;
}