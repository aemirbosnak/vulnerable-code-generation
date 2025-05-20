//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Define the size of the grid
#define ROW 5
#define COL 5

// Create a boolean matrix for visited nodes
bool visited[ROW][COL];

// Define a structure for each node
struct node {
    int row;
    int col;
    int f;
    int g;
    int h;
    struct node *parent;
};

// Define a structure for the starting and ending nodes
struct point {
    int row;
    int col;
};

// Define a function to calculate the heuristic value for a given node
int calculate_heuristic(int cx, int cy, int ex, int ey) {
    return abs(cx - ex) + abs(cy - ey);
}

// Define a function to check whether a node is valid or not
bool is_valid(int r, int c) {
    return (r >= 0) && (r < ROW) &&
           (c >= 0) && (c < COL);
}

// Define a function to check whether a node is blocked or not
bool is_blocked(int grid[][COL], int r, int c) {
    return (grid[r][c] == 1);
}

// Define a function to check whether a node has been visited or not
bool is_visited(int r, int c) {
    return visited[r][c];
}

// Define a function to mark a node as visited
void mark_visited(int r, int c) {
    visited[r][c] = true;
}

// Define a function to create a new node
struct node *create_node(int r, int c, int f, int g, int h, struct node *parent) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->row = r;
    new_node->col = c;
    new_node->f = f;
    new_node->g = g;
    new_node->h = h;
    new_node->parent = parent;
    return new_node;
}

// Define a function to display the path taken
void print_path(struct node *current) {
    if (current->parent == NULL) {
        printf("[%d, %d]", current->row, current->col);
        return;
    }
    print_path(current->parent);
    printf(" -> [%d, %d]", current->row, current->col);
}

// Define the A* pathfinding algorithm
void a_star(int grid[][COL], struct point start, struct point end) {
    // Initialize the open list
    struct node *open_list = create_node(start.row, start.col, 0, 0, 0, NULL);
    open_list->f = open_list->g + open_list->h;
    mark_visited(start.row, start.col);
    
    // Initialize variables for the current node and the neighbors
    struct node *current_node;
    int r, c;
    int new_g, new_h, new_f;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    
    // Keep looping until the open list is empty
    while (open_list != NULL) {
        // Get the node with the smallest f-value
        current_node = open_list;
        struct node *n = open_list;
        while (n->parent != NULL) {
            n = n->parent;
        }
        printf("Visiting [%d, %d]\n", current_node->row, current_node->col);
        if (current_node->row == end.row && current_node->col == end.col) {
            // The end node has been reached, print the path and return
            printf("Path found: ");
            print_path(current_node);
            printf("\n");
            return;
        }
        
        // Remove the current node from the open list
        open_list = open_list->parent;
        
        // Check the neighbors
        for (int i = 0; i < 4; ++i) {
            r = current_node->row + dx[i];
            c = current_node->col + dy[i];
            
            if (is_valid(r, c) && !is_visited(r, c) && !is_blocked(grid, r, c)) {
                // Calculate the new g, h, and f values for the neighbor
                new_g = current_node->g + 1;
                new_h = calculate_heuristic(r, c, end.row, end.col);
                new_f = new_g + new_h;
                
                // Add the neighbor to the open list
                struct node *new_node = create_node(r, c, new_f, new_g, new_h, current_node);
                struct node *n = open_list;
                bool added = false;
                while (n != NULL) {
                    if (new_node->f < n->f) {
                        new_node->parent = n->parent;
                        n->parent = new_node;
                        if (n == open_list) {
                            open_list = new_node;
                        }
                        added = true;
                        break;
                    }
                    n = n->parent;
                }
                if (!added) {
                    new_node->parent = open_list;
                    open_list = new_node;
                }
                
                // Mark the node as visited
                mark_visited(r, c);
            }
        }
    }
    
    // No path was found
    printf("No path found\n");
}

// Test the A* pathfinding algorithm
int main() {
    int grid[ROW][COL] = {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0}
    };
    struct point start = {0, 0};
    struct point end = {4, 4};
    a_star(grid, start, end);
    return 0;
}