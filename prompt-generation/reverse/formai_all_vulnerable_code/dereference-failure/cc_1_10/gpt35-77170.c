//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define maximum number  of vertices and edges
#define MAX_VERTICES 100
#define MAX_EDGES 200

// Structure to represent a vertex
struct Vertex {
    int id;
    char name[20];
};

// Structure to represent an edge
struct Edge {
    int id;
    int from_vertex_id;
    int to_vertex_id;
};

// Structure to represent the graph
struct Graph {
    int num_vertices;
    int num_edges;
    struct Vertex vertices[MAX_VERTICES];
    struct Edge edges[MAX_EDGES];
};

// Function to get a vertex by id
struct Vertex get_vertex_by_id(struct Graph *graph, int id) {
    int i;
    for (i = 0; i < graph->num_vertices; i++) {
        if (graph->vertices[i].id == id) {
            return graph->vertices[i];
        }
    }
    struct Vertex v;
    v.id = -1;
    return v;
}

// Function to add a vertex to the graph
void add_vertex(struct Graph *graph, struct Vertex vertex) {
    graph->vertices[graph->num_vertices] = vertex;
    graph->num_vertices++;
}

// Function to add an edge to the graph
void add_edge(struct Graph *graph, struct Edge edge) {
    graph->edges[graph->num_edges] = edge;
    graph->num_edges++;
}

// Function to print the graph
void print_graph(struct Graph *graph) {
    int i;
    printf("Vertices:\n");
    for (i = 0; i < graph->num_vertices; i++) {
        printf("%d: %s\n", graph->vertices[i].id, graph->vertices[i].name);
    }
    printf("Edges:\n");
    for (i = 0; i < graph->num_edges; i++) {
        struct Vertex from_vertex = get_vertex_by_id(graph, graph->edges[i].from_vertex_id);
        struct Vertex to_vertex = get_vertex_by_id(graph, graph->edges[i].to_vertex_id);
        printf("%d: %d (%s) -> %d (%s)\n", graph->edges[i].id, from_vertex.id, from_vertex.name, to_vertex.id, to_vertex.name);
    }
}

int main() {
    struct Graph graph;
    graph.num_vertices = 0;
    graph.num_edges = 0;

    // Add some vertices
    char vertexName[5];
    for (int i = 0; i < 10; i++) {
        sprintf(vertexName, "V%d", i + 1);
        struct Vertex v;
        v.id = i + 1;
        strcpy(v.name, vertexName);
        add_vertex(&graph, v);
    }

    // Add some edges
    for (int i = 0; i < 15; i++) {
        int fromVertexIndex = rand() % graph.num_vertices;
        int toVertexIndex = rand() % graph.num_vertices;
        struct Edge e;
        e.id = i + 1;
        e.from_vertex_id = graph.vertices[fromVertexIndex].id;
        e.to_vertex_id = graph.vertices[toVertexIndex].id;
        add_edge(&graph, e);
    }

    // Print the graph
    print_graph(&graph);

    return 0;
}