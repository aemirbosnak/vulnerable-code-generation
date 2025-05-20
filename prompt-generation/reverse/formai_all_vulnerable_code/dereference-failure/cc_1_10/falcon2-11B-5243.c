//Falcon2-11B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct Node {
    int x;
    int y;
    int z;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    Node *tail;
    int size;
} List;

List *createList(int size) {
    List *list = (List *)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = size;
    return list;
}

void appendNode(List *list, int x, int y, int z) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->z = z;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

void printList(List *list) {
    Node *node = list->head;
    while (node!= NULL) {
        printf("(%d, %d, %d)\n", node->x, node->y, node->z);
        node = node->next;
    }
}

int main() {
    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    List *list = createList(size);
    printf("Enter the elements of the list: ");
    for (int i = 0; i < size; i++) {
        int x, y, z;
        printf("Enter x: ");
        scanf("%d", &x);
        printf("Enter y: ");
        scanf("%d", &y);
        printf("Enter z: ");
        scanf("%d", &z);
        appendNode(list, x, y, z);
    }
    printf("The list is: ");
    printList(list);
    return 0;
}