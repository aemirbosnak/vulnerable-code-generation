//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

/* Graph representation: Adjacency list */
struct adj_list {
    int vertex;  /* Vertex number */
    struct adj_list *next;  /* Pointer to the next adjacent vertex */
};

/* Graph representation: Adjacency list head */
struct adj_list_head {
    int num_vertices;  /* Number of vertices in the graph */
    struct adj_list **heads;  /* Array of pointers to the adjacency lists */
};

/* Create a new graph with n vertices */
struct adj_list_head *create_graph(int n) {
    struct adj_list_head *g = malloc(sizeof(struct adj_list_head));
    if (g == NULL) {
        return NULL;
    }
    g->num_vertices = n;
    g->heads = malloc(n * sizeof(struct adj_list *));
    if (g->heads == NULL) {
        free(g);
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        g->heads[i] = NULL;
    }
    return g;
}

/* Add an edge between vertices u and v */
void add_edge(struct adj_list_head *g, int u, int v) {
    struct adj_list *new_node = malloc(sizeof(struct adj_list));
    if (new_node == NULL) {
        return;
    }
    new_node->vertex = v;
    new_node->next = g->heads[u];
    g->heads[u] = new_node;
}

/* Print the graph */
void print_graph(struct adj_list_head *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        struct adj_list *curr = g->heads[i];
        printf("Vertex %d: ", i);
        while (curr != NULL) {
            printf("%d ", curr->vertex);
            curr = curr->next;
        }
        printf("\n");
    }
}

/* Free the graph */
void free_graph(struct adj_list_head *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        struct adj_list *curr = g->heads[i];
        while (curr != NULL) {
            struct adj_list *next = curr->next;
            free(curr);
            curr = next;
        }
    }
    free(g->heads);
    free(g);
}

int main() {
    /* Create a graph with 5 vertices */
    struct adj_list_head *g = create_graph(5);

    /* Add edges to the graph */
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);

    /* Print the graph */
    print_graph(g);

    /* Free the graph */
    free_graph(g);

    return 0;
}