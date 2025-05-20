//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: curious
#include<stdio.h>
#include<stdlib.h>

//structure for graph node
struct GraphNode{
    int color;
    int degree;
    int *neighbors;
};

//function for updating the degree of a node
void calculateDegree(struct GraphNode *graph, int n){
    for(int u = 0; u < n; u++){
        graph[u].degree = 0;
        for(int v = 0; v < n; v++){
            if(u != v && graph[u].neighbors[v] == 1){
                graph[u].degree++;
            }
        }
    }
}

//function for coloring the graph nodes
void graphColoring(struct GraphNode *graph, int n, int k){

    calculateDegree(graph, n);

    //initialize all nodes as uncolored
    for(int i = 0; i < n; i++){
        graph[i].color = -1;
    }

    //color first node with first color
    graph[0].color = 0;

    //color rest of nodes
    for(int i = 1; i < n; i++){
        //create array to store used colors in neighbors
        int *usedColors = (int *)calloc(k, sizeof(int));

        //iterate through neighbors to find used colors
        for(int j = 0; j < n; j++){
            if(graph[i].neighbors[j] && graph[j].color != -1){
                usedColors[graph[j].color] = 1;
            }
        }

        //find first available color
        int color;
        for(color = 0; color < k; color++){
            if(!usedColors[color]){
                break;
            }
        }

        graph[i].color = color;

        //free used colors array
        free(usedColors);
    }

    //print the result
    for(int i = 0; i < n; i++){
        printf("Node %d is colored with color %d\n", i, graph[i].color);
    }
}

int main(){

    //initialize graph nodes
    struct GraphNode graph[5] = {
        { -1, 0, (int []){0,1,1,-1,-1}}, //Node 0 with neighbors 1 and 2
        { -1, 0, (int []){1,0,1,1,0}}, //Node 1 with neighbors 0, 2, 3, and 4
        { -1, 0, (int []){1,1,0,1,1}}, //Node 2 with neighbors 0, 1, 3, and 4
        { -1, 0, (int []){-1,1,1,0,1}}, //Node 3 with neighbors 1, 2, 4
        { -1, 0, (int []){-1,0,1,1,0}}, //Node 4 with neighbors 1, 2, and 3
    };

    graphColoring(graph, 5, 3);

    return 0;
}