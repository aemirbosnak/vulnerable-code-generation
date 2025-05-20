//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 9
#define COLS 9

// Create the maze as a 2-dimensional array
int maze[ROWS][COLS] = {
    {1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,1},
    {1,1,1,0,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1},
};

bool visited[ROWS][COLS]; // Create a 2-dimensional array to keep track of which cells have been visited

// Define a struct to represent a coordinate (x,y)
typedef struct {
    int row;
    int col;
} coord;

// Define a struct to represent a node in the linked list we will use to keep track of the path through the maze
typedef struct node {
    coord pos;
    struct node *next;
} node;

// Create a function to initialize the linked list with a starting position
node* init_list(coord pos) {
    node *head = malloc(sizeof(node));
    head->pos = pos;
    head->next = NULL;
    return head;
}

// Create a function to add a new node to the end of the linked list
void add_node(node *head, coord pos) {
    node *new_node = malloc(sizeof(node));
    new_node->pos = pos;
    new_node->next = NULL;
    
    node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Create a function to print out the path through the maze
void print_path(node *head) {
    printf("The path through the maze is:\n");
    node *current = head;
    while (current != NULL) {
        printf("(%d,%d) ", current->pos.row, current->pos.col);
        current = current->next;
    }
    printf("\n");
}

// Create a recursive function to find a path through the maze
bool find_path(int row, int col, node *head) {
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS || maze[row][col] == 1 || visited[row][col]) {
        return false; // If we are out of bounds, hit a wall, or have already visited this cell, return false
    }
    
    visited[row][col] = true; // Mark this cell as visited
    
    if (row == ROWS-1 && col == COLS-1) {
        // If we have reached the end of the maze, print the path and return true
        add_node(head, (coord) {row,col});
        print_path(head);
        return true;
    }
    
    // Try going up, down, left, and right
    if (find_path(row-1, col, head) || find_path(row, col+1, head) ||
        find_path(row+1, col, head) || find_path(row, col-1, head)) {
        // If we find a path in any of these directions, add this cell to the linked list and return true
        add_node(head, (coord) {row,col});
        return true;
    }
    
    return false; // If we couldn't find a path in any direction, return false
}

int main() {
    node *head = init_list((coord) {0,0});
    
    if (!find_path(0, 0, head)) {
        printf("Sorry, there is no path through the maze.\n");
    }
    
    return 0;
}