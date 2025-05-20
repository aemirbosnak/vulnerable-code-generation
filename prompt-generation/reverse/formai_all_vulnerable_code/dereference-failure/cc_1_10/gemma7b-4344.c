//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
    char name[MAX];
    struct Node* next;
} Node;

void createGraph(Node** head) {
    *head = NULL;
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, "A");
    newNode->next = NULL;
    *head = newNode;
}

void addVertex(Node** head, char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    Node* traverse = *head;
    if (traverse == NULL) {
        *head = newNode;
    } else {
        while (traverse->next) {
            traverse = traverse->next;
        }
        traverse->next = newNode;
    }
}

void printGraph(Node* head) {
    while (head) {
        printf("%s ", head->name);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* graph = NULL;
    createGraph(&graph);
    addVertex(graph, "B");
    addVertex(graph, "C");
    addVertex(graph, "D");
    printGraph(graph);
    return 0;
}