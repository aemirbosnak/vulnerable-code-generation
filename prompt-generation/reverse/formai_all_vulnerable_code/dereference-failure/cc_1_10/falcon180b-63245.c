//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct node {
    char name[MAX_NAME_LENGTH];
    int age;
    struct node* next;
} Node;

Node* createNode(char* name, int age) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->next = NULL;
    return newNode;
}

Node* addNode(Node* head, char* name, int age) {
    Node* newNode = createNode(name, age);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    Node* currentNode = head;
    while (currentNode->next!= NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    return head;
}

Node* deleteNode(Node* head, char* name) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if (strcmp(head->name, name) == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* currentNode = head;
    while (currentNode->next!= NULL && strcmp(currentNode->next->name, name)!= 0) {
        currentNode = currentNode->next;
    }
    if (currentNode->next == NULL) {
        printf("Node not found.\n");
    } else {
        Node* temp = currentNode->next;
        currentNode->next = currentNode->next->next;
        free(temp);
    }
    return head;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* currentNode = head;
    while (currentNode!= NULL) {
        printf("%s %d\n", currentNode->name, currentNode->age);
        currentNode = currentNode->next;
    }
}

int main() {
    Node* head = NULL;
    head = addNode(head, "John", 25);
    head = addNode(head, "Jane", 30);
    head = addNode(head, "Bob", 20);
    head = addNode(head, "Alice", 28);
    printList(head);
    head = deleteNode(head, "Bob");
    printList(head);
    head = deleteNode(head, "Alice");
    printList(head);
    head = deleteNode(head, "Jane");
    printList(head);
    head = deleteNode(head, "John");
    printList(head);
    return 0;
}