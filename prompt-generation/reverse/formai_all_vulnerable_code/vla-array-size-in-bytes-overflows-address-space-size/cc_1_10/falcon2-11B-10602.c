//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the graph
struct Node {
    int vertex;
    int color;
};

// Function to print the graph
void printGraph(struct Node* graph, int n) {
    printf("Graph is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> %d : %d\n", graph[i].vertex, i, graph[i].color);
    }
}

// Function to initialize the graph with vertices
struct Node* initializeGraph(int n) {
    struct Node* graph = (struct Node*)malloc(n * sizeof(struct Node));
    int i;
    for (i = 0; i < n; i++) {
        graph[i].vertex = i;
        graph[i].color = i;
    }
    return graph;
}

// Function to find the chromatic number of the graph
int findChromaticNumber(struct Node* graph, int n) {
    int colorCount[n];
    int minColorCount = n;
    int minColorCountIndex;

    for (int i = 0; i < n; i++) {
        colorCount[i] = 0;
    }

    while (minColorCount > 1) {
        int minColorCountVertex;
        minColorCount = n;
        minColorCountIndex = -1;

        for (int i = 0; i < n; i++) {
            if (colorCount[i] == minColorCount) {
                minColorCountVertex = i;
                minColorCountIndex = i;
            }
        }

        if (minColorCountIndex!= -1) {
            for (int j = 0; j < n; j++) {
                if (graph[minColorCountIndex].color == graph[j].color) {
                    graph[j].color = (graph[j].color + 1) % n;
                }
            }
            minColorCount--;
            colorCount[minColorCountIndex]--;
        }
    }

    int maxColorCount = 0;
    for (int i = 0; i < n; i++) {
        if (colorCount[i] > maxColorCount) {
            maxColorCount = colorCount[i];
        }
    }

    return maxColorCount;
}

// Function to run the program
int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    struct Node* graph = initializeGraph(n);

    for (int i = 0; i < n; i++) {
        int vertex;
        printf("Enter vertex %d's color: ", i);
        scanf("%d", &vertex);
        graph[i].color = vertex;
    }

    printGraph(graph, n);

    int chromaticNumber = findChromaticNumber(graph, n);
    printf("The chromatic number of the graph is %d\n", chromaticNumber);

    return 0;
}