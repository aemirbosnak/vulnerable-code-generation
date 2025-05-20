//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define INF 99999

typedef struct {
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

void add_edge(Graph *graph, int src, int dest, int weight);
void dfs(Graph *graph, int src, int visited[]);
void bfs(Graph *graph, int src, int visited[]);
void print_graph(Graph *graph);

int main() {
    int num_vertices, num_edges, src, dest, weight;
    Graph graph;

    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);
    graph.num_vertices = num_vertices;

    printf("Enter number of edges: ");
    scanf("%d", &num_edges);

    srand(time(NULL));

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph.adj_matrix[i][j] = INF;
        }
        graph.adj_matrix[i][i] = 0;
    }

    printf("Adding edges dynamically:\n");
    for (int i = 0; i < num_edges; i++) {
        scanf("%d%d%d", &src, &dest, &weight);
        add_edge(&graph, src, dest, weight);
    }

    printf("\nAdjacency Matrix:\n");
    print_graph(&graph);

    int *visited = calloc(num_vertices, sizeof(int));

    printf("\nDepth First Search Traversal:\n");
    dfs(&graph, 0, visited);
    printf("\n");

    free(visited);

    visited = calloc(num_vertices, sizeof(int));

    printf("\nBreadth First Search Traversal:\n");
    bfs(&graph, 0, visited);
    printf("\n");

    free(visited);

    return 0;
}

void add_edge(Graph *graph, int src, int dest, int weight) {
    graph->adj_matrix[src][dest] = weight;
    graph->adj_matrix[dest][src] = weight;
}

void dfs(Graph *graph, int src, int visited[]) {
    visited[src] = 1;
    printf("%d ", src);

    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adj_matrix[src][i] != INF && visited[i] == 0) {
            dfs(graph, i, visited);
        }
    }
}

void bfs(Graph *graph, int src, int visited[]) {
    int queue[MAX_VERTICES], front = -1, rear = -1;

    visited[src] = 1;
    printf("%d ", src);

    queue[++rear] = src;

    while (front < rear) {
        int curr = queue[front++];

        for (int i = 0; i < graph->num_vertices; i++) {
            if (graph->adj_matrix[curr][i] != INF && visited[i] == 0) {
                visited[i] = 1;
                printf("%d ", i);
                queue[++rear] = i;
            }
        }
    }
}

void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("\nVertex %d: ", i);
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
    }
}