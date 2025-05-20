//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    size_t size;
    struct Node* next;
} Node;

Node* createNode(int data, size_t size) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory error: Unable to allocate new Node\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->size = size;
    newNode->next = NULL;
    return newNode;
}

Node* addNode(Node* head, int data, size_t size) {
    Node* newNode = createNode(data, size);
    if (!head) {
        head = newNode;
        return head;
    }

    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

void printList(Node* head) {
    Node* current = head;
    printf("List contents:\n");
    while (current) {
        printf("Data: %d, Size: %zu, Next: %p\n", current->data, current->size, current->next);
        current = current->next;
    }
}

int main() {
    Node* myList = NULL;

    myList = addNode(myList, 5, sizeof(int));
    myList = addNode(myList, 10, sizeof(int));
    myList = addNode(myList, 15, sizeof(int));
    myList = addNode(myList, 20, sizeof(int));

    printList(myList);

    Node* temp = myList;
    while (myList) {
        temp = myList;
        myList = myList->next;
        free(temp);
    }

    printf("\nMemory is fully released.\n");

    return EXIT_SUCCESS;
}