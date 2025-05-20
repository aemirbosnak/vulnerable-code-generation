//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int node;
    struct adj_list_node* next;
} adj_list_node;

typedef struct {
    adj_list_node* head;
} adj_list;

typedef struct {
    int v;
    int w;
} edge;

int num_nodes, num_edges;
adj_list adj_lists[MAX_NODES];

void add_edge(int u, int v, int w) {
    edge* new_edge = (edge*) malloc(sizeof(edge));
    new_edge->v = v;
    new_edge->w = w;
    adj_list_node* new_node = (adj_list_node*) malloc(sizeof(adj_list_node));
    new_node->node = v;
    new_node->next = adj_lists[u].head;
    adj_lists[u].head = new_node;
    num_edges++;
}

void print_graph() {
    printf("Graph:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: ", i);
        adj_list_node* curr_node = adj_lists[i].head;
        while (curr_node!= NULL) {
            printf("%d ", curr_node->node);
            curr_node = curr_node->next;
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    for (int i = 0; i < num_nodes; i++) {
        adj_lists[i].head = NULL;
    }

    printf("Enter the edges (u v w):\n");
    for (int i = 0; i < num_edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }

    print_graph();

    return 0;
}