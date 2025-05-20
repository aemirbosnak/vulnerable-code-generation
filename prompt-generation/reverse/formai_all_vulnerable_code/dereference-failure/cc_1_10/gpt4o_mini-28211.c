//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_NAME_LENGTH 50

typedef struct AdjNode {
    int vertex;
    struct AdjNode* next;
} AdjNode;

typedef struct Graph {
    int numVertices;
    AdjNode** adjLists;
    char vertexNames[MAX_VERTICES][MAX_NAME_LENGTH];
} Graph;

AdjNode* createAdjNode(int vertex) {
    AdjNode* newNode = malloc(sizeof(AdjNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph() {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->adjLists = malloc(MAX_VERTICES * sizeof(AdjNode*));
    
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph->adjLists[i] = NULL;
    }
    
    return graph;
}

void addVertex(Graph* graph, char* name) {
    if (graph->numVertices < MAX_VERTICES) {
        strcpy(graph->vertexNames[graph->numVertices], name);
        graph->numVertices++;
    } else {
        printf("Maximum vertex limit reached.\n");
    }
}

void addEdge(Graph* graph, int src, int dest) {
    AdjNode* newNode = createAdjNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    
    newNode = createAdjNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        printf("%s: ", graph->vertexNames[v]);
        AdjNode* temp = graph->adjLists[v];
        while (temp) {
            printf("%s ", graph->vertexNames[temp->vertex]);
            temp = temp->next;
        }
        printf("\n");
    }
}

void detectiveQuest(Graph* graph) {
    printf("Sherlock Holmes is now investigating the following places:\n");
    printGraph(graph);
    
    char detectiveWork[MAX_NAME_LENGTH];
    printf("Inquire the detective about which place is suspicious: ");
    scanf("%s", detectiveWork);

    int vertexIndex = -1;
    for (int i = 0; i < graph->numVertices; i++) {
        if (strcmp(graph->vertexNames[i], detectiveWork) == 0) {
            vertexIndex = i;
            break;
        }
    }

    if (vertexIndex == -1) {
        printf("The specified place does not exist in our database.\n");
        return;
    }

    printf("Inspecting connections from %s...\n", detectiveWork);
    AdjNode* temp = graph->adjLists[vertexIndex];
    while (temp) {
        printf("Investigating nearby: %s\n", graph->vertexNames[temp->vertex]);
        temp = temp->next;
    }
    printf("Investigation concluded for %s.\n", detectiveWork);
}

int main() {
    Graph* graph = createGraph();
    
    addVertex(graph, "Baker Street");
    addVertex(graph, "Scotland Yard");
    addVertex(graph, "The Hound of the Baskervilles");
    addVertex(graph, "The Abominable Bride");
    addVertex(graph, "The Reigate Squires");
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    
    detectiveQuest(graph);
    
    // Clean-up memory
    for (int v = 0; v < graph->numVertices; v++) {
        AdjNode* temp = graph->adjLists[v];
        while (temp) {
            AdjNode* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjLists);
    free(graph);
    
    return 0;
}