//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 100

// Data structure to represent a node in the graph
struct node {
    int x, y; // coordinates of the node in the grid
    int g, h, f; // variables used by A* algorithm
    int neighbors[MAX_NODES]; // list of neighboring nodes
    int num_neighbors; // number of neighboring nodes
};

// Heuristic function to calculate estimated distance between two nodes
int heuristic(struct node* node1, struct node* node2) {
    return abs(node1->x - node2->x) + abs(node1->y - node2->y);
}

// Function to find the node with the lowest f score in a list of nodes
struct node* lowest_f_score(struct node** list, int num_nodes) {
    struct node* lowest = list[0];
    for (int i = 1; i < num_nodes; i++) {
        if (list[i]->f < lowest->f) {
            lowest = list[i];
        }
    }
    return lowest;
}

// Function to find the shortest path between two nodes using A* algorithm
void generate_path(struct node* start, struct node* goal) {
    // open and closed lists used by A* algorithm
    struct node* open[MAX_NODES] = { NULL };
    struct node* closed[MAX_NODES] = { NULL };
    int num_open = 0;
    int num_closed = 0;
    
    // set initial g, h, and f scores for start node
    start->g = 0;
    start->h = heuristic(start, goal);
    start->f = start->g + start->h;
    open[num_open++] = start;
    
    while (num_open > 0) {
        // find the node with the lowest f score and remove it from the open list
        struct node* current = lowest_f_score(open, num_open);
        for (int i = 0; i < num_open; i++) {
            if (open[i] == current) {
                open[i] = open[num_open-1];
                num_open--;
                break;
            }
        }
        
        // add the current node to the closed list
        closed[num_closed++] = current;
        
        // check if we have reached the goal node
        if (current == goal) {
            // construct path by following parent pointers from goal node to start node
            printf("Path found!\n");
            struct node* path[MAX_NODES] = { NULL };
            int num_nodes_path = 0;
            path[num_nodes_path++] = current;
            while (current != start) {
                current = current->neighbors[current->num_neighbors-1];
                path[num_nodes_path++] = current;
            }
            printf("Total nodes in path: %d\n", num_nodes_path);
            printf("Path: ");
            for (int i = num_nodes_path-1; i >= 0; i--) {
                printf("(%d, %d) ", path[i]->x, path[i]->y);
            }
            printf("\n");
            return;
        }
        
        // loop through neighboring nodes and update their f, g, and h scores if necessary
        for (int i = 0; i < current->num_neighbors; i++) {
            struct node* neighbor = &(current->neighbors[i]);
            
            // check if neighbor is already in the closed list
            int in_closed = 0;
            for (int j = 0; j < num_closed; j++) {
                if (closed[j] == neighbor) {
                    in_closed = 1;
                    break;
                }
            }
            
            if (!in_closed) {
                // calculate tentative g score for neighbor
                int tentative_g = current->g + 1;
                
                // check if neighbor is already in open list
                int in_open = 0;
                int node_index = 0;
                for (int j = 0; j < num_open; j++) {
                    if (open[j] == neighbor) {
                        in_open = 1;
                        node_index = j;
                        break;
                    }
                }
                
                if (!in_open) {
                    // add neighbor to open list and calculate its f, g, and h scores
                    neighbor->g = tentative_g;
                    neighbor->h = heuristic(neighbor, goal);
                    neighbor->f = neighbor->g + neighbor->h;
                    neighbor->neighbors[neighbor->num_neighbors++] = current;
                    open[num_open++] = neighbor;
                } else {
                    // update neighbor's g score and f score if it has a better path from current node
                    if (tentative_g < neighbor->g) {
                        neighbor->g = tentative_g;
                        neighbor->f = neighbor->g + neighbor->h;
                        neighbor->neighbors[neighbor->num_neighbors++] = current;
                        open[node_index] = neighbor;
                    }
                }
            }
        }
    }
    
    // no path found
    printf("No path found.\n");
}

int main() {
    // create example graph of nodes
    struct node nodes[MAX_NODES];
    nodes[0].x = 0;
    nodes[0].y = 0;
    nodes[0].num_neighbors = 2;
    nodes[0].neighbors[0] = &nodes[1];
    nodes[0].neighbors[1] = &nodes[3];
    nodes[1].x = 1;
    nodes[1].y = 0;
    nodes[1].num_neighbors = 3;
    nodes[1].neighbors[0] = &nodes[0];
    nodes[1].neighbors[1] = &nodes[2];
    nodes[1].neighbors[2] = &nodes[4];
    nodes[2].x = 2;
    nodes[2].y = 0;
    nodes[2].num_neighbors = 2;
    nodes[2].neighbors[0] = &nodes[1];
    nodes[2].neighbors[1] = &nodes[5];
    nodes[3].x = 0;
    nodes[3].y = 1;
    nodes[3].num_neighbors = 2;
    nodes[3].neighbors[0] = &nodes[0];
    nodes[3].neighbors[1] = &nodes[4];
    nodes[4].x = 1;
    nodes[4].y = 1;
    nodes[4].num_neighbors = 4;
    nodes[4].neighbors[0] = &nodes[1];
    nodes[4].neighbors[1] = &nodes[3];
    nodes[4].neighbors[2] = &nodes[5];
    nodes[4].neighbors[3] = &nodes[7];
    nodes[5].x = 2;
    nodes[5].y = 1;
    nodes[5].num_neighbors = 3;
    nodes[5].neighbors[0] = &nodes[2];
    nodes[5].neighbors[1] = &nodes[4];
    nodes[5].neighbors[2] = &nodes[8];
    nodes[6].x = 0;
    nodes[6].y = 2;
    nodes[6].num_neighbors = 2;
    nodes[6].neighbors[0] = &nodes[3];
    nodes[6].neighbors[1] = &nodes[7];
    nodes[7].x = 1;
    nodes[7].y = 2;
    nodes[7].num_neighbors = 4;
    nodes[7].neighbors[0] = &nodes[4];
    nodes[7].neighbors[1] = &nodes[6];
    nodes[7].neighbors[2] = &nodes[8];
    nodes[7].neighbors[3] = &nodes[9];
    nodes[8].x = 2;
    nodes[8].y = 2;
    nodes[8].num_neighbors = 3;
    nodes[8].neighbors[0] = &nodes[5];
    nodes[8].neighbors[1] = &nodes[7];
    nodes[8].neighbors[2] = &nodes[9];
    nodes[9].x = 3;
    nodes[9].y = 2;
    nodes[9].num_neighbors = 2;
    nodes[9].neighbors[0] = &nodes[7];
    nodes[9].neighbors[1] = &nodes[8];
    
    // find path from node 0 to node 9 using A* algorithm
    struct node* start = &nodes[0];
    struct node* goal = &nodes[9];
    generate_path(start, goal);
    
    return 0;
}