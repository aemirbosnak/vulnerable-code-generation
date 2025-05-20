//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Claude Shannon
#include<stdio.h>

int V;  // Number of vertices in the graph
int graph[100][100]; // Adjacency matrix representation of the graph

void printSolution(int color[]);

// Check if the given color is safe for the vertex v
int isSafe(int v, int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return 0;
    return 1;
}

// A recursive function to solve graph coloring problem
int graphColoringUtil(int m, int color[], int v)
{
    if (v == V)
        return 1;

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++)
    {
        // Check if color c can be assigned to vertex v
        if (isSafe(v, color, c))
        {
            color[v] = c;

            // Recur for the remaining vertices
            if (graphColoringUtil(m, color, v + 1) == 1)
                return 1;

            // If assigning color c doesn't lead to a solution
            color[v] = 0;
        }
    }

    // If no color can be assigned to this vertex
    return 0;
}

// This function solves the graph coloring problem using Backtracking
void graphColoring(int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    // Call the recursive function graphColoringUtil for vertex 0
    if (graphColoringUtil(m, color, 0) == 0)
    {
        printf("Solution does not exist\n");
        return;
    }

    // Print the solution
    printSolution(color);
}

// A utility function to print solution
void printSolution(int color[])
{
    printf("Solution Exists:"
           " Following are the assigned colors \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", color[i]);
    printf("\n");
}

// Main function
int main()
{
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    int m;
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(m);

    return 0;
}