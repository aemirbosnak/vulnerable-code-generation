//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data[MAX_SIZE];
    int length;
    struct node* next;
} Node;

Node* createNode(char* data, int length) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->data, data, length);
    newNode->length = length;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, char* data, int length) {
    Node* newNode = createNode(data, length);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

int search(Node* head, char* data, int length) {
    Node* current = head;
    while (current!= NULL) {
        if (current->length == length && strncmp(current->data, data, length) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    char* data = "apple";
    int length = strlen(data);
    addNode(&head, data, length);
    data = "banana";
    length = strlen(data);
    addNode(&head, data, length);
    data = "pear";
    length = strlen(data);
    addNode(&head, data, length);
    data = "orange";
    length = strlen(data);
    addNode(&head, data, length);
    data = "grape";
    length = strlen(data);
    addNode(&head, data, length);
    int found = search(head, "banana", strlen("banana"));
    if (found) {
        printf("Found banana\n");
    } else {
        printf("Did not find banana\n");
    }
    printList(head);
    return 0;
}