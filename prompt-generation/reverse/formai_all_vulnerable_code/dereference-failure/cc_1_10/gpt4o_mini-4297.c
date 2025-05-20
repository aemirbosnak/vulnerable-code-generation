//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define GRID_WIDTH 10
#define GRID_HEIGHT 10
#define OBSTACLE -1
#define EMPTY 0
#define START 1
#define DEST 2

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    int g; // Cost from start to this node
    int h; // Heuristic cost to destination
    int f; // Total cost
} Node;

Node* create_node(int x, int y, int g, int h) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->point.x = x;
    new_node->point.y = y;
    new_node->g = g;
    new_node->h = h;
    new_node->f = g + h;
    return new_node;
}

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool is_valid(Point p, int grid[GRID_WIDTH][GRID_HEIGHT]) {
    return (p.x >= 0 && p.x < GRID_WIDTH && p.y >= 0 && p.y < GRID_HEIGHT && grid[p.x][p.y] != OBSTACLE);
}

void reconstruct_path(Point came_from[][GRID_WIDTH], Point current, Point start) {
    Point path[GRID_WIDTH * GRID_HEIGHT];
    int path_length = 0;

    while (current.x != start.x || current.y != start.y) {
        path[path_length++] = current;
        current = came_from[current.x][current.y];
    }
    
    path[path_length++] = start; // add the start point to the path

    // Output the path in reverse order
    printf("Path: ");
    for (int i = path_length - 1; i >= 0; --i) {
        printf("(%d, %d) ", path[i].x, path[i].y);
    }
    printf("\n");
}

void a_star(int grid[GRID_WIDTH][GRID_HEIGHT], Point start, Point dest) {
    bool closed_set[GRID_WIDTH][GRID_HEIGHT] = {false};
    Node* open_set[GRID_WIDTH * GRID_HEIGHT];
    int open_set_size = 0;
    Point came_from[GRID_WIDTH][GRID_HEIGHT];

    open_set[open_set_size++] = create_node(start.x, start.y, 0, heuristic(start, dest));
    
    while (open_set_size > 0) {
        // Find the node with the lowest 'f' value
        int lowest_index = 0;
        for (int i = 1; i < open_set_size; i++) {
            if (open_set[i]->f < open_set[lowest_index]->f) {
                lowest_index = i;
            }
        }

        Node* current = open_set[lowest_index];

        // Check if we have reached the destination
        if (current->point.x == dest.x && current->point.y == dest.y) {
            reconstruct_path(came_from, current->point, start);
            return;
        }

        // Remove the current node from open_set and add to closed_set
        closed_set[current->point.x][current->point.y] = true;
        open_set[lowest_index] = open_set[--open_set_size];

        // Check neighbors
        Point neighbors[4] = {
            {current->point.x + 1, current->point.y},
            {current->point.x - 1, current->point.y},
            {current->point.x, current->point.y + 1},
            {current->point.x, current->point.y - 1}
        };

        for (int i = 0; i < 4; i++) {
            Point neighbor = neighbors[i];
            if (!is_valid(neighbor, grid) || closed_set[neighbor.x][neighbor.y]) {
                continue;
            }

            int tentative_g = current->g + 1; // Assuming cost between nodes is 1
            bool in_open_set = false;

            for (int j = 0; j < open_set_size; j++) {
                if (open_set[j]->point.x == neighbor.x && open_set[j]->point.y == neighbor.y) {
                    in_open_set = true;
                    if (tentative_g < open_set[j]->g) {
                        open_set[j]->g = tentative_g;
                        open_set[j]->f = tentative_g + heuristic(neighbor, dest);
                        came_from[neighbor.x][neighbor.y] = current->point;
                    }
                    break;
                }
            }

            if (!in_open_set) {
                Node* neighbor_node = create_node(neighbor.x, neighbor.y, tentative_g, heuristic(neighbor, dest));
                open_set[open_set_size++] = neighbor_node;
                came_from[neighbor.x][neighbor.y] = current->point;
            }
        }
    }

    printf("No path found!\n");
}

int main() {
    int grid[GRID_WIDTH][GRID_HEIGHT] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, -1, -1, 0, -1, -1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, -1, -1, 0},
        {0, -1, -1, -1, -1, -1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, -1, -1, -1, 0},
        {0, 0, -1, -1, -1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, -1, -1, 0},
        {0, -1, -1, -1, -1, -1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, -1, 0},
        {0, 0, 0, 0, 0, 0, 2, 0, 0, 0}
    };
    Point start = {0, 0};
    Point destination = {9, 6};

    printf("Starting pathfinding from (%d, %d) to (%d, %d)\n", start.x, start.y, destination.x, destination.y);
    a_star(grid, start, destination);

    return 0;
}