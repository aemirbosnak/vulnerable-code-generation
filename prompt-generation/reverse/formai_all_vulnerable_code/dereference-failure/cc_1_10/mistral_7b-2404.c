//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    char name[20];
    struct Node* next;
} Node;

Node* head = NULL;
Node* temp = NULL;

void initList() {
    head = NULL;
}

void displayList() {
    Node* travel = head;
    printf("Linked List: \n");
    printf("Data\tName\tAddress\n");
    while (travel != NULL) {
        printf("%d\t%s\t%p\n", travel->data, travel->name, (void*) travel);
        travel = travel->next;
    }
}

void addNodeAtEnd(int data, char* name) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void addNodeAtBeginning(int data, char* name) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    strcpy(newNode->name, name);
    newNode->next = head;
    head = newNode;
}

int deleteNodeAtPosition(int position) {
    Node* current = head, *previous = NULL;
    int count = 0;

    if (head == NULL) {
        return -1;
    }

    while (current != NULL && count < position) {
        previous = current;
        current = current->next;
        count++;
    }

    if (current == NULL) {
        return -1;
    }

    previous->next = current->next;
    free(current);

    return 1;
}

Node* searchNode(int data) {
    Node* current = head;

    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

int main() {
    initList();
    addNodeAtBeginning(1, "John");
    addNodeAtEnd(2, "Mike");
    addNodeAtEnd(3, "Bob");
    addNodeAtBeginning(0, "Eve");

    displayList();

    printf("\nDeleted Node at position 3: \n");
    deleteNodeAtPosition(3);
    displayList();

    printf("\nSearching for Node with Data: 2\n");
    Node* searchedNode = searchNode(2);
    if (searchedNode != NULL) {
        printf("Data: %d, Name: %s\n", searchedNode->data, searchedNode->name);
    } else {
        printf("Node not found\n");
    }

    return 0;
}