//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_COLORS 10

typedef struct {
    int id;
    int color;
} Node;

void print_graph(Node *graph, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", graph[i].id);
    }
    printf("\n");
}

int is_valid(Node *graph, int n, int color, int node_id) {
    for (int i = 0; i < n; i++) {
        if (graph[i].id == node_id && graph[i].color == color) {
            return 0;
        }
        if (graph[i].color == color) {
            return 0;
        }
    }
    return 1;
}

void color_graph(Node *graph, int n) {
    int colors[MAX_COLORS] = {0};
    for (int i = 0; i < n; i++) {
        int color = rand() % MAX_COLORS;
        while (!is_valid(graph, n, color, i)) {
            color = rand() % MAX_COLORS;
        }
        graph[i].color = color;
        colors[color] = 1;
    }
}

void k_coloring(Node *graph, int n, int k) {
    int colors[MAX_COLORS] = {0};
    for (int i = 0; i < n; i++) {
        int color = rand() % k;
        while (!is_valid(graph, n, color, i)) {
            color = rand() % k;
        }
        graph[i].color = color;
        colors[color] = 1;
    }
}

int main() {
    srand(time(NULL));
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    Node *graph = malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        graph[i].id = i;
        graph[i].color = -1;
    }
    printf("Random Graph:\n");
    print_graph(graph, n);
    color_graph(graph, n);
    printf("Colored Graph:\n");
    print_graph(graph, n);
    printf("Enter the number of colors: ");
    scanf("%d", &n);
    k_coloring(graph, n, n);
    printf("K-Colored Graph:\n");
    print_graph(graph, n);
    return 0;
}