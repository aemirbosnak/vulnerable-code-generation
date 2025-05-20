//FormAI DATASET v1.0 Category: Graph representation ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

struct node{
    int id;
    struct node *next;
};

typedef struct node node;

void addEdge(node *graph[], int u, int v){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->id = v;
    newnode->next = graph[u];
    graph[u] = newnode;
}

void printGraph(node *graph[], int n){
    for(int i=0;i<n;i++){
        node *temp = graph[i];
        printf("%d -->", i);
        while(temp!=NULL){
            printf(" %d", temp->id);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int n,m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    node *graph[n];
    for(int i=0;i<n;i++){
        graph[i] = NULL;
    }
    printf("Enter edges: \n");
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
        addEdge(graph, v, u);
    }
    printf("\n");
    printGraph(graph, n);
    return 0;
}