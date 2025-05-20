//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_NODES 100

typedef struct {
    int x, y;
} Node;

typedef struct {
    Node node;
    int g_cost;
    int h_cost;
    int f_cost;
} AStarNode;

AStarNode* open_list[MAX_NODES];
AStarNode* closed_list[MAX_NODES];
int open_list_count = 0;
int closed_list_count = 0;

int grid[WIDTH][HEIGHT] = {
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 1, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void initialize() {
    open_list_count = 0;
    closed_list_count = 0;
}

bool is_valid(int x, int y) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && grid[x][y] == 0);
}

int heuristic(Node a, Node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);  // Use Manhattan distance
}

void add_to_open_list(Node node, int g_cost, int h_cost) {
    if (open_list_count < MAX_NODES) {
        AStarNode* new_node = (AStarNode*)malloc(sizeof(AStarNode));
        new_node->node = node;
        new_node->g_cost = g_cost;
        new_node->h_cost = h_cost;
        new_node->f_cost = g_cost + h_cost;
        open_list[open_list_count++] = new_node;
    }
}

AStarNode* get_lowest_cost_node() {
    AStarNode* lowest = open_list[0];
    for (int i = 1; i < open_list_count; i++) {
        if (open_list[i]->f_cost < lowest->f_cost) {
            lowest = open_list[i];
        }
    }
    return lowest;
}

void remove_from_open_list(AStarNode* node) {
    for (int i = 0; i < open_list_count; i++) {
        if (open_list[i] == node) {
            open_list[i] = open_list[--open_list_count];
            return;
        }
    }
}

bool is_in_closed_list(Node node) {
    for (int i = 0; i < closed_list_count; i++) {
        if (closed_list[i]->node.x == node.x && closed_list[i]->node.y == node.y) {
            return true;
        }
    }
    return false;
}

void reconstruct_path(Node came_from[WIDTH][HEIGHT], Node start, Node end) {
    Node current = end;
    while (current.x != start.x || current.y != start.y) {
        printf("Path: (%d, %d)\n", current.x, current.y);
        current = came_from[current.x][current.y];
    }
    printf("Path: (%d, %d)\n", start.x, start.y);
}

void a_star(Node start, Node end) {
    Node came_from[WIDTH][HEIGHT];

    add_to_open_list(start, 0, heuristic(start, end));

    while (open_list_count > 0) {
        AStarNode* current = get_lowest_cost_node();
        remove_from_open_list(current);
        closed_list[closed_list_count++] = current;

        if (current->node.x == end.x && current->node.y == end.y) {
            reconstruct_path(came_from, start, end);
            return;
        }

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) == abs(dy)) continue; // Skip diagonals
                int new_x = current->node.x + dx;
                int new_y = current->node.y + dy;
                Node neighbor = {new_x, new_y};

                if (is_valid(new_x, new_y) && !is_in_closed_list(neighbor)) {
                    int tentative_g_cost = current->g_cost + 1;

                    bool in_open_list = false;
                    for (int i = 0; i < open_list_count; i++) {
                        if (open_list[i]->node.x == new_x && open_list[i]->node.y == new_y) {
                            in_open_list = true;
                            break;
                        }
                    }

                    if (!in_open_list) {
                        came_from[new_x][new_y] = current->node;
                        add_to_open_list(neighbor, tentative_g_cost, heuristic(neighbor, end));
                    }
                }
            }
        }
        free(current); // Free the current node after processing
    }
    printf("No path found!\n");
}

int main() {
    initialize();
    Node start = {0, 0};
    Node end = {9, 9};
    a_star(start, end);
    return 0;
}