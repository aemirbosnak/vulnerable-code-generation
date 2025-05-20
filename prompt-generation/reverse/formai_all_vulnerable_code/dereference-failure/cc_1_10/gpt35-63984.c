//FormAI DATASET v1.0 Category: Graph representation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {             // Define a struct for Graph Edge 
    int src, dest, weight;        // Contain Source, Destination and Weight of the Edge
} Edge;

typedef struct Graph {            // Define a struct for Graph
    int V, E;                     // Contain Number of Vertices and Edges in the Graph
    Edge* edge;                   // Pointer to an array of edges
} Graph;

Graph* createGraph(int V, int E) {             // Function to create a Graph with given vertices and edges
    Graph* graph = (Graph*)malloc(sizeof(Graph));          // Allocate memory for Graph      
    graph->V = V;                                          // Set the number of Vertices in Graph      
    graph->E = E;                                          // Set the number of Edges in Graph     
    graph->edge = (Edge*)malloc(E * sizeof(Edge));         // Allocate memory for Edges in graph      
    return graph;                                          // Return Created Graph
}

void printGraph(Graph* graph) {            // Function to print Graph
    int i;
    for (i = 0; i < graph->E; ++i) {      // Loop through all edges
        printf("Source Vertex: %d, Destination Vertex: %d, Weight: %d\n", graph->edge[i].src, graph->edge[i].dest, graph->edge[i].weight);   // Print the details of each Edge
    }
}

int main() {
    int V = 4;                                // Set the number of Vertices
    int E = 5;                                // Set the number of Edges     
    Graph* graph = createGraph(V, E);         // Create Graph with given Vertices and Edges      
                                          
    graph->edge[0].src = 0;                  // Add Edge between Vertex 0 and Vertex 1      
    graph->edge[0].dest = 1;   
    graph->edge[0].weight = 10;     
                                          
    graph->edge[1].src = 0;                  // Add Edge between Vertex 0 and Vertex 2
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;
                                          
    graph->edge[2].src = 0;                  // Add Edge between Vertex 1 and Vertex 3
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;
                                          
    graph->edge[3].src = 1;                  // Add Edge between Vertex 2 and Vertex 3
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;
                                          
    graph->edge[4].src = 2;                  // Add Edge between Vertex 2 and Vertex 3
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;
    
    printf("Here are the Details of Graph: \n");
    printGraph(graph);                        // Call the Function to print Graph
    
    return 0;
}