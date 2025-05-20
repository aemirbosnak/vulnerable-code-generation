//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Node structure representing graph vertices
typedef struct node {
    int value;   // Vertex value
    int color;   // Color assigned to the vertex (-1 indicates uncolored)
    struct node* next;  // Pointer to the next vertex
} node;

// Graph structure
typedef struct graph {
    int num_vertices;  // Number of vertices in the graph
    node** adj_list;   // Array of linked lists representing adjacency lists
} graph;

// Function to create a new graph with num_vertices vertices
graph* create_graph(int num_vertices) {
    // Allocate memory for the graph
    graph* g = (graph*)malloc(sizeof(graph));

    // Initialize the number of vertices
    g->num_vertices = num_vertices;

    // Allocate memory for the adjacency list
    g->adj_list = (node**)malloc(sizeof(node*) * num_vertices);

    // Initialize the adjacency list to NULL
    for (int i = 0; i < num_vertices; i++) {
        g->adj_list[i] = NULL;
    }

    return g;
}

// Function to add an edge to the graph
void add_edge(graph* g, int u, int v) {
    // Create new nodes for the vertices u and v if they don't exist
    if (g->adj_list[u] == NULL) {
        g->adj_list[u] = (node*)malloc(sizeof(node));
        g->adj_list[u]->value = u;
        g->adj_list[u]->color = -1;
        g->adj_list[u]->next = NULL;
    }
    if (g->adj_list[v] == NULL) {
        g->adj_list[v] = (node*)malloc(sizeof(node));
        g->adj_list[v]->value = v;
        g->adj_list[v]->color = -1;
        g->adj_list[v]->next = NULL;
    }

    // Add the edge between u and v
    node* new_node = (node*)malloc(sizeof(node));
    new_node->value = v;
    new_node->color = -1;
    new_node->next = g->adj_list[u]->next;
    g->adj_list[u]->next = new_node;
}

// Function to check if the graph is complete
int is_complete(graph* g) {
    // A graph is complete if there is an edge between every pair of vertices
    for (int i = 0; i < g->num_vertices; i++) {
        node* curr = g->adj_list[i];
        while (curr != NULL) {
            if (curr->value == i) {
                return 0;  // A vertex cannot be connected to itself
            }
            curr = curr->next;
        }
        for (int j = i + 1; j < g->num_vertices; j++) {
            if (g->adj_list[j] == NULL || g->adj_list[j]->next == NULL) {
                return 0;  // There must be an edge between every pair of vertices
            }
        }
    }

    return 1;
}

// Function to check if the graph is 2-colorable
int is_2_colorable(graph* g) {
    // A graph is 2-colorable if it is complete and bipartite
    if (!is_complete(g)) {
        return 0;  // A graph that is not complete cannot be 2-colorable
    }

    // Perform a depth-first search to check if the graph is bipartite
    int* visited = (int*)malloc(sizeof(int) * g->num_vertices);
    int* color = (int*)malloc(sizeof(int) * g->num_vertices);
    for (int i = 0; i < g->num_vertices; i++) {
        visited[i] = 0;
        color[i] = -1;
    }

    int stack[g->num_vertices];
    int top = -1;
    int u = 0;
    while (u != -1) {
        if (visited[u] == 0) {
            stack[++top] = u;
            visited[u] = 1;
            color[u] = 0;
        }
        else if (visited[u] == 1) {
            color[u] = 1 - color[stack[top--]];
        }
        int v = g->adj_list[u]->next->value;
        if (visited[v] == 0) {
            u = v;
        }
        else if (color[u] == color[v]) {
            return 0;  // The graph is not bipartite
        }
        else {
            u = stack[top--];
        }
    }

    return 1;  // The graph is bipartite and hence 2-colorable
}

// Function to print the graph coloring
void print_coloring(graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d: Color %d\n", g->adj_list[i]->value, g->adj_list[i]->color);
    }
}

int main() {
    // Create a graph with 4 vertices
    graph* g = create_graph(4);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 0, 3);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);

    // Check if the graph is 2-colorable
    if (is_2_colorable(g)) {
        // Color the graph
        int colors[] = {0, 1};
        for (int i = 0; i < g->num_vertices; i++) {
            g->adj_list[i]->color = colors[i];
        }

        // Print the graph coloring
        printf("Graph Coloring:\n");
        print_coloring(g);
    }
    else {
        printf("The graph is not 2-colorable.\n");
    }

    return 0;
}