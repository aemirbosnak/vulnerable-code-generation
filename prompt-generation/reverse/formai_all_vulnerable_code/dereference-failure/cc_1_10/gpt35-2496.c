//FormAI DATASET v1.0 Category: Graph representation ; Style: brave
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

 void insert(struct node** head, int value) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;
        if (*head == NULL) {
            *head = newNode;
        }
        else {
            struct node* current = *head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

void printGraph(struct node** head, int total) {
    printf("The Graph:\n");
    for (int i = 0; i < total; i++) {
        printf("Vertex %d: ", i+1);
        struct node* current = head[i];
        while (current != NULL) {
            printf("-> %d ", current->data+1);
            current = current->next;
        }
        printf("\n");
    }
}

void main() {
    int vertices;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    struct node** graph = (struct node**)malloc(vertices * sizeof(struct node*));
    for (int i = 0; i < vertices; i++) {
        graph[i] = NULL;
    }
    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the vertices for each edge: \n");
    for (int j = 0; j < edges; j++) {
        int from;
        int to;
        printf("Edge %d:\n",j+1);
        printf("From Vertex: ");
        scanf("%d", &from);
        printf("To Vertex: ");
        scanf("%d", &to);
        insert(&graph[from-1], to-1);
    }
    printGraph(graph, vertices);
}