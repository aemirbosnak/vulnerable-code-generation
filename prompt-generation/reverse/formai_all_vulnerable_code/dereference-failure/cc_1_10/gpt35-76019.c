//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to hold information about each vertex
struct vertex{
    int name;
    int color;
};

//Function to color the vertices
void colorGraph(int** graph, struct vertex* vertices, int numVertices, int numColors){
    int i,j;
    int* possibleColors = (int*)malloc(numColors*sizeof(int));
    for(i=0; i<numVertices; i++){
        memset(possibleColors,0,numColors*sizeof(int));
        for(j=0; j<numVertices; j++){
            if(graph[i][j]){
                if(vertices[j].color != -1){
                    possibleColors[vertices[j].color] = 1;
                }
            }
        }
        for(j=0; j<numColors; j++){
            if(possibleColors[j]){
                continue;
            }
            else{
                vertices[i].color = j;
                break;
            }
        }
    }
}

int main(){
    int numVertices = 10;
    int numColors = 3;
    int** graph = (int**)malloc(numVertices*sizeof(int*));
    struct vertex* vertices = (struct vertex*)malloc(numVertices*sizeof(struct vertex));
    int i,j;
    for(i=0; i<numVertices; i++){
        graph[i] = (int*)malloc(numVertices*sizeof(int));
        vertices[i].name = i+1;
        vertices[i].color = -1;
    }
    //Medieval style graph edges
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[0][3] = 1;
    graph[0][4] = 1;
    graph[1][2] = 1;
    graph[2][4] = 1;
    graph[2][5] = 1;
    graph[3][4] = 1;
    graph[4][5] = 1;
    graph[5][6] = 1;
    graph[5][7] = 1;
    graph[6][7] = 1;
    graph[7][8] = 1;
    graph[8][9] = 1;
    colorGraph(graph,vertices,numVertices,numColors);
    printf("Vertex\tColor\n");
    for(i=0; i<numVertices; i++){
        printf("%d\t%d\n",vertices[i].name,vertices[i].color);
    }
    return 0;
}