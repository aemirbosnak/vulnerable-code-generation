//FormAI DATASET v1.0 Category: Graph representation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

struct node{
    int vertex;
    struct node* next;
};

struct Graph{
    int vertices;
    struct node** adjList;
};

//function to add edge between two vertices
void addEdge(struct Graph* graph,int src,int dest){
    //adding edge between source and destination
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->vertex=dest;
    newNode->next=graph->adjList[src];
    graph->adjList[src]=newNode;

    //adding edge between destination and source
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->vertex=src;
    newNode->next=graph->adjList[dest];
    graph->adjList[dest]=newNode;

}

//function to print the Graph
void printGraph(struct Graph* graph){
    int i;
    for(i=0;i<graph->vertices;i++){
        struct node* temp=graph->adjList[i];
        printf("Vertex %d: ",i);
        while(temp){
            printf("%d->",temp->vertex);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

int main(){

    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices=5; //total vertices in graph

    graph->adjList=malloc(graph->vertices*sizeof(struct node*)); //allocating memory to adjacency list

    int i;
    for(i=0;i<graph->vertices;i++){
        graph->adjList[i]=NULL; //initializing adjacency list with null pointers
    }

    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,2,3);
    addEdge(graph,3,4);

    printGraph(graph); //print the Graph

    return 0;
}