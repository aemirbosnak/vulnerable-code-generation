//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 10
#define HEIGHT 10
#define INF 9999

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pos;
    int g;     // Cost from start
    int h;     // Heuristic cost to goal
    int f;     // Total cost
    struct Node* parent;
} Node;

Node* create_node(int x, int y, Node* parent) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->pos.x = x;
    new_node->pos.y = y;
    new_node->g = parent ? parent->g + 1 : 0;
    new_node->h = 0;
    new_node->f = 0;
    new_node->parent = parent;
    return new_node;
}

void free_node(Node* node) {
    free(node);
}

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool is_valid(Point p, int maze[HEIGHT][WIDTH]) {
    return (p.x >= 0 && p.x < HEIGHT && p.y >= 0 && p.y < WIDTH && maze[p.x][p.y] == 0);
}

void trace_path(Node* node) {
    while (node != NULL) {
        printf("(%d, %d) <- ", node->pos.x, node->pos.y);
        node = node->parent;
    }
    printf("Start\n");
}

void a_star(int maze[HEIGHT][WIDTH], Point start, Point goal) {
    Node* open_list[WIDTH * HEIGHT];
    int open_count = 0;
    
    Node* closed_list[WIDTH * HEIGHT];
    int closed_count = 0;

    Node* start_node = create_node(start.x, start.y, NULL);
    open_list[open_count++] = start_node;

    while (open_count > 0) {
        // Find the node with the lowest f cost
        Node* current = open_list[0];
        int current_index = 0;

        for (int i = 1; i < open_count; i++) {
            if (open_list[i]->f < current->f) {
                current = open_list[i];
                current_index = i;
            }
        }

        // Remove current from open_list
        for (int i = current_index; i < open_count - 1; i++) {
            open_list[i] = open_list[i + 1];
        }
        open_count--;

        // Check if goal is reached
        if (current->pos.x == goal.x && current->pos.y == goal.y) {
            printf("Path found:\n");
            trace_path(current);
            free_node(current);
            return;
        }

        // Add current to closed_list
        closed_list[closed_count++] = current;

        // Explore neighbors
        Point directions[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Right, Down, Left, Up

        for (int i = 0; i < 4; i++) {
            Point neighbor_pos = {current->pos.x + directions[i].x, current->pos.y + directions[i].y};

            if (!is_valid(neighbor_pos, maze)) continue;

            // Check if neighbor is already in closed_list
            bool in_closed = false;
            for (int j = 0; j < closed_count; j++) {
                if (closed_list[j]->pos.x == neighbor_pos.x && closed_list[j]->pos.y == neighbor_pos.y) {
                    in_closed = true;
                    break;
                }
            }
            if (in_closed) continue;

            // Create the neighbor node
            Node* neighbor = create_node(neighbor_pos.x, neighbor_pos.y, current);
            neighbor->h = heuristic(neighbor->pos, goal);
            neighbor->f = neighbor->g + neighbor->h;

            // Check if already in open_list
            bool in_open = false;
            for (int j = 0; j < open_count; j++) {
                if (open_list[j]->pos.x == neighbor->pos.x && open_list[j]->pos.y == neighbor->pos.y && open_list[j]->g <= neighbor->g) {
                    in_open = true;
                    free_node(neighbor);
                    break;
                }
            }

            // Add neighbor to open_list
            if (!in_open) {
                open_list[open_count++] = neighbor;
            } else {
                free_node(neighbor);
            }
        }
    }

    printf("No Path found\n");
}

int main() {
    int maze[HEIGHT][WIDTH] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1, 0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0, 1, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0}
    };

    Point start = {0, 0};
    Point goal = {9, 9};

    a_star(maze, start, goal);

    return 0;
}