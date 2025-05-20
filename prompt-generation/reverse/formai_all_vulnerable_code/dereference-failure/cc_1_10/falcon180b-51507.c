//Falcon-180B DATASET v1.0 Category: Sorting ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define the structure of each node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of the linked list itself
typedef struct list {
    Node* head;
    Node* tail;
    int size;
} List;

// Create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Add a new node to the end of the list
void addNode(List* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

// Remove a node with the given data from the list
void removeNode(List* list, int data) {
    Node* currNode = list->head;
    Node* prevNode = NULL;
    while (currNode!= NULL && currNode->data!= data) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    if (currNode!= NULL) {
        if (prevNode == NULL) {
            list->head = currNode->next;
        } else {
            prevNode->next = currNode->next;
        }
        if (currNode == list->tail) {
            list->tail = prevNode;
        }
        free(currNode);
        list->size--;
    }
}

// Sort the list using bubble sort
void bubbleSort(List* list) {
    int swapped;
    Node* currNode;
    do {
        swapped = 0;
        currNode = list->head;
        while (currNode!= NULL && currNode->next!= NULL) {
            if (currNode->data > currNode->next->data) {
                int temp = currNode->data;
                currNode->data = currNode->next->data;
                currNode->next->data = temp;
                swapped = 1;
            }
            currNode = currNode->next;
        }
    } while (swapped);
}

// Print the list
void printList(List* list) {
    Node* currNode = list->head;
    while (currNode!= NULL) {
        printf("%d -> ", currNode->data);
        currNode = currNode->next;
    }
    printf("NULL\n");
}

int main() {
    List myList;
    myList.head = NULL;
    myList.tail = NULL;
    myList.size = 0;

    addNode(&myList, 5);
    addNode(&myList, 3);
    addNode(&myList, 8);
    addNode(&myList, 4);
    addNode(&myList, 2);

    printf("Before sorting:\n");
    printList(&myList);

    bubbleSort(&myList);

    printf("After sorting:\n");
    printList(&myList);

    removeNode(&myList, 2);

    printf("After removing 2:\n");
    printList(&myList);

    removeNode(&myList, 5);

    printf("After removing 5:\n");
    printList(&myList);

    removeNode(&myList, 8);

    printf("After removing 8:\n");
    printList(&myList);

    return 0;
}