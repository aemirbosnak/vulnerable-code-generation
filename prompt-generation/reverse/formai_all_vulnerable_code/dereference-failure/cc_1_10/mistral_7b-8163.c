//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    char name[20];
    struct Node *next;
} Node;

Node* createNode(int data, char name[]) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtBeginning(Node *head, Node *newNode) {
    newNode->next = head;
    head = newNode;
    return head;
}

Node* insertAtEnd(Node *head, Node *newNode) {
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

void printList(Node *head) {
    Node *current = head;
    printf("\nList is happy:\n");
    while (current != NULL) {
        printf("%d, %s -> ", current->data, current->name);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    int data, i;
    char name[20];

    printf("Inserting nodes with data and names happily:\n");
    for (i = 0; i < 5; i++) {
        printf("Enter data: ");
        scanf("%d", &data);
        printf("Enter name: ");
        scanf("%s", name);
        Node *newNode = createNode(data, name);
        head = insertAtBeginning(head, newNode);
    }

    printList(head);

    printf("\nInserting nodes with data and names at the end happily:\n");
    for (i = 0; i < 5; i++) {
        printf("Enter data: ");
        scanf("%d", &data);
        printf("Enter name: ");
        scanf("%s", name);
        Node *newNode = createNode(data, name);
        head = insertAtEnd(head, newNode);
    }

    printList(head);

    return 0;
}