//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

// Define the Node struct
struct Node {
    int x;
    int y;
    int g_cost;
    int h_cost;
    int f_cost;
    struct Node* parent;
};

// Define the Map array
int Map[MAP_WIDTH][MAP_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Define the heuristic function
int heuristic(int current_x, int current_y, int target_x, int target_y) {
    int dx = abs(target_x - current_x);
    int dy = abs(target_y - current_y);
    return (dx + dy);
}

// Define the find_node function
struct Node* find_node(struct Node* list[], int x, int y) {
    for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++) {
        if (list[i] == NULL) {
            return NULL;
        }
        if (list[i]->x == x && list[i]->y == y) {
            return list[i];
        }
    }
    return NULL;
}

// Define the get_neighbors function
void get_neighbors(struct Node* current_node, struct Node* neighbors[]) {
    int x = current_node->x;
    int y = current_node->y;
    int index = 0;

    if (x > 0 && Map[x - 1][y] == 0) {
        neighbors[index] = find_node(neighbors, x - 1, y);
        if (neighbors[index] == NULL) {
            neighbors[index] = (struct Node*) malloc(sizeof(struct Node));
            neighbors[index]->x = x - 1;
            neighbors[index]->y = y;
            neighbors[index]->parent = current_node;
            index++;
        }
    }

    // Add the rest of the neighbors here...
}

// Define the main function
int main() {
    // Create the start and end nodes
    struct Node* start_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* end_node = (struct Node*) malloc(sizeof(struct Node));

    start_node->x = 1;
    start_node->y = 1;
    end_node->x = 8;
    end_node->y = 8;

    // Create the open and closed lists
    struct Node* open_list[MAP_WIDTH * MAP_HEIGHT];
    struct Node* closed_list[MAP_WIDTH * MAP_HEIGHT];

    for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++) {
        open_list[i] = NULL;
        closed_list[i] = NULL;
    }

    int open_list_count = 0;
    int closed_list_count = 0;

    // Add the start node to the open list
    open_list[0] = start_node;
    open_list_count++;

    while (open_list_count > 0) {
        // Find the node with the lowest F cost in the open list
        int current_index = 0;
        for (int i = 0; i < open_list_count; i++) {
            if (open_list[i]->f_cost < open_list[current_index]->f_cost) {
                current_index = i;
            }
        }

        // Set the current node to the node with the lowest F cost
        struct Node* current_node = open_list[current_index];

        // If the current node is the end node, we are done
        if (current_node->x == end_node->x && current_node->y == end_node->y) {
            printf("Path found!");
            break;
        }

        // Remove the current node from the open list and add it to the closed list
        open_list[current_index] = NULL;
        open_list_count--;
        closed_list[closed_list_count] = current_node;
        closed_list_count++;

        // Get the neighbors of the current node
        struct Node* neighbors[8];
        get_neighbors(current_node, neighbors);

        for (int i = 0; i < 8; i++) {
            if (neighbors[i] == NULL) {
                continue;
            }

            // If the neighbor is in the closed list, skip it
            bool found = false;
            for (int j = 0; j < closed_list_count; j++) {
                if (closed_list[j]->x == neighbors[i]->x && closed_list[j]->y == neighbors[i]->y) {
                    found = true;
                    break;
                }
            }
            if (found) {
                continue;
            }

            // Calculate the G cost of the neighbor
            int g_cost = current_node->g_cost + 1;

            // If the neighbor is not in the open list, add it
            bool is_new = false;
            if (find_node(open_list, neighbors[i]->x, neighbors[i]->y) == NULL) {
                neighbors[i]->g_cost = g_cost;
                neighbors[i]->h_cost = heuristic(neighbors[i]->x, neighbors[i]->y, end_node->x, end_node->y);
                neighbors[i]->f_cost = neighbors[i]->g_cost + neighbors[i]->h_cost;
                neighbors[i]->parent = current_node;
                open_list[open_list_count] = neighbors[i];
                open_list_count++;
                is_new = true;
            }

            // If the neighbor is in the open list and the new G cost is lower, update it
            else if (g_cost < neighbors[i]->g_cost) {
                neighbors[i]->g_cost = g_cost;
                neighbors[i]->f_cost = neighbors[i]->g_cost + neighbors[i]->h_cost;
                neighbors[i]->parent = current_node;
            }

            // Print out some debug information
            printf("Neighbor: (%d, %d), F-cost: %d, Parent: (%d, %d), New: %d\n", 
                   neighbors[i]->x, neighbors[i]->y, neighbors[i]->f_cost, 
                   neighbors[i]->parent->x, neighbors[i]->parent->y, is_new);
        }
    }

    // TODO: Print out the path
}