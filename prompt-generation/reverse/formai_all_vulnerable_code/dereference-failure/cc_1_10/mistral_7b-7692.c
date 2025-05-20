//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_SIZE 1
#define ELEMENT_NOT_FOUND (-1)

typedef struct Node {
    int data;
    size_t size;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Memory error");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->size = sizeof(int);
    newNode->next = NULL;

    return newNode;
}

void append(Node** head, Node* newNode) {
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

void printList(Node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }

    Node* current = head;
    printf("List: [");
    while (current != NULL) {
        printf("%d,%lu", current->data, current->size);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");
}

int linearSearch(Node* head, int target) {
    Node* current = head;
    size_t index = 0;

    while (current != NULL) {
        if (current->data == target) {
            return index;
        }
        index++;
        current = current->next;
    }

    return ELEMENT_NOT_FOUND;
}

int main() {
    Node* list = NULL;

    int array[] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 10};
    int arraySize = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < arraySize; i++) {
        Node* newNode = createNode(array[i]);
        append(&list, newNode);
    }

    printList(list);

    int target = 5;
    int result = linearSearch(list, target);

    if (result != ELEMENT_NOT_FOUND) {
        printf("The first occurrence of %d is at index %ld\n", target, result);
    } else {
        printf("%d is not present in the list\n", target);
    }

    return EXIT_SUCCESS;
}