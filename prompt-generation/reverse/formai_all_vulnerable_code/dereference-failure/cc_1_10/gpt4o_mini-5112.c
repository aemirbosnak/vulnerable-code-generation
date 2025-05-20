//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

// Let's create a fun graph representation of a candy shop!
typedef struct Candy {
    char name[20];
    int sweetness;
} Candy;

typedef struct Graph {
    int numVertices;
    Candy candies[MAX];
    int adjacencyMatrix[MAX][MAX];
} Graph;

// Function to create a new candy
Candy createCandy(char* name, int sweetness) {
    Candy candy;
    strcpy(candy.name, name);
    candy.sweetness = sweetness;
    return candy;
}

// Function to initialize the graph
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    
    // Set all adjacency values to 0 (no connections)
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            graph->adjacencyMatrix[i][j] = 0;
    
    return graph;
}

// Function to add a candy to the graph
void addCandy(Graph* graph, int index, char* name, int sweetness) {
    if (index < graph->numVertices) {
        graph->candies[index] = createCandy(name, sweetness);
        printf("Added a sweet candy: %s with sweetness %d! Yum!\n", name, sweetness);
    } else {
        printf("Oh no! Can't add more candies, the shop is full!\n");
    }
}

// Function to add a connection between two candies
void addConnection(Graph* graph, int src, int dest) {
    if (src < graph->numVertices && dest < graph->numVertices) {
        graph->adjacencyMatrix[src][dest] = 1; // oh, they are friends now!
        graph->adjacencyMatrix[dest][src] = 1; // and it's a two-way street!
        printf("Connected %s with %s! They're officially best friends!\n", 
               graph->candies[src].name, graph->candies[dest].name);
    } else {
        printf("Oops! One of the candy indices is out of range! Can they still be friends?\n");
    }
}

// Function to display the candies and their connections
void displayGraph(Graph* graph) {
    printf("\nCandy Shop Connections - Hold on to your sweet tooth!\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%s (Sweetness level: %d) is friends with: ", 
               graph->candies[i].name, graph->candies[i].sweetness);
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjacencyMatrix[i][j] == 1) {
                printf("%s, ", graph->candies[j].name);
            }
        }
        printf("\n");
    }
}

// Function to clean up the graph
void freeGraph(Graph* graph) {
    free(graph);
    printf("Candy shop closed, see you next sugar rush!\n");
}

int main() {
    int numberOfCandies = 5;
    Graph* candyShop = createGraph(numberOfCandies);
    
    addCandy(candyShop, 0, "Choco Bar", 8);
    addCandy(candyShop, 1, "Sweet Tarts", 9);
    addCandy(candyShop, 2, "Gummy Bears", 7);
    addCandy(candyShop, 3, "Lollipop", 10);
    addCandy(candyShop, 4, "Cotton Candy", 6);

    addConnection(candyShop, 0, 1);
    addConnection(candyShop, 1, 2);
    addConnection(candyShop, 3, 4);
    addConnection(candyShop, 0, 4);
    addConnection(candyShop, 2, 3);

    displayGraph(candyShop);

    freeGraph(candyShop);
    
    return 0;
}