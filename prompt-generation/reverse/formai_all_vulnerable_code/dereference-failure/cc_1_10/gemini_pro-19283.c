//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_COLORS 10

/* Graph data structure */
typedef struct {
    int num_nodes;
    int num_edges;
    int** adj_matrix;
} Graph;

/* Color data structure */
typedef enum {
    UNCOLORED,
    COLORED
} ColorStatus;

/* Stack data structure */
typedef struct {
    int* arr;
    int top;
} Stack;

/* Create a new graph */
Graph* create_graph(int num_nodes, int num_edges) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->num_edges = num_edges;

    graph->adj_matrix = (int**)malloc(num_nodes * sizeof(int*));
    for (int i = 0; i < num_nodes; i++) {
        graph->adj_matrix[i] = (int*)malloc(num_nodes * sizeof(int));
    }

    return graph;
}

/* Free the memory allocated for the graph */
void free_graph(Graph* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
}

/* Create a new stack */
Stack* create_stack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(size * sizeof(int));
    stack->top = -1;
    return stack;
}

/* Free the memory allocated for the stack */
void free_stack(Stack* stack) {
    free(stack->arr);
    free(stack);
}

/* Push an element onto the stack */
void push(Stack* stack, int element) {
    stack->arr[++stack->top] = element;
}

/* Pop an element from the stack */
int pop(Stack* stack) {
    return stack->arr[stack->top--];
}

/* Check if the stack is empty */
int is_empty(Stack* stack) {
    return stack->top == -1;
}

/* Check if the graph is connected */
int is_connected(Graph* graph) {
    Stack* stack = create_stack(graph->num_nodes);

    int visited[graph->num_nodes];
    for (int i = 0; i < graph->num_nodes; i++) {
        visited[i] = 0;
    }

    push(stack, 0);
    visited[0] = 1;

    while (!is_empty(stack)) {
        int u = pop(stack);
        for (int v = 0; v < graph->num_nodes; v++) {
            if (graph->adj_matrix[u][v] == 1 && visited[v] == 0) {
                push(stack, v);
                visited[v] = 1;
            }
        }
    }

    free_stack(stack);

    for (int i = 0; i < graph->num_nodes; i++) {
        if (visited[i] == 0) {
            return 0;
        }
    }

    return 1;
}

/* Color the graph using the greedy algorithm */
int color_graph(Graph* graph, int* colors) {
    int num_colors = 0;

    for (int i = 0; i < graph->num_nodes; i++) {
        colors[i] = UNCOLORED;
    }

    for (int i = 0; i < graph->num_nodes; i++) {
        if (colors[i] == UNCOLORED) {
            colors[i] = COLORED;
            num_colors++;
            for (int j = 0; j < graph->num_nodes; j++) {
                if (graph->adj_matrix[i][j] == 1) {
                    colors[j] = UNCOLORED;
                }
            }
        }
    }

    return num_colors;
}

/* Print the coloring of the graph */
void print_coloring(Graph* graph, int* colors) {
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("Node %d: Color %d\n", i, colors[i]);
    }
}

int main() {
    // Create a graph
    Graph* graph = create_graph(5, 4);
    graph->adj_matrix[0][1] = 1;
    graph->adj_matrix[0][2] = 1;
    graph->adj_matrix[1][2] = 1;
    graph->adj_matrix[1][3] = 1;
    graph->adj_matrix[2][3] = 1;
    graph->adj_matrix[3][4] = 1;

    // Check if the graph is connected
    if (!is_connected(graph)) {
        printf("The graph is not connected.\n");
        return 1;
    }

    // Create an array to store the colors of the nodes
    int colors[graph->num_nodes];

    // Color the graph using the greedy algorithm
    int num_colors = color_graph(graph, colors);

    // Print the coloring of the graph
    print_coloring(graph, colors);

    // Free the memory allocated for the graph
    free_graph(graph);

    return 0;
}