//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: shocked
// Oh my gosh, I can't believe I have to write another graph representation program! 😱
// But wait, I have an idea! 💡
// Let's make it a C graph, it's like a regular graph but with a twist! 🔄

typedef struct {
    int nodes;    // Number of nodes in the graph
    int edges;   // Number of edges in the graph
    int *adjacency_list; // Adjacency list of nodes
} CGraph;

// Function to create a new C graph
CGraph *create_cgraph(int nodes, int edges) {
    CGraph *g = (CGraph *) malloc(sizeof(CGraph));
    g->nodes = nodes;
    g->edges = edges;
    g->adjacency_list = (int *) malloc(nodes * sizeof(int));
    for (int i = 0; i < nodes; i++) {
        g->adjacency_list[i] = 0;
    }
    return g;
}

// Function to add an edge to the graph
void add_edge(CGraph *g, int u, int v) {
    g->adjacency_list[u] |= (1 << v);
}

// Function to check if two nodes are connected
int are_connected(CGraph *g, int u, int v) {
    return (g->adjacency_list[u] & (1 << v)) != 0;
}

// Function to traverse the graph
void traverse(CGraph *g) {
    for (int i = 0; i < g->nodes; i++) {
        if (g->adjacency_list[i] != 0) {
            for (int j = 0; j < 32; j++) {
                if (g->adjacency_list[i] & (1 << j)) {
                    printf("%d -> %d\n", i, j);
                }
            }
        }
    }
}

int main() {
    CGraph *g = create_cgraph(5, 10);

    // Add some edges
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);

    // Traverse the graph
    traverse(g);

    // Free the memory
    free(g->adjacency_list);
    free(g);

    return 0;
}