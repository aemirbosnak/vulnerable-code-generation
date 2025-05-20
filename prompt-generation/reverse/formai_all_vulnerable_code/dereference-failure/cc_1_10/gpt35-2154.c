//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    char name[20];
    struct Node* next;
} Node;

typedef struct Edge {
    Node* from;
    Node* to;
} Edge;

Node* createNode(int id, char* name) {
    Node* node = malloc(sizeof(Node));
    node->id = id;
    strcpy(node->name, name);
    node->next = NULL;
    return node;
}

void connectNodes(Node* node1, Node* node2) {
    Edge* edge = malloc(sizeof(Edge));
    edge->from = node1;
    edge->to = node2;
    printf("Connected node %s (%d) to node %s (%d)\n", node1->name, node1->id, node2->name, node2->id);
}

void printNodes(Node* start) {
    Node* current = start;
    while (current != NULL) {
        printf("Node %d: %s\n", current->id, current->name);
        current = current->next;
    }
}

int main() {
    Node* node1 = createNode(1, "Router");
    Node* node2 = createNode(2, "Switch");
    Node* node3 = createNode(3, "Printer");
    Node* node4 = createNode(4, "Computer");
    Node* node5 = createNode(5, "Server");

    connectNodes(node1, node2);
    connectNodes(node1, node3);
    connectNodes(node2, node4);
    connectNodes(node2, node5);
    connectNodes(node3, node4);
    connectNodes(node4, node5);

    printNodes(node1);

    return 0;
}