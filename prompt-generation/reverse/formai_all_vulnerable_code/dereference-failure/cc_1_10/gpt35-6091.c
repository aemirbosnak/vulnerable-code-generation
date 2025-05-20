//FormAI DATASET v1.0 Category: Graph representation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent each node in the graph
typedef struct GraphNode {
    int id;
    struct GraphNode* neighbors;
    int neighborCount;
} GraphNode;

// Define a struct to represent the whole graph
typedef struct Graph {
    GraphNode** nodes;
    int nodeCount;
    int* visited;
} Graph;

// Define a function to add an edge between two nodes
void addEdge(GraphNode* node1, GraphNode* node2) {
    node1->neighbors = realloc(node1->neighbors, sizeof(GraphNode) * (node1->neighborCount + 1));
    node1->neighbors[node1->neighborCount] = *node2;
    node1->neighborCount += 1;
}

// Define a function to create a new graph node
GraphNode* createNode(int id) {
    GraphNode* newNode = malloc(sizeof(GraphNode));
    newNode->id = id;
    newNode->neighbors = NULL;
    newNode->neighborCount = 0;
    return newNode;
}

// Define a function to create a new graph
Graph* createGraph(int nodeCount) {
    Graph* newGraph = malloc(sizeof(Graph));
    newGraph->nodes = malloc(sizeof(GraphNode*) * nodeCount);
    newGraph->nodeCount = nodeCount;
    newGraph->visited = calloc(nodeCount, sizeof(int));
    
    // Create a node for each id
    for (int i = 0; i < nodeCount; i++) {
        newGraph->nodes[i] = createNode(i);
    }
    
    // Add some edges
    addEdge(newGraph->nodes[0], newGraph->nodes[1]);
    addEdge(newGraph->nodes[1], newGraph->nodes[2]);
    addEdge(newGraph->nodes[2], newGraph->nodes[3]);
    addEdge(newGraph->nodes[3], newGraph->nodes[4]);
    addEdge(newGraph->nodes[4], newGraph->nodes[5]);
    addEdge(newGraph->nodes[5], newGraph->nodes[6]);
    addEdge(newGraph->nodes[6], newGraph->nodes[7]);
    addEdge(newGraph->nodes[7], newGraph->nodes[8]);
    addEdge(newGraph->nodes[7], newGraph->nodes[9]);
    addEdge(newGraph->nodes[9], newGraph->nodes[10]);
    addEdge(newGraph->nodes[10], newGraph->nodes[11]);
    addEdge(newGraph->nodes[11], newGraph->nodes[12]);
    addEdge(newGraph->nodes[12], newGraph->nodes[0]);
    
    return newGraph;
}

// Define a function to recursively detect cycles in a graph
int detectCycle(Graph* graph, int currentNode, int parentNode) {
    graph->visited[currentNode] = 1;
    GraphNode* node = graph->nodes[currentNode];
    for (int i = 0; i < node->neighborCount; i++) {
        int neighborId = node->neighbors[i].id;
        if (!graph->visited[neighborId]) {
            if (detectCycle(graph, neighborId, currentNode)) {
                return 1;
            }
        } else if (neighborId != parentNode) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // Create a new graph
    Graph* graph = createGraph(13);
    
    // Detect cycles in the graph
    if (detectCycle(graph, 0, -1)) {
        printf("A cycle was detected in the graph!\n");
    } else {
        printf("No cycles were detected in the graph.\n");
    }
    
    // Free memory
    for (int i = 0; i < graph->nodeCount; i++) {
        free(graph->nodes[i]->neighbors);
        free(graph->nodes[i]);
    }
    free(graph->visited);
    free(graph->nodes);
    free(graph);
    
    return 0;
}