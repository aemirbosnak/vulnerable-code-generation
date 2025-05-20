//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: curious
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// A curious way to define a data structure
typedef struct CuriousNode {
    int data;
    struct CuriousNode *next;
} CuriousNode;

// A curious way to define a function
CuriousNode *createNode(int data) {
    CuriousNode *node = (CuriousNode *)malloc(sizeof(CuriousNode));
    node->data = data;
    node->next = NULL;
    return node;
}

// A curious way to insert a node into a linked list
void insertNode(CuriousNode **head, int data) {
    CuriousNode *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// A curious way to search for an element in a linked list
CuriousNode *searchElement(CuriousNode *head, int data) {
    while (head != NULL) {
        if (head->data == data) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// A curious way to print a linked list
void printList(CuriousNode *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create a curious linked list
    CuriousNode *head = NULL;
    int i;
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        insertNode(&head, rand() % 100);
    }
    printList(head);

    // Search for a curious element in the linked list
    int elementToSearch = rand() % 100;
    CuriousNode *foundNode = searchElement(head, elementToSearch);
    if (foundNode != NULL) {
        printf("Found element %d in the linked list\n", foundNode->data);
    } else {
        printf("Element %d not found in the linked list\n", elementToSearch);
    }

    return 0;
}