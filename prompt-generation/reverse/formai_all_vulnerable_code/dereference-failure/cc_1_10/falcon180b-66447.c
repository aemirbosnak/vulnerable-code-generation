//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50

//Structure for node
struct Node{
    char name[20];
    int id;
    int degree;
    struct Node* adj[MAX];
};

//Function to create a new node
struct Node* createNode(char name[20], int id){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->id = id;
    newNode->degree = 0;
    for(int i=0; i<MAX; i++){
        newNode->adj[i] = NULL;
    }
    return newNode;
}

//Function to add an edge between two nodes
void addEdge(struct Node* node1, struct Node* node2){
    struct Node* temp = node1->adj[node1->degree];
    node1->adj[node1->degree] = node2;
    node1->degree++;
    node2->degree++;
}

//Function to print the adjacency list representation of the graph
void printGraph(struct Node* node){
    printf("\nAdjacency List Representation:\n");
    printf("Node ID  Node Name   Degree\n");
    for(int i=0; i<node->degree; i++){
        printf("%d  %s  %d\n", node->adj[i]->id, node->adj[i]->name, node->adj[i]->degree);
    }
}

//Function to print the degree of a given node
void printDegree(struct Node* node){
    printf("\nDegree of %s is %d\n", node->name, node->degree);
}

int main(){
    struct Node* node1 = createNode("Node 1", 1);
    struct Node* node2 = createNode("Node 2", 2);
    struct Node* node3 = createNode("Node 3", 3);
    struct Node* node4 = createNode("Node 4", 4);
    struct Node* node5 = createNode("Node 5", 5);

    addEdge(node1, node2);
    addEdge(node1, node3);
    addEdge(node2, node4);
    addEdge(node3, node4);
    addEdge(node4, node5);

    printf("\nThe given graph:\n");
    printGraph(node1);

    printf("\nDegree of Node 1:\n");
    printDegree(node1);

    return 0;
}