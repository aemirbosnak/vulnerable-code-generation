//FormAI DATASET v1.0 Category: Data structures visualization ; Style: lively
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

int main() {
    Node* head = NULL;
    
    printf("Welcome to the Linked List Visualizer!\n");
    printf("Here's our current list:\n");
    printList(head);
    
    printf("Let's add some elements to the list...\n");
    insertAtEnd(&head, 10);
    printf("Added 10 to the end of the list.\n");
    printList(head);
    insertAtEnd(&head, 20);
    printf("Added 20 to the end of the list.\n");
    printList(head);
    insertAtEnd(&head, 30);
    printf("Added 30 to the end of the list.\n");
    printList(head);
    insertAtEnd(&head, 40);
    printf("Added 40 to the end of the list.\n");
    printList(head);
    insertAtEnd(&head, 50);
    printf("Added 50 to the end of the list.\n");
    printList(head);

    return 0;
}