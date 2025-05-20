//FormAI DATASET v1.0 Category: Graph representation ; Style: innovative
/* 
   This program generates a graph representation using adjacency matrix 
   and adjacency list implementation in C language. The graph is undirected.
*/

#include<stdio.h>
#include<stdlib.h>

/* Defining the maximum number of vertices allowed */
#define MAX_VERTICES 100

/* Structure to define each node for the adjacency list */
struct node {
    int vertex;
    struct node* next;
};

/* Structure to define the entire adjacency list */
struct adj_list {
    struct node *head;
};

/* Graph structure using adjacency list */
struct graph_adj_list {
    int num_vertices;
    struct adj_list adj_list_array[MAX_VERTICES];
};

/* Graph structure using adjacency matrix */
struct graph_adj_matrix {
    int num_vertices;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
};

/* Function to initialize the adjacency list */
void init_adj_list(struct graph_adj_list *g) {
    int i;
    for(i=0; i<g->num_vertices; i++) {
        g->adj_list_array[i].head = NULL;
    }
}

/* Function to add an edge to the graph using adjacency list */
void add_edge_adj_list(struct graph_adj_list *g, int src, int dest) {
    /* Adding edge from source to destination */
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->vertex = dest;
    new_node->next = g->adj_list_array[src].head;
    g->adj_list_array[src].head = new_node;
    /* Adding edge from destination to source */
    new_node = (struct node*) malloc(sizeof(struct node));
    new_node->vertex = src;
    new_node->next = g->adj_list_array[dest].head;
    g->adj_list_array[dest].head = new_node;
}

/* Function to initialize the adjacency matrix */
void init_adj_matrix(struct graph_adj_matrix *g) {
    int i, j;
    for(i=0; i<g->num_vertices; i++) {
        for(j=0; j<g->num_vertices; j++) {
            g->adj_matrix[i][j] = 0;
        }
    }
}

/* Function to add an edge to the graph using adjacency matrix */
void add_edge_adj_matrix(struct graph_adj_matrix *g, int src, int dest) {
    g->adj_matrix[src][dest] = 1;
    g->adj_matrix[dest][src] = 1;
}

/* Function to print the graph using adjacency list */
void print_graph_adj_list(struct graph_adj_list *g) {
    int i;
    for(i=0; i<g->num_vertices; i++) {
        struct node* ptr = g->adj_list_array[i].head;
        printf("Adjacency list of vertex %d -> ", i);
        while(ptr != NULL) {
            printf("%d -> ", ptr->vertex);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

/* Function to print the graph using adjacency matrix */
void print_graph_adj_matrix(struct graph_adj_matrix *g) {
    int i, j;
    for(i=0; i<g->num_vertices; i++) {
        for(j=0; j<g->num_vertices; j++) {
            printf("%d ", g->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct graph_adj_list G_adj_list;
    struct graph_adj_matrix G_adj_matrix;

    /* Initialize the graph */
    G_adj_list.num_vertices = 5;
    G_adj_matrix.num_vertices = 5;

    /* Initialize adjacency list and adjacency matrix */
    init_adj_list(&G_adj_list);
    init_adj_matrix(&G_adj_matrix);

    /* Adding edges to the graph */
    add_edge_adj_list(&G_adj_list, 0, 1);
    add_edge_adj_list(&G_adj_list, 0, 4);
    add_edge_adj_list(&G_adj_list, 1, 2);
    add_edge_adj_list(&G_adj_list, 1, 3);
    add_edge_adj_list(&G_adj_list, 1, 4);
    add_edge_adj_list(&G_adj_list, 2, 3);
    add_edge_adj_list(&G_adj_list, 3, 4);

    add_edge_adj_matrix(&G_adj_matrix, 0, 1);
    add_edge_adj_matrix(&G_adj_matrix, 0, 4);
    add_edge_adj_matrix(&G_adj_matrix, 1, 2);
    add_edge_adj_matrix(&G_adj_matrix, 1, 3);
    add_edge_adj_matrix(&G_adj_matrix, 1, 4);
    add_edge_adj_matrix(&G_adj_matrix, 2, 3);
    add_edge_adj_matrix(&G_adj_matrix, 3, 4);

    /* Printing adjacency list and adjacency matrix */
    printf("Adjacency list representation of the graph:\n");
    print_graph_adj_list(&G_adj_list);
    printf("\nAdjacency matrix representation of the graph:\n");
    print_graph_adj_matrix(&G_adj_matrix);

    return 0;
}