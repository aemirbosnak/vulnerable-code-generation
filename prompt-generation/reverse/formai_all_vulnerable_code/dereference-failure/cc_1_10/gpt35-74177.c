//FormAI DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

void printList(Node* head, int level) {
    if (head == NULL) {
        return;
    }
    
    printf("%*s", level * 4, "");
    printf("%d\n", head->value);
    
    printList(head->next, level + 1);
}

Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
}

void freeList(Node* head) {
    if (head == NULL) {
        return;
    }
    freeList(head->next);
    free(head);
}

int main() {
    Node* list = NULL;
    
    printf("Adding values to the list:\n");
    insertNode(&list, 5);
    insertNode(&list, 10);
    insertNode(&list, 15);
    
    printf("\nThe final list:\n");
    printList(list, 0);
    
    printf("\nCleaning up the list\n");
    freeList(list);
    
    return 0;
}