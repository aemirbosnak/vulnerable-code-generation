//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
 
typedef struct Edge {
    int source, destination, weight;
} Edge;
 
typedef struct Graph {
    int vertices, edges;
    Edge* edge;
} Graph;
 
Graph* createGraph(int vertices, int edges) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
 
    graph->vertices = vertices;
    graph->edges = edges;
 
    graph->edge = (Edge*)malloc(edges * sizeof(Edge));
 
    return graph;
}
 
void printResult(int* result, int size) {
    printf("The following are the selected edges:\n");
    for (int i = 0; i < size; i++) {
        printf("%d - %d\n", result[i] % MAX, result[i] / MAX);
    }
}
 
int checkCycle(int* parent, int vertex1, int vertex2) {
    int parent1 = parent[vertex1];
    int parent2 = parent[vertex2];
    while(parent1 != vertex1) {
        vertex1 = parent1;
        parent1 = parent[vertex1];
    }
    while(parent2 != vertex2) {
        vertex2 = parent2;
        parent2 = parent[vertex2];
    }
    if(parent1 == parent2)
        return 1;
    else
        return 0;
}
 
int cmp(const void* a, const void* b) {
    return (((Edge*)a)->weight - ((Edge*)b)->weight);
}
 
void kruskals(Graph* graph) {
    Edge result[graph->vertices];
    int parent[graph->vertices];
    for(int i = 0; i < graph->vertices; i++)
        parent[i] = i;
    int count = 0, resultCount = 0;
    while(resultCount < graph->vertices - 1) {
        Edge minimalEdge = graph->edge[count++];
        int sourceParent = parent[minimalEdge.source];
        int destinationParent = parent[minimalEdge.destination];
        if(sourceParent != destinationParent) {
            result[resultCount++] = minimalEdge;
            parent[sourceParent] = destinationParent;
        }
    }
    int* tempResult = (int*)malloc((graph->vertices - 1) * sizeof(int));
    for(int i = 0; i < graph->vertices - 1; i++)
        tempResult[i] = result[i].source * MAX + result[i].destination;
    printResult(tempResult, graph->vertices - 1);
    free(tempResult);
}
 
int main() {
    int vertices, edges;
    printf("Enter the number of vertices and edges in the graph: ");
    scanf("%d%d", &vertices, &edges);
    Graph* graph = createGraph(vertices, edges);
    for(int i = 0; i < edges; i++) {
        printf("\nEdge %d \nEnter source, destination and weighted value : ", i);
        scanf("%d%d%d",&graph->edge[i].source,&graph->edge[i].destination,&graph->edge[i].weight);
    }
    qsort(graph->edge, graph->edges, sizeof(graph->edge[0]), cmp);
    printf("\nThe edges in the graph are sorted in ascending order of their weights using Quick Sort for Greedy Algorithm Solution:\n");
    for(int i = 0; i < edges; i++) {
        printf("\nEdge %d : %d - %d : %d\n", i+1, graph->edge[i].source, graph->edge[i].destination, graph->edge[i].weight);
    }
    kruskals(graph);
    return 0;
}