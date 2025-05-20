//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>  // INT_MAX

typedef struct Node Node;
struct Node {
    int x, y;
    Node *next;
    Node *prev;
};

typedef struct Queue Queue;
struct Queue {
    Node *head;
    Node *tail;
};

void queue_push(Queue *queue, int x, int y) {
    Node *new_node = malloc(sizeof(Node));
    new_node->x = x;
    new_node->y = y;
    new_node->next = NULL;
    if (queue->tail) {
        queue->tail->next = new_node;
        new_node->prev = queue->tail;
        queue->tail = new_node;
    } else {
        queue->head = queue->tail = new_node;
    }
}

Node *queue_pop(Queue *queue) {
    Node *node = queue->head;
    if (node) {
        queue->head = node->next;
        if (queue->head) {
            queue->head->prev = NULL;
        } else {
            queue->tail = NULL;
        }
    }
    return node;
}

// where walls are represented by 1 and empty space by 0
int **create_grid(int width, int height) {
    int **grid = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        grid[i] = malloc(sizeof(int) * width);
    }
    return grid;
}

void free_grid(int **grid, int height) {
    for (int i = 0; i < height; i++) {
        free(grid[i]);
    }
    free(grid);
}

void print_grid(int **grid, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// A* algorithm implementation
int dijkstra(int **grid, int width, int height, int start_x, int start_y, int end_x, int end_y) {
    if (grid[start_y][start_x] == 1 || grid[end_y][end_x] == 1) {
        return -1;  // no path found
    }

    int **cost = create_grid(width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cost[i][j] = INT_MAX;
        }
    }

    Queue queue;
    queue.head = queue.tail = NULL;
    queue_push(&queue, start_x, start_y);
    cost[start_y][start_x] = 0;

    while (queue.head) {
        Node *node = queue_pop(&queue);
        if (node->x == end_x && node->y == end_y) {
            free_grid(cost, height);
            return cost[node->y][node->x];
        }

        int x = node->x;
        int y = node->y;

        if (x + 1 < width && grid[y][x + 1] != 1 && cost[y][x + 1] > cost[y][x] + 1) {
            queue_push(&queue, x + 1, y);
            cost[y][x + 1] = cost[y][x] + 1;
        }

        if (y + 1 < height && grid[y + 1][x] != 1 && cost[y + 1][x] > cost[y][x] + 1) {
            queue_push(&queue, x, y + 1);
            cost[y + 1][x] = cost[y][x] + 1;
        }

        if (x - 1 >= 0 && grid[y][x - 1] != 1 && cost[y][x - 1] > cost[y][x] + 1) {
            queue_push(&queue, x - 1, y);
            cost[y][x - 1] = cost[y][x] + 1;
        }

        if (y - 1 >= 0 && grid[y - 1][x] != 1 && cost[y - 1][x] > cost[y][x] + 1) {
            queue_push(&queue, x, y - 1);
            cost[y - 1][x] = cost[y][x] + 1;
        }
        
        free(node);
    }

    free_grid(cost, height);
    return -1;  // no path found
}

int main() {
    int width = 10;
    int height = 10;
    int **grid = create_grid(width, height);

    // create walls
    for (int i = 0; i < height; i++) {
        grid[i][0] = 1;
        grid[i][width - 1] = 1;
    }
    for (int j = 0; j < width; j++) {
        grid[0][j] = 1;
        grid[height - 1][j] = 1;
    }
    grid[3][3] = 1;
    grid[3][4] = 1;
    grid[3][5] = 1;
    grid[5][3] = 1;
    grid[5][4] = 1;
    grid[5][5] = 1;

    // print grid
    print_grid(grid, width, height);

    // find shortest path
    int start_x = 1;
    int start_y = 1;
    int end_x = 8;
    int end_y = 8;
    int distance = dijkstra(grid, width, height, start_x, start_y, end_x, end_y);
    if (distance == -1) {
        printf("No path found.\n");
    } else {
        printf("Shortest path length: %d\n", distance);
    }

    free_grid(grid, height);
    return 0;
}