//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define SIZE 10

// Struct for each node in the graph
typedef struct Node {
    int x, y;              // coordinates
    int g, h, f;           // pathfinding values
    bool is_wall;          // whether the node is a wall
    struct Node* parent;   // parent in the path
} Node;

// Function to calculate Manhattan distance between two nodes
int manhattan_distance(Node* node_a, Node* node_b) {
    return abs(node_a->x - node_b->x) + abs(node_a->y - node_b->y);
}

// Function to find the node with lowest f value in open list
Node* lowest_f_node(Node** open_list, int open_list_count) {
    int lowest_f = INT_MAX;
    Node* lowest_f_node = NULL;
    
    for (int i = 0; i < open_list_count; i++) {
        if (open_list[i]->f < lowest_f) {
            lowest_f = open_list[i]->f;
            lowest_f_node = open_list[i];
        }
    }
    
    return lowest_f_node;
}

// Function to check if a node is in a given list
bool node_in_list(Node** list, int list_count, Node* node) {
    for (int i = 0; i < list_count; i++) {
        if (list[i] == node) {
            return true;
        }
    }
    return false;
}

// Function to get a node's neighbors
Node** get_neighbors(Node** graph, Node* node, int* neighbor_count) {
    *neighbor_count = 0;
    int x = node->x;
    int y = node->y;
    
    // Allocate memory for array of neighboring nodes
    Node** neighbors = (Node**) malloc(sizeof(Node*) * 4);
    
    // Check if each neighbor is within bounds and not a wall
    if (x > 0 && !(graph[(x-1)*SIZE+y]->is_wall)) {
        neighbors[*neighbor_count] = graph[(x-1)*SIZE+y];
        (*neighbor_count)++;
    }
    if (x < SIZE-1 && !(graph[(x+1)*SIZE+y]->is_wall)) {
        neighbors[*neighbor_count] = graph[(x+1)*SIZE+y];
        (*neighbor_count)++;
    }
    if (y > 0 && !(graph[x*SIZE+(y-1)]->is_wall)) {
        neighbors[*neighbor_count] = graph[x*SIZE+(y-1)];
        (*neighbor_count)++;
    }
    if (y < SIZE-1 && !(graph[x*SIZE+(y+1)]->is_wall)) {
        neighbors[*neighbor_count] = graph[x*SIZE+(y+1)];
        (*neighbor_count)++;
    }

    return neighbors;
}

// Function to print the shortest path found
void print_path(Node* start, Node* current) {
    if (current == start) {
        printf("(%d,%d)", start->x, start->y);
        return;
    }
    print_path(start, current->parent);
    printf(" -> (%d,%d)", current->x, current->y);
}

// Function to find the shortest path using A* pathfinding algorithm
void a_star_pathfinding(Node** graph, Node* start, Node* end) {
    Node* open_list[SIZE*SIZE];
    int open_list_count = 0;
    Node* closed_list[SIZE*SIZE];
    int closed_list_count = 0;
    
    // Initialize A* values for start node
    start->g = 0;
    start->h = manhattan_distance(start, end);
    start->f = start->g + start->h;
    
    // Add start node to open list
    open_list[open_list_count] = start;
    open_list_count++;
    
    while (open_list_count > 0) {
        // Get node with lowest f value from open list
        Node* current = lowest_f_node(open_list, open_list_count);
        
        // End search if current node is the end node
        if (current == end) {
            printf("Shortest path: ");
            print_path(start, current);
            printf("\n");
            return;
        }
        
        // Move current node from open list to closed list
        for (int i = 0; i < open_list_count; i++) {
            if (open_list[i] == current) {
                for (int j = i; j < open_list_count-1; j++) {
                    open_list[j] = open_list[j+1];
                }
                open_list_count--;
                break;
            }
        }
        closed_list[closed_list_count] = current;
        closed_list_count++;
        
        // Get current node's neighbors
        int neighbor_count;
        Node** neighbors = get_neighbors(graph, current, &neighbor_count);
        
        // Check each neighbor
        for (int i = 0; i < neighbor_count; i++) {
            Node* neighbor = neighbors[i];
            
            // Skip neighbor if it is in the closed list
            if (node_in_list(closed_list, closed_list_count, neighbor)) {
                continue;
            }
            
            // Calculate new g value for neighbor
            int new_g = current->g + 1;
            
            // Add neighbor to open list if it is not already there
            if (!(node_in_list(open_list, open_list_count, neighbor))) {
                neighbor->g = new_g;
                neighbor->h = manhattan_distance(neighbor, end);
                neighbor->f = neighbor->g + neighbor->h;
                neighbor->parent = current;
                open_list[open_list_count] = neighbor;
                open_list_count++;
            }
            // Update neighbor's values if new g value is better
            else if (new_g < neighbor->g) {
                neighbor->g = new_g;
                neighbor->f = neighbor->g + neighbor->h;
                neighbor->parent = current;
            }
        }
        
        free(neighbors);   // free memory for neighbors array
    }
    
    printf("No path found.\n");
}

int main() {
    // Create 2D array of nodes representing the graph
    Node* graph[SIZE*SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            Node* node = (Node*) malloc(sizeof(Node));
            node->x = i;
            node->y = j;
            node->is_wall = false;
            node->parent = NULL;
            graph[i*SIZE+j] = node;
        }
    }
    
    // Set some nodes as walls
    graph[2*SIZE+2]->is_wall = true;
    graph[3*SIZE+2]->is_wall = true;
    graph[4*SIZE+2]->is_wall = true;
    graph[5*SIZE+2]->is_wall = true;
    graph[6*SIZE+2]->is_wall = true;
    
    // Run A* pathfinding algorithm
    Node* start = graph[1*SIZE+1];
    Node* end = graph[8*SIZE+8];
    a_star_pathfinding(graph, start, end);
    
    // Free memory for graph nodes
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            free(graph[i*SIZE+j]);
        }
    }
    
    return 0;
}