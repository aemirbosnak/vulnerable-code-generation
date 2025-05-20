//FormAI DATASET v1.0 Category: Graph representation ; Style: puzzling
#include <stdlib.h>
#include <stdio.h>

struct node { 
    int data; 
    struct node* next; 
};

void addEdge(struct node* adj[], int u, int v) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node)); 
    newNode->data = v; 
    newNode->next = adj[u]; 
    adj[u] = newNode; 
}

void printGraph(struct node* adj[], int V) {
    printf("\nM... Mindscape's Hidden Language: \n");
    for (int u = 0; u < V; u++) {
        printf("|");
        struct node* temp = adj[u]; 
        while (temp) { 
            printf(" %d ->", temp->data); 
            temp = temp->next; 
        }
        printf(" NULL \n");
    }
    printf("|");
}

int main() { 
    int V = 7; 
    struct node* adj[V]; 
    for (int i = 0; i < V; i++) {
        adj[i] = NULL; 
    }
    
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 3); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    
    printGraph(adj, V); 
    
    printf("\n\t Hidden Message: In our language, a graph is a way of representing a set of objects where some pairs of the objects are connected by links.\n\n");
    
    return 0; 
}