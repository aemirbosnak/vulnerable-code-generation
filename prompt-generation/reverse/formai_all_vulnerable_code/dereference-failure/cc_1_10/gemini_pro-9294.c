//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int x, y;
    struct Node *parent;
    int g, h, f;
} Node;

typedef struct PriorityQueue {
    int size;
    Node **nodes;
} PriorityQueue;

Node *create_node(int x, int y, Node *parent) {
    Node *node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->parent = parent;
    node->g = INT_MAX;
    node->h = INT_MAX;
    node->f = INT_MAX;
    return node;
}

PriorityQueue *create_priority_queue() {
    PriorityQueue *queue = malloc(sizeof(PriorityQueue));
    queue->size = 0;
    queue->nodes = malloc(sizeof(Node *) * 100);
    return queue;
}

void enqueue(PriorityQueue *queue, Node *node) {
    queue->nodes[queue->size++] = node;
}

Node *dequeue(PriorityQueue *queue) {
    int min_index = 0;
    for (int i = 1; i < queue->size; i++) {
        if (queue->nodes[i]->f < queue->nodes[min_index]->f) {
            min_index = i;
        }
    }
    Node *node = queue->nodes[min_index];
    queue->nodes[min_index] = queue->nodes[queue->size - 1];
    queue->size--;
    return node;
}

int is_in_queue(PriorityQueue *queue, Node *node) {
    for (int i = 0; i < queue->size; i++) {
        if (queue->nodes[i] == node) {
            return 1;
        }
    }
    return 0;
}

int is_valid(int x, int y, int width, int height) {
    return x >= 0 && x < width && y >= 0 && y < height;
}

int is_obstacle(int x, int y, int **grid, int width, int height) {
    return grid[x][y] == 1;
}

int calculate_heuristic(Node *node, Node *goal) {
    return abs(node->x - goal->x) + abs(node->y - goal->y);
}

void calculate_g_h_f(Node *node, Node *goal) {
    if (node->parent != NULL) {
        node->g = node->parent->g + 1;
    }
    node->h = calculate_heuristic(node, goal);
    node->f = node->g + node->h;
}

Node *a_star(int **grid, int width, int height, Node *start, Node *goal) {
    PriorityQueue *open_set = create_priority_queue();
    PriorityQueue *closed_set = create_priority_queue();
    enqueue(open_set, start);
    while (open_set->size > 0) {
        Node *current = dequeue(open_set);
        if (current == goal) {
            return current;
        }
        closed_set->nodes[closed_set->size++] = current;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int x = current->x + i;
                int y = current->y + j;
                if (is_valid(x, y, width, height) && !is_obstacle(x, y, grid, width, height)) {
                    Node *neighbour = create_node(x, y, current);
                    calculate_g_h_f(neighbour, goal);
                    if (!is_in_queue(open_set, neighbour) && !is_in_queue(closed_set, neighbour)) {
                        enqueue(open_set, neighbour);
                    }
                }
            }
        }
    }
    return NULL;
}

void print_path(Node *node) {
    if (node == NULL) {
        return;
    }
    print_path(node->parent);
    printf("(%d, %d)\n", node->x, node->y);
}

int main() {
    int width = 10;
    int height = 10;
    int **grid = malloc(sizeof(int *) * width);
    for (int i = 0; i < width; i++) {
        grid[i] = malloc(sizeof(int) * height);
    }
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            grid[i][j] = 0;
        }
    }
    grid[1][1] = 1;
    grid[1][2] = 1;
    grid[2][1] = 1;
    grid[2][2] = 1;
    grid[3][1] = 1;
    grid[3][2] = 1;
    grid[4][1] = 1;
    grid[4][2] = 1;
    Node *start = create_node(0, 0, NULL);
    Node *goal = create_node(9, 9, NULL);
    Node *path = a_star(grid, width, height, start, goal);
    print_path(path);
    return 0;
}