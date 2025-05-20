//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 10

int vertices, edges, colors;
int adjMat[MAX_VERTICES][MAX_VERTICES];
int moves[MAX_VERTICES];

//Function to randomly generate a graph with given number of vertices and edges
void generateGraph(){
    int i, j, rand1, rand2;
    for (i = 0; i < edges; ++i) {
        rand1 = rand() % vertices;
        rand2 = rand() % vertices;
        if (rand1 == rand2 || adjMat[rand1][rand2] != -1 || adjMat[rand2][rand1] != -1)
            --i;
        else {
            adjMat[rand1][rand2] = 1;
            adjMat[rand2][rand1] = 1;
        }
    }
}

int main(){
    srand(time(NULL));
    //Prompt the user to enter the number of vertices, edges and colors
    printf("Enter the number of vertices (maximum %d): ", MAX_VERTICES);
    scanf("%d", &vertices);
    printf("Enter the number of edges (maximum %d): ", vertices*(vertices-1)/2);
    scanf("%d", &edges);
    printf("Enter the number of colors (minimum 3): ");
    scanf("%d", &colors);

    //Initialize the adjacency matrix with -1
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            adjMat[i][j] = -1;
        }
    }

    //Generate the random graph
    generateGraph();

    //Print the generated graph
    printf("Generated Graph:\n");
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            printf("%d ", adjMat[i][j]);
        }
        printf("\n");
    }

    return 0;
}