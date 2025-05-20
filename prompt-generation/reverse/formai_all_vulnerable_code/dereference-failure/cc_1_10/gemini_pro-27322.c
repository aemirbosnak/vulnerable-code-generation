//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// The brave knight, ready to explore the dungeon
typedef struct {
    int x, y;
} Knight;

// The gloomy dungeon, filled with monsters and traps
typedef struct {
    int width, height;
    char **map;
} Dungeon;

// The brave knight's trusty steed, the Graph
typedef struct {
    int num_nodes;
    int **adj_matrix;
} Graph;

// Initialize the brave knight
Knight *knight_init(int x, int y) {
    Knight *knight = (Knight *)malloc(sizeof(Knight));
    knight->x = x;
    knight->y = y;
    return knight;
}

// Initialize the gloomy dungeon
Dungeon *dungeon_init(int width, int height, char **map) {
    Dungeon *dungeon = (Dungeon *)malloc(sizeof(Dungeon));
    dungeon->width = width;
    dungeon->height = height;
    dungeon->map = map;
    return dungeon;
}

// Initialize the brave knight's trusty steed
Graph *graph_init(int num_nodes) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->adj_matrix = (int **)malloc(num_nodes * sizeof(int *));
    for (int i = 0; i < num_nodes; i++) {
        graph->adj_matrix[i] = (int *)calloc(num_nodes, sizeof(int));
    }
    return graph;
}

// Build the dungeon's graph
void graph_build(Graph *graph, Dungeon *dungeon) {
    for (int i = 0; i < dungeon->height; i++) {
        for (int j = 0; j < dungeon->width; j++) {
            if (dungeon->map[i][j] != '#') {
                int node_id = i * dungeon->width + j;
                // Connect left and right
                if (j > 0 && dungeon->map[i][j - 1] != '#') {
                    int left_node_id = i * dungeon->width + j - 1;
                    graph->adj_matrix[node_id][left_node_id] = 1;
                    graph->adj_matrix[left_node_id][node_id] = 1;
                }
                // Connect up and down
                if (i > 0 && dungeon->map[i - 1][j] != '#') {
                    int up_node_id = (i - 1) * dungeon->width + j;
                    graph->adj_matrix[node_id][up_node_id] = 1;
                    graph->adj_matrix[up_node_id][node_id] = 1;
                }
            }
        }
    }
}

// Guide the brave knight through the dungeon
void knight_explore(Knight *knight, Dungeon *dungeon, Graph *graph) {
    // Create a queue to store the knight's possible moves
    int *queue = (int *)malloc(graph->num_nodes * sizeof(int));
    int front = 0, rear = 0;

    // Enqueue the knight's starting position
    int start_node_id = knight->y * dungeon->width + knight->x;
    queue[rear++] = start_node_id;

    // Explore the dungeon until the queue is empty
    while (front != rear) {
        // Dequeue the next move
        int node_id = queue[front++];

        // Check if the move is valid
        int x = node_id % dungeon->width;
        int y = node_id / dungeon->width;
        if (dungeon->map[y][x] == '#') {
            continue;
        }

        // Update the knight's position
        knight->x = x;
        knight->y = y;

        // Check if the knight has reached the exit
        if (dungeon->map[y][x] == 'E') {
            break;
        }

        // Enqueue all possible moves from the current position
        for (int i = 0; i < graph->num_nodes; i++) {
            if (graph->adj_matrix[node_id][i] == 1) {
                queue[rear++] = i;
            }
        }
    }

    // Free the queue
    free(queue);
}

// Print the dungeon and the knight's path
void print_dungeon(Dungeon *dungeon, Knight *knight) {
    for (int i = 0; i < dungeon->height; i++) {
        for (int j = 0; j < dungeon->width; j++) {
            if (i == knight->y && j == knight->x) {
                printf("@");
            } else {
                printf("%c", dungeon->map[i][j]);
            }
        }
        printf("\n");
    }
}

// Free the dungeon
void dungeon_free(Dungeon *dungeon) {
    for (int i = 0; i < dungeon->height; i++) {
        free(dungeon->map[i]);
    }
    free(dungeon->map);
    free(dungeon);
}

// Free the graph
void graph_free(Graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
}

// Free the knight
void knight_free(Knight *knight) {
    free(knight);
}

// Main function
int main() {
    // Initialize the dungeon
    int width = 10;
    int height = 10;
    char *map[] = {
        "##########",
        "#........#",
        "#.##.##.#",
        "#..#..#.#",
        "#..#..#.#",
        "#..#..#.#",
        "#.##.##.#",
        "#........#",
        "##########",
    };
    Dungeon *dungeon = dungeon_init(width, height, map);

    // Initialize the knight
    Knight *knight = knight_init(1, 1);

    // Initialize the graph
    Graph *graph = graph_init(width * height);

    // Build the graph
    graph_build(graph, dungeon);

    // Guide the knight through the dungeon
    knight_explore(knight, dungeon, graph);

    // Print the dungeon and the knight's path
    print_dungeon(dungeon, knight);

    // Free the knight
    knight_free(knight);

    // Free the graph
    graph_free(graph);

    // Free the dungeon
    dungeon_free(dungeon);

    return 0;
}