//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char name[50];
    struct node *next;
} Node;

typedef struct list {
    Node *head;
    Node *tail;
} List;

List *createList() {
    List *newList = (List *)malloc(sizeof(List));
    if (newList == NULL) {
        return NULL;
    }
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}

void append(List *list, char *name) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return;
    }
    strcpy(newNode->name, name);
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void deleteList(List *list) {
    Node *current = list->head;
    Node *prev = NULL;
    while (current!= NULL) {
        Node *temp = current->next;
        free(current);
        current = temp;
    }
    free(list);
}

void printList(List *list) {
    Node *current = list->head;
    while (current!= NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

int main() {
    List *list = createList();
    append(list, "John");
    append(list, "Jane");
    append(list, "Bob");
    append(list, "Alice");
    printList(list);
    deleteList(list);
    return 0;
}