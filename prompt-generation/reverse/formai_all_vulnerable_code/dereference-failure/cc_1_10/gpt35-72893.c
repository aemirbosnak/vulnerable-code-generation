//FormAI DATASET v1.0 Category: Data structures visualization ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void push(Node **head, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node *head) {
    printf("List: ");
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void deleteList(Node **head) {
    Node *current = *head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    Node *head = NULL;
    
    push(&head, 5);
    push(&head, 10);
    push(&head, 15);
    push(&head, 20);
    push(&head, 25);
    
    printList(head);
    
    deleteList(&head);
    
    printf("List deleted!\n");
    
    return 0;
}