//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Node {
    int data;
    char name[20];
    struct Node *next;
} Node;

Node* createNode(int data, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d: %s\n", current->data, current->name);
        current = current->next;
    }
}

Node* partition(Node** head, int* pivotIndex) {
    Node* i = *head;
    Node* j = NULL;
    Node* pivot = NULL;
    int leftSize = 0;

    while (i != NULL) {
        if (i->data < *pivotIndex) {
            if (leftSize == 0) {
                pivot = i;
                j = i;
                leftSize++;
            } else {
                i->next = j->next;
                j->next = i;
            }
        }
        i = i->next;
    }

    *pivotIndex = leftSize;
    return pivot;
}

void quickSort(Node** head, int left, int right) {
    if (left >= right)
        return;

    int pivotIndex;
    Node* pivot = partition(head, &pivotIndex);

    quickSort(head, left, pivotIndex - 1);
    quickSort(head, pivotIndex + 1, right);
}

int main(int argc, char** argv) {
    int listSize = 7;
    Node* head = NULL;

    for (int i = 0; i < listSize; ++i) {
        char name[20];
        snprintf(name, sizeof(name), "Person_%d", i + 1);
        head = createNode(i, name);
        Node* current = head;
        while (current->next != NULL)
            current = current->next;
        current->next = createNode(rand() % 10, "Temp");
    }

    printf("Unsorted list:\n");
    printList(head);

    quickSort(&head, 0, listSize - 1);

    printf("\nSorted list:\n");
    printList(head);

    free(head);
    return 0;
}