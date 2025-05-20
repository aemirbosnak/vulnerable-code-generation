//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ARRAY_WIDTH 10
#define ARRAY_HEIGHT 10

// Define the map of the post-apocalyptic world
int map[ARRAY_WIDTH][ARRAY_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Define the start and end coordinates
int start_x = 1;
int start_y = 1;
int end_x = 8;
int end_y = 8;

// Define the heuristic function
int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Define the A* algorithm
int astar(int start_x, int start_y, int end_x, int end_y) {
    // Create a priority queue to store the open nodes
    typedef struct {
        int x;
        int y;
        int g;
        int h;
        int f;
    } Node;

    Node *open = (Node *)malloc(sizeof(Node) * ARRAY_WIDTH * ARRAY_HEIGHT);
    int open_size = 0;

    // Create a closed list to store the visited nodes
    int closed[ARRAY_WIDTH][ARRAY_HEIGHT];
    for (int i = 0; i < ARRAY_WIDTH; i++) {
        for (int j = 0; j < ARRAY_HEIGHT; j++) {
            closed[i][j] = 0;
        }
    }

    // Add the start node to the open list
    Node start = {start_x, start_y, 0, heuristic(start_x, start_y, end_x, end_y), 0};
    open[open_size++] = start;

    // While the open list is not empty
    while (open_size > 0) {
        // Find the node with the lowest f-score in the open list
        int best_index = 0;
        for (int i = 1; i < open_size; i++) {
            if (open[i].f < open[best_index].f) {
                best_index = i;
            }
        }

        // Get the node with the lowest f-score
        Node current = open[best_index];

        // Remove the node from the open list
        open[best_index] = open[open_size - 1];
        open_size--;

        // Add the node to the closed list
        closed[current.x][current.y] = 1;

        // If the node is the end node, return the f-score
        if (current.x == end_x && current.y == end_y) {
            return current.f;
        }

        // Get the neighbors of the current node
        Node neighbors[4] = {
            {current.x + 1, current.y, current.g + 1, heuristic(current.x + 1, current.y, end_x, end_y), current.g + 1 + heuristic(current.x + 1, current.y, end_x, end_y)},
            {current.x - 1, current.y, current.g + 1, heuristic(current.x - 1, current.y, end_x, end_y), current.g + 1 + heuristic(current.x - 1, current.y, end_x, end_y)},
            {current.x, current.y + 1, current.g + 1, heuristic(current.x, current.y + 1, end_x, end_y), current.g + 1 + heuristic(current.x, current.y + 1, end_x, end_y)},
            {current.x, current.y - 1, current.g + 1, heuristic(current.x, current.y - 1, end_x, end_y), current.g + 1 + heuristic(current.x, current.y - 1, end_x, end_y)},
        };

        // For each neighbor
        for (int i = 0; i < 4; i++) {
            Node neighbor = neighbors[i];

            // If the neighbor is valid and not in the closed list
            if (neighbor.x >= 0 && neighbor.x < ARRAY_WIDTH && neighbor.y >= 0 && neighbor.y < ARRAY_HEIGHT && closed[neighbor.x][neighbor.y] == 0) {
                // Add the neighbor to the open list
                open[open_size++] = neighbor;
            }
        }
    }

    // Return -1 if no path was found
    return -1;
}

// Print the map with the path
void print_map(int path_length) {
    for (int i = 0; i < ARRAY_WIDTH; i++) {
        for (int j = 0; j < ARRAY_HEIGHT; j++) {
            if (map[i][j] == 1) {
                printf("#");
            } else if (i == start_x && j == start_y) {
                printf("S");
            } else if (i == end_x && j == end_y) {
                printf("E");
            } else if (map[i][j] == 2) {
                printf(".");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("Path length: %d\n", path_length);
}

int main() {
    // Find the path using the A* algorithm
    int path_length = astar(start_x, start_y, end_x, end_y);

    // If a path was found, print the map with the path
    if (path_length != -1) {
        print_map(path_length);
    } else {
        printf("No path found\n");
    }

    return 0;
}