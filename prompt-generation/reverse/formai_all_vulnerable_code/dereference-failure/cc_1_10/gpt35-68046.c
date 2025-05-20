//FormAI DATASET v1.0 Category: Graph representation ; Style: lively
#include <stdio.h> // Calling Standard Input Output Library
#include <stdlib.h> // Calling Standard Library

// Defining Edge struct for our Graph
struct Edge
{
    int src; // Source Vertex
    int dest; // Destination Vertex 
};

// Defining Graph struct
struct Graph
{
    int V; // Number of Vertices
    int E; // Number of Edges 
    struct Edge* edge; // Pointer to Edge Struct 
};

// Function to Create Graph
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph)); // Allocating memory for Graph Struct
    graph->V = V; // Assigning Number of Vertices to the Graph
    graph->E = E; // Assigning Number of Edges to the Graph
    graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge)); // Allocating memory for Edge Struct
    return graph; // Return the Graph Struct
}

// Main Function
int main()
{
    int V = 5; // Number of Vertices in the Graph
    int E = 6; // Number of Edges in the Graph

    struct Graph* graph = createGraph(V, E); // Creating Graph using Create Graph Function

    // Defining Edge Array for the Graph
    int edges[6][2] = {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {4, 5}};

    // Assigning the values from Edges Array to Edge Struct in Graph
    for(int i = 0; i < graph->E; i++)
    {
        graph->edge[i].src = edges[i][0];
        graph->edge[i].dest = edges[i][1];
    }

    // Printing the Graph in the form of an Adjacency List
    printf("Adjacency List Representation of Graph:\n");
    for(int i = 1; i <= graph->V; i++)
    {
        printf("Vertex %d: ", i);
        for(int j = 0; j < graph->E; j++)
        {
            if(graph->edge[j].src == i)
            {
                printf("%d ", graph->edge[j].dest);
            }
            else if(graph->edge[j].dest == i)
            {
                printf("%d ", graph->edge[j].src);
            }
        }
        printf("\n");
    }

    return 0;
}