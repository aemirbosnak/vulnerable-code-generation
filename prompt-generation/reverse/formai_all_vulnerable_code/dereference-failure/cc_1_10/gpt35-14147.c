//FormAI DATASET v1.0 Category: Graph representation ; Style: futuristic
//Futuristic C Graph Representation Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10
#define TRUE 1
#define FALSE 0

//Declaring Struct for a Node in the Graph
struct node
{
    int vertex;
    struct node *next;
};

//Graph Struct
struct Graph
{
    int num_vertices;
    struct node **adj_list;
    int visited[MAX_VERTICES];
};

//Function to create a New Node
struct node *create_node(int vertex)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->vertex = vertex;
    new_node->next = NULL;
    return new_node;
}

//Function to create the Graph
struct Graph *create_graph(int num_vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->num_vertices = num_vertices;

    //Create an Array of Adjacency Lists. Each List Represents a Node.
    graph->adj_list = malloc(num_vertices * sizeof(struct node *));

    for (int i = 0; i < num_vertices; i++)
    {
        graph->adj_list[i] = NULL;
        graph->visited[i] = FALSE;
    }

    return graph;
}

//Function to add an Edge to the Graph
void add_edge(struct Graph *graph, int src, int dest)
{
    //Add an Edge from Source to Destination
    struct node *new_node = create_node(dest);
    new_node->next = graph->adj_list[src];
    graph->adj_list[src] = new_node;

    //Add an Edge from Destination to Source
    new_node = create_node(src);
    new_node->next = graph->adj_list[dest];
    graph->adj_list[dest] = new_node;
}

//Function to Print the Graph
void print_graph(struct Graph *graph)
{
    printf("Futuristic Graph Representation:\n");
    for (int i = 0; i < graph->num_vertices; i++)
    {
        struct node *temp = graph->adj_list[i];
        printf("%d: ", i);
        while (temp)
        {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

//Function to traverse the Graph using Depth First Search (DFS)
void DFS(struct Graph *graph, int start)
{
    struct node *adj_list = graph->adj_list[start];
    struct node *temp = adj_list;

    graph->visited[start] = TRUE;
    printf("Visited Node: %d\n", start);

    while (temp != NULL)
    {
        int connected_vertex = temp->vertex;

        if (graph->visited[connected_vertex] == FALSE)
            DFS(graph, connected_vertex);

        temp = temp->next;
    }
}

int main()
{
    //Create the Graph
    struct Graph *graph = create_graph(5);

    //Add the Edges to the Graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    //Print the Graph
    print_graph(graph);

    //Traverse the Graph using Depth First Search (DFS)
    printf("Traversing the Graph using Depth First Search (DFS):\n");
    DFS(graph, 0);

    return 0;
}