//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLUMNS 10

// Nodes in the pathfinding graph
typedef struct _Node {
    int row;
    int col;
    bool visited;
    bool wall;
    int gcost; // Distance from start
    int hcost; // Distance from end
    struct _Node* parent;
} Node;

// Priority queue for storing open nodes
typedef struct _Pqueue {
    int count;
    Node* heap[ROWS*COLUMNS];
} Pqueue;

// Initializes a new node
Node* create_node(int row, int col, bool wall) {
    Node* node = malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->visited = false;
    node->wall = wall;
    node->gcost = 0;
    node->hcost = 0;
    node->parent = NULL;
    return node;
}

// Calculates the heuristic value for a node based on Manhattan distance
int calculate_hcost(Node* node, Node* end) {
    return abs(node->row - end->row) + abs(node->col - end->col);
}

// Initializes a new priority queue
Pqueue* create_pqueue() {
    Pqueue* pqueue = malloc(sizeof(Pqueue));
    pqueue->count = 0;
    return pqueue;
}

// Adds a node to the priority queue
void add_to_pqueue(Pqueue* pqueue, Node* node) {
    int i = pqueue->count; // Position of the last element in the heap
    pqueue->count++;

    // Add the node to the end of the heap
    while (i > 0 && pqueue->heap[(i-1)/2]->gcost + pqueue->heap[(i-1)/2]->hcost > node->gcost + node->hcost) {
        pqueue->heap[i] = pqueue->heap[(i-1)/2];
        i = (i-1)/2;
    }
    pqueue->heap[i] = node;
}

// Removes the node with the lowest fcost from the priority queue
Node* remove_from_pqueue(Pqueue* pqueue) {
    Node* node = pqueue->heap[0];
    pqueue->count--;
    int i = 0; // Position of the first element in the heap

    // Move the last element to the root position and restore heap order
    while (2*i+1 < pqueue->count) {
        int child = 2*i+1;
        if (child+1 < pqueue->count && pqueue->heap[child+1]->gcost + pqueue->heap[child+1]->hcost < pqueue->heap[child]->gcost + pqueue->heap[child]->hcost) {
            child++;
        }
        if (pqueue->heap[child]->gcost + pqueue->heap[child]->hcost >= node->gcost + node->hcost) {
            break;
        }
        pqueue->heap[i] = pqueue->heap[child];
        i = child;
    }
    pqueue->heap[i] = pqueue->heap[pqueue->count];
    return node;
}

// Finds the optimal path from start to end using the A* algorithm
void find_optimal_path(Node* start, Node* end) {
    Pqueue* open = create_pqueue();
    Node* closed[ROWS*COLUMNS] = {0};

    start->hcost = calculate_hcost(start, end);
    add_to_pqueue(open, start);

    while (open->count > 0) {
        Node* current = remove_from_pqueue(open);

        if (current == end) {
            // End node reached, print the path and exit
            while (current != start) {
                printf("(%d,%d) ", current->row, current->col);
                current = current->parent;
            }
            printf("(%d,%d)\n", start->row, start->col);
            return;
        } 

        current->visited = true;
        closed[current->row*COLUMNS+current->col] = current;

        // Check neighbors
        for (int r = -1; r <= 1; r++) {
            for (int c = -1; c <= 1; c++) {
                if ((r == 0 && c == 0) || current->row + r < 0 || current->row + r >= ROWS || current->col + c < 0 || current->col + c >= COLUMNS) {
                    continue;
                }
                Node* neighbor = &closed[(current->row + r)*COLUMNS + (current->col + c)];
                if (neighbor->visited || neighbor->wall) {
                    continue;
                }
                int tentative_gcost = current->gcost + abs(r) + abs(c);
                if (tentative_gcost < neighbor->gcost || neighbor->parent == NULL) {
                    neighbor->parent = current;
                    neighbor->gcost = tentative_gcost;
                    neighbor->hcost = calculate_hcost(neighbor, end);
                    if (!neighbor->visited) {
                        add_to_pqueue(open, neighbor);
                    }
                }
            }
        }
    }

    // Path not found
    printf("No path found from (%d,%d) to (%d,%d)\n", start->row, start->col, end->row, end->col);
}

// Initializes the pathfinding graph
void initialize_graph(Node graph[ROWS][COLUMNS]) {
    srand(1234);
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLUMNS; col++) {
            graph[row][col] = *create_node(row, col, rand() % 4 == 0); // 25% chance of wall
        }
    }
}

int main(int argc, char** argv) {
    // Initialize the pathfinding graph
    Node graph[ROWS][COLUMNS];
    initialize_graph(graph);

    // Start and end nodes
    Node* start = &graph[0][0];
    Node* end = &graph[ROWS-1][COLUMNS-1];

    // Find optimal path
    find_optimal_path(start, end);

    return 0;
}