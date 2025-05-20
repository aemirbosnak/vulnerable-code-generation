//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define V 9

//Defining the structure of the graph
struct Graph{
    int vertex;
    int **adj_matrix;
};

//Function to create the graph
void create_graph(struct Graph *graph){
    int i,j,k;
    graph->vertex=V;
    graph->adj_matrix=(int **)malloc(graph->vertex*sizeof(int *));
    for(i=0;i<graph->vertex;i++){
        graph->adj_matrix[i]=(int *)malloc(graph->vertex*sizeof(int));
        for(j=0;j<graph->vertex;j++){
            graph->adj_matrix[i][j]=INT_MAX;
        }
    }
    printf("\nEnter the edges and their weights:\n");
    for(i=0;i<graph->vertex;i++){
        for(j=0;j<graph->vertex;j++){
            scanf("%d",&k);
            if(k!=INT_MAX){
                graph->adj_matrix[i][j]=k;
                graph->adj_matrix[j][i]=k;
            }
        }
    }
}

//Function to print the graph
void print_graph(struct Graph *graph){
    int i,j;
    for(i=0;i<graph->vertex;i++){
        for(j=0;j<graph->vertex;j++){
            printf("%d ",graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

//Function to perform Dijkstra's algorithm
void dijkstra(struct Graph *graph,int source){
    int i,j,k,u,v;
    int dist[V];
    int visited[V];
    for(i=0;i<V;i++){
        dist[i]=INT_MAX;
        visited[i]=0;
    }
    dist[source]=0;
    for(k=0;k<V-1;k++){
        for(i=0;i<V;i++){
            for(j=0;j<V;j++){
                if(dist[i]>dist[j]+graph->adj_matrix[i][j]){
                    dist[i]=dist[j]+graph->adj_matrix[i][j];
                }
            }
        }
    }
    printf("\nVertex\t Distance from Source\n");
    for(i=0;i<V;i++){
        printf("%d \t %d\n",i,dist[i]);
    }
}

//Main function
int main(){
    struct Graph graph;
    create_graph(&graph);
    dijkstra(&graph,0);
    return 0;
}