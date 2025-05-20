//FormAI DATASET v1.0 Category: Graph representation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

typedef struct Node* Graph;

void addEdge(Graph* graph, int u, int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = v;
    node->next = (*graph + u)->next;
    (*graph + u)->next = node;
}

void show(Graph graph, int n) {
    for(int i = 0; i < n; i++) {
        struct Node* curr = (graph + i)->next;
        printf("%d -> ", i);
        while(curr != NULL) {
            printf("%d ", curr->val);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main() {
    int n = 5;
    Graph graph = (Graph)malloc(sizeof(struct Node) * n);

    for (int i = 0; i < n; i++){
        (graph + i)->val = i;
        (graph + i)->next = NULL;
    }

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 3);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);

    show(graph, n);

    free(graph);

    return 0;
}