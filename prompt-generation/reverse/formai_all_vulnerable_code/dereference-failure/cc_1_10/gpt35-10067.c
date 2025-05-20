//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NODES 1000 // maximum number of nodes can be n

struct node{
    int vertex;
    struct node* next;
};

struct Graph{
    int numOfVertices;
    struct node** adjList;
};

int isMapped(int* mapping, int num){
    for(int i=0; i<MAX_NODES; i++){
        if(mapping[i] == num)
            return 1;
    }
    return 0;
}

void addEdge(struct Graph* graph, int src, int dest){
    // Adding Directed Edge from src to dest
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

void mapTopology(struct Graph* originalGraph, int* mapping){
    int maxNum = 0;
    for(int i=0; i<originalGraph->numOfVertices; i++){
        struct node* temp = originalGraph->adjList[i];
        while(temp != NULL){
            if(temp->vertex > maxNum)
                maxNum = temp->vertex;
            temp = temp->next;
        }
    }

    // Creating the New Graph
    struct Graph* newGraph = (struct Graph*)malloc(sizeof(struct Graph));
    newGraph->numOfVertices = maxNum+1;
    newGraph->adjList = (struct node**)calloc(newGraph->numOfVertices, sizeof(struct node*));

    for(int i=0; i<originalGraph->numOfVertices; i++){
        struct node* temp = originalGraph->adjList[i];
        while(temp != NULL){
            // If the Vertex is already mapped then use the mapped vertex's number
            if(isMapped(mapping, temp->vertex))
                addEdge(newGraph, i, mapping[temp->vertex]);
            // Else, map the unmapped vertex to the next available number and then use it
            else{
                mapping[temp->vertex] = maxNum+1;
                addEdge(newGraph, i, maxNum+1);
                maxNum++;
            }
            temp = temp->next;
        }
    }

    // Printing the Mapped Topology Graph
    printf("\nThe Mapped Topology of the Network is:\n\n");
    for(int i=0; i<newGraph->numOfVertices; i++){
        struct node* temp = newGraph->adjList[i];
        printf("Node %d -> ",i);
        while(temp != NULL){
            printf("%d -> ",temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
    // Creating the Original Graph
    struct Graph* originalGraph = (struct Graph*)malloc(sizeof(struct Graph));
    originalGraph->numOfVertices = 7;

    originalGraph->adjList = (struct node**)calloc(originalGraph->numOfVertices, sizeof(struct node*));

    addEdge(originalGraph, 0,1);
    addEdge(originalGraph, 1,2);
    addEdge(originalGraph, 1,3);
    addEdge(originalGraph, 2,3);
    addEdge(originalGraph, 3,0);
    addEdge(originalGraph, 3,4);
    addEdge(originalGraph, 4,2);
    addEdge(originalGraph, 4,5);
    addEdge(originalGraph, 5,6);
    addEdge(originalGraph, 6,4);

    // Mapping the Topology of the Graph
    int mapping[MAX_NODES];
    memset(mapping, -1, sizeof(mapping));

    mapTopology(originalGraph, mapping);

    return 0;
}