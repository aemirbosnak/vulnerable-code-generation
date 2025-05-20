//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*function to check if the current color is safe*/
int isSafe(int v, int **graph, int *color, int c, int V){
    for(int i=0; i<V; i++){
        if(graph[v][i] && color[i]==c){
            return 0;
        }
    }
    return 1;
}

/*recursive function to solve graph coloring*/
int graphColoringUtil(int **graph, int *color, int v, int V, int m){
    if(v==V){
        return 1;
    }

    for(int c=1; c<=m; c++){
        if(isSafe(v, graph, color, c, V)){
            color[v] = c;
            if(graphColoringUtil(graph, color, v+1, V, m)){
                return 1;
            }
            color[v] = 0; //backtracking
        }
    }

    return 0;
}

/*function to solve graph coloring*/
void graphColoring(int **graph, int V, int m){
    int *color = (int*)malloc(V*sizeof(int)); //array to store color for each vertex

    for(int i=0; i<V; i++){ //initialize all colors to 0
        color[i] = 0;
    }

    if(!graphColoringUtil(graph, color, 0, V, m)){
        printf("No solution found\n");
        return;
    }

    printf("Vertex\tColor\n");
    for(int i=0; i<V; i++){
        printf("%d\t%d\n", i, color[i]);
    }

    free(color);
}

/*main function*/
int main(){
    int V=5;
    int **graph = (int**)malloc(V*sizeof(int*)); //2D array to represent graph

    for(int i=0; i<V; i++){
        graph[i] = (int*)malloc(V*sizeof(int));
    }

    //initialize graph
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            graph[i][j] = 0;
        }
    }

    //add edges
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[2][4] = graph[4][2] = 1;
    graph[3][4] = graph[4][3] = 1;

    printf("Graph:\n");
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    int m=3; //number of colors
    graphColoring(graph, V, m);

    //free memory
    for(int i=0; i<V; i++){
        free(graph[i]);
    }
    free(graph);

    return 0;
}