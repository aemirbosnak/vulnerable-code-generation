//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct Node {
    Point point;
    struct Node *parent;
    int g;
    int h;
    int f;
} Node;

typedef struct {
    Node *nodes;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue *create_priority_queue(int capacity) {
    PriorityQueue *queue = malloc(sizeof(PriorityQueue));
    queue->nodes = malloc(sizeof(Node) * capacity);
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

void destroy_priority_queue(PriorityQueue *queue) {
    free(queue->nodes);
    free(queue);
}

void push_priority_queue(PriorityQueue *queue, Node *node) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->nodes = realloc(queue->nodes, sizeof(Node) * queue->capacity);
    }
    queue->nodes[queue->size++] = *node;
}

Node *pop_priority_queue(PriorityQueue *queue) {
    if (queue->size == 0) {
        return NULL;
    }

    int min_index = 0;
    for (int i = 1; i < queue->size; i++) {
        if (queue->nodes[i].f < queue->nodes[min_index].f) {
            min_index = i;
        }
    }

    Node *node = malloc(sizeof(Node));
    *node = queue->nodes[min_index];

    queue->nodes[min_index] = queue->nodes[queue->size - 1];
    queue->size--;

    return node;
}

int manhattan_distance(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

Node *create_node(Point point, Node *parent, int g, int h) {
    Node *node = malloc(sizeof(Node));
    node->point = point;
    node->parent = parent;
    node->g = g;
    node->h = h;
    node->f = node->g + node->h;
    return node;
}

void destroy_node(Node *node) {
    free(node);
}

int main() {
    int width = 10;
    int height = 10;
    int start_x = 0;
    int start_y = 0;
    int end_x = 9;
    int end_y = 9;

    int **grid = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        grid[i] = malloc(sizeof(int) * width);
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = 1;  // 1 represents a traversable cell
        }
    }

    grid[0][0] = 0;  // Start cell
    grid[9][9] = 0;  // End cell

    // Create the start and end nodes
    Node *start_node = create_node((Point) {start_x, start_y}, NULL, 0, manhattan_distance((Point) {start_x, start_y}, (Point) {end_x, end_y}));
    Node *end_node = create_node((Point) {end_x, end_y}, NULL, 0, 0);

    // Create the priority queue
    PriorityQueue *queue = create_priority_queue(100);

    // Push the start node into the priority queue
    push_priority_queue(queue, start_node);

    while (queue->size > 0) {
        // Pop the node with the lowest f-score from the priority queue
        Node *current_node = pop_priority_queue(queue);

        // Check if the current node is the end node
        if (current_node->point.x == end_node->point.x && current_node->point.y == end_node->point.y) {
            // Reconstruct the path from the start node to the end node
            Node *path = current_node;
            while (path != NULL) {
                printf("(%d, %d)\n", path->point.x, path->point.y);
                path = path->parent;
            }

            // Destroy the priority queue and the nodes
            destroy_priority_queue(queue);
            destroy_node(current_node);
            for (int i = 0; i < height; i++) {
                free(grid[i]);
            }
            free(grid);

            return 0;
        }

        // Set the current node as visited
        grid[current_node->point.x][current_node->point.y] = 0;

        // Get the neighbors of the current node
        Point neighbors[] = {
            {current_node->point.x - 1, current_node->point.y},
            {current_node->point.x + 1, current_node->point.y},
            {current_node->point.x, current_node->point.y - 1},
            {current_node->point.x, current_node->point.y + 1}
        };

        for (int i = 0; i < 4; i++) {
            // Check if the neighbor is within the bounds of the grid and is traversable
            if (neighbors[i].x >= 0 && neighbors[i].x < width && neighbors[i].y >= 0 && neighbors[i].y < height && grid[neighbors[i].x][neighbors[i].y] == 1) {
                // Calculate the g-score of the neighbor
                int g = current_node->g + 1;

                // Calculate the h-score of the neighbor
                int h = manhattan_distance(neighbors[i], end_node->point);

                // Create the neighbor node
                Node *neighbor = create_node(neighbors[i], current_node, g, h);

                // Push the neighbor node into the priority queue
                push_priority_queue(queue, neighbor);
            }
        }

        // Destroy the current node
        destroy_node(current_node);
    }

    // Destroy the priority queue and the nodes
    destroy_priority_queue(queue);
    destroy_node(start_node);
    destroy_node(end_node);
    for (int i = 0; i < height; i++) {
        free(grid[i]);
    }
    free(grid);

    printf("No path found.\n");

    return 1;
}