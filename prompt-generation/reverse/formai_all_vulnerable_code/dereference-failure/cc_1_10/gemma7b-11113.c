//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTS 100

typedef struct Node {
    int index;
    struct Node* next;
    struct Node* prev;
} Node;

Node* CreateNode(int index) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->index = index;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void AddEdge(Node* node1, Node* node2) {
    node1->next = node2;
    node2->prev = node1;
}

void PrintTopology(Node* head) {
    Node* current = head;
    while (current) {
        printf("Vertex %d: ", current->index);
        Node* neighbor = current->next;
        while (neighbor) {
            printf("-> Neighbor %d ", neighbor->index);
            neighbor = neighbor->next;
        }
        printf("\n");
        current = current->next;
    }
}

int main() {
    Node* head = CreateNode(0);
    AddEdge(head, CreateNode(1));
    AddEdge(head, CreateNode(2));
    AddEdge(head, CreateNode(3));
    AddEdge(head, CreateNode(4));
    AddEdge(head, CreateNode(5));

    PrintTopology(head);

    return 0;
}