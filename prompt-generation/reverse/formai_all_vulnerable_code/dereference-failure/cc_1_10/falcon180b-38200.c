//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Dennis Ritchie
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
} linkedList;

void init(linkedList* lst) {
    lst->head = NULL;
    lst->size = 0;
}

bool isEmpty(linkedList lst) {
    return lst.head == NULL;
}

void push(linkedList* lst, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(*lst)) {
        lst->head = newNode;
    } else {
        node* temp = lst->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    lst->size++;
}

int pop(linkedList* lst) {
    if (isEmpty(*lst)) {
        printf("Error: List is empty!\n");
        exit(1);
    }
    int data = lst->head->data;
    node* temp = lst->head;
    lst->head = lst->head->next;
    free(temp);
    lst->size--;
    return data;
}

void printList(linkedList lst) {
    if (isEmpty(lst)) {
        printf("Empty List!\n");
    } else {
        node* temp = lst.head;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    linkedList lst;
    init(&lst);

    push(&lst, 10);
    push(&lst, 20);
    push(&lst, 30);
    push(&lst, 40);
    push(&lst, 50);

    printf("List after pushing elements:\n");
    printList(lst);

    int poppedElement = pop(&lst);
    printf("Popped element: %d\n", poppedElement);

    printf("List after popping an element:\n");
    printList(lst);

    return 0;
}