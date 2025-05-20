//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define ROW 10    // Number of rows
#define COL 10    // Number of columns

// Structure for a node in the grid
struct Node {
    int row;
    int col;
    int is_visited;
};

// Function to create a new node
struct Node* create_node(int row, int col) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->row = row;
    node->col = col;
    node->is_visited = 0;
    return node;
}

// Function to find the shortest path using Breadth First Search algorithm
int bfs_algorithm(int grid[ROW][COL], struct Node* start_node, struct Node* end_node) {
    int shortest_path = 0;
    struct Node* queue[ROW*COL];
    int front = 0;
    int rear = -1;
    int queue_size = 0;
    queue[++rear] = start_node;
    queue_size++;
    start_node->is_visited = 1;
    int found = 0;
    while(queue_size > 0 && !found) {
        struct Node* current_node = queue[front];
        front++;
        queue_size--;
        if(current_node->row == end_node->row && current_node->col == end_node->col) {
            found = 1;
            shortest_path = current_node->is_visited;
        }
        if(current_node->row > 0 && grid[current_node->row-1][current_node->col] != 1 
           && !create_node(current_node->row-1, current_node->col)->is_visited) {
            /* Add the node above current node to queue */
            struct Node* node_above = create_node(current_node->row-1, current_node->col);
            node_above->is_visited = current_node->is_visited + 1;
            queue[++rear] = node_above;
            queue_size++;
        }
        if(current_node->col < COL-1 && grid[current_node->row][current_node->col+1] != 1 
           && !create_node(current_node->row, current_node->col+1)->is_visited) {
            /* Add the node to the right of current node to queue */
            struct Node* node_right = create_node(current_node->row, current_node->col+1);
            node_right->is_visited = current_node->is_visited + 1;
            queue[++rear] = node_right;
            queue_size++;
        }
        if(current_node->row < ROW-1 && grid[current_node->row+1][current_node->col] != 1 
           && !create_node(current_node->row+1, current_node->col)->is_visited) {
            /* Add the node below current node to queue */
            struct Node* node_below = create_node(current_node->row+1, current_node->col);
            node_below->is_visited = current_node->is_visited + 1;
            queue[++rear] = node_below;
            queue_size++;
        }
        if(current_node->col > 0 && grid[current_node->row][current_node->col-1] != 1 
           && !create_node(current_node->row, current_node->col-1)->is_visited) {
            /* Add the node to the left of current node to queue */
            struct Node* node_left = create_node(current_node->row, current_node->col-1);
            node_left->is_visited = current_node->is_visited + 1;
            queue[++rear] = node_left;
            queue_size++;
        }
    }
    return shortest_path;
}

int main() {
    /* Initialize the grid */
    int grid[ROW][COL] = { {0, 0, 1, 0, 1, 0, 0, 0, 0, 1},
                           {1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                           {0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
                           {0, 0, 0, 0, 1, 1, 1, 0, 1, 0},
                           {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
                           {0, 0, 1, 1, 1, 1, 0, 1, 0, 0},
                           {1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
                           {0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
                           {1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                           {1, 0, 1, 0, 1, 0, 1, 1, 0, 0} };
    /* Create start node */
    struct Node* start_node = create_node(0, 0);
    /* Create end node */
    struct Node* end_node = create_node(ROW-1, COL-1);
    /* Find shortest path using Breadth First Search Algorithm */
    int shortest_path = bfs_algorithm(grid, start_node, end_node);
    printf("The shortest path from (0,0) to (%d,%d) is %d\n", ROW-1, COL-1, shortest_path);
    return 0;
}