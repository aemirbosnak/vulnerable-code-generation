//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int data;
    struct node *next;
};

struct list {
    struct node *head;
    struct node *tail;
};

struct list* createList() {
    struct list* list = (struct list*)malloc(sizeof(struct list));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void addNode(struct list* list, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void printList(struct list* list) {
    struct node* curr = list->head;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    struct list* list = createList();
    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    printList(list);
    
    return 0;
}