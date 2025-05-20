//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_DATA 100

struct Node {
    int data;
    struct Node *next;
};

struct List {
    struct Node *head;
    struct Node *tail;
};

void initList(struct List *list) {
    list->head = NULL;
    list->tail = NULL;
}

void addNode(struct List *list, int data) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
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

int getNodeData(struct List *list, int index) {
    int i = 0;
    struct Node *current = list->head;

    while (i < index) {
        current = current->next;
        i++;
    }

    return current->data;
}

void printList(struct List *list) {
    struct Node *current = list->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    struct List list;

    initList(&list);

    addNode(&list, 1);
    addNode(&list, 2);
    addNode(&list, 3);
    addNode(&list, 4);
    addNode(&list, 5);

    printList(&list);

    int data = getNodeData(&list, 3);
    printf("Node at index 3 has data %d\n", data);

    return 0;
}