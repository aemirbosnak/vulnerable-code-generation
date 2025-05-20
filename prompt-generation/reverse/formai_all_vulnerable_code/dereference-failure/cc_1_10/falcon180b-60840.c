//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct linkedList {
    Node *head;
    int size;
} LinkedList;

void initLinkedList(LinkedList *list) {
    list->head = NULL;
    list->size = 0;
}

void addNode(LinkedList *list, int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
    } else {
        Node *temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
    list->size++;
}

void deleteNode(LinkedList *list, int data) {
    Node *temp = list->head;
    Node *prev = NULL;

    if (temp!= NULL && temp->data == data) {
        list->head = temp->next;
        free(temp);
        list->size--;
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
    list->size--;
}

void printList(LinkedList *list) {
    Node *temp = list->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    LinkedList list;
    initLinkedList(&list);

    addNode(&list, 10);
    addNode(&list, 20);
    addNode(&list, 30);
    addNode(&list, 40);
    addNode(&list, 50);

    printf("List before deletion:\n");
    printList(&list);

    deleteNode(&list, 20);
    deleteNode(&list, 40);

    printf("List after deletion:\n");
    printList(&list);

    return 0;
}