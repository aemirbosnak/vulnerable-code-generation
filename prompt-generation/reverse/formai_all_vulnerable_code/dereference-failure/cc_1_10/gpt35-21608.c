//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: scientific
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define ROW 10
#define COLUMN 10

// Define a structure to store the nodes
typedef struct node {
    int x, y;
    double g, h, f;
    struct node* parent;
} node;

// Define a structure to store the open and closed lists
typedef struct list {
    int length;
    node** items;
} list;

// Create a list of nodes
node** createNodeList() {
    node** result = malloc(sizeof(node*) * ROW * COLUMN);
    return result;
}

// Create a list
list* createList() {
    list* result = malloc(sizeof(list));
    result->length = 0;
    result->items = malloc(sizeof(node*) * ROW * COLUMN);
    return result;
}

// Calculate the Manhattan distance between two nodes
double calculateDistance(node* node1, node* node2) {
    double result = abs(node1->x - node2->x) + abs(node1->y - node2->y);
    return result;
}

// Check if a node is in the open or closed list
bool isInList(list* list, node* node) {
    for (int i = 0; i < list->length; i++) {
        if (list->items[i]->x == node->x && list->items[i]->y == node->y) {
            return true;
        }
    }
    return false;
}

// Add a node to a list
void addToList(list* list, node* node) {
    list->items[list->length] = node;
    list->length++;
}

// Remove a node from a list
void removeFromList(list* list, int index) {
    for (int i = index; i < list->length - 1; i++) {
        list->items[i] = list->items[i + 1];
    }
    list->length--;
}

// Find the node with the lowest f value in a list
node* findLowestFValue(list* list) {
    node* result = list->items[0];
    for (int i = 1; i < list->length; i++) {
        if (list->items[i]->f < result->f) {
            result = list->items[i];
        }
    }
    return result;
}

// Check if a node is valid
bool isNodeValid(int maze[ROW][COLUMN], int x, int y) {
    if (x >= 0 && x < ROW && y >= 0 && y < COLUMN) {
        if (maze[x][y] == 0) {
            return true;
        }
    }
    return false;
}

// Find a path using the A* algorithm
node* findPath(int maze[ROW][COLUMN], int startX, int startY, int endX, int endY) {
    // Create the open and closed lists
    list* openList = createList();
    list* closedList = createList();

    // Create the starting node
    node* startNode = malloc(sizeof(node));
    startNode->x = startX;
    startNode->y = startY;
    startNode->g = 0;
    startNode->h = calculateDistance(startNode, (node*) &(node) { endX, endY });
    startNode->f = startNode->g + startNode->h;
    startNode->parent = NULL;

    // Add the starting node to the open list
    addToList(openList, startNode);

    // Loop until the end node is found or there are no more nodes in the open list
    while (openList->length > 0) {
        // Find the node with the lowest f value in the open list
        node* currentNode = findLowestFValue(openList);

        // If this node is the end node, return it
        if (currentNode->x == endX && currentNode->y == endY) {
            return currentNode;
        }

        // Move the current node from the open list to the closed list
        removeFromList(openList, 0);
        addToList(closedList, currentNode);

        // Loop through the eight neighboring nodes of the current node
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                // Skip the current node and diagonals
                if (i == 0 && j == 0) continue;
                if (i != 0 && j != 0) continue;

                // Calculate the coordinates of the neighboring node
                int neighborX = currentNode->x + i;
                int neighborY = currentNode->y + j;

                // If the node is not valid or is in the closed list, skip it
                if (!isNodeValid(maze, neighborX, neighborY)) continue;
                if (isInList(closedList, &(node) { neighborX, neighborY })) continue;

                // Calculate the g value of the neighboring node
                double newG = currentNode->g + calculateDistance(currentNode, &(node) { neighborX, neighborY });

                // If the neighboring node is not in the open list, add it
                node* neighborNode = &(node) { neighborX, neighborY };
                if (!isInList(openList, neighborNode)) {
                    neighborNode = malloc(sizeof(node));
                    neighborNode->x = neighborX;
                    neighborNode->y = neighborY;
                    neighborNode->parent = currentNode;
                    neighborNode->g = newG;
                    neighborNode->h = calculateDistance(neighborNode, &(node) { endX, endY });
                    neighborNode->f = neighborNode->g + neighborNode->h;
                    addToList(openList, neighborNode);
                }
                // If the neighboring node is already in the open list, check if this path is better
                else {
                    for (int k = 0; k < openList->length; k++) {
                        if (openList->items[k]->x == neighborX && openList->items[k]->y == neighborY) {
                            if (newG < openList->items[k]->g) {
                                openList->items[k]->parent = currentNode;
                                openList->items[k]->g = newG;
                                openList->items[k]->f = openList->items[k]->g + openList->items[k]->h;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    // Define the maze as a two-dimensional array of integers
    int maze[ROW][COLUMN] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0, 0, 1, 1, 0 },
        { 0, 1, 0, 0, 0, 0, 0, 0, 1, 0 },
        { 0, 1, 0, 0, 0, 0, 0, 0, 1, 0 },
        { 0, 1, 0, 0, 1, 1, 1, 1, 1, 0 },
        { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };

    // Define the start and end coordinates of the maze
    int startX = 1;
    int startY = 1;
    int endX = 8;
    int endY = 8;

    // Find the path using the A* algorithm
    node* path = findPath(maze, startX, startY, endX, endY);

    // Print the path
    printf("Path found:\n");
    while (path != NULL) {
        printf("(%d, %d)\n", path->x, path->y);
        path = path->parent;
    }

    return 0;
}