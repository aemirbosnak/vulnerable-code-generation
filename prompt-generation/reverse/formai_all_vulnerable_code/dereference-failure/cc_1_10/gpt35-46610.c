//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 6
#define COLS 6
#define WALL 1
#define PATH 0

int matrix[ROWS][COLS] = {
    {0, 0, 0, 0, 1, 1},
    {1, 1, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 1},
    {1, 1, 0, 1, 1, 0},
    {1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0}
};

typedef struct Node {
    int row, col;
    struct Node* parent;
} Node;

Node* create_node(int row, int col, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->parent = parent;
    return node;
}

bool is_valid(int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && matrix[row][col] == PATH) {
        return true;
    }
    return false;
}

void print_path(Node* node) {
    if (node == NULL) {
        return;
    }
    print_path(node->parent);
    printf("(%d, %d) -> ", node->row, node->col);
}

void find_path() {
    Node* start_node = create_node(ROWS - 1, 0, NULL);
    Node* goal_node = create_node(0, COLS - 1, NULL);

    Node* current_node = NULL;
    Node* child_node = NULL;

    int row_offsets[] = {-1, 0, 1, 0};
    int col_offsets[] = {0, 1, 0, -1};

    int i, j;
    bool found = false;

    // Create the frontier queue and add the start node
    Node** frontier = (Node**)malloc(sizeof(Node*) * ROWS * COLS);
    int front = 0, rear = 0;
    frontier[rear++] = start_node;

    // Create the visited matrix and initialize all cells to false
    bool visited[ROWS][COLS];
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            visited[i][j] = false;
        }
    }

    // Mark the start node as visited
    visited[start_node->row][start_node->col] = true;

    // BFS loop
    while (front != rear) {
        // Dequeue a node from the frontier queue
        current_node = frontier[front++];
        if (current_node->row == goal_node->row && current_node->col == goal_node->col) {
            found = true;
            break;
        }

        // Generate child nodes and add to frontier
        for (i = 0; i < 4; i++) {
            int r = current_node->row + row_offsets[i];
            int c = current_node->col + col_offsets[i];
            if (is_valid(r, c) && !visited[r][c]) {
                visited[r][c] = true;
                child_node = create_node(r, c, current_node);
                frontier[rear++] = child_node;
            }
        }
    }
    // Print path if found
    if (found) {
        print_path(current_node);
    } else {
        printf("Path not found\n");
    }
}

int main() {
    find_path();
    return 0;
}