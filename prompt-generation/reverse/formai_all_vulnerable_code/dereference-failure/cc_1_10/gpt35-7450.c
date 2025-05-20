//FormAI DATASET v1.0 Category: Graph representation ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#define MAX_NODE 10
struct Graph{
    int nodes;
    int edge[MAX_NODE][MAX_NODE];
};

struct Graph* createGraph(){
    struct Graph* graph;
    int nodeCount, i, j, response;
    graph=(struct Graph*)malloc(sizeof(struct Graph));
    if(!graph){
        printf("Memory Allocation Error!");
        exit(0);
    }
    printf("Enter the number of nodes in the graph (max 10): ");
    scanf("%d", &nodeCount);
    graph->nodes=nodeCount;
    for(i=0;i<nodeCount;i++){
        for(j=0;j<nodeCount;j++){
            graph->edge[i][j]=0;
        }
    }
    printf("Enter the edges between the nodes.\n");
    printf("Enter 1 if there is an edge between the nodes, or 0 if there isn't.\n");
    for(i=0;i<nodeCount;i++){
        for(j=i+1;j<nodeCount;j++){
            printf("Edge between node %d and node %d: ", i+1, j+1);
            scanf("%d", &response);
            if(response==1){
                graph->edge[i][j]=1;
                graph->edge[j][i]=1;
            }
        }
    }
    return graph;
}

void printGraph(struct Graph* graph){
    int i, j;
    for(i=0;i<graph->nodes;i++){
        for(j=0;j<graph->nodes;j++){
            printf("%d ", graph->edge[i][j]);
        }
        printf("\n");
    }
}

int main(){
    struct Graph* graph=createGraph();
    printGraph(graph);
    return 0;
}