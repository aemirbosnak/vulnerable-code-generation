//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: happy
#include<stdio.h>
#include<stdlib.h>

//Function for checking if two adjacent vertices have the same color 
int check_color(int** graph,int* color,int v,int c,int n){
    for(int i=0;i<n;i++){
        if(graph[v][i]==1 && color[i]==c){
            return 0;
        }
    }
    return 1;
}

//Function for graph coloring
int graph_coloring(int** graph,int* color,int v,int m,int n){
    if(v==n){
        return 1;
    }
    for(int c=1;c<=m;c++){
        if(check_color(graph,color,v,c,n)){
            color[v]=c;
            if(graph_coloring(graph,color,v+1,m,n)){
                return 1;
            }
            color[v]=0;
        }
    }
    return 0;
}

//Function for printing the resultant colors
void print_colors(int* color,int n){
    printf("\nColors for the vertices are : \n");
    for(int i=0;i<n;i++){
        printf("Vertex %d ---> Color %d\n",i+1,color[i]);
    }
}

int main(){
    printf("Welcome to the Graph Coloring Problem Solver! Let's give some colors to the vertices!\n\n");
    int n,m;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    int** graph;
    graph=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        graph[i]=(int*)malloc(n*sizeof(int));
    }
    printf("\nEnter the adjacency matrix of the graph : \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("\nHow many colors do you want to use for coloring the vertices? : ");
    scanf("%d",&m);
    int* color;
    color=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        color[i]=0;
    }
    if(!graph_coloring(graph,color,0,m,n)){
        printf("\nCannot color the vertices!\n");
    }
    else{
        print_colors(color,n);
    }
    return 0;
}