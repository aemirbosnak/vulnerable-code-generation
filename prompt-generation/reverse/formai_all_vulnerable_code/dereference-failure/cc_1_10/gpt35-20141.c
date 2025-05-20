//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define ROWS 10
#define COLS 10

typedef struct node {
    int x;
    int y;
    int f;
    int g;
    int h;
    bool visited;
    struct node *parent;
} Node;

Node *get_lowest_f_node(Node **open_set);
void reconstruct_path(Node *goal_node, Node **closed_set);
int manhattan_distance(Node *current_node, Node *goal_node);

int map[ROWS][COLS] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,1,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0},
    {1,0,1,0,0,0,0,0,0,0},
    {1,0,1,1,1,1,1,1,1,0},
    {1,0,0,0,0,0,0,0,1,0},
    {1,1,1,1,1,1,1,0,1,0},
    {0,0,0,0,0,0,1,0,1,0},
    {0,0,0,0,0,0,1,0,1,0},
    {0,0,0,0,0,0,0,0,0,0}
};

int main() {
    int start_x = 1;
    int start_y = 1;
    int goal_x = 8;
    int goal_y = 8;

    Node *start_node = malloc(sizeof(Node));
    start_node->x = start_x;
    start_node->y = start_y;
    start_node->visited = false;

    Node *goal_node = malloc(sizeof(Node));
    goal_node->x = goal_x;
    goal_node->y = goal_y;

    Node *open_set[ROWS*COLS];
    Node *closed_set[ROWS*COLS];
    int open_set_size = 0;
    int closed_set_size = 0;

    open_set[0] = start_node;
    open_set_size++;

    while (open_set_size > 0) {
        Node *current_node = get_lowest_f_node(open_set);

        if (current_node->x == goal_node->x && current_node->y == goal_node->y) {
            reconstruct_path(goal_node, closed_set);
            break;
        }

        // Remove current node from open set
        for (int i = 0; i < open_set_size; i++) {
            if (open_set[i] == current_node) {
                for (int j = i; j < open_set_size - 1; j++) {
                    open_set[j] = open_set[j+1];
                }
                open_set_size--;
                break;
            }
        }

        // Add current node to closed set
        current_node->visited = true;
        closed_set[closed_set_size] = current_node;
        closed_set_size++;

        // Check neighbors
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                int neighbor_x = current_node->x + i;
                int neighbor_y = current_node->y + j;

                if (neighbor_x < 0 || neighbor_y < 0 || neighbor_x >= ROWS || neighbor_y >= COLS) {
                    continue;
                }

                if (map[neighbor_x][neighbor_y] == 1) {
                    continue;
                }

                bool neighbor_visited = false;

                for (int k = 0; k < closed_set_size; k++) {
                    if (closed_set[k]->x == neighbor_x && closed_set[k]->y == neighbor_y) {
                        neighbor_visited = true;
                        break;
                    }
                }

                if (neighbor_visited) {
                    continue;
                }

                int tentative_g_score = current_node->g + 1;
                bool neighbor_in_open_set = false;

                for (int k = 0; k < open_set_size; k++) {
                    if (open_set[k]->x == neighbor_x && open_set[k]->y == neighbor_y) {
                        neighbor_in_open_set = true;
                        if (tentative_g_score < open_set[k]->g) {
                            open_set[k]->g = tentative_g_score;
                            open_set[k]->f = open_set[k]->g + open_set[k]->h;
                            open_set[k]->parent = current_node;
                        }
                        break;
                    }
                }

                if (!neighbor_in_open_set) {
                    Node *new_node = malloc(sizeof(Node));
                    new_node->x = neighbor_x;
                    new_node->y = neighbor_y;
                    new_node->visited = false;
                    new_node->g = tentative_g_score;
                    new_node->h = manhattan_distance(new_node, goal_node);
                    new_node->f = new_node->g + new_node->h;
                    new_node->parent = current_node;
                    open_set[open_set_size] = new_node;
                    open_set_size++;
                }
            }
        }
    }

    return 0;
}

Node *get_lowest_f_node(Node **open_set) {
    Node *lowest_f_node = open_set[0];
    for (int i = 0; i < ROWS*COLS; i++) {
        if (open_set[i] != NULL && open_set[i]->f < lowest_f_node->f) {
            lowest_f_node = open_set[i];
        }
    }
    return lowest_f_node;
}

void reconstruct_path(Node *goal_node, Node **closed_set) {
    printf("Path: [%d,%d]", goal_node->x, goal_node->y);
    Node *current_node = goal_node->parent;
    while (current_node != NULL) {
        printf(" -> [%d,%d]", current_node->x, current_node->y);
        current_node = current_node->parent;
    }
}

int manhattan_distance(Node *current_node, Node *goal_node) {
    return abs(current_node->x - goal_node->x) + abs(current_node->y - goal_node->y);
}