//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: happy
#include<stdio.h>
#include<stdlib.h>

// assign colors to vertices
void assignColor(int vertex, int *color, int **graph, int numOfColors, int vertices){

    // check for the next available color if can be filled to current vertex
    for(int i=1; i<=numOfColors; i++){
        int flag=1;
        // check if adjacent vertices are assigned same color
        for(int j=0; j<vertices; j++){
            if(graph[vertex][j] && color[j]==i){
                flag=0;
                break;
            }
        }
        if(flag==1){
            color[vertex]=i;
            break;
        }
    }
}

int main(){
    printf("----Happy Example of C Graph Coloring Problem----\n");

    int vertices, numOfEdges, numOfColors;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numOfEdges);

    // dynamically size the matrix to vertices
    int **graph = (int **)malloc(vertices * sizeof(int *));
    for(int i=0; i<vertices; i++)
        graph[i] = (int *)calloc(vertices, sizeof(int));

    // read graph edges and update matrix
    int source, destination;
    printf("Enter the edges of the graph: \n");
    for(int i=0; i<numOfEdges; i++){
        scanf("%d%d", &source, &destination);
        graph[source][destination]=1;
        graph[destination][source]=1;
    }

    printf("Enter the number of colors: ");
    scanf("%d", &numOfColors);

    // initialize colors of all vertices to 0
    int *color = (int *)calloc(vertices, sizeof(int));

    // loop through all vertices and assign color
    for(int vertex=0; vertex<vertices; vertex++){
        if(color[vertex]==0){
            assignColor(vertex, color, graph, numOfColors, vertices);
        }
    }

    // print the final color assignment
    printf("Solution to graph coloring problem with minimum number of colors:\n");
    for(int vertex=0; vertex<vertices; vertex++){
        printf("Vertex %d: Color %d\n", vertex, color[vertex]);
    }

    // free dynamicaly allocated memory
    for(int i=0; i<vertices; i++)
        free(graph[i]);
    free(graph);
    return 0;
}