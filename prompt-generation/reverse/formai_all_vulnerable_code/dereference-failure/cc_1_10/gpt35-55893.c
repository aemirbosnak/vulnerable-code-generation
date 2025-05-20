//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

struct Node {
    int row;
    int col;
};

struct Stack {
    struct Node* nodes[ROWS * COLS];
    int top;
};

struct Queue {
    struct Node* nodes[ROWS * COLS];
    int front;
    int rear;
    int size;
};

struct Node* create_node(int row, int col) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->row = row;
    node->col = col;
    return node;
}

struct Stack* create_stack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

struct Queue* create_queue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

bool is_valid_move(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || maze[row][col] == 1) {
        return false;
    }
    return true;
}

bool dfs_helper(int row, int col, struct Stack* stack, bool visited[ROWS][COLS]) {
    if (row == ROWS - 1 && col == COLS - 1) {
        return true;
    }
    
    visited[row][col] = true;
    struct Node* node = create_node(row, col);
    stack->nodes[++stack->top] = node;
    
    if (is_valid_move(row + 1, col) && !visited[row + 1][col]) { // down
        if (dfs_helper(row + 1, col, stack, visited)) {
            return true;
        }
    }
    if (is_valid_move(row, col + 1) && !visited[row][col + 1]) { // right
        if (dfs_helper(row, col + 1, stack, visited)) {
            return true;
        }
    }
    if (is_valid_move(row - 1, col) && !visited[row - 1][col]) { // up
        if (dfs_helper(row - 1, col, stack, visited)) {
            return true;
        }
    }
    if (is_valid_move(row, col - 1) && !visited[row][col - 1]) { // left
        if (dfs_helper(row, col - 1, stack, visited)) {
            return true;
        }
    }
    
    stack->top--;
    return false;
}

void dfs() {
    struct Stack* stack = create_stack();
    bool visited[ROWS][COLS] = {false};
    
    if (dfs_helper(0, 0, stack, visited)) {
        printf("Path found!\n");
        printf("Path: ");
        for (int i = 0; i <= stack->top; ++i) {
            printf("(%d, %d) ", stack->nodes[i]->row, stack->nodes[i]->col);
        }
        printf("\n");
    } else {
        printf("Path not found!\n");
    }
}

bool bfs_helper(int row, int col, struct Queue* queue, bool visited[ROWS][COLS]) {
    visited[row][col] = true;
    struct Node* node = create_node(row, col);
    queue->nodes[++queue->rear] = node;
    queue->size++;
    
    while (queue->size != 0) {
        struct Node* curr = queue->nodes[queue->front++];
        queue->size--;
        
        if (curr->row == ROWS - 1 && curr->col == COLS - 1) {
            return true;
        }
        
        if (is_valid_move(curr->row + 1, curr->col) && !visited[curr->row + 1][curr->col]) { // down
            visited[curr->row + 1][curr->col] = true;
            struct Node* node = create_node(curr->row + 1, curr->col);
            queue->nodes[++queue->rear] = node;
            queue->size++;
        }
        if (is_valid_move(curr->row, curr->col + 1) && !visited[curr->row][curr->col + 1]) { // right
            visited[curr->row][curr->col + 1] = true;
            struct Node* node = create_node(curr->row, curr->col + 1);
            queue->nodes[++queue->rear] = node;
            queue->size++;
        }
        if (is_valid_move(curr->row - 1, curr->col) && !visited[curr->row - 1][curr->col]) { // up
            visited[curr->row - 1][curr->col] = true;
            struct Node* node = create_node(curr->row - 1, curr->col);
            queue->nodes[++queue->rear] = node;
            queue->size++;
        }
        if (is_valid_move(curr->row, curr->col - 1) && !visited[curr->row][curr->col - 1]) { // left
            visited[curr->row][curr->col - 1] = true;
            struct Node* node = create_node(curr->row, curr->col - 1);
            queue->nodes[++queue->rear] = node;
            queue->size++;
        }
    }
    
    return false;
}

void bfs() {
    struct Queue* queue = create_queue();
    bool visited[ROWS][COLS] = {false};
    
    if (bfs_helper(0, 0, queue, visited)) {
        printf("Path found!\n");
        printf("Path: ");
        for (int i = queue->front; i <= queue->rear; ++i) {
            printf("(%d, %d) ", queue->nodes[i]->row, queue->nodes[i]->col);
        }
        printf("\n");
    } else {
        printf("Path not found!\n");
    }
}

int main() {
    dfs();
    bfs();
    return 0;
}