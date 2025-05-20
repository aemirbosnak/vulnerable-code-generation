//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct LinkedArrayNode {
    int data;
    struct LinkedArrayNode *next;
} LinkedArrayNode;

void printLinkedList(LinkedArrayNode *head) {
    LinkedArrayNode *currentNode = head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\b\n");
}

void createLinkedListFromArray(LinkedArrayNode **head, int array[], int size) {
    for (int i = 0; i < size; i++) {
        LinkedArrayNode *newNode = (LinkedArrayNode *)malloc(sizeof(LinkedArrayNode));
        newNode->data = array[i];
        newNode->next = *head;
        *head = newNode;
    }
}

void swapNodes(LinkedArrayNode **node1, LinkedArrayNode **node2) {
    int tempData = (*node1)->data;
    (*node1)->data = (*node2)->data;
    (*node2)->data = tempData;

    LinkedArrayNode *tempNode = *node1;
    *node1 = *node2;
    *node2 = tempNode;
}

bool isSorted(LinkedArrayNode *head) {
    LinkedArrayNode *currentNode = head;
    LinkedArrayNode *nextNode = NULL;

    while (currentNode != NULL) {
        nextNode = currentNode->next;

        if (currentNode->data > nextNode->data) {
            return false;
        }

        currentNode = nextNode;
    }

    return true;
}

void bubbleSortLinkedList(LinkedArrayNode **head) {
    if (isSorted(*head)) {
        return;
    }

    LinkedArrayNode *currentNode = *head;
    LinkedArrayNode *nextNode = NULL;

    while (currentNode != NULL) {
        nextNode = currentNode->next;

        while (nextNode != NULL) {
            if (currentNode->data > nextNode->data) {
                swapNodes(&currentNode, &nextNode);
            }
            nextNode = nextNode->next;
        }

        currentNode = currentNode->next;
    }
}

int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 15};
    int size = sizeof(array) / sizeof(array[0]);

    LinkedArrayNode *head = NULL;

    createLinkedListFromArray(&head, array, size);
    printf("Unsorted Linked List: ");
    printLinkedList(head);

    bubbleSortLinkedList(&head);
    printf("Sorted Linked List: ");
    printLinkedList(head);

    free(head);
    return 0;
}