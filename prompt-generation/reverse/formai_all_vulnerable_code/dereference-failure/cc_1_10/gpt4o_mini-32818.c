//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define GRID_SIZE 10
#define OPEN 0
#define BLOCKED 1
#define PATH 2

typedef struct Node {
    int x;
    int y;
    float g_cost;
    float h_cost;
    float f_cost;
    struct Node *parent;
} Node;

int grid[GRID_SIZE][GRID_SIZE] = {
    {OPEN, OPEN, OPEN, BLOCKED, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN},
    {OPEN, BLOCKED, OPEN, BLOCKED, OPEN, BLOCKED, BLOCKED, BLOCKED, OPEN, OPEN},
    {OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, BLOCKED, OPEN, BLOCKED, OPEN},
    {BLOCKED, BLOCKED, OPEN, BLOCKED, BLOCKED, OPEN, BLOCKED, OPEN, OPEN, OPEN},
    {OPEN, OPEN, OPEN, BLOCKED, OPEN, OPEN, OPEN, BLOCKED, BLOCKED, OPEN},
    {OPEN, BLOCKED, BLOCKED, BLOCKED, BLOCKED, OPEN, OPEN, OPEN, OPEN, OPEN},
    {OPEN, OPEN, OPEN, OPEN, BLOCKED, BLOCKED, BLOCKED, BLOCKED, OPEN, BLOCKED},
    {OPEN, BLOCKED, BLOCKED, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN},
    {OPEN, OPEN, OPEN, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, OPEN, OPEN},
    {OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, BLOCKED, OPEN, BLOCKED}
};

Node* create_node(int x, int y, Node* parent) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->x = x;
    new_node->y = y;
    new_node->g_cost = (parent) ? parent->g_cost + 1 : 0;
    new_node->h_cost = 0;
    new_node->f_cost = 0;
    new_node->parent = parent;
    return new_node;
}

float heuristic(int x1, int y1, int x2, int y2) {
    return fabs(x1 - x2) + fabs(y1 - y2);
}

bool is_valid_move(int x, int y) {
    return (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE && grid[x][y] != BLOCKED);
}

void print_grid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == BLOCKED) printf("## ");
            else if (grid[i][j] == PATH) printf(".. ");
            else printf("   ");
        }
        printf("\n");
    }
}

void trace_path(Node* node) {
    while (node) {
        grid[node->x][node->y] = PATH;
        node = node->parent;
    }
}

void find_path(int start_x, int start_y, int target_x, int target_y) {
    Node* open_list[GRID_SIZE * GRID_SIZE];
    int open_count = 0;
    
    Node* start_node = create_node(start_x, start_y, NULL);
    start_node->h_cost = heuristic(start_x, start_y, target_x, target_y);
    start_node->f_cost = start_node->g_cost + start_node->h_cost;
    
    open_list[open_count++] = start_node;
    
    while (open_count > 0) {
        Node* current_node = open_list[0];
        int current_index = 0;

        for (int i = 1; i < open_count; i++) {
            if (open_list[i]->f_cost < current_node->f_cost) {
                current_node = open_list[i];
                current_index = i;
            }
        }
        
        if (current_node->x == target_x && current_node->y == target_y) {
            printf("Path found!\n");
            trace_path(current_node);
            print_grid();
            return;
        }
        
        open_count--;
        if (current_index < open_count) {
            open_list[current_index] = open_list[open_count];
        }
        
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) + abs(dy) != 1) continue;
                
                int new_x = current_node->x + dx;
                int new_y = current_node->y + dy;
                
                if (!is_valid_move(new_x, new_y)) continue;

                Node* neighbor = create_node(new_x, new_y, current_node);
                neighbor->h_cost = heuristic(new_x, new_y, target_x, target_y);
                neighbor->f_cost = neighbor->g_cost + neighbor->h_cost;

                // Check if neighbor is already on open list
                bool in_open = false;
                for (int i = 0; i < open_count; i++) {
                    if (open_list[i]->x == neighbor->x && open_list[i]->y == neighbor->y && open_list[i]->g_cost <= neighbor->g_cost) {
                        in_open = true;
                        break;
                    }
                }
                if (!in_open) {
                    open_list[open_count++] = neighbor;
                } else {
                    free(neighbor);
                }
            }
        }
    }

    printf("No path found!\n");
}

int main() {
    int start_x = 0, start_y = 0;
    int target_x = 9, target_y = 9;

    printf("Starting A* Pathfinding from (%d, %d) to (%d, %d)...\n", start_x, start_y, target_x, target_y);
    find_path(start_x, start_y, target_x, target_y);
    
    return 0;
}