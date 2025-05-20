//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW_SIZE 10
#define COL_SIZE 10

typedef struct Node {
    int x;
    int y;
    int f_score;
    int g_score;
    struct Node* parent;
} Node;

Node* make_node(int x, int y, int g_score, Node* parent) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->g_score = g_score;
    node->f_score = g_score + abs(x - ROW_SIZE) + abs(y - COL_SIZE);
    node->parent = parent;
    return node;
}

int heuristic_cost_estimation(int x, int y) {
    return abs(x - ROW_SIZE) + abs(y - COL_SIZE);
}

Node* lowest_f_score_node(Node* open_set[]) {
    Node* lowest_node = open_set[0];
    int lowest_f_score = open_set[0]->f_score;
    for (int i = 1; i < ROW_SIZE * COL_SIZE; i++) {
        if (open_set[i] != NULL && open_set[i]->f_score < lowest_f_score) {
            lowest_node = open_set[i];
            lowest_f_score = open_set[i]->f_score;
        }
    }
    return lowest_node;
}

int contains_node(Node* arr[], Node* node) {
    for (int i = 0; i < ROW_SIZE * COL_SIZE; i++) {
        if (arr[i] != NULL && arr[i]->x == node->x && arr[i]->y == node->y) {
            return 1;
        }
    }
    return 0;
}

void retrace_path(Node* current) {
    printf("Path:\n");
    while (current != NULL) {
        printf("(%d, %d)\n", current->x, current->y);
        current = current->parent;
    }
}

void a_star_pathfinding(int grid[][COL_SIZE]) {
    Node* start_node = make_node(0, 0, 0, NULL);
    Node* open_set[ROW_SIZE * COL_SIZE];
    for (int i = 0; i < ROW_SIZE * COL_SIZE; i++) {
        open_set[i] = NULL;
    }
    open_set[0] = start_node;
    Node* closed_set[ROW_SIZE * COL_SIZE];
    for (int i = 0; i < ROW_SIZE * COL_SIZE; i++) {
        closed_set[i] = NULL;
    }
    
    while (open_set[ROW_SIZE * COL_SIZE - 1] == NULL) {
        Node* current = lowest_f_score_node(open_set);
        if (current->x == ROW_SIZE && current->y == COL_SIZE) {
            retrace_path(current);
            return;
        }
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue; // Skip the current node
                int neighbor_x = current->x + i;
                int neighbor_y = current->y + j;
                if (neighbor_x < 0 || neighbor_x >= ROW_SIZE || neighbor_y < 0 || neighbor_y >= COL_SIZE) {
                    continue; // Out of bounds
                }
                if (grid[neighbor_x][neighbor_y] == 1) {
                    continue; // Wall
                }
                Node* neighbor = make_node(neighbor_x, neighbor_y, current->g_score + sqrt(i * i + j * j), current);
                if (contains_node(closed_set, neighbor)) {
                    continue; // Already evaluated
                }
                if (!contains_node(open_set, neighbor)) {
                    open_set[neighbor_x * COL_SIZE + neighbor_y] = neighbor;
                } else if (current->g_score + sqrt(i * i + j * j) >= neighbor->g_score) {
                    continue; // Not a better path
                }
                neighbor->parent = current;
                neighbor->g_score = current->g_score + sqrt(i * i + j * j);
                neighbor->f_score = neighbor->g_score + heuristic_cost_estimation(neighbor_x, neighbor_y);
            }
        }
        open_set[current->x * COL_SIZE + current->y] = NULL;
        closed_set[current->x * COL_SIZE + current->y] = current;
    }
}

int main() {
    int grid[ROW_SIZE][COL_SIZE] = { {0,0,0,0,0,0,0,0,0,0},
                                      {0,1,1,1,1,0,0,0,0,0},
                                      {0,0,0,0,1,0,0,1,0,0},
                                      {0,0,0,0,1,0,0,1,0,0},
                                      {0,0,0,0,1,0,0,1,0,0},
                                      {0,0,0,0,1,0,0,1,0,0},
                                      {0,0,0,0,1,0,0,1,0,0},
                                      {0,0,0,0,1,0,0,1,0,0},
                                      {0,0,0,0,0,0,0,1,0,0},
                                      {0,0,0,0,0,0,0,0,0,0} };
    a_star_pathfinding(grid);
    return 0;
}