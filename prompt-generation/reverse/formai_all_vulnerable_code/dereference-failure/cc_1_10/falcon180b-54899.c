//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* addNode(struct node* head, int data) {
    struct node* newNode = createNode(data);
    struct node* temp = head;
    if (head == NULL) {
        head = newNode;
        return head;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void addEdge(struct node* head, int u, int v) {
    struct node* newNode = createNode(v);
    struct node* temp = head;
    if (head == NULL) {
        head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, m, u, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    struct node* graph = NULL;
    for (int i = 0; i < n; i++) {
        graph = addNode(graph, i);
    }
    for (int i = 0; i < m; i++) {
        printf("Enter the edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }
    printf("Adjacency list representation of the graph:\n");
    printList(graph);
    return 0;
}