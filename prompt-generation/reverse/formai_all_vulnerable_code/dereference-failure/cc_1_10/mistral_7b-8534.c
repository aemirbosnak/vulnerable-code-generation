//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    int data;
    char name[20];
    struct Node* next;
} Node;

Node* createNode(int data, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL)
        current = current->next;

    current->next = newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d - %s -> ", current->data, current->name);
        current = current->next;
    }
    printf("NULL\n");
}

void generateRandomData(Node** head, int numNodes) {
    srand(time(NULL));
    for (int i = 0; i < numNodes; i++) {
        int data = rand() % 100;
        char name[20];
        sprintf(name, "Node%d", i + 1);
        Node* newNode = createNode(data, name);
        insertAtEnd(head, newNode);
    }
}

int main() {
    Node* head = NULL;
    int numNodes = 10;

    generateRandomData(&head, numNodes);
    printf("Linked List before deletion:\n");
    printList(head);

    Node* current = head;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            Node* temp = current->next;
            free(current);
            current = temp;
        } else {
            current = current->next;
        }
    }

    printf("Linked List after deleting even numbered data:\n");
    printList(head);

    return 0;
}