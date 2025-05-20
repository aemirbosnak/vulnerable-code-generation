//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_SIZE 100

// Enchanted node structure shimmers with potential
typedef struct Node {
    int x, y;
    float f_cost, g_cost, h_cost;
    struct Node *parent;
} Node;

// The realms of the maze are filled with walls, clear paths, and treasures!
int grid[HEIGHT][WIDTH] = {
    {0, 1, 0, 0, 0, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 1, 1, 0, 1, 1, 0},
    {1, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 1, 1, 1, 0, 1, 0},
    {0, 1, 1, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0}
};

// A magical function to create a node from coordinates
Node* create_node(int x, int y, Node* parent) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->x = x;
    new_node->y = y;
    new_node->parent = parent;
    new_node->g_cost = 0;
    new_node->h_cost = 0;
    new_node->f_cost = 0;
    return new_node;
}

// Squandering walls along the path to glory
bool is_valid(int x, int y) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && grid[y][x] == 0);
}

// Fabled distance to the goal – the art of heuristic
float heuristic(int x1, int y1, int x2, int y2) {
    return fabs(x1 - x2) + fabs(y1 - y2);
}

// A grandiose pathfinding function
void astar(int start_x, int start_y, int goal_x, int goal_y) {
    Node* open_set[MAX_SIZE];
    int open_count = 0;
    bool closed_set[HEIGHT][WIDTH] = {false};

    Node* start_node = create_node(start_x, start_y, NULL);
    start_node->g_cost = 0;
    start_node->h_cost = heuristic(start_x, start_y, goal_x, goal_y);
    start_node->f_cost = start_node->g_cost + start_node->h_cost;

    open_set[open_count++] = start_node;

    while (open_count > 0) {
        // We shall find the node with the lowest f_cost
        Node* current_node = open_set[0];
        int current_index = 0;
        for (int i = 1; i < open_count; i++) {
            if (open_set[i]->f_cost < current_node->f_cost) {
                current_node = open_set[i];
                current_index = i;
            }
        }

        // If we have reached the goal, the victory dance begins!
        if (current_node->x == goal_x && current_node->y == goal_y) {
            printf("Path found:\n");
            Node* node = current_node;
            while (node != NULL) {
                printf("(%d, %d) ", node->x, node->y);
                node = node->parent;
            }
            printf("\n");
            return; // Celebration concluded, we found the treasure!
        }

        // Remove current from open set and place into the elixir of closed set
        open_count--;
        open_set[current_index] = open_set[open_count];
        closed_set[current_node->y][current_node->x] = true;

        // Shamelessly check neighbor nodes
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if ((abs(dx) + abs(dy) == 1)) {
                    int neighbor_x = current_node->x + dx;
                    int neighbor_y = current_node->y + dy;

                    if (!is_valid(neighbor_x, neighbor_y) || closed_set[neighbor_y][neighbor_x]) {
                        continue; // Not valid or already visited
                    }

                    // Calculate costs as we tango through the realms
                    Node* neighbor_node = create_node(neighbor_x, neighbor_y, current_node);
                    neighbor_node->g_cost = current_node->g_cost + 1;
                    neighbor_node->h_cost = heuristic(neighbor_x, neighbor_y, goal_x, goal_y);
                    neighbor_node->f_cost = neighbor_node->g_cost + neighbor_node->h_cost;

                    // Check if neighbor is in open set already
                    bool in_open_set = false;
                    for (int i = 0; i < open_count; i++) {
                        if (open_set[i]->x == neighbor_node->x && open_set[i]->y == neighbor_node->y) {
                            in_open_set = true;
                            if (open_set[i]->g_cost > neighbor_node->g_cost) {
                                open_set[i]->g_cost = neighbor_node->g_cost; // Update path
                                open_set[i]->parent = current_node;
                            }
                            break;
                        }
                    }
                    if (!in_open_set) {
                        open_set[open_count++] = neighbor_node;
                    }
                }
            }
        }
    }

    printf("No path found...\n"); // A tragic ending for our hero's quest
}

int main() {
    int start_x = 0, start_y = 0;
    int goal_x = 9, goal_y = 9;
    printf("Searching for a path from (%d, %d) to (%d, %d)...\n", start_x, start_y, goal_x, goal_y);
    astar(start_x, start_y, goal_x, goal_y);
    return 0;
}