//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 6

typedef struct {
    int vertex;
    int color;
} vertex_t;

int is_valid(int *colors, int n, int color) {
    for(int i=0; i<n; i++) {
        if(colors[i] == color)
            return 0;
    }
    return 1;
}

void print_graph(int **graph, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int **create_graph(int n) {
    int **graph = (int **)malloc(n * sizeof(int *));
    for(int i=0; i<n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int));
        for(int j=0; j<n; j++) {
            graph[i][j] = rand() % 2;
        }
    }
    return graph;
}

void color_graph(int **graph, int n, int *colors) {
    int colored = 0;
    int *color_count = (int *)malloc(MAX_COLORS * sizeof(int));
    for(int i=0; i<MAX_COLORS; i++) {
        color_count[i] = 0;
    }

    while(colored < n) {
        int max_color_count = 0;
        int max_color = 0;
        for(int i=0; i<MAX_COLORS; i++) {
            if(color_count[i] > max_color_count) {
                max_color_count = color_count[i];
                max_color = i;
            }
        }

        for(int i=0; i<n; i++) {
            if(graph[i][colored] == 1 && is_valid(colors, colored, max_color)) {
                colors[colored] = max_color;
                color_count[max_color]++;
                colored++;
            }
        }
    }

    free(color_count);
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int **graph = create_graph(n);
    print_graph(graph, n);

    int *colors = (int *)malloc(n * sizeof(int));
    srand(time(NULL));
    color_graph(graph, n, colors);

    printf("\nColored Graph:\n");
    for(int i=0; i<n; i++) {
        printf("Vertex %d -> Color %d\n", i+1, colors[i]);
    }

    free(graph);
    free(colors);

    return 0;
}