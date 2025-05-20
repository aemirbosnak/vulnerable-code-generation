//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct linkedlist {
    Node *head;
} LinkedList;

void create_linkedlist(LinkedList *list) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = 1;
    new_node->next = NULL;

    list->head = new_node;
}

void insert_node(LinkedList *list, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        return;
    }

    Node *current = list->head;
    while (current->next!= NULL) {
        current = current->next;
    }

    current->next = new_node;
}

void delete_node(LinkedList *list, int data) {
    Node *current = list->head;
    Node *prev = NULL;

    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    if (prev == NULL) {
        list->head = current->next;
        free(current);
        return;
    }

    prev->next = current->next;
    free(current);
}

int main() {
    LinkedList list;
    create_linkedlist(&list);
    insert_node(&list, 2);
    insert_node(&list, 4);
    insert_node(&list, 6);
    insert_node(&list, 8);
    delete_node(&list, 2);
    insert_node(&list, 10);

    Node *current = list.head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}