//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 100

typedef struct node {
    int id;
    char label[20];
    struct node* next;
} node;

node* addNode(node** head, int id, char* label) {
    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->label, label);
    newNode->id = id;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return newNode;
    }
    node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
    return newNode;
}

void addEdge(node* src, node* dest, int weight) {
    node* current = src->next;
    while (current!= dest) {
        if (current->id == dest->id) {
            printf("Edge already exists!\n");
            return;
        }
        current = current->next;
    }
    node* newEdge = (node*)malloc(sizeof(node));
    strcpy(newEdge->label, "Edge");
    newEdge->id = weight;
    newEdge->next = src->next;
    src->next = newEdge;
}

void printGraph(node* head) {
    node* current = head;
    while (current!= NULL) {
        printf("%s -> %s\n", current->label, current->next? current->next->label : "None");
        current = current->next;
    }
}

int main() {
    srand(time(NULL));
    node* head = NULL;
    int numNodes = 0;
    while (numNodes < MAX_NODES) {
        int id = rand() % 10;
        char label[20];
        sprintf(label, "Node %d", id);
        node* newNode = addNode(&head, id, label);
        numNodes++;
    }
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = i + 1; j < MAX_NODES; j++) {
            addEdge(head[i].next, head[j].next, rand() % 10);
        }
    }
    printGraph(head);
    return 0;
}