//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// define the row and column size of the grid
#define ROW 10
#define COL 10

// define the max heap size
#define HEAP_SIZE 100

// define the struct for a node
typedef struct Node {
    int row, col;
    int gcost, fcost;
    struct Node* parent;
} Node;

// define the struct for a heap
typedef struct Heap {
    Node* nodes[HEAP_SIZE];
    int count;
} Heap;

// define the 2D array to represent the grid
int grid[ROW][COL] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

// define the start and goal coordinates
int start_row = 1;
int start_col = 1;
int goal_row = 8;
int goal_col = 8;

// define the function to calculate the heuristics
int heuristic(Node* current) {
    int dx = abs(current->row - goal_row);
    int dy = abs(current->col - goal_col);
    int distance = abs(dx - dy) * 10;
    return distance;
}

// define the function to generate a new node
Node* new_node(int row, int col, int gcost, int fcost, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->gcost = gcost;
    node->fcost = fcost;
    node->parent = parent;
    return node;
}

// define the function to check if a node is in the open/closed list
int in_list(Node* current, Node** list, int count) {
    for (int i = 0; i < count; i++) {
        if (current->row == list[i]->row && current->col == list[i]->col) {
            return 1;
        }
    }
    return 0;
}

// define the function to swap nodes in the heap
void swap_nodes(Node** nodes, int i, int j) {
    Node* temp = nodes[i];
    nodes[i] = nodes[j];
    nodes[j] = temp;
}

// define the function to push a node into the heap
void push(Heap* heap, Node* node) {
    int index = heap->count;
    heap->nodes[index] = node;
    while (index >= 1) {
        int parent_index = (index - 1) / 2;
        if (heap->nodes[parent_index]->fcost > heap->nodes[index]->fcost) {
            swap_nodes(heap->nodes, index, parent_index);
            index = parent_index;
        } else {
            break;
        }
    }
    heap->count++;
}

// define the function to pop the top node from the heap
Node* pop(Heap* heap) {
    int index = 0;
    Node* node = heap->nodes[index];
    heap->count--;
    heap->nodes[index] = heap->nodes[heap->count];
    while (index * 2 + 1 < heap->count) {
        int child1_index = index * 2 + 1;
        int child2_index = index * 2 + 2;
        int min_index = index;
        if (heap->nodes[min_index]->fcost > heap->nodes[child1_index]->fcost) {
            min_index = child1_index;
        }
        if (child2_index < heap->count && heap->nodes[min_index]->fcost > heap->nodes[child2_index]->fcost) {
            min_index = child2_index;
        }
        if (min_index != index) {
            swap_nodes(heap->nodes, index, min_index);
            index = min_index;
        } else {
            break;
        }
    }
    return node;
}

// define the function to print the path from start to goal
void print_path(Node* current) {
    while (current != NULL) {
        grid[current->row][current->col] = 2;
        current = current->parent;
    }
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// define the main function
int main() {
    // initialize the open/closed lists and the heap
    Node* open_list[HEAP_SIZE];
    int open_count = 0;
    Node* closed_list[HEAP_SIZE];
    int closed_count = 0;
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->count = 0;

    // push the start node into the heap
    Node* start_node = new_node(start_row, start_col, 0, 0, NULL);
    start_node->fcost = heuristic(start_node);
    push(heap, start_node);

    // loop through the heap until it is empty
    while (heap->count > 0) {
        // pop the top node from the heap
        Node* current = pop(heap);

        // check if the current node is the goal node
        if (current->row == goal_row && current->col == goal_col) {
            print_path(current);
            break;
        }

        // add the current node to the closed list
        closed_list[closed_count++] = current;

        // generate the adjacent nodes
        int row, col;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                row = current->row + i;
                col = current->col + j;
                if (row < 0 || row >= ROW || col < 0 || col >= COL) {
                    continue;
                }
                if (grid[row][col] == 1) {
                    continue;
                }
                int gcost = current->gcost + ((i == 0 || j == 0) ? 10 : 14);
                Node* node = new_node(row, col, gcost, 0, current);
                node->fcost = gcost + heuristic(node);
                if (in_list(node, open_list, open_count) || in_list(node, closed_list, closed_count)) {
                    continue;
                }
                push(heap, node);
                open_list[open_count++] = node;
            }
        }
    }

    // free the heap memory
    free(heap);

    return 0;
}