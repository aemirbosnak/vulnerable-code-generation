//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define ROW 15
#define COL 20

// Defining the node structure for the pathfinding algorithm
struct node {
    int row;
    int col;
    int f_cost; //total estimated cost of the path (g_cost + h_cost)
    int g_cost; //cost from start node to current node
    int h_cost; //estimated cost from current node to end node
    int is_obstacle; // is obstacle or not
    struct node* parent; //parent node
};

// Function to create a new node
struct node* create_node(int row, int col) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->row = row;
    new_node->col = col;
    new_node->f_cost = 0;
    new_node->g_cost = 0;
    new_node->h_cost = 0;
    new_node->is_obstacle = 0;
    new_node->parent = NULL;
    return new_node;
}

//Function to calculate Manhattan distance (heuristic) between two nodes
int manhattan_distance(struct node* node1, struct node* node2) {
    int distance = abs(node1->row - node2->row) + abs(node1->col - node2->col);
    return distance;
}

//Function to check whether the given coordinate is within the bounds of the grid
int is_within_bounds(int row, int col) {
    if (row < 0 || row >= ROW || col < 0 || col >= COL) {
        return 0;
    }
    return 1;
}

//Function to check whether the given node is an obstacle
int is_obstacle(struct node* node) {
    if (node->is_obstacle) {
        return 1;
    }
    return 0;
}

//Function to check whether the given node is the goal node
int is_goal_node(struct node* current_node, struct node* goal_node) {
    if (current_node->row == goal_node->row && current_node->col == goal_node->col) {
        return 1;
    }
    return 0;
}

//Function to get the neighbors of a given node
struct node** get_neighbors(struct node* current_node) {
    struct node** neighbors = (struct node**) malloc(sizeof(struct node*) * 4);
    int row = current_node->row;
    int col = current_node->col;
    int index = 0;
    int neighbor_row, neighbor_col;
    
    //up neighbor
    neighbor_row = row - 1;
    neighbor_col = col;
    if (is_within_bounds(neighbor_row, neighbor_col)) {
        neighbors[index] = create_node(neighbor_row, neighbor_col);
        neighbors[index]->is_obstacle = is_obstacle(neighbors[index]);
        index++;
    }
    
    //down neighbor
    neighbor_row = row + 1;
    neighbor_col = col;
    if (is_within_bounds(neighbor_row, neighbor_col)) {
        neighbors[index] = create_node(neighbor_row, neighbor_col);
        neighbors[index]->is_obstacle = is_obstacle(neighbors[index]);
        index++;
    }
    
    //left neighbor
    neighbor_row = row;
    neighbor_col = col - 1;
    if (is_within_bounds(neighbor_row, neighbor_col)) {
        neighbors[index] = create_node(neighbor_row, neighbor_col);
        neighbors[index]->is_obstacle = is_obstacle(neighbors[index]);
        index++;
    }
    
    //right neighbor
    neighbor_row = row;
    neighbor_col = col + 1;
    if (is_within_bounds(neighbor_row, neighbor_col)) {
        neighbors[index] = create_node(neighbor_row, neighbor_col);
        neighbors[index]->is_obstacle = is_obstacle(neighbors[index]);
        index++;
    }
    
    //add NULL as the last element to indicate the end of the array
    neighbors[index] = NULL;
    
    return neighbors;
}

//Function to print the grid
void print_grid(struct node* grid[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (grid[i][j]->is_obstacle) {
                printf("|  #  ");
            }
            else {
                printf("| (%d,%d) ", i, j);
            }
        }
        printf("|\n");
    }
}

//Function to destroy a node and free its memory
void destroy_node(struct node* node) {
    free(node);
}

