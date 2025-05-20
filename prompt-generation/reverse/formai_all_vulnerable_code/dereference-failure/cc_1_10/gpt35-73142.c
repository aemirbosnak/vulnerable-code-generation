//FormAI DATASET v1.0 Category: Graph representation ; Style: cheerful
/* Hey there! I am a cheerful chatbot, and I'm thrilled to present to you my unique C graph representation program! 

   This program uses linked lists to represent a graph data structure, and allows for dynamic input of nodes and edges. 
   Additionally, it supports both directed and undirected graphs, as well as weighted and unweighted edges. 
    
   I hope you find this program helpful and fun to use! Enjoy! */

#include <stdio.h>
#include <stdlib.h>

/* Define a structure for graph nodes */
typedef struct Node {
    int id;
    float weight;
    struct Node *next;
} Node;

/* Define a structure for the graph */
typedef struct Graph {
    Node *nodes[100];
    int numNodes;
    int isDirected;
} Graph;

/* Function to create a new graph */
Graph* createGraph(int isDirected) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->numNodes = 0;
    graph->isDirected = isDirected;

    int i;
    for(i = 0; i < 100; i++) {
        graph->nodes[i] = NULL;
    }

    return graph;
}

/* Function to add a node to the graph */
void addNode(Graph *graph, int id) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->id = id;
    newNode->next = NULL;

    graph->nodes[graph->numNodes++] = newNode;
}

/* Function to add an edge to the graph */
void addEdge(Graph *graph, int id1, int id2, float weight) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->id = id2;
    newNode->weight = weight;
    newNode->next = graph->nodes[id1];

    graph->nodes[id1] = newNode;

    if(!graph->isDirected) {
        /* Add a second edge for an undirected graph */
        newNode = (Node *) malloc(sizeof(Node));
        newNode->id = id1;
        newNode->weight = weight;
        newNode->next = graph->nodes[id2];

        graph->nodes[id2] = newNode;
    }
}

/* Function to print the graph */
void printGraph(Graph *graph) {
    int i;
    for(i = 0; i < graph->numNodes; i++) {
        Node *current = graph->nodes[i];

        printf("Node %d: ", i);

        while(current) {
            printf("%d (%g) ", current->id, current->weight);
            current = current->next;
        }

        printf("\n");
    }
}

/* Main function to run the program */
int main() {
    /* Create a graph */
    Graph *myGraph = createGraph(0);

    /* Add some nodes */
    addNode(myGraph, 0);
    addNode(myGraph, 1);
    addNode(myGraph, 2);
    addNode(myGraph, 3);

    /* Add some edges */
    addEdge(myGraph, 0, 1, 2);
    addEdge(myGraph, 0, 2, 3);
    addEdge(myGraph, 1, 2, 1);
    addEdge(myGraph, 2, 3, 4);

    /* Print the graph */
    printGraph(myGraph);

    /* Free the graph memory */
    free(myGraph);

    return 0;
}