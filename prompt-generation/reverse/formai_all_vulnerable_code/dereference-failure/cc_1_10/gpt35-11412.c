//FormAI DATASET v1.0 Category: Graph representation ; Style: authentic
#include<stdio.h>
#include<stdlib.h>

struct vertex{
    int value;
    struct edge *edgeList;
    int visited;
};

struct edge{
    struct vertex *connectsTo;
    struct edge *nextEdge;
};

void printGraph(struct vertex *graph[], int size);
void addEdge(struct vertex *startVertex, struct vertex *endVertex);
void createGraph(struct vertex *graph[], int size);

int main(){
    int size;
    printf("Enter the size of the graph: ");
    scanf("%d", &size);

    struct vertex *graph[size];

    for(int i=0; i<size; i++){
        graph[i] = (struct vertex*)malloc(sizeof(struct vertex));
        graph[i]->value = i+1;
        graph[i]->edgeList = NULL;
        graph[i]->visited = 0;
    }

    createGraph(graph, size);
    printGraph(graph, size);
}

void createGraph(struct vertex *graph[], int size){
    int graphType;
    printf("Enter 1 for directed graph or 2 for undirected graph: ");
    scanf("%d", &graphType);
    
    int choice = 1;

    while(choice == 1){
        int start, end;
        printf("\nEnter the start vertex of the edge: ");
        scanf("%d", &start);
        printf("Enter the end vertex of the edge: ");
        scanf("%d", &end);

        if(start > size || end > size || start < 1 || end < 1){
            printf("Invalid input. Please try again.\n");
            continue;
        }

        addEdge(graph[start-1], graph[end-1]);

        if(graphType == 2){
            addEdge(graph[end-1], graph[start-1]);
        }

        printf("\nEnter 1 to add more edges or enter any other number to stop: ");
        scanf("%d", &choice);
    }
}

void addEdge(struct vertex *startVertex, struct vertex *endVertex){
    struct edge *newEdge = (struct edge*)malloc(sizeof(struct edge));
    newEdge->connectsTo = endVertex;
    newEdge->nextEdge = startVertex->edgeList;
    startVertex->edgeList = newEdge;
}

void printGraph(struct vertex *graph[], int size){
    printf("\nThe graph's adjacency list representation is as follows:\n");

    for(int i=0; i<size; i++){
        struct edge *list = graph[i]->edgeList;
        printf("%d -> ", graph[i]->value);

        while(list != NULL){
            printf("%d -> ", list->connectsTo->value);
            list = list->nextEdge;
        }

        printf("NULL\n");
    }
}