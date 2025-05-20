//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORK_SIZE 100

typedef struct Node {
    char name[20];
    struct Node* next;
    struct Node* prev;
    struct Node* up;
    struct Node* down;
} Node;

Node* createNode(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->up = NULL;
    newNode->down = NULL;
    return newNode;
}

void addNode(Node* node, char* name) {
    Node* newNode = createNode(name);
    if (node->next) {
        node->next->prev = newNode;
    } else {
        node->next = newNode;
    }
    newNode->prev = node;
}

void mapNetwork(Node* node) {
    printf("Node: %s\n", node->name);
    printf("-----------------------\n");
    printf("Up: ");
    if (node->up) {
        printf("%s\n", node->up->name);
    } else {
        printf("None\n");
    }
    printf("Down: ");
    if (node->down) {
        printf("%s\n", node->down->name);
    } else {
        printf("None\n");
    }
    printf("Left: ");
    if (node->prev) {
        printf("%s\n", node->prev->name);
    } else {
        printf("None\n");
    }
    printf("Right: ");
    if (node->next) {
        printf("%s\n", node->next->name);
    } else {
        printf("None\n");
    }
    printf("-----------------------\n");
}

int main() {
    Node* head = createNode("A");
    addNode(head, "B");
    addNode(head, "C");
    addNode(head, "D");
    addNode(head, "E");

    mapNetwork(head);

    return 0;
}