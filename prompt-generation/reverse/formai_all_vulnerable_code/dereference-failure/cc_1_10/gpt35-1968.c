//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int x, y, g, h, f;
    bool is_obstacle;
    struct node *parent;
} node;

int rows = 10;
int cols = 10;

int heuristic(int start_x, int start_y, int goal_x, int goal_y) {
    return abs(goal_x - start_x) + abs(goal_y - start_y);
}

bool is_valid(int x, int y) {
    return (x >= 0 && x < rows && y >=0 && y < cols);
}

void set_obstacle(node *grid[][cols], int i, int j) {
    grid[i][j]->is_obstacle = true;
}

void print_grid(node *grid[][cols], int sx, int sy, int gx, int gy) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == sx && j == sy) printf(" S ");
            else if (i == gx && j == gy) printf(" G ");
            else if (grid[i][j]->is_obstacle) printf(" x ");
            else printf(" . ");
        }
        printf("\n");
    }
}

node *get_min_f_cost_node(node *open_list[], int *open_list_count) {
    node *min_node = open_list[0];
    int min_f = open_list[0]->f;

    for (int i = 0; i < *open_list_count; i++) {
        if (open_list[i]->f < min_f) {
            min_f = open_list[i]->f;
            min_node = open_list[i];
        }
    }

    // remove the selected node from the open list
    for (int i = 0; i < *open_list_count; i++) {
        if (open_list[i] == min_node) {
            (*open_list_count)--;
            for (int j=i; j < *open_list_count; j++) {
                open_list[j] = open_list[j+1];
            }
            break;
        }
    }

    return min_node;
}

void reconstruct_path(node *current_node) {
    printf("\nPath:");
    while(current_node != NULL) {
        printf("(%d,%d)->", current_node->x, current_node->y);
        current_node = current_node->parent;
    }
}

void astar(node *grid[][cols], int start_x, int start_y, int goal_x, int goal_y) {
    node *open_list[rows*cols];
    int open_list_count = 0;

    node *visited_list[rows][cols];

    // initialize all nodes
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = malloc(sizeof(node));
            grid[i][j]->x = i;
            grid[i][j]->y = j;
            grid[i][j]->is_obstacle = false;
            grid[i][j]->g = 0;
            grid[i][j]->h = heuristic(i, j, goal_x, goal_y);
            grid[i][j]->f = grid[i][j]->g + grid[i][j]->h;
            grid[i][j]->parent = NULL;
            visited_list[i][j] = NULL;
        }
    }

    // add the start node to open list
    open_list[open_list_count++] = grid[start_x][start_y];
    visited_list[start_x][start_y] = grid[start_x][start_y];

    node *current_node = NULL;

    while (open_list_count > 0) {
        current_node = get_min_f_cost_node(open_list, &open_list_count);

        if (current_node->x == goal_x && current_node->y == goal_y) {
            reconstruct_path(current_node);
            return;
        }

        // generate all neighbors
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int neighbor_x = current_node->x + i;
                int neighbor_y = current_node->y + j;

                if (is_valid(neighbor_x, neighbor_y)) {
                    // ignore the current node
                    if (i == 0 && j == 0) continue;

                    // ignore obstacles
                    if (grid[neighbor_x][neighbor_y]->is_obstacle) continue;

                    int tentative_g = current_node->g + 1;

                    // check if the neighbor node is not in the visited list
                    if (visited_list[neighbor_x][neighbor_y] == NULL) {
                        visited_list[neighbor_x][neighbor_y] = grid[neighbor_x][neighbor_y];
                        grid[neighbor_x][neighbor_y]->g = tentative_g;
                        grid[neighbor_x][neighbor_y]->f = grid[neighbor_x][neighbor_y]->g + grid[neighbor_x][neighbor_y]->h;
                        grid[neighbor_x][neighbor_y]->parent = current_node;
                        open_list[open_list_count++] = grid[neighbor_x][neighbor_y];
                    } else if (tentative_g < visited_list[neighbor_x][neighbor_y]->g) {
                        visited_list[neighbor_x][neighbor_y]->g = tentative_g;
                        visited_list[neighbor_x][neighbor_y]->f = visited_list[neighbor_x][neighbor_y]->g + visited_list[neighbor_x][neighbor_y]->h;
                        visited_list[neighbor_x][neighbor_y]->parent = current_node;
                    }

                }
            }
        }
    }

}

int main() {
    node *grid[rows][cols];
    int start_x = 1;
    int start_y = 1;
    int goal_x = 8;
    int goal_y = 8;

    set_obstacle(grid, 2, 2);
    set_obstacle(grid, 3, 2);
    set_obstacle(grid, 4, 2);
    set_obstacle(grid, 5, 2);
    set_obstacle(grid, 6, 2);
    set_obstacle(grid, 7, 4);
    set_obstacle(grid, 7, 5);
    set_obstacle(grid, 7, 6);
    
    print_grid(grid, start_x, start_y, goal_x, goal_y);

    astar(grid, start_x, start_y, goal_x, goal_y);

    return 0;
}