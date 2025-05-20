//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function prototypes
void graphColoring(int **graph, int numOfVertices, int numOfColors);
int chooseRandomColor(int **graph, int vertex, int numOfVertices, int numOfColors);

int main()
{
    //Seed for generating random numbers
    srand(time(0));
  
    //Number of vertices in the graph
    int numOfVertices = 5;
  
    //Number of colors to color the graph
    int numOfColors = 3;
  
    //2D array to represent the graph
    int **graph = (int **)malloc(numOfVertices * sizeof(int *));
    for(int i = 0; i < numOfVertices; i++)
        graph[i] = (int *)malloc(numOfVertices * sizeof(int));
  
    //Initializing the graph with 0's
    for(int i = 0; i < numOfVertices; i++)
    {
        for(int j = 0; j < numOfVertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    //Adding edges to the graph
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[2][0] = 1;
    graph[2][1] = 1;
    graph[2][3] = 1;
    graph[2][4] = 1;
    graph[3][1] = 1;
    graph[3][2] = 1;
    graph[3][4] = 1;
    graph[4][2] = 1;
    graph[4][3] = 1;
  
    //Printing the graph
    printf("Graph is:\n");
    for(int i = 0; i < numOfVertices; i++)
    {
        for(int j = 0; j < numOfVertices; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
  
    //Calling the graphColoring function to color the graph
    graphColoring(graph, numOfVertices, numOfColors);
  
    return 0;
}

void graphColoring(int **graph, int numOfVertices, int numOfColors)
{
    //Array to hold the color assigned to each vertex
    int *color = (int *)malloc(numOfVertices * sizeof(int));
  
    //Initializing all the colors to -1, indicating no color is assigned to any vertex yet
    for(int i = 0; i < numOfVertices; i++)
        color[i] = -1;

    //Printing the initial status of vertices' coloring
    printf("\nInitial status of vertices:\n");
    for(int i = 0; i < numOfVertices; i++)
        printf("Vertex %d: Color %d\n", i, color[i]);
    printf("\n");

    //Coloring the vertices one by one
    for(int i = 0; i < numOfVertices; i++)
    {
        //Choose a random color for the current vertex
        color[i] = chooseRandomColor(graph, i, numOfVertices, numOfColors);
    }

    //Printing the final status of vertices' coloring
    printf("Final status of vertices:\n");
    for(int i = 0; i < numOfVertices; i++)
        printf("Vertex %d: Color %d\n", i, color[i]);
    printf("\n");
}

int chooseRandomColor(int **graph, int vertex, int numOfVertices, int numOfColors)
{
    //Array to hold the available colors for the current vertex
    int *availableColors = (int *)malloc(numOfColors * sizeof(int));
  
    //Initializing all the available colors to 1, indicating all colors are available for the current vertex
    for(int i = 0; i < numOfColors; i++)
        availableColors[i] = 1;

    //Checking the colors of adjacent vertices and marking their colors as unavailable
    for(int i = 0; i < numOfVertices; i++)
    {
        if(graph[vertex][i] == 1 && availableColors[i] != -1)
            availableColors[graph[vertex][i]] = -1;
    }

    //Choosing a random color from the available colors
    int randomColor = rand() % numOfColors;
    while(availableColors[randomColor] == -1)
        randomColor = rand() % numOfColors;

    //Returning the chosen random color
    return randomColor;
}