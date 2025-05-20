//FormAI DATASET v1.0 Category: Graph representation ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

struct node {
    int key;
    struct node *next;
};

void add_edge(struct node** graph, int src, int dest) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->key = dest;
    newNode->next = graph[src];
    graph[src] = newNode;

    newNode = (struct node*) malloc(sizeof(struct node));
    newNode->key = src;
    newNode->next = graph[dest];
    graph[dest] = newNode;
}

void print_graph(struct node** graph, int vertices) {
    printf("The graph:\n");
    for(int i = 0; i < vertices; i++) {
        printf("Vertex %d: ", i);
        struct node* curr = graph[i];
        while(curr != NULL) {
            printf("%d -> ", curr->key);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    struct node** graph = (struct node**) malloc(sizeof(struct node*) * n);
    for(int i = 0; i < n; i++) {
        graph[i] = NULL;
    }

    printf("Enter the connections between the vertices:\n");
    for(int i = 0; i < m; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        add_edge(graph, src, dest);
        printf("Connected vertex %d with vertex %d\n", src, dest);
    }

    print_graph(graph, n);

    return 0;
}