//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Struct to represent a node in the maze
typedef struct Node {
    int value;
    int visited;
    struct Node* north;
    struct Node* south;
    struct Node* east;
    struct Node* west;
    int x;
    int y;
} Node;

// Function to create a new node
Node* createNode(int value, int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->visited = 0;
    node->north = NULL;
    node->south = NULL;
    node->east = NULL;
    node->west = NULL;
    node->x = x;
    node->y = y;
    return node;
}

// Function to allocate memory for a maze
Node*** createMaze(int rows, int cols) {
    Node*** maze = (Node***)malloc(rows * sizeof(Node**));
    for (int i = 0; i < rows; i++) {
        maze[i] = (Node**)malloc(cols * sizeof(Node*));
        for (int j = 0; j < cols; j++) {
            maze[i][j] = createNode(0, i, j);
        }
    }
    return maze;
}

// Function to print the maze
void printMaze(Node*** maze, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", maze[i][j]->value);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to link adjacent nodes in the maze
void linkNodes(Node*** maze, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i > 0) {
                maze[i][j]->north = maze[i - 1][j];
            }
            if (i < rows - 1) {
                maze[i][j]->south = maze[i + 1][j];
            }
            if (j > 0) {
                maze[i][j]->west = maze[i][j - 1];
            }
            if (j < cols - 1) {
                maze[i][j]->east = maze[i][j + 1];
            }
        }
    }
}

// Function to generate a random maze
void generateMaze(Node*** maze, int rows, int cols) {
    Node* current = maze[0][0];
    current->visited = 1;
    while (1) {
        current->value = 1; // Set current node as path
        Node** neighbors = (Node**)malloc(4 * sizeof(Node*));
        int num_neighbors = 0;
        if (current->north && !current->north->visited) {
            neighbors[num_neighbors++] = current->north;
        }
        if (current->south && !current->south->visited) {
            neighbors[num_neighbors++] = current->south;
        }
        if (current->west && !current->west->visited) {
            neighbors[num_neighbors++] = current->west;
        }
        if (current->east && !current->east->visited) {
            neighbors[num_neighbors++] = current->east;
        }
        if (num_neighbors > 0) {
            Node* next = neighbors[rand() % num_neighbors];
            if (next == current->north) {
                current->north = NULL;
                next->south = NULL;
            }
            else if (next == current->south) {
                current->south = NULL;
                next->north = NULL;
            }
            else if (next == current->west) {
                current->west = NULL;
                next->east = NULL;
            }
            else if (next == current->east) {
                current->east = NULL;
                next->west = NULL;
            }
            current = next;
            current->visited = 1;
        } 
        else {
            break;
        }
    }
}

// Function to find the shortest path between two nodes using BFS
int shortestPath(Node*** maze, int rows, int cols, int start_x, int start_y, int end_x, int end_y) {
    Node* start = maze[start_x][start_y];
    Node* end = maze[end_x][end_y];
    start->value = 2; // Set start node as start
    end->value = 3; // Set end node as end
    int path_found = 0;
    Node** queue = (Node**)malloc(rows * cols * sizeof(Node*));
    int front = 0;
    int back = 0;
    queue[back++] = start;
    while (front < back) {
        Node* current = queue[front++];
        if (current == end) {
            path_found = 1;
            break;
        }
        if (current->north && current->north->value == 0) {
            queue[back++] = current->north;
            current->north->value = current->value + 1;
        }
        if (current->south && current->south->value == 0) {
            queue[back++] = current->south;
            current->south->value = current->value + 1;
        }
        if (current->west && current->west->value == 0) {
            queue[back++] = current->west;
            current->west->value = current->value + 1;
        }
        if (current->east && current->east->value == 0) {
            queue[back++] = current->east;
            current->east->value = current->value + 1;
        }
    }
    if (!path_found) {
        return -1; // Path not found
    }
    int path_length = maze[end_x][end_y]->value - 2;
    Node* current = maze[end_x][end_y];
    while (current != start) {
        if (current->north && current->north->value == current->value-1) {
            current->north->value = 2;
            current = current->north;
        }
        else if (current->south && current->south->value == current->value-1) {
            current->south->value = 2;
            current = current->south;
        }
        else if (current->west && current->west->value == current->value-1) {
            current->west->value = 2;
            current = current->west;
        }
        else if (current->east && current->east->value == current->value-1) {
            current->east->value = 2;
            current = current->east;
        }
    }
    return path_length;
}

// Main function
int main() {
    int rows = 10;
    int cols = 10;
    Node*** maze = createMaze(rows, cols);
    linkNodes(maze, rows, cols);
    generateMaze(maze, rows, cols);
    printf("Maze:\n");
    printMaze(maze, rows, cols);
    int shortest_path = shortestPath(maze, rows, cols, 0, 0, rows-1, cols-1);
    if (shortest_path == -1) {
        printf("No path found\n");
    }
    else {
        printf("Shortest path length: %d\n", shortest_path);
        printf("Shortest path:\n");
        printMaze(maze, rows, cols);
    }
    return 0;
}