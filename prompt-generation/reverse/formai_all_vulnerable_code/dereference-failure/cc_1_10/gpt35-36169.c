//FormAI DATASET v1.0 Category: Linked list operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct List {
    struct Node *head;
    int size;
};

void insert(struct List *list, int value, int position) {
    if (position < 0 || position > list->size) {
        printf("Error: index out of bounds\n");
        return;
    }
    
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    
    if (position == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        struct Node *currentNode = list->head;
        for (int i = 0; i < position - 1; i++) {
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
    list->size++;
}

void removeNode(struct List *list, int position) {
    if (position < 0 || position >= list->size) {
        printf("Error: index out of bounds\n");
        return;
    }
    
    struct Node *currentNode = list->head;
    if (position == 0) {
        list->head = currentNode->next;
        free(currentNode);
    } else {
        for (int i = 0; i < position - 1; i++) {
            currentNode = currentNode->next;
        }
        struct Node *nodeToRemove = currentNode->next;
        currentNode->next = nodeToRemove->next;
        free(nodeToRemove);
    }
    list->size--;
}

void printList(struct List *list) {
    struct Node *currentNode = list->head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    struct List myList;
    myList.head = NULL;
    myList.size = 0;
    
    insert(&myList, 0, 0);
    insert(&myList, 1, 1);
    insert(&myList, 2, 2);
    printList(&myList);
    
    removeNode(&myList, 1);
    printList(&myList);
    
    insert(&myList, 3, 2);
    printList(&myList);
    
    removeNode(&myList, 0);
    printList(&myList);
    
    return 0;
}