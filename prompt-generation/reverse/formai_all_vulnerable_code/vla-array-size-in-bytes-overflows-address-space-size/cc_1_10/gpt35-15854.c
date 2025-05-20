//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: statistical
#include<stdio.h>
#include<stdlib.h>

//Defining the number of colors available
#define COLORS 4

//Defining a Global variable to store the number of vertices
int V;

//Function declaration for graph coloring
void graphColoring(int graph[V][V]);

//Function to check if a color can be assigned to the vertex
int isSafe(int vertex, int graph[V][V], int color_code[], int color);

//Main function starts here
int main()
{
    printf("\n------Coloring of a Graph using %d colors------\n\n", COLORS);
    
    //Taking user input for the number of vertices in the graph
    printf("Enter the number of vertices in the Graph: ");
    scanf("%d", &V);

    //Dynamically allocating memory for the 2D Graph Array
    int **graph = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++){
        graph[i] = (int*)malloc(V * sizeof(int));
    }

    //Taking user input for the connectivity of vertices in the graph
    printf("\nEnter the Graph connectivity (in the form of an adjacency matrix):\n");
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    //Function call to color the Graph
    graphColoring(graph);

    return 0;
}

//Function to check if a color can be assigned to the vertex
int isSafe(int vertex, int graph[V][V], int color_code[], int color)
{
    for (int i = 0; i < V; i++){
        if (graph[vertex][i] && color_code[i] == color){
            return 0;
        }
    }
    return 1;
}

//Function to color the Graph
void graphColoring(int graph[V][V])
{
    int color_code[V];

    //Assigning -1 to all vertices as no initial color is assigned
    for (int i = 0; i < V; i++){
        color_code[i] = -1;
    }

    //Assigning color to first vertex
    color_code[0] = 0;

    //Assigning color to rest of the vertices
    for (int i = 1; i < V; i++)
    {
        //Assigning zero to all colors
        for (int j = 0; j < COLORS; j++){
            color_code[i] = j;
            if (isSafe(i, graph, color_code, j)){
                break;
            }
        }
    }
    
    //Displaying the result
    printf("\n------Graph Coloring Output------\n");
    printf("\nVertex | Color\n");
    printf("--------------\n");
    for (int i = 0; i < V; i++)
        printf("   %d   |  %d\n", i+1, color_code[i]+1);
    printf("\n\n");
}