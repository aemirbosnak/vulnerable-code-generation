//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// define maze size constants
#define ROWS 8
#define COLS 10

// define maze structure as 2D array
int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// define traversal directions
#define NORTH 1
#define SOUTH 2
#define EAST  3
#define WEST  4

// define node structure for linked list
typedef struct node {
    int x;
    int y;
    struct node *next;
} node_t;

// function to add a node to the end of a linked list
void add_node(node_t **head, int x, int y) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->x = x;
    new_node->y = y;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// function to find a path through the maze
node_t *maze_route_finder(int start_x, int start_y, int end_x, int end_y) {
    // create empty linked list to store path
    node_t *path = NULL;

    // create queue for BFS
    node_t *queue = malloc(sizeof(node_t));
    queue->x = start_x;
    queue->y = start_y;
    queue->next = NULL;

    // create visited 2D array
    int visited[ROWS][COLS] = {};
    visited[start_x][start_y] = 1;

    // create parent 2D array for backtracking later
    int parent[ROWS][COLS][2] = {};

    // continue BFS while queue is not empty
    while (queue != NULL) {
        // remove first node from queue
        int x = queue->x;
        int y = queue->y;
        queue = queue->next;

        // check if this is the end point
        if (x == end_x && y == end_y) {
            // backtrack to start point and add nodes to path linked list
            while (x != start_x || y != start_y) {
                add_node(&path, x, y);
                int temp_x = x;
                x = parent[temp_x][y][0];
                y = parent[temp_x][y][1];
            }
            add_node(&path, start_x, start_y);
            break;
        }

        // check north neighbor
        if (x > 0 && maze[x-1][y] == 0 && visited[x-1][y] == 0) {
            visited[x-1][y] = 1;
            parent[x-1][y][0] = x;
            parent[x-1][y][1] = y;
            add_node(&queue, x-1, y);
        }

        // check south neighbor
        if (x < ROWS-1 && maze[x+1][y] == 0 && visited[x+1][y] == 0) {
            visited[x+1][y] = 1;
            parent[x+1][y][0] = x;
            parent[x+1][y][1] = y;
            add_node(&queue, x+1, y);
        }

        // check east neighbor
        if (y < COLS-1 && maze[x][y+1] == 0 && visited[x][y+1] == 0) {
            visited[x][y+1] = 1;
            parent[x][y+1][0] = x;
            parent[x][y+1][1] = y;
            add_node(&queue, x, y+1);
        }

        // check west neighbor
        if (y > 0 && maze[x][y-1] == 0 && visited[x][y-1] == 0) {
            visited[x][y-1] = 1;
            parent[x][y-1][0] = x;
            parent[x][y-1][1] = y;
            add_node(&queue, x, y-1);
        }
    }

    // reverse path linked list to get correct order
    node_t *current = path;
    node_t *prev = NULL;
    node_t *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    path = prev;

    // return path linked list
    return path;
}

// main function to test maze_route_finder function
int main() {
    node_t *path = maze_route_finder(1, 1, 6, 8); // start at (1, 1) and end at (6, 8)
    if (path == NULL) {
        printf("No path found!\n");
    } else {
        printf("Path found:\n");
        node_t *current = path;
        while (current != NULL) {
            printf("(%d, %d) -> ", current->x, current->y);
            current = current->next;
        }
        printf("END\n");
    }
    return 0;
}