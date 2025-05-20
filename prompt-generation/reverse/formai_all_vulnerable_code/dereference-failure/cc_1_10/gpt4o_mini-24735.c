//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 20

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjacencyList[MAX_NODES];
    int numNodes;
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, const char* src, const char* dest) {
    int srcIndex = -1, destIndex = -1;

    for (int i = 0; i < graph->numNodes; i++) {
        if (strcmp(graph->adjacencyList[i]->name, src) == 0) {
            srcIndex = i;
        }
        if (strcmp(graph->adjacencyList[i]->name, dest) == 0) {
            destIndex = i;
        }
    }

    if (srcIndex == -1) {
        srcIndex = graph->numNodes++;
        graph->adjacencyList[srcIndex] = (Node*)malloc(sizeof(Node));
        strcpy(graph->adjacencyList[srcIndex]->name, src);
        graph->adjacencyList[srcIndex]->next = NULL;
    }

    if (destIndex == -1) {
        destIndex = graph->numNodes++;
        graph->adjacencyList[destIndex] = (Node*)malloc(sizeof(Node));
        strcpy(graph->adjacencyList[destIndex]->name, dest);
        graph->adjacencyList[destIndex]->next = NULL;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, dest);
    newNode->next = graph->adjacencyList[srcIndex]->next;
    graph->adjacencyList[srcIndex]->next = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, src);
    newNode->next = graph->adjacencyList[destIndex]->next;
    graph->adjacencyList[destIndex]->next = newNode;
}

void bfs(Graph* graph, const char* startName) {
    int visited[MAX_NODES] = {0};
    Node* queue[MAX_NODES];
    int front = 0, rear = 0;

    for (int i = 0; i < graph->numNodes; i++) {
        if (strcmp(graph->adjacencyList[i]->name, startName) == 0) {
            visited[i] = 1;
            queue[rear++] = graph->adjacencyList[i];
            break;
        }
    }

    printf("BFS Order starting from %s:\n", startName);
    while (front < rear) {
        Node* currNode = queue[front++];

        printf("%s ", currNode->name);
        Node* adj = currNode->next;
        while (adj != NULL) {
            int index = -1;
            for (int i = 0; i < graph->numNodes; i++) {
                if (strcmp(graph->adjacencyList[i]->name, adj->name) == 0) {
                    index = i;
                    break;
                }
            }
            if (index != -1 && !visited[index]) {
                visited[index] = 1;
                queue[rear++] = graph->adjacencyList[index];
            }
            adj = adj->next;
        }
    }
    printf("\n");
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        Node* adjNode = graph->adjacencyList[i]->next;
        while (adjNode != NULL) {
            Node* temp = adjNode;
            adjNode = adjNode->next;
            free(temp);
        }
        free(graph->adjacencyList[i]);
    }
    free(graph);
}

int main() {
    Graph* graph = createGraph();
    char src[MAX_NAME_LENGTH], dest[MAX_NAME_LENGTH];

    printf("Enter connections (src dest) or 'exit' to quit:\n");
    while (1) {
        scanf("%s", src);
        if (strcmp(src, "exit") == 0) {
            break;
        }
        scanf("%s", dest);
        addEdge(graph, src, dest);
    }

    printf("Enter starting node for BFS:\n");
    scanf("%s", src);
    bfs(graph, src);

    freeGraph(graph);
    return 0;
}