//FormAI DATASET v1.0 Category: Linked list operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
    struct _node *prev;
} node;

typedef struct _list {
    node *head;
    node *tail;
    int size;
} list;

void init(list *l)
{
    // Initialize the list with null values
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;

    printf("A new list has been initiated. Watch as I shape shift the elements!\n");
}

void insert(list *l, int data)
{
    node *n = (node*) malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    n->prev = NULL;

    if (l->head == NULL) {
        // If the list is empty, set the head and tail to the new node
        l->head = n;
        l->tail = n;
    } else {
        // Otherwise, insert the new node at the tail
        node *temp = l->tail;
        temp->next = n;
        n->prev = temp;
        l->tail = n;
    }

    l->size++;

    // Shape shift the new node's value based on its position in the list
    if (l->size % 2 == 0) {
        n->data *= n->data;
        printf("The value of the node at index %d has been squared!\n", l->size - 1);
    } else {
        n->data += 10;
        printf("The value of the node at index %d has been increased by 10!\n", l->size - 1);
    }
}

void display(list *l)
{
    if (l->head == NULL) {
        printf("The list is empty!\n");
        return;
    }

    printf("The list contains: ");
    node *temp = l->head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void destroy(list *l)
{
    if (l->head == NULL) {
        printf("The list is already empty!\n");
        return;
    }

    while(l->head != NULL) {
        node *temp = l->head;
        l->head = temp->next;
        free(temp);
        l->size--;

        // Shape shift the next node's value based on its position in the list
        if (l->head != NULL) {
            if (l->size % 2 == 0) {
                l->head->data /= 2;
                printf("The value of the node at index 0 has been halved!\n");
            } else {
                l->head->data -= 5;
                printf("The value of the node at index 0 has been decreased by 5!\n");
            }
        }
    }

    l->tail = NULL;

    printf("The list has been destroyed and the shape shifting is complete!\n");
}

int main()
{
    list l;
    init(&l);

    insert(&l, 5);
    insert(&l, 10);
    insert(&l, 15);

    display(&l);

    destroy(&l);

    return 0;
}