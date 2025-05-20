//FormAI DATASET v1.0 Category: Graph representation ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

/*This program demonstrates a unique way of representing a graph via
  adjacency list and the different functions that one can perform on 
  such a graph */

// Structure to represent each node in the graph
struct node
{
    int vertex; // vertex value
    struct node* next; // pointer to next adjacent node
};

// Function to create a new node
struct node* createNode(int v)
{
    struct node* newNode = NULL;

    // Allocate memory for new node
    newNode = (struct node*)malloc(sizeof(struct node));

    // Assign values
    newNode->vertex = v;
    newNode->next = NULL;

    return newNode;
}

// Function to create a graph of V vertices
struct node** createGraph(int V)
{
    struct node** adjList = NULL;

    // Allocate memory for adjacency list
    adjList = (struct node**)malloc(V * sizeof(struct node*));

    // Initialize adjacency list for all vertices
    for(int i=0; i<V; i++)
        adjList[i] = NULL;

    return adjList;
}

// Function to add an edge to an undirected graph
void addEdge(struct node** adjList, int src, int dest)
{
    // Create a new node for destination vertex
    struct node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    // Create a new node for source vertex
    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

// Function to print the adjacency list of the graph
void printGraph(struct node** adjList, int V)
{
    for(int i=0; i<V; i++)
    {
        struct node* temp = adjList[i];

        printf("\nAdjacency list of vertex %d:\n", i);
        while(temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to delete a node from the graph
void deleteNode(struct node** adjList, int V, int vertex)
{
    struct node* temp = NULL;
    struct node* prev = NULL;

    // Traverse the adjacency list of the vertex
    temp = adjList[vertex];

    while(temp != NULL)
    {
        adjList[vertex] = temp->next;
        free(temp);
        temp = adjList[vertex];
    }

    // Traverse the adjacency list of all other vertices
    for(int i=0; i<V; i++)
    {
        if(i != vertex)
        {
            temp = prev = adjList[i];

            while(temp != NULL)
            {
                if(temp->vertex == vertex)
                {
                    prev->next = temp->next;
                    free(temp);
                    break;
                }

                prev = temp;
                temp = temp->next;
            }
        }
    }
}

// Main function
int main()
{
    // Create adjacency list for a graph of 4 vertices
    int V = 4;
    struct node **adjList = createGraph(V);

    // Add edges to the graph
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 3);

    // Print the adjacency list of the graph
    printf("Initial graph:\n");
    printGraph(adjList, V);

    // Delete vertex 2 from the graph
    deleteNode(adjList, V, 2);

    // Print the updated adjacency list of the graph
    printf("\nUpdated graph after deleting vertex 2:\n");
    printGraph(adjList, V);
  
    return 0;
}