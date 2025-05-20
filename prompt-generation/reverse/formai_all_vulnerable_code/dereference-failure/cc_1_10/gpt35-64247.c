//FormAI DATASET v1.0 Category: Graph representation ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

// defining a graph node structure
struct node {
    int vertex;
    struct node* next;
};

// function to create a new node
struct node* createNode(int v) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// function to create graph
void createGraph(struct node* adjList[], int vertices) {
    int i;
    for(i=0; i<vertices; i++) {
        adjList[i] = NULL;
    }
    int u, v;
    printf("\nEnter the edges of the graph: (Enter -1 to exit)\n");
    while(1){
        printf("Enter start vertex: ");
        scanf("%d", &u);
        if(u == -1)
            break;
        printf("Enter end vertex: ");
        scanf("%d", &v);
        
        struct node* newNode = createNode(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;

        newNode = createNode(u);
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }
}

// function to print the graph
void displayGraph(struct node* adjList[], int vertices) {
    int i;
    for(i=0; i<vertices; i++) {
        printf("\nVertex %d: ", i);
        struct node* temp = adjList[i];
        while(temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL");
    }
}

int main() {
    struct node* adjList[MAX];
    int vertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    createGraph(adjList, vertices);
    displayGraph(adjList, vertices);

    return 0;
}