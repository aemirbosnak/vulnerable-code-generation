//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: visionary
// Embarking on a Cerebral Odyssey: Unveiling the Intricate Tapestry of Graph Structures

// Prelude: Establishing the Foundation
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Prelude: Defining an Edge, the Building Block of Graphs
typedef struct Edge {
    int destination;     // The vertex at the other end of the edge
    int weight;         // The weight associated with the edge (optional)
    struct Edge *next;  // Pointer to the next edge in the adjacency list
} Edge;

// Prelude: Defining a Vertex, the Cornerstone of Graphs
typedef struct Vertex {
    int label;          // The unique identifier for the vertex
    int distance;       // The distance from a starting vertex (for shortest path algorithms)
    bool visited;       // A flag indicating whether the vertex has been visited
    Edge *head;         // Pointer to the head of the adjacency list for the vertex
} Vertex;

// Prelude: Defining a Graph, the Interwoven Symphony of Vertices and Edges
typedef struct Graph {
    int numVertices;    // The number of vertices in the graph
    Vertex *vertices;  // An array of vertices
} Graph;

// Prelude: Graph Initialization, Laying the Groundwork for Connections
Graph* createGraph(int numVertices) {
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->vertices = malloc(sizeof(Vertex) * numVertices);
    for (int i = 0; i < numVertices; i++) {
        graph->vertices[i].label = i;
        graph->vertices[i].distance = -1;
        graph->vertices[i].visited = false;
        graph->vertices[i].head = NULL;
    }
    return graph;
}

// Prelude: Adding an Edge, Forging Connections in the Graph's Tapestry
Edge* addEdge(int source, int destination, int weight, Edge *head) {
    Edge *newEdge = malloc(sizeof(Edge));
    newEdge->destination = destination;
    newEdge->weight = weight;
    newEdge->next = head;
    return newEdge;
}

// Prelude: Graph Traversal, Unveiling the Paths and Patterns
void depthFirstSearch(Graph *graph, int source) {
    Vertex *stack[graph->numVertices];
    int top = -1;
    stack[++top] = &graph->vertices[source];
    graph->vertices[source].visited = true;
    while (top >= 0) {
        Vertex *current = stack[top--];
        printf("%d ", current->label);
        Edge *edge = current->head;
        while (edge != NULL) {
            if (!graph->vertices[edge->destination].visited) {
                stack[++top] = &graph->vertices[edge->destination];
                graph->vertices[edge->destination].visited = true;
            }
            edge = edge->next;
        }
    }
}

// Prelude: Graph Visualization, Making the Invisible Visible
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", graph->vertices[i].label);
        Edge *edge = graph->vertices[i].head;
        while (edge != NULL) {
            printf("(%d, %d) ", edge->destination, edge->weight);
            edge = edge->next;
        }
        printf("\n");
    }
}

// Prelude: Main, the Orchestrator of Graph Explorations
int main() {
    // Genesis: Creating a Graph, the Canvas for Our Explorations
    Graph *graph = createGraph(5);

    // Etching Connections, Weaving Intricate Paths
    addEdge(0, 1, 4, graph->vertices[0].head);
    addEdge(0, 2, 2, graph->vertices[0].head);
    addEdge(1, 2, 1, graph->vertices[1].head);
    addEdge(1, 3, 6, graph->vertices[1].head);
    addEdge(2, 4, 3, graph->vertices[2].head);
    addEdge(3, 4, 2, graph->vertices[3].head);

    // Unveiling the Labyrinth: Visualizing the Graph's Structure
    printGraph(graph);

    // Threading the Maze: Traversing the Graph's Depths
    printf("Depth-First Search: ");
    depthFirstSearch(graph, 0);

    return 0;
}