//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    char* name;
    struct Node* next;
} Node;

Node* createNode(int data, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->name = strdup(name);
    newNode->next = NULL;
    return newNode;
}

Node* insertAtBeginning(Node* head, int data, char* name) {
    Node* newNode = createNode(data, name);
    newNode->next = head;
    head = newNode;
    return head;
}

Node* insertAtEnd(Node* head, int data, char* name) {
    Node* newNode = createNode(data, name);

    if (head == NULL) {
        head = newNode;
        return head;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

void printList(Node* head) {
    Node* current = head;
    printf("--Linked List--\n");
    while (current != NULL) {
        printf("| Data: %d, Name: %s |-> ", current->data, current->name);
        current = current->next;
    }
    printf("NULL\n");
}

int main(void) {
    Node* head = NULL;

    head = insertAtBeginning(head, 5, "Five");
    head = insertAtBeginning(head, 3, "Three");
    head = insertAtBeginning(head, 1, "One");

    head = insertAtEnd(head, 8, "Eight");
    head = insertAtEnd(head, 6, "Six");
    head = insertAtEnd(head, 7, "Seven");

    printList(head);

    Node* temp = head;
    while (temp != NULL) {
        Node* nextTemp = temp->next;
        free(temp->name);
        free(temp);
        temp = nextTemp;
    }

    return 0;
}