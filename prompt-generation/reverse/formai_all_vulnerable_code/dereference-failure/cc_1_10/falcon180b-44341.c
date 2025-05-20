//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int size;
    struct node* next;
} node;

node* createNode(char* data, int size) {
    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->data, data);
    newNode->size = size;
    newNode->next = NULL;
    return newNode;
}

void addNode(node** head, char* data, int size) {
    node* newNode = createNode(data, size);
    if (*head == NULL) {
        *head = newNode;
    } else {
        node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Data in the list:\n");
    while (head!= NULL) {
        printf("Data: %s, Size: %d\n", head->data, head->size);
        head = head->next;
    }
}

void freeList(node* head) {
    if (head == NULL) {
        return;
    }
    node* temp = head;
    while (temp!= NULL) {
        node* nextTemp = temp->next;
        free(temp);
        temp = nextTemp;
    }
}

int main() {
    node* head = NULL;
    addNode(&head, "Hello", 5);
    addNode(&head, "World", 5);
    addNode(&head, "How", 3);
    addNode(&head, "are", 3);
    addNode(&head, "you", 3);
    printList(head);
    freeList(head);
    return 0;
}