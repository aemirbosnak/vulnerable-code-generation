//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Node structure
typedef struct Node {
    int x, y;
    struct Node *parent;
    double g, h, f;
} Node;

// Heap structure for open set
typedef struct Heap {
    int size;
    Node **nodes;
} Heap;

// Create a new node
Node *create_node(int x, int y, Node *parent) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->parent = parent;
    node->g = 0;
    node->h = 0;
    node->f = 0;
    return node;
}

// Create a new heap
Heap *create_heap() {
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->size = 0;
    heap->nodes = (Node **)malloc(sizeof(Node *) * 100);
    return heap;
}

// Insert a node into the heap
void insert_heap(Heap *heap, Node *node) {
    heap->nodes[heap->size] = node;
    heap->size++;
    int i = heap->size - 1;
    while (i > 0 && heap->nodes[i]->f < heap->nodes[(i - 1) / 2]->f) {
        Node *temp = heap->nodes[i];
        heap->nodes[i] = heap->nodes[(i - 1) / 2];
        heap->nodes[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Extract the minimum node from the heap
Node *extract_min_heap(Heap *heap) {
    Node *min = heap->nodes[0];
    heap->nodes[0] = heap->nodes[heap->size - 1];
    heap->size--;
    int i = 0;
    while (i < heap->size / 2) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < heap->size && heap->nodes[left]->f < heap->nodes[smallest]->f) {
            smallest = left;
        }
        if (right < heap->size && heap->nodes[right]->f < heap->nodes[smallest]->f) {
            smallest = right;
        }
        if (smallest != i) {
            Node *temp = heap->nodes[i];
            heap->nodes[i] = heap->nodes[smallest];
            heap->nodes[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
    }
    return min;
}

// Calculate the heuristic cost
double heuristic_cost(Node *node, Node *goal) {
    return sqrt(pow(node->x - goal->x, 2) + pow(node->y - goal->y, 2));
}

// Calculate the path
void calculate_path(Node *node) {
    while (node != NULL) {
        printf("(%d, %d)\n", node->x, node->y);
        node = node->parent;
    }
}

// A* pathfinding algorithm
Node *a_star_pathfinding(Node *start, Node *goal, int **grid, int width, int height) {
    // Initialize the open and closed sets
    Heap *open_set = create_heap();
    Node **closed_set = (Node **)malloc(sizeof(Node *) * width * height);
    for (int i = 0; i < width * height; i++) {
        closed_set[i] = NULL;
    }

    // Add the start node to the open set
    insert_heap(open_set, start);

    // While the open set is not empty
    while (open_set->size > 0) {
        // Extract the node with the lowest f cost from the open set
        Node *current = extract_min_heap(open_set);

        // If the current node is the goal node, return the path
        if (current->x == goal->x && current->y == goal->y) {
            return current;
        }

        // Add the current node to the closed set
        closed_set[current->x + current->y * width] = current;

        // For each neighbor of the current node
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                // If the neighbor is not the current node
                if (i == 0 && j == 0) {
                    continue;
                }

                // If the neighbor is not in the closed set
                if (closed_set[current->x + i + (current->y + j) * width] == NULL) {
                    // Create a new node for the neighbor
                    Node *neighbor = create_node(current->x + i, current->y + j, current);

                    // Calculate the cost of the neighbor
                    neighbor->g = current->g + 1;
                    neighbor->h = heuristic_cost(neighbor, goal);
                    neighbor->f = neighbor->g + neighbor->h;

                    // If the neighbor is not in the open set or if the new cost is lower than the old cost
                    if (open_set->size == 0 || neighbor->f < open_set->nodes[0]->f) {
                        // Add the neighbor to the open set
                        insert_heap(open_set, neighbor);
                    }
                }
            }
        }
    }

    // Return NULL if no path found
    return NULL;
}

// Main function
int main() {
    // Create the grid
    int **grid = (int **)malloc(sizeof(int *) * 10);
    for (int i = 0; i < 10; i++) {
        grid[i] = (int *)malloc(sizeof(int) * 10);
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j] = 0;
        }
    }

    // Set the start and goal nodes
    Node *start = create_node(0, 0, NULL);
    Node *goal = create_node(9, 9, NULL);

    // Run the A* pathfinding algorithm
    Node *path = a_star_pathfinding(start, goal, grid, 10, 10);

    // Print the path
    calculate_path(path);

    // Free the memory
    free(grid);
    free(start);
    free(goal);

    return 0;
}