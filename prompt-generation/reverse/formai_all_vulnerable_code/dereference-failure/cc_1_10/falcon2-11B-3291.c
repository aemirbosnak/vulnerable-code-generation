//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Function to perform graph coloring
void graphColoring(int n, int graph[][n]) {
    // Variables to keep track of used colors and vertices
    int used[n], colors[n], colorsUsed[n];
    int i, j;

    // Set all colors to -1
    for (i = 0; i < n; i++) {
        used[i] = 0;
        colors[i] = -1;
    }

    // Find the maximum number of colors required
    int maxColors = INT_MIN;
    for (i = 0; i < n; i++) {
        if (used[i] == 0) {
            maxColors = (maxColors > (graph[i][i] + 1))? maxColors : graph[i][i] + 1;
        }
    }

    // Perform graph coloring
    for (i = 0; i < n; i++) {
        if (used[i] == 0) {
            colorsUsed[i] = 0;
            for (j = 0; j < maxColors; j++) {
                if (colors[j] == -1) {
                    colors[j] = i;
                    colorsUsed[i] = 1;
                    break;
                }
            }
        }
    }

    // Print the colored graph
    printf("Colored Graph:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", i);
        for (j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    // Print the colored vertices
    printf("\nColored Vertices:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", i);
        if (colors[i]!= -1) {
            printf("(%d) ", colors[i]);
        }
        printf("\n");
    }
}

int main() {
    // Sample graph
    int graph[4][4] = {
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 0}
    };
    int n = 4;

    // Perform graph coloring
    graphColoring(n, graph);

    return 0;
}