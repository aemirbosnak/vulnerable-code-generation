//FormAI DATASET v1.0 Category: Graph representation ; Style: safe
#include<stdio.h>
#include<stdlib.h>

struct node{
    int vertex;
    struct node *next;
};

struct Graph{
    int V;
    struct node **adjList;
};

struct Graph* createGraph(int V){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct node **)malloc(V * sizeof(struct node *));
    for(int i=0;i<V;i++){
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->vertex = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void printGraph(struct Graph *graph){
    for(int i=0;i<graph->V;i++){
        struct node* temp = graph->adjList[i];
        printf("\nAdjacency list of vertex %d\n",i);
        while(temp){
            printf("%d -> ",temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
    struct Graph* graph = createGraph(5);
    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
    printGraph(graph);
    return 0;
}