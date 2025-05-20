//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct list {
    Node* head;
    Node* tail;
    int size;
} List;

void addToList(List* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

void printList(List* list) {
    if (list->size == 0) {
        printf("List is empty\n");
        return;
    }
    Node* current = list->head;
    printf("List: ");
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    List myList;
    myList.head = NULL;
    myList.tail = NULL;
    myList.size = 0;

    addToList(&myList, 1);
    addToList(&myList, 2);
    addToList(&myList, 3);
    addToList(&myList, 4);

    printf("List: ");
    printList(&myList);

    return 0;
}