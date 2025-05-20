//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Node structure for the A* algorithm
typedef struct Node {
    int x;
    int y;
    int g_score;  // Cost from start to current node
    int h_score;  // Heuristic score
    int f_score;  // Total cost (g_score + h_score)
    struct Node* parent;
} Node;

// Comparison function for sorting nodes based on their f_scores
int compare(const void* a, const void* b) {
    const Node* node1 = (const Node*)a;
    const Node* node2 = (const Node*)b;
    return node1->f_score - node2->f_score;
}

// Heuristic function to estimate the remaining cost to the goal
int heuristic(Node* current, Node* goal) {
    return abs(current->x - goal->x) + abs(current->y - goal->y);
}

// Function to reconstruct the path from the start node to the goal node
void reconstruct_path(Node* start, Node* goal) {
    if (goal == start) {
        printf("(%d, %d)", goal->x, goal->y);
        return;
    } else if (goal->parent == NULL) {
        printf("No path found!");
        return;
    }
    reconstruct_path(start, goal->parent);
    printf(" -> (%d, %d)", goal->x, goal->y);
}

// A* pathfinding algorithm implementation
Node* a_star(Node* start, Node* goal, int width, int height, int** grid) {
    // Initialize the open and closed lists
    Node** open_list = (Node**)malloc(sizeof(Node*) * width * height);
    int open_list_size = 0;
    Node** closed_list = (Node**)malloc(sizeof(Node*) * width * height);
    int closed_list_size = 0;

    // Add the start node to the open list
    open_list[open_list_size++] = start;
    start->g_score = 0;
    start->h_score = heuristic(start, goal);
    start->f_score = start->g_score + start->h_score;

    // While the open list is not empty
    while (open_list_size > 0) {
        // Find the node with the lowest f_score on the open list
        int min_index = 0;
        for (int i = 1; i < open_list_size; i++) {
            if (open_list[i]->f_score < open_list[min_index]->f_score) {
                min_index = i;
            }
        }
        Node* current = open_list[min_index];

        // If the current node is the goal node, return it
        if (current == goal) {
            reconstruct_path(start, goal);
            return goal;
        }

        // Remove the current node from the open list and add it to the closed list
        open_list[min_index] = open_list[open_list_size - 1];
        open_list_size--;
        closed_list[closed_list_size++] = current;

        // Get the neighbors of the current node
        int neighbors[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < 4; i++) {
            int x = current->x + neighbors[i][0];
            int y = current->y + neighbors[i][1];
            if (x >= 0 && x < width && y >= 0 && y < height && grid[x][y] != 1) {
                // Calculate the tentative g_score and f_score of the neighbor
                Node* neighbor = (Node*)malloc(sizeof(Node));
                neighbor->x = x;
                neighbor->y = y;
                neighbor->g_score = current->g_score + 1;
                neighbor->h_score = heuristic(neighbor, goal);
                neighbor->f_score = neighbor->g_score + neighbor->h_score;

                // If the neighbor is not already in the open list or closed list
                int found = 0;
                for (int j = 0; j < open_list_size; j++) {
                    if (open_list[j] == neighbor) {
                        found = 1;
                        break;
                    }
                }
                for (int j = 0; j < closed_list_size; j++) {
                    if (closed_list[j] == neighbor) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    neighbor->parent = current;
                    open_list[open_list_size++] = neighbor;
                }
            }
        }
    }

    // No path found
    return NULL;
}

// Sample grid map
int** create_grid(int width, int height) {
    int** grid = (int**)malloc(sizeof(int*) * height);
    for (int i = 0; i < height; i++) {
        grid[i] = (int*)malloc(sizeof(int) * width);
    }

    // Set obstacles
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                grid[i][j] = 1;  // Wall
            } else {
                grid[i][j] = 0;  // Open space
            }
        }
    }

    // Add some random obstacles
    for (int i = 0; i < height * width / 10; i++) {
        int x = rand() % width;
        int y = rand() % height;
        grid[y][x] = 1;
    }

    return grid;
}

int main() {
    // Initialize the grid map
    int width = 50;
    int height = 50;
    int** grid = create_grid(width, height);

    // Initialize the start and goal nodes
    Node* start = (Node*)malloc(sizeof(Node));
    start->x = 1;
    start->y = 1;
    Node* goal = (Node*)malloc(sizeof(Node));
    goal->x = width - 2;
    goal->y = height - 2;

    // Find the path using A* algorithm
    Node* path = a_star(start, goal, width, height, grid);

    // Display the path
    if (path == NULL) {
        printf("No path found!");
    } else {
        printf("Path found: ");
    }

    return 0;
}