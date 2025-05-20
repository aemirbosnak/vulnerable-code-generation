//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// A node in a graph
typedef struct node {
    int id;
    struct node *next;
} node;

// A graph
typedef struct graph {
    int num_nodes;
    node *nodes;
} graph;

// Create a new graph
graph *create_graph() {
    graph *g = malloc(sizeof(graph));
    if (!g) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    g->num_nodes = 0;
    g->nodes = NULL;
    return g;
}

// Add a node to a graph
void add_node(graph *g, int id) {
    node *n = malloc(sizeof(node));
    if (!n) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    n->id = id;
    n->next = g->nodes;
    g->nodes = n;
    g->num_nodes++;
}

// Find a node in a graph by its ID
node *find_node(graph *g, int id) {
    node *n = g->nodes;
    while (n) {
        if (n->id == id) {
            return n;
        }
        n = n->next;
    }
    return NULL;
}

// Add an edge to a graph between two nodes
void add_edge(graph *g, int src, int dst) {
    node *src_node = find_node(g, src);
    node *dst_node = find_node(g, dst);
    assert(src_node && dst_node); // Nodes must exist before adding an edge

    node *new_edge = malloc(sizeof(node));
    if (!new_edge) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    new_edge->id = dst;
    new_edge->next = src_node->next;
    src_node->next = new_edge;
}

// Print a graph
void print_graph(graph *g) {
    node *n = g->nodes;
    while (n) {
        printf("Node %d: ", n->id);
        node *e = n->next;
        while (e) {
            printf("%d -> ", e->id);
            e = e->next;
        }
        printf("\n");
        n = n->next;
    }
}

// Free a graph
void free_graph(graph *g) {
    node *n = g->nodes;
    while (n) {
        node *next = n->next;
        free(n);
        n = next;
    }
    free(g);
}

// Topological sort of a graph
// - Returns an array of nodes in a topologically sorted order
// - If the graph contains a cycle, returns NULL
int *topological_sort(graph *g) {
    int *result = malloc(sizeof(int) * g->num_nodes);
    if (!result) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    int *visited = malloc(sizeof(int) * g->num_nodes);
    if (!visited) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < g->num_nodes; i++) {
        visited[i] = 0;
    }
    int index = 0;
    for (node *n = g->nodes; n; n = n->next) {
        if (!visited[n->id]) {
            if (!dfs(g, n, visited, result, &index)) {
                free(result);
                free(visited);
                return NULL;
            }
        }
    }
    free(visited);
    return result;
}

// DFS traversal of a graph
// - Recursively visits nodes in a depth-first manner
// - Detects cycles in the graph
int dfs(graph *g, node *n, int *visited, int *result, int *index) {
    visited[n->id] = 1;
    for (node *e = n->next; e; e = e->next) {
        if (!visited[e->id]) {
            if (!dfs(g, e, visited, result, index)) {
                return 0;
            }
        } else if (visited[e->id] == 1) {
            return 0; // Cycle detected
        }
    }
    visited[n->id] = 2;
    result[(*index)++] = n->id;
    return 1;
}

// Main function
int main() {
    // Create a graph
    graph *g = create_graph();

    // Add nodes to the graph
    add_node(g, 0);
    add_node(g, 1);
    add_node(g, 2);
    add_node(g, 3);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);

    // Print the graph
    printf("Graph:\n");
    print_graph(g);

    // Perform topological sort on the graph
    int *result = topological_sort(g);
    if (!result) {
        printf("Cycle detected in graph, topological sort not possible.\n");
    } else {
        printf("Topological sort:\n");
        for (int i = 0; i < g->num_nodes; i++) {
            printf("%d -> ", result[i]);
        }
        printf("\n");
    }

    // Free the graph
    free_graph(g);

    return 0;
}