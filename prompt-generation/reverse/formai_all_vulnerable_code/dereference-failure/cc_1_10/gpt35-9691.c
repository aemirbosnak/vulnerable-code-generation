//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct node {
    int x; // X-coordinate of the node
    int y; // Y-coordinate of the node
    int cost; // Cost to reach this node from starting node
    int heuristic; // Estimated cost from this node to goal node
    struct node *parent; // Pointer to parent node for tracing path
};

// Define a structure for the priority queue
struct priority_queue {
    int size; // Size of the queue
    struct node **elements; // Array of pointers to nodes
};

// Function to create a new node
struct node *create_node(int x, int y, int cost, int heuristic, struct node *parent) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->x = x;
    new_node->y = y;
    new_node->cost = cost;
    new_node->heuristic = heuristic;
    new_node->parent = parent;
    return new_node;
}

// Function to create the priority queue
struct priority_queue *create_priority_queue(int size) {
    struct priority_queue *new_queue = malloc(sizeof(struct priority_queue));
    new_queue->size = 0;
    new_queue->elements = malloc(sizeof(struct node *) * size);
    return new_queue;
}

// Function to destroy the priority queue
void destroy_priority_queue(struct priority_queue *pq) {
    free(pq->elements);
    free(pq);
}

// Function to insert a node into the priority queue
void enqueue(struct priority_queue *pq, struct node *new_node) {
    int i, j;
    for (i = 0; i < pq->size; i++) {
        if (new_node->cost + new_node->heuristic < pq->elements[i]->cost + pq->elements[i]->heuristic) {
            break;
        }
    }
    for (j = pq->size - 1; j >= i; j--) {
        pq->elements[j + 1] = pq->elements[j];
    }
    pq->elements[i] = new_node;
    pq->size++;
}

// Function to remove and return the node with lowest cost from the queue
struct node *dequeue(struct priority_queue *pq) {
    struct node *node = pq->elements[0];
    pq->size--;
    for (int i = 0; i < pq->size; i++) {
        pq->elements[i] = pq->elements[i + 1];
    }
    return node;
}

// Function to check if a node has already been visited
int visited(struct node *node, struct node **visited_nodes, int size) {
    for (int i = 0; i < size; i++) {
        if (node->x == visited_nodes[i]->x && node->y == visited_nodes[i]->y) {
            return 1;
        }
    }
    return 0;
}

// Function to calculate the Manhattan distance heuristic for a node
int manhattan_distance(struct node *node, struct node *goal_node) {
    return abs(goal_node->x - node->x) + abs(goal_node->y - node->y);
}

// Function to find the shortest path using A* algorithm
struct node **a_star(int **grid, int width, int height, int start_x, int start_y, int goal_x, int goal_y) {
    struct node *start_node = create_node(start_x, start_y, 0, 0, NULL);
    struct node *goal_node = create_node(goal_x, goal_y, 0, 0, NULL);
    struct priority_queue *pq = create_priority_queue(width * height);
    struct node **visited_nodes = malloc(sizeof(struct node *) * width * height);
    int visited_size = 0;
    enqueue(pq, start_node);
    while (pq->size > 0) {
        struct node *current_node = dequeue(pq);
        if (current_node->x == goal_x && current_node->y == goal_y) {
            struct node **path = malloc(sizeof(struct node *) * width * height);
            int path_size = 0;
            while (current_node != NULL) {
                path[path_size++] = current_node;
                current_node = current_node->parent;
            }
            destroy_priority_queue(pq);
            free(visited_nodes);
            return path;
        }
        int x = current_node->x;
        int y = current_node->y;
        int cost = current_node->cost + 1;
        // Check neighboring nodes
        if (x > 0 && grid[y][x - 1] == 0) {
            struct node *left_node = create_node(x - 1, y, cost, manhattan_distance(current_node, goal_node), current_node);
            if (!visited(left_node, visited_nodes, visited_size)) {
                enqueue(pq, left_node);
                visited_nodes[visited_size++] = left_node;
            } else {
                free(left_node);
            }
        }
        if (x < width - 1 && grid[y][x + 1] == 0) {
            struct node *right_node = create_node(x + 1, y, cost, manhattan_distance(current_node, goal_node), current_node);
            if (!visited(right_node, visited_nodes, visited_size)) {
                enqueue(pq, right_node);
                visited_nodes[visited_size++] = right_node;
            } else {
                free(right_node);
            }
        }
        if (y > 0 && grid[y - 1][x] == 0) {
            struct node *top_node = create_node(x, y - 1, cost, manhattan_distance(current_node, goal_node), current_node);
            if (!visited(top_node, visited_nodes, visited_size)) {
                enqueue(pq, top_node);
                visited_nodes[visited_size++] = top_node;
            } else {
                free(top_node);
            }
        }
        if (y < height - 1 && grid[y + 1][x] == 0) {
            struct node *bottom_node = create_node(x, y + 1, cost, manhattan_distance(current_node, goal_node), current_node);
            if (!visited(bottom_node, visited_nodes, visited_size)) {
                enqueue(pq, bottom_node);
                visited_nodes[visited_size++] = bottom_node;
            } else {
                free(bottom_node);
            }
        }
    }
    // No path found
    destroy_priority_queue(pq);
    free(visited_nodes);
    return NULL;
}

// Function to print the grid and path
void print_grid(int **grid, int width, int height, struct node **path, int path_size) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (grid[y][x] == 1) {
                printf("# ");
            } else if (path != NULL) {
                int in_path = 0;
                for (int i = 0; i < path_size; i++) {
                    if (path[i]->x == x && path[i]->y == y) {
                        in_path = 1;
                        break;
                    }
                }
                if (in_path) {
                    printf("* ");
                } else {
                    printf(". ");
                }
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Define a grid with obstacles (1) and open spaces (0)
    int width = 10;
    int height = 10;
    int **grid = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        grid[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1 || (i == 4 && j > 2 && j < 7) || (i == 8 && j > 1 && j < 8)) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
    // Print the grid with obstacles
    printf("Grid with obstacles:\n");
    print_grid(grid, width, height, NULL, 0);
    // Find the shortest path using A* algorithm
    int start_x = 1;
    int start_y = 1;
    int goal_x = 8;
    int goal_y = 8;
    struct node **path = a_star(grid, width, height, start_x, start_y, goal_x, goal_y);
    int path_size = 0;
    while (path[path_size] != NULL) {
        path_size++;
    }
    // Print the grid with the shortest path
    printf("Grid with shortest path:\n");
    print_grid(grid, width, height, path, path_size);
    // Free memory
    for (int i = 0; i < height; i++) {
        free(grid[i]);
    }
    free(grid);
    for (int i = 0; i < path_size; i++) {
        free(path[i]);
    }
    free(path);
    return 0;
}