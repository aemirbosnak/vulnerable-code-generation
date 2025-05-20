//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100

typedef struct {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node nodes[MAX_NODES];
    int size;
} LovelaceList;

void initList(LovelaceList* list) {
    list->size = 0;
}

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(LovelaceList* list, int data) {
    Node* newNode = createNode(data);
    if (list->size == 0) {
        list->nodes[0] = *newNode;
    } else {
        list->nodes[list->size - 1].next = newNode;
    }
    list->size++;
}

void displayList(LovelaceList list) {
    int i;
    for (i = 0; i < list.size; i++) {
        printf("%d -> ", list.nodes[i].data);
        if (list.size == i + 1) {
            printf("NULL\n");
        }
    }
}

int main() {
    LovelaceList lovelaceList;
    initList(&lovelaceList);
    addNode(&lovelaceList, 1);
    addNode(&lovelaceList, 2);
    addNode(&lovelaceList, 3);
    addNode(&lovelaceList, 4);
    displayList(lovelaceList);
    return 0;
}