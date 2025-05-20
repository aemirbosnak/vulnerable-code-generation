//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define GRID_SIZE 10
#define OBSTACLE '*'
#define FREE '.'

// Node structure for A* algorithm
typedef struct Node {
    int x;
    int y;
    float g_cost; // Cost from start to this node
    float h_cost; // Heuristic cost to end
    float f_cost; // Total cost
    struct Node* parent;
} Node;

// Priority queue for open list
typedef struct {
    Node** nodes;
    int size;
    int capacity;
} PriorityQueue;

// Function prototypes
Node* create_node(int x, int y, Node* parent);
PriorityQueue* create_priority_queue(int capacity);
void push(PriorityQueue* pq, Node* node);
Node* pop(PriorityQueue* pq);
bool in_open_list(PriorityQueue* pq, Node* node);
float calculate_h(int x1, int y1, int x2, int y2);
bool is_valid(int x, int y, char grid[GRID_SIZE][GRID_SIZE]);
void a_star(char grid[GRID_SIZE][GRID_SIZE], int start_x, int start_y, int target_x, int target_y);
void print_path(Node* node);
void free_memory(PriorityQueue* pq);

int main() {
    char grid[GRID_SIZE][GRID_SIZE] = {
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '*', '*', '*', '.', '*', '*', '*', '*', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '*', '.', '.'},
        {'.', '*', '*', '*', '*', '*', '.', '*', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '*', '*', '*', '*', '*' ,'*', '*', '*', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '*', '*', '*', '*', '*', '.', '.', '.'},
    };

    int start_x = 0, start_y = 0;
    int target_x = 9, target_y = 9;

    a_star(grid, start_x, start_y, target_x, target_y);

    return 0;
}

// Create a new node
Node* create_node(int x, int y, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->g_cost = 0.0f;
    node->h_cost = 0.0f;
    node->f_cost = 0.0f;
    node->parent = parent;
    return node;
}

// Create a priority queue
PriorityQueue* create_priority_queue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    pq->capacity = capacity;
    pq->nodes = (Node**)malloc(capacity * sizeof(Node*));
    return pq;
}

// Push a node into the priority queue
void push(PriorityQueue* pq, Node* node) {
    int i = pq->size++;
    pq->nodes[i] = node;
    
    // Sort by f_cost
    while (i > 0 && pq->nodes[(i - 1) / 2]->f_cost > pq->nodes[i]->f_cost) {
        Node* temp = pq->nodes[i];
        pq->nodes[i] = pq->nodes[(i - 1) / 2];
        pq->nodes[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Pop the node with the lowest f_cost from the priority queue
Node* pop(PriorityQueue* pq) {
    if (pq->size == 0) return NULL;

    Node* top = pq->nodes[0];
    pq->nodes[0] = pq->nodes[--pq->size];

    // Re-heapify
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < pq->size && pq->nodes[left]->f_cost < pq->nodes[smallest]->f_cost) {
            smallest = left;
        }
        if (right < pq->size && pq->nodes[right]->f_cost < pq->nodes[smallest]->f_cost) {
            smallest = right;
        }
        if (smallest == i) break;

        Node* temp = pq->nodes[i];
        pq->nodes[i] = pq->nodes[smallest];
        pq->nodes[smallest] = temp;
        i = smallest;
    }
    return top;
}

// Check if the node is in the open list
bool in_open_list(PriorityQueue* pq, Node* node) {
    for (int i = 0; i < pq->size; i++) {
        if (pq->nodes[i]->x == node->x && pq->nodes[i]->y == node->y) {
            return true;
        }
    }
    return false;
}

// Calculate heuristic (Manhattan distance)
float calculate_h(int x1, int y1, int x2, int y2) {
    return fabsf(x1 - x2) + fabsf(y1 - y2);
}

// Check if a position is valid (within bounds and not an obstacle)
bool is_valid(int x, int y, char grid[GRID_SIZE][GRID_SIZE]) {
    return (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE && grid[x][y] != OBSTACLE);
}

// A* pathfinding algorithm
void a_star(char grid[GRID_SIZE][GRID_SIZE], int start_x, int start_y, int target_x, int target_y) {
    PriorityQueue* open_set = create_priority_queue(100);
    Node* start_node = create_node(start_x, start_y, NULL);
    start_node->h_cost = calculate_h(start_x, start_y, target_x, target_y);
    start_node->f_cost = start_node->h_cost;

    push(open_set, start_node);

    while (open_set->size > 0) {
        Node* current = pop(open_set);

        if (current->x == target_x && current->y == target_y) {
            print_path(current);
            free_memory(open_set);
            free(current);
            return;
        }

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // Down, Up, Right, Left
        for (int i = 0; i < 4; i++) {
            int new_x = current->x + directions[i][0];
            int new_y = current->y + directions[i][1];

            if (is_valid(new_x, new_y, grid)) {
                Node* neighbor = create_node(new_x, new_y, current);
                neighbor->g_cost = current->g_cost + 1; // Assume cost = 1
                neighbor->h_cost = calculate_h(new_x, new_y, target_x, target_y);
                neighbor->f_cost = neighbor->g_cost + neighbor->h_cost;

                if (!in_open_list(open_set, neighbor)) {
                    push(open_set, neighbor);
                } else {
                    free(neighbor);
                }
            }
        }
        free(current);
    }

    printf("No path found.\n");
    free_memory(open_set);
}

// Print the found path
void print_path(Node* node) {
    if (node == NULL) return;
    print_path(node->parent);
    printf("-> (%d, %d) ", node->x, node->y);
}

// Free memory
void free_memory(PriorityQueue* pq) {
    for (int i = 0; i < pq->size; i++) {
        free(pq->nodes[i]);
    }
    free(pq->nodes);
    free(pq);
}