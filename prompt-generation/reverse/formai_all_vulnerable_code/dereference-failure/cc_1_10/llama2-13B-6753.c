//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: relaxed
// A relaxed graph representation in C

// Define the graph structure
typedef struct {
    int num_vertices;    // Number of vertices in the graph
    int *edges;        // Array of edges (vertex indices)
} graph_t;

// Function to create a new graph
graph_t *new_graph(int num_vertices) {
    graph_t *g = malloc(sizeof(graph_t));
    g->num_vertices = num_vertices;
    g->edges = malloc(num_vertices * sizeof(int));
    return g;
}

// Function to add an edge to the graph
void add_edge(graph_t *g, int v1, int v2) {
    g->edges[v1] = v2;
}

// Function to retrieve the number of edges in the graph
int get_num_edges(graph_t *g) {
    int num_edges = 0;
    for (int i = 0; i < g->num_vertices; i++) {
        num_edges += g->edges[i] == -1 ? 0 : 1;
    }
    return num_edges;
}

// Function to retrieve the degree of a vertex in the graph
int get_degree(graph_t *g, int v) {
    int degree = 0;
    for (int i = 0; i < g->num_vertices; i++) {
        if (g->edges[i] == v) {
            degree++;
        }
    }
    return degree;
}

// Function to traverse the graph
void traverse(graph_t *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d ", i);
        if (g->edges[i] != -1) {
            traverse(g->edges[i]);
        }
    }
    printf("\n");
}

int main() {
    graph_t *g = new_graph(5);

    // Add some edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);

    // Print the number of edges and the degree of each vertex
    printf("Number of edges: %d\n", get_num_edges(g));
    for (int i = 0; i < 5; i++) {
        printf("Degree of %d: %d\n", i, get_degree(g, i));
    }

    // Traverse the graph
    traverse(g);

    return 0;
}