//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100
#define MAX_WEIGHT 1000

typedef struct {
    int vertex;
    int weight;
} Edge;

typedef struct {
    int size;
    Edge* edges;
} Graph;

void print_graph(Graph* graph);
void add_edge(Graph* graph, int from, int to, int weight);
int bfs(Graph* graph, int start);

int main() {
    srand(time(NULL));

    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->size = n;
    graph->edges = (Edge*)malloc(sizeof(Edge) * n);

    for (int i = 0; i < n; i++) {
        graph->edges[i].vertex = rand() % n;
        graph->edges[i].weight = rand() % MAX_WEIGHT;
    }

    printf("Graph created:\n");
    print_graph(graph);

    int start, end;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    printf("Enter the ending vertex: ");
    scanf("%d", &end);

    int shortest_path = bfs(graph, start);
    printf("Shortest path length: %d\n", shortest_path);

    return 0;
}

void print_graph(Graph* graph) {
    printf("Vertices:\n");
    for (int i = 0; i < graph->size; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->size; j++) {
            if (graph->edges[i].vertex == j) {
                printf("%d ", graph->edges[i].weight);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void add_edge(Graph* graph, int from, int to, int weight) {
    if (from < 0 || from >= graph->size || to < 0 || to >= graph->size) {
        printf("Invalid vertex\n");
        return;
    }

    graph->edges[from].vertex = to;
    graph->edges[from].weight = weight;
}

int bfs(Graph* graph, int start) {
    int* visited = (int*)calloc(graph->size, sizeof(int));
    for (int i = 0; i < graph->size; i++) {
        visited[i] = 0;
    }

    int* queue = (int*)calloc(graph->size, sizeof(int));
    queue[0] = start;
    visited[start] = 1;

    int queue_size = 1;

    while (queue_size > 0) {
        int current = queue[--queue_size];
        printf("%d ", current);

        for (int i = 0; i < graph->size; i++) {
            if (graph->edges[current].vertex == i &&!visited[i]) {
                queue[queue_size] = i;
                visited[i] = 1;
                queue_size++;
            }
        }
    }

    return queue_size;
}