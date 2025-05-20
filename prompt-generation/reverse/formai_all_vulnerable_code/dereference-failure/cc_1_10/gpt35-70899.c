//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: calm
/* 
    Pathfinding Algorithm: A* Search
    Author: Your Name

    This program implements the A* search algorithm for finding the shortest path 
    between two nodes in a graph. The graph is an adjacency matrix representation 
    of the maze, where each element represents a node, and its value indicates 
    whether it is open or blocked. 

    The A* algorithm works by expanding nodes based on their f values, which are 
    the sum of their heuristic estimate and the cost to reach them from the start node. 
    The heuristic used in this program is the Euclidean distance between the current 
    node and the goal node.

    To run the program, input the maze file name in the terminal when prompted.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 50
#define INF 99999

struct Node {
    int x, y;           // coordinates of node
    float f, g, h;      // f = g + h
    struct Node* parent;
};

struct Node* start, *goal;
int maze[MAX_SIZE][MAX_SIZE];
int rows, cols;
int dx[] = {-1, 0, 1, 0};   // left, up, right, down
int dy[] = {0, -1, 0, 1};   

// function prototypes
float heuristic(int x1, int y1, int x2, int y2);
int is_valid(int x, int y);
int is_goal(int x, int y);
void process_node(struct Node* current, struct Node* neighbor);
void print_path(struct Node* current);
void find_path();


int main() {

    printf("Enter the filename: ");
    char filename[20];
    scanf("%s", filename);

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    fscanf(fp, "%d %d", &rows, &cols);

    // read maze file
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(fp, "%d", &maze[i][j]);
            if (maze[i][j] == 2) {
                start = (struct Node*)malloc(sizeof(struct Node));
                start->x = i;
                start->y = j;
                start->g = 0.0;
                start->h = 0.0;
                start->parent = NULL;
            }
            else if (maze[i][j] == 3) {
                goal = (struct Node*)malloc(sizeof(struct Node));
                goal->x = i;
                goal->y = j;
            }
        }
    }
    fclose(fp);

    find_path();

    return 0;
}


/* 
    Calculates the Euclidean distance between two nodes
*/
float heuristic(int x1, int y1, int x2, int y2) {
    float dx = x1 - x2;
    float dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}


/* 
    Checks if the given coordinates are within the maze and is open
*/
int is_valid(int x, int y) {
    if (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] != 1) {
        return 1;
    }
    return 0;
}


/* 
    Checks if the given coordinates are the goal
*/
int is_goal(int x, int y) {
    if (x == goal->x && y == goal->y) {
        return 1;
    }
    return 0;
}


/* 
    Add neighbor to the open list and processes its values
*/
void process_node(struct Node* current, struct Node* neighbor) {
    float cost = current->g + heuristic(current->x, current->y, neighbor->x, neighbor->y);
    if (cost < neighbor->g) {
        neighbor->g = cost;
        neighbor->h = heuristic(neighbor->x, neighbor->y, goal->x, goal->y);
        neighbor->f = neighbor->g + neighbor->h;
        neighbor->parent = current;
    }
}


/* 
    Recursively prints the path from start to goal node
*/
void print_path(struct Node* current) {
    if (current == start) {
        printf("(%d, %d)", current->x, current->y);
        return;
    }
    print_path(current->parent);
    printf(" -> (%d, %d)", current->x, current->y);
}


/*
    Finds the shortest path from start to goal using A* algorithm
*/
void find_path() {

    // create open and closed lists and initialize with start node
    struct Node* open[MAX_SIZE * MAX_SIZE] = { 0 };
    struct Node* closed[MAX_SIZE * MAX_SIZE] = { 0 };
    int open_size = 0, closed_size = 0;
    start->h = heuristic(start->x, start->y, goal->x, goal->y);
    start->f = start->g + start->h;
    open[open_size++] = start;

    // loop until goal node is found or open list is empty
    while (open_size > 0) {

        // get the node with the lowest f value
        struct Node* current = open[0];
        int current_idx = 0;
        for (int i = 1; i < open_size; i++) {
            if (open[i]->f < current->f) {
                current = open[i];
                current_idx = i;
            }
        }

        // move current node from open to closed list
        open[current_idx] = open[--open_size];
        closed[closed_size++] = current;

        // if goal node found, print path and exit function
        if (is_goal(current->x, current->y)) {
            printf("Shortest path: ");
            print_path(current);
            return;
        }

        // expand neighbors of current node
        for (int i = 0; i < 4; i++) {
            int new_x = current->x + dx[i];
            int new_y = current->y + dy[i];
            if (is_valid(new_x, new_y)) {
                // check if neighbor is in closed list
                int in_closed = 0;
                for (int j = 0; j < closed_size; j++) {
                    if (new_x == closed[j]->x && new_y == closed[j]->y) {
                        in_closed = 1;
                        break;
                    }
                }
                if (!in_closed) {
                    struct Node* neighbor = (struct Node*)malloc(sizeof(struct Node));
                    neighbor->x = new_x;
                    neighbor->y = new_y;
                    neighbor->g = INF;
                    neighbor->h = INF;
                    neighbor->f = INF;
                    neighbor->parent = NULL;
                    process_node(current, neighbor);
                    // check if neighbor is already in open list
                    int in_open = 0;
                    for (int j = 0; j < open_size; j++) {
                        if (new_x == open[j]->x && new_y == open[j]->y) {
                            in_open = 1;
                            break;
                        }
                    }
                    if (!in_open) {
                        open[open_size++] = neighbor;
                    }
                }
            }
        }
    }

    // if goal node not found, path does not exist
    printf("No path found.\n");
}