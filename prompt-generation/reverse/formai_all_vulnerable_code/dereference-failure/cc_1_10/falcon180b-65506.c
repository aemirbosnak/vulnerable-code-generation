//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

typedef struct {
    node* head;
    int size;
} linkedlist;

void init(linkedlist* list) {
    list->head = NULL;
    list->size = 0;
}

bool isempty(linkedlist* list) {
    return list->head == NULL;
}

void push(linkedlist* list, int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    if (isempty(list)) {
        list->head = newnode;
    } else {
        node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    list->size++;
}

int pop(linkedlist* list) {
    int data;
    node* temp = list->head;

    if (isempty(list)) {
        printf("List is empty\n");
        exit(1);
    }

    data = temp->data;
    list->head = temp->next;
    free(temp);

    list->size--;

    return data;
}

void printlist(linkedlist* list) {
    node* temp = list->head;

    if (isempty(list)) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    linkedlist llist;
    init(&llist);

    push(&llist, 10);
    push(&llist, 20);
    push(&llist, 30);
    push(&llist, 40);
    push(&llist, 50);

    printf("List after pushing elements: ");
    printlist(&llist);

    int popped = pop(&llist);
    printf("Popped element: %d\n", popped);

    printf("List after popping an element: ");
    printlist(&llist);

    return 0;
}