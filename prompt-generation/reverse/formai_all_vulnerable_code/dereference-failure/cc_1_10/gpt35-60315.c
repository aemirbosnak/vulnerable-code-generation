//FormAI DATASET v1.0 Category: Graph representation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 20
#define COLUMNS 30

// Function to print the graph
void printGraph(bool graph[ROWS][COLUMNS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(graph[i][j]) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
}

// Function to add an edge to the graph
void addEdge(bool graph[ROWS][COLUMNS], int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;
    while(true) {
        graph[x1][y1] = true;
        if(x1 == x2 && y1 == y2) break;
        int e2 = err * 2;
        if(e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if(e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

int main() {
    bool graph[ROWS][COLUMNS] = {0};
    addEdge(graph, 10, 1, 3, 15);
    addEdge(graph, 10, 1, 23, 10);
    addEdge(graph, 10, 1, 15, 25);
    addEdge(graph, 3, 15, 23, 10);
    addEdge(graph, 23, 10, 15, 25);
    printGraph(graph);
    return 0;
}