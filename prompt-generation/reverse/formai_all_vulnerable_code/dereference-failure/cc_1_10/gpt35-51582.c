//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

// Defining struct node
struct node {
    int x, y, level;
    struct node *next;
};

// Initializing the maze
int maze[ROW][COL] = { {0, 0, 0, 0, 0},
                       {0, 1, 1, 0, 0},
                       {0, 0, 1, 0, 0},
                       {0, 0, 1, 1, 0},
                       {0, 0, 0, 0, 0} };

// Checking if node is valid or not
int is_valid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && maze[row][col] != 1;
}

// Printing the solution path
void print_path(struct node *node) {
    if (node == NULL) return;
    print_path(node->next);
    printf("(%d, %d) ", node->x, node->y);
}

// Code for solving the maze using BFS algorithm
void BFS(struct node *start, struct node *end) {
    int direction_x[] = {-1, 0, 1, 0};
    int direction_y[] = {0, 1, 0, -1};

    // Initializing the queue for BFS algorithm
    struct node *queue = malloc(sizeof(struct node));
    queue->x = start->x;
    queue->y = start->y;
    queue->level = 0;
    queue->next = NULL;

    struct node *temp, *tail;
    tail = queue;

    while (queue != NULL) {
        temp = queue;
        queue = queue->next;

        // Setting the end node levels
        if (temp->x == end->x && temp->y == end->y) {
            printf("The shortest path from (%d, %d) to (%d, %d) is: ", start->x, start->y, end->x, end->y);
            print_path(temp);
            printf("\n");
            return;
        }

        // Exploring the neighboring nodes
        int i;
        for (i = 0; i < 4; i++) {
            int row = temp->x + direction_x[i];
            int col = temp->y + direction_y[i];

            if (is_valid(row, col)) {
                maze[row][col] = 1;
                struct node *new_node = (struct node*) malloc(sizeof(struct node));
                new_node->x = row;
                new_node->y = col;
                new_node->level = temp->level + 1;
                new_node->next = NULL;
                tail->next = new_node;
                tail = tail->next;
            }
        }
    }

    // Path not found
    printf("No path found!\n");
}

int main() {
    struct node start = {0, 0, 0, NULL};
    struct node end = {ROW-1, COL-1, 0, NULL};
    BFS(&start, &end);
    return 0;
}