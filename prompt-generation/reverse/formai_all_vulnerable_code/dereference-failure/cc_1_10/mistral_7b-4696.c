//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    char name[20];
    struct Node* next;
} Node;

Node* createNode(int data, char* name) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, int data, char* name) {
    Node* newNode = createNode(data, name);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayList(Node* head) {
    Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("(%d, %s) -> ", current->data, current->name);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    addNode(&head, 1, "Apple");
    addNode(&head, 2, "Banana");
    addNode(&head, 3, "Cherry");
    addNode(&head, 4, "Durian");
    displayList(head);

    free(head);
    return 0;
}