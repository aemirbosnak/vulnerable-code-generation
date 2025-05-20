//FormAI DATASET v1.0 Category: Graph representation ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
// A structure to represent a node in a graph
struct node{
    int data;
    struct node* next;
};
// A structure to represent a graph
struct Graph{
    int V;
    struct node** adjList;
};
// Function to create a new node with given data
struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Function to create a graph with V vertices
struct Graph* createGraph(int V){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct node**)malloc(sizeof(struct node*)*V);

    int i;
    for(i=0;i<V;i++){
        graph->adjList[i] = NULL;
    }

    return graph;
}
// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest){
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}
// Function to print the graph
void printGraph(struct Graph* graph){
    int i;
    for(i=0;i<graph->V;i++){
        struct node* temp = graph->adjList[i];
        printf("Adjacency list of vertex %d : ",i);
        while(temp){
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main(){
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}