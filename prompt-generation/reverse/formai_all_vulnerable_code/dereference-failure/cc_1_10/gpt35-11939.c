//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COL 6
#define INF 10000

int grid[ROW][COL] = {
    {0, 8, 2, INF, INF, INF},
    {8, 0, INF, 7, INF, 4},
    {2, INF, 0, INF, 7, INF},
    {INF, 7, INF, 0, 9, 14},
    {INF, INF, 7, 9, 0, 10},
    {INF, 4, INF, 14, 10, 0}};

typedef struct node {
    int x, y;
    struct node* parent;
    int f, g, h; // f(n) = g(n) + h(n)
} node;

node* new_node(int x, int y, node* parent, int g, int h) {
    node* n = malloc(sizeof(node));
    n->x = x;
    n->y = y;
    n->parent = parent;
    n->g = g;
    n->h = h;
    n->f = g + h;
    return n;
}

int get_distance(int x1, int y1, int x2, int y2) {
    int dx = x1 - x2;
    int dy = y1 - y2;
    return dx*dx + dy*dy;
}

node* pathfind(node* start, node* goal) {
    node* open_list[ROW*COL] = {0}; // priority queue sorted by f(n)
    int open_size = 0;
    int closed[ROW][COL] = {0}; // visited nodes
    open_list[open_size++] = start;
    while (open_size > 0) {
        node* curr = open_list[0]; // get node with lowest f(n) value
        for (int i = 0; i < open_size-1; ++i) {
            if (open_list[i+1]->f < open_list[i]->f) {
                open_list[i] = open_list[i+1];
            }
        }
        open_list[--open_size] = 0; // remove node from open list
        if (curr == goal) {
            return curr;
        }
        closed[curr->x][curr->y] = 1; // mark node as visited
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) continue;
                int x = curr->x + i;
                int y = curr->y + j;
                if (x < 0 || x >= ROW || y < 0 || y >= COL) continue;
                if (closed[x][y]) continue; // already visited
                if (grid[x][y] == INF) continue; // obstacle
                int g = curr->g + get_distance(curr->x, curr->y, x, y);
                int h = get_distance(x, y, goal->x, goal->y);
                node* n = new_node(x, y, curr, g, h);
                int found = 0;
                for (int k = 0; k < open_size; ++k) {
                    if (open_list[k]->x == x && open_list[k]->y == y) {
                        if (g + h < open_list[k]->f) { // better path found
                            open_list[k]->f = g + h;
                            open_list[k]->g = g;
                            open_list[k]->h = h;
                            open_list[k]->parent = curr;
                        }
                        found = 1;
                        free(n); // free memory allocated for new node
                        break;
                    }
                }
                if (!found) {
                    open_list[open_size++] = n; // add new node to open list
                }
            }
        }
    }
    return NULL; // no path found
}

node* find_path(int start_x, int start_y, int goal_x, int goal_y) {
    node* start = new_node(start_x, start_y, NULL, 0, 0);
    node* goal = new_node(goal_x, goal_y, NULL, 0, 0);
    node* path = pathfind(start, goal);
    free(start);
    free(goal);
    return path;
}

int main() {
    node* path = find_path(0, 0, 5, 5);
    if (path != NULL) {
        printf("Path found!\n");
        node* curr = path;
        while (curr != NULL) {
            printf("(%d, %d)\n", curr->x, curr->y);
            curr = curr->parent;
        }
    } else {
        printf("No path found!\n");
    }
    return 0;
}