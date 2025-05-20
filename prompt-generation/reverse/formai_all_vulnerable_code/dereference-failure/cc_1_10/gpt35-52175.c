//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 10
#define COL 10

// define a node structure for A* Algorithm implementation
struct node {
    int x,y;  // coordinate of the node
    int g,h,f;  // values used for A* algorithm calculation
    struct node *parent;  // parent node pointer
};

// define a structure for the maze
struct maze {
    int matrix[ROW][COL];  // matrix representation of the maze
    struct node *start, *end;  // start and end points of the maze
};

// create a new node with specified coordinate and parent node
struct node *new_node(int x, int y, struct node *parent) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->x = x;
    newNode->y = y;
    newNode->f = newNode->g = newNode->h = 0;
    newNode->parent = parent;
    return newNode;
}

// create a new maze with specified start and end point
struct maze *new_maze(int start_x, int start_y, int end_x, int end_y) {
    struct maze *newMaze = (struct maze*)malloc(sizeof(struct maze));
    int i,j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            newMaze->matrix[i][j] = 0;
        }
    }
    newMaze->start = new_node(start_x, start_y, NULL);
    newMaze->end = new_node(end_x, end_y, NULL);
    return newMaze;
}

// calculate the Manhattan distance between two nodes
int manhattan_distance(struct node *n, struct node *end) {
    int distance = (abs(n->x - end->x) + abs(n->y - end->y));
    return distance;
}

// check if a node is valid or not
int is_valid_node(int x, int y, struct maze *maze) {
    if (x >= 0 && x < ROW && y >= 0 && y < COL && maze->matrix[x][y] == 0) {
        return 1;
    } else {
        return 0;
    }
}

// check if a node is in the closed set or not
int is_in_closedset(struct node *n, struct node **closedset, int closed_length) {
    int i;
    for (i = 0; i < closed_length; i++) {
        if (n->x == closedset[i]->x && n->y == closedset[i]->y) {
            return 1;
        }
    }
    return 0;
}

// check if a node is in the open set or not
int is_in_openset(struct node *n, struct node **openset, int open_length) {
    int i;
    for (i = 0; i < open_length; i++) {
        if (n->x == openset[i]->x && n->y == openset[i]->y) {
            return 1;
        }
    }
    return 0;
}

// get the node with the lowest f value from the open set
struct node *get_lowest_f_node(struct node **openset, int open_length) {
    if (open_length == 0) {
        return NULL;
    }
    struct node *lowest_f_node = openset[0];
    int i;
    for (i = 1; i < open_length; i++) {
       if (openset[i]->f < lowest_f_node->f) {
          lowest_f_node = openset[i];
       }
    }
    return lowest_f_node;
}

// get the neighbors of a node
void get_neighbors(struct node *n, struct maze *maze, struct node **neighbors, int *num_neighbors) {
    int x = n->x;
    int y = n->y;
    int i,j;
    *num_neighbors = 0;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if ((i == 0 && j == 0) || (i != 0 && j != 0)) {
                continue;
            }
            int new_x = x + i;
            int new_y = y + j;
            if (is_valid_node(new_x, new_y, maze)) {
                neighbors[*num_neighbors] = new_node(new_x, new_y, n);
                (*num_neighbors)++;
            }
        }
    }
}

// calculate the path from start to end
void calculate_path(struct maze *maze) {
    struct node *start = maze->start;
    struct node *end = maze->end;
    int open_length = 0;
    struct node *openset[ROW*COL];
    int closed_length = 0;
    struct node *closedset[ROW*COL];
    openset[open_length++] = start;
    while (open_length > 0) {
        struct node *current = get_lowest_f_node(openset, open_length);
        if (current == end) {
            struct node *path = current;
            printf("Path: ");
            while (path != NULL) {
                printf("(%d,%d) ", path->x, path->y);
                path = path->parent;
            }
            printf("\n");
            return;
        }
        int i;
        for (i = 0; i < open_length; i++) {
            if (openset[i] == current) {
                openset[i] = openset[open_length-1];
                open_length--;
                break;
            }
        }
        closedset[closed_length++] = current;
        struct node *neighbors[8];
        int num_neighbors = 0;
        get_neighbors(current, maze, neighbors, &num_neighbors);
        for (i = 0; i < num_neighbors; i++) {
            struct node *neighbor = neighbors[i];
            if (is_in_closedset(neighbor, closedset, closed_length)) {
                continue;
            }
            int tentative_g = current->g + 1;
            if (!is_in_openset(neighbor, openset, open_length)) {
                openset[open_length++] = neighbor;
                neighbor->h = manhattan_distance(neighbor, end);
                neighbor->g = tentative_g;
                neighbor->f = neighbor->g + neighbor->h;
            } else if (tentative_g < neighbor->g) {
                neighbor->g = tentative_g;
                neighbor->f = neighbor->g + neighbor->h;
                neighbor->parent = current;
            }
        }
    }
    printf("No path found\n");
}

int main() {
    struct maze *maze = new_maze(0, 0, 9, 9);
    int i,j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (i == 2 && j != 7 && j != 8 && j != 9) {
                maze->matrix[i][j] = 1;
            } else if (i == 4 && j != 2 && j != 3 && j != 4) {
                maze->matrix[i][j] = 1;
            } else if (i == 6 && j != 6 && j != 7 && j != 8) {
                maze->matrix[i][j] = 1;
            } else if (i == 8 && j != 0 && j != 1 && j != 2) {
                maze->matrix[i][j] = 1;
            } else {
                maze->matrix[i][j] = 0;
            }
            printf("%d ", maze->matrix[i][j]);
        }
        printf("\n");
    }
    calculate_path(maze);
    return 0;
}