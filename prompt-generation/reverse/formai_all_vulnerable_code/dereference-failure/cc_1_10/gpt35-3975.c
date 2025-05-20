//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: shocked
#include<stdio.h>
#include<stdbool.h>

//Define the maximum number of vertices
#define MAX_VERTICES 1000

//Define the maximum number of colors to be used
#define MAX_COLORS 50

/*Graph data structure with adjacency list representation
For each vertex, an array of connecting vertices is present*/

struct Graph{
    int vertices;
    int **adjacencyList;
};

/*Functions for creating and initializing an instance of the above graph data structure*/

struct Graph* createGraph(int vertices){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjacencyList = (int**)malloc(sizeof(int*) * vertices);
  
    int i;
    for(i = 0; i < vertices; i++){
        graph->adjacencyList[i] = (int*)malloc(sizeof(int) * vertices);
        
	//Set each element of the adjacency list to -1, indicating they are not connected.
        int j;
        for(j = 0; j < vertices; j++){
            graph->adjacencyList[i][j] = -1;
        }
    }

    return graph;
}

/*Function to add an edge to the graph*/

void addEdge(struct Graph* graph, int vertex1, int vertex2){
    int temp = 0;
    
    // check if the vertices are valid and not already connected
    if(vertex1 >= 0 && vertex1 < graph->vertices && vertex2 >=0 && vertex2 < graph->vertices){
        if(graph->adjacencyList[vertex1][vertex2] == -1 && graph->adjacencyList[vertex2][vertex1] == -1){
	  
	    //If not connected before set them as neighbors and vice versa.
            graph->adjacencyList[vertex1][temp] = vertex2;
            graph->adjacencyList[vertex2][temp] = vertex1;
	    temp++;
        }
    }
}

/*Function to print the adjacency list for debugging*/

void printAdjacencyList(struct Graph* graph){
    int i;
    for(i = 0; i < graph->vertices; i++){
        printf("Neighbors of vertex %d: ", i);
        int j;
        for(j = 0; j < graph->vertices; j++){
            if(graph->adjacencyList[i][j] != -1){
                printf("%d ", graph->adjacencyList[i][j]);
            }
        }
        printf("\n");
    }
}

/*Color the given vertex with one of the available colors*/

bool colorVertex(int vertex, int vertices, int colors[], struct Graph* graph){
    int i;
    for(i = 0; i < vertices; i++){
      
      //Checks if adjacent vertices colors conflict with color[i]
        if(graph->adjacencyList[vertex][i] != -1 && colors[graph->adjacencyList[vertex][i]] == colors[vertex]){
            return false;
        }
    }
    return true;
}

/*Function to recursively color the rest of the vertices if color has been successfully applied to current vertex*/

bool colorGraph(int vertex, int vertices, int colors[], struct Graph* graph){
    if(vertex == vertices){
        return true;
    }

    int i;
    for(i = 0; i < MAX_COLORS; i++){
        colors[vertex] = i;

        if(colorVertex(vertex, vertices, colors, graph)){
            if(colorGraph(vertex + 1, vertices, colors, graph)){
                return true;
            }
        }
    }

    colors[vertex] = -1;
    return false;
}

/*Function for coloring the graph*/

void graphColoring(struct Graph* graph){
    int colors[MAX_VERTICES];
    int i;
  
   //Setting all vertices to the default color or -1, indicating no color, to begin with. 
    for(i = 0; i < MAX_VERTICES; i++){
        colors[i] = -1;
    }

    //Starting to color the vertices
    if(colorGraph(0, graph->vertices, colors, graph)){
        printf("Vertices have been colored successfully. The colors assigned to them may differ from optimal.");
    }
    else{
        printf("No coloring solution could be found for the given graph.");
    }

    printf("\n\nThe applied coloring scheme to the vertices is: \n\n");

    //Printing out the applied coloring scheme
    for(i = 0; i < graph->vertices; i++){
        printf("Vertex %d : Color %d\n", i, colors[i]);
    }
}

int main(){
    //Creating an instance of the graph data structure with 4 vertices
    struct Graph* graph = createGraph(4);

    //Adding the edges among the vertices of the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printf("The adjacency list of the created graph is: \n");
    printAdjacencyList(graph);

    graphColoring(graph);

    return 0;
}