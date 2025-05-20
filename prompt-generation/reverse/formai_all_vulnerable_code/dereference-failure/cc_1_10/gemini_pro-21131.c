//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: introspective
// A maze-solving program that uses a graph representation.
// The maze is represented as a 2D array of integers, where each integer represents a different type of terrain.
// The program uses a depth-first search algorithm to find a path from the starting point to the ending point.

#include <stdio.h>
#include <stdlib.h>

// The different types of terrain.
#define WALL 0
#define OPEN 1
#define START 2
#define END 3

// The size of the maze.
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// The starting point.
#define START_X 0
#define START_Y 0

// The ending point.
#define END_X 9
#define END_Y 9

// The maze.
int maze[MAZE_WIDTH][MAZE_HEIGHT] = {
    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, WALL},
    {WALL, OPEN, WALL, WALL, WALL, WALL, WALL, WALL, OPEN, WALL},
    {WALL, OPEN, WALL, OPEN, OPEN, OPEN, OPEN, WALL, OPEN, WALL},
    {WALL, OPEN, WALL, WALL, WALL, WALL, WALL, WALL, OPEN, WALL},
    {WALL, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, WALL},
    {WALL, OPEN, WALL, WALL, WALL, WALL, WALL, WALL, OPEN, WALL},
    {WALL, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, WALL},
    {WALL, OPEN, WALL, WALL, WALL, WALL, WALL, WALL, OPEN, WALL},
    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}
};

// The graph representation of the maze.
typedef struct {
    int num_vertices;
    int** adj_list;
} graph;

// Create a new graph.
graph* create_graph(int num_vertices) {
    graph* g = malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->adj_list = malloc(sizeof(int*) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        g->adj_list[i] = malloc(sizeof(int) * num_vertices);
        for (int j = 0; j < num_vertices; j++) {
            g->adj_list[i][j] = 0;
        }
    }
    return g;
}

// Add an edge to the graph.
void add_edge(graph* g, int v1, int v2) {
    g->adj_list[v1][v2] = 1;
    g->adj_list[v2][v1] = 1;
}

// Print the graph.
void print_graph(graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = 0; j < g->num_vertices; j++) {
            printf("%d ", g->adj_list[i][j]);
        }
        printf("\n");
    }
}

// Find the path from the starting point to the ending point.
int* find_path(graph* g, int start, int end) {
    // Create a queue to store the vertices that have been visited.
    int* queue = malloc(sizeof(int) * g->num_vertices);
    int front = 0;
    int rear = 0;

    // Add the starting point to the queue.
    queue[rear++] = start;

    // Create a visited array to keep track of which vertices have been visited.
    int* visited = malloc(sizeof(int) * g->num_vertices);
    for (int i = 0; i < g->num_vertices; i++) {
        visited[i] = 0;
    }

    // Visit the vertices in the queue until the ending point is found.
    while (front != rear) {
        // Get the next vertex from the queue.
        int v = queue[front++];

        // If the vertex is the ending point, return the path.
        if (v == end) {
            return queue;
        }

        // Otherwise, add the vertex's neighbors to the queue.
        for (int i = 0; i < g->num_vertices; i++) {
            if (g->adj_list[v][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    // If the ending point was not found, return NULL.
    return NULL;
}

// Free the memory allocated for the graph.
void free_graph(graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        free(g->adj_list[i]);
    }
    free(g->adj_list);
    free(g);
}

// Main function.
int main() {
    // Create a graph to represent the maze.
    graph* g = create_graph(MAZE_WIDTH * MAZE_HEIGHT);

    // Add edges to the graph to represent the open spaces in the maze.
    for (int i = 0; i < MAZE_WIDTH; i++) {
        for (int j = 0; j < MAZE_HEIGHT; j++) {
            if (maze[i][j] == OPEN) {
                if (i > 0 && maze[i - 1][j] == OPEN) {
                    add_edge(g, i * MAZE_WIDTH + j, (i - 1) * MAZE_WIDTH + j);
                }
                if (i < MAZE_WIDTH - 1 && maze[i + 1][j] == OPEN) {
                    add_edge(g, i * MAZE_WIDTH + j, (i + 1) * MAZE_WIDTH + j);
                }
                if (j > 0 && maze[i][j - 1] == OPEN) {
                    add_edge(g, i * MAZE_WIDTH + j, i * MAZE_WIDTH + j - 1);
                }
                if (j < MAZE_HEIGHT - 1 && maze[i][j + 1] == OPEN) {
                    add_edge(g, i * MAZE_WIDTH + j, i * MAZE_WIDTH + j + 1);
                }
            }
        }
    }

    // Print the graph.
    printf("Graph:\n");
    print_graph(g);

    // Find the path from the starting point to the ending point.
    int* path = find_path(g, START_X * MAZE_WIDTH + START_Y, END_X * MAZE_WIDTH + END_Y);

    // Print the path.
    printf("Path:\n");
    for (int i = 0; i < g->num_vertices; i++) {
        if (path[i] != -1) {
            printf("%d ", path[i]);
        }
    }
    printf("\n");

    // Free the memory allocated for the graph.
    free_graph(g);

    return 0;
}