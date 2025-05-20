//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>

int vertices, edges, **graph; //global variables

void printSolution(int color[]);

//Function to check if it's valid to color a vertex with the given color
int isSafe(int v, int color[], int c)
{
    for(int i = 0; i < vertices; i++)
        if(graph[v][i] && c == color[i]) //if there is a row in the graph[][] matrix which represents the connections to adjacent vertices, and the adjacent vertex has already been assigned the same color, the given color isn't safe
            return 0;
    return 1;
}

int graphColoringUtil(int m, int color[], int v)
{
    if(v == vertices) //If all the vertices have been assigned colors, return true
        return 1;
    for(int c = 1; c <= m; c++)
    {
        if(isSafe(v, color, c)) //Check if it is valid to color the vertex v with color c
        {
            color[v] = c; //Assign the color c to vertex v
            if(graphColoringUtil(m, color, v+1)) //Recursively apply the same method to the next vertex
                return 1;
            color[v] = 0; //Backtracking - If the algorithm fails for the present color, reset the color value to 0
        }
    }
    return 0; //If no colors can be assigned to the vertices adjacent to the current vertex, return false
}

void graphColoring(int m) //Function to execute the graph coloring problem
{
    int color[vertices];
    for (int i = 0; i < vertices; i++)
        color[i] = 0;
    if(graphColoringUtil(m, color, 0) == 0) //If none of the colors can be assigned to a vertex, it returns 0
        printf("\nSolution does not exist for the given number of colors\n");
    else
        printSolution(color);
}

void printSolution(int color[]) //Helper function to print the assigned colors to each vertex
{
    printf("\nAssigned Colors :\n");
    for (int i = 0; i < vertices; i++)
        printf("Color assigned to vertex %d is %d\n", i+1, color[i]);
}

int main()
{
    printf("\nEnter the number of vertices in the graph : ");
    scanf("%d", &vertices);
    graph = (int**)malloc(vertices*sizeof(int*));
    for(int i=0;i<vertices;i++)
        graph[i]=(int*)malloc(vertices*sizeof(int));
    printf("Enter the number of edges in the graph : ");
    scanf("%d", &edges);
    int x, y;
    for(int i=0;i<edges;i++)
    {
        printf("Enter the two vertices (separated by spaces) that form the edge #%d : ", i+1);
        scanf("%d %d", &x, &y);
        graph[x-1][y-1] = 1;
        graph[y-1][x-1] = 1; //Mark the corresponding spots in the graph[][] matrix as 1 to indicate the vertices are interconnected
    }
    int m;
    printf("\nEnter the number of colors available: ");
    scanf("%d", &m);
    graphColoring(m);
    return 0;
}