//Main function
int main() {
    struct node* grid[ROW][COL]; //2d array to represent the grid
    struct node* start_node = create_node(2, 0); //start node
    struct node* goal_node = create_node(11, 19); //goal node
    struct node* current_node; //current node
    int is_found = 0; //flag to indicate whether the goal node is found or not
    
    //grid initialization
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            grid[i][j] = create_node(i, j);
            grid[i][j]->is_obstacle = rand() % 100 < 15 ? 1 : 0; //randomly assign obstacles to nodes
        }
    }
    grid[start_node->row][start_node->col] = start_node;
    grid[goal_node->row][goal_node->col] = goal_node;
    
    printf("Welcome to the pathfinding algorithm in a post-apocalyptic world!\n");
    printf("You are trying to find a safe place to live after a zombie apocalypse has destroyed the world.\n");
    printf("You are currently at (%d,%d) and trying to reach (%d,%d).\n", start_node->row, start_node->col, goal_node->row, goal_node->col);
    printf("The following grid shows your current location and the obstacles blocking your way:\n");
    print_grid(grid);
    
    //A* algorithm
    start_node->g_cost = 0;
    start_node->h_cost = manhattan_distance(start_node, goal_node);
    start_node->f_cost = start_node->g_cost + start_node->h_cost;
    current_node = start_node;
    while (!is_found) {
        //get all the neighbors of the current node
        struct node** neighbors = get_neighbors(current_node);
        int index = 0;
        
        //iterate through all the neighbors
        while (neighbors[index]) {
            struct node* neighbor = neighbors[index];
            
            //skip if the neighbor is an obstacle or has already been checked
            if (is_obstacle(neighbor) || neighbor == current_node->parent) {
                index++;
                continue;
            }
            
            //calculate the tentative g_cost and f_cost of the neighbor
            int tentative_g_cost = current_node->g_cost + 1;
            int tentative_f_cost = tentative_g_cost + manhattan_distance(neighbor, goal_node);
            
            //check if the neighbor is the goal node
            if (is_goal_node(neighbor, goal_node)) {
                neighbor->parent = current_node;
                is_found = 1;
                break;
            }
            
            //if the neighbor is not in the open list, add it to the open list
            if (neighbor->f_cost == 0) {
                neighbor->g_cost = tentative_g_cost;
                neighbor->h_cost = manhattan_distance(neighbor, goal_node);
                neighbor->f_cost = tentative_f_cost;
                neighbor->parent = current_node;
                index++;
                continue;
            }
            
            //if the neighbor is in the open list with a higher f_cost, update its f_cost
            if (neighbor->f_cost > tentative_f_cost) {
                neighbor->g_cost = tentative_g_cost;
                neighbor->f_cost = tentative_f_cost;
                neighbor->parent = current_node;
                index++;
                continue;
            }
            index++;
        }
        
        //if the goal node is found, print the path and exit
        if (is_found) {
            printf("Congratulations! You have found a safe place to live!\n");
            printf("The following grid shows your path from (%d,%d) to (%d,%d):\n", start_node->row, start_node->col, goal_node->row, goal_node->col);
            struct node* path[ROW * COL];
            int length = 0;
            struct node* node = goal_node;
            while (node != start_node) {
                path[length] = node;
                length++;
                node = node->parent;
            }
            path[length] = start_node;
            for (int i = length; i >= 0; i--) {
                printf("(%d,%d)\n", path[i]->row, path[i]->col);
            }
            break;
        }
        
        //if the open list is empty, exit
        if (neighbors[0] == NULL) {
            printf("Unfortunately, there is no way to get to a safe place.\n");
            break;
        }
        
        //get the node with the lowest f_cost from the open list
        struct node* lowest_f_cost_node = NULL;
        int lowest_f_cost = 1000000;
        index = 0;
        while (neighbors[index]) {
            struct node* neighbor = neighbors[index];
            if (!is_obstacle(neighbor) && neighbor->f_cost < lowest_f_cost && neighbor->f_cost > 0) {
                lowest_f_cost_node = neighbor;
                lowest_f_cost = lowest_f_cost_node->f_cost;
            }
            index++;
        }
        
        //update the current node
        if (lowest_f_cost_node != NULL) {
            current_node = lowest_f_cost_node;
        }
        
        free(neighbors);
    }
    
    //destroy all the nodes and free their memory
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            destroy_node(grid[i][j]);
        }
    }
    destroy_node(start_node);
    destroy_node(goal_node);
    
    return 0;
}