//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

int map[ROWS][COLS] = {    //Initialize the map
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,1,0,1,1,0,1},
    {1,0,1,0,1,0,0,0,0,0},
    {1,0,1,0,1,1,1,1,1,1},
    {1,0,1,0,0,0,0,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,0,0,0,1,0,1,0,0,1},
    {1,0,1,0,1,0,1,0,1,1},
    {1,1,1,1,1,1,1,1,1,1},
};

typedef struct Node {   //Create a struct to represent each node on the map
    int x;
    int y;
    int g;
    int h;
    int f;
    struct Node* parent;
} Node;

Node* createNode(int x, int y, int g, int h, Node* parent){  //Function to create a node
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->g = g;
    node->h = h;
    node->f = g + h;
    node->parent = parent;
    return node;
}

bool inBounds(int x, int y){    //Check if a node is within the map bounds
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

bool isBlocked(int x, int y){   //Check if a node is blocked (has a value of 1 on the map)
    return map[x][y] == 1;
}

bool isGoal(int x, int y, Node* end){   //Check if a node is the goal node
    return (x == end->x && y == end->y);
}

int heuristic(int x, int y, Node* end){ //Calculate the heuristic (euclidean distance) between two nodes
    return ((x - end->x) * (x - end->x)) + ((y - end->y) * (y - end->y));
}

Node* findLowestF(Node** nodes, int size){    //Find the node with the lowest f value
    Node* lowest = nodes[0];
    for (int i = 1; i < size; i++){
        if (nodes[i]->f < lowest->f){
            lowest = nodes[i];
        }
    }
    return lowest;
}

bool containsNode(Node** nodes, int size, int x, int y){   //Check if a node is in a given array of nodes
    for (int i = 0; i < size; i++){
        if (nodes[i]->x == x && nodes[i]->y == y){
            return true;
        }
    }
    return false;
}

void printPath(Node* node){  //Print out the path from the start to the end node
    if (node->parent != NULL){
        printPath(node->parent);
    }
    printf("(%d,%d) ", node->x, node->y);
}

void findPath(Node* start, Node* end){ //Function to find the optimal path from start to end node
    Node* openSet[ROWS * COLS];
    Node* closedSet[ROWS * COLS];
    int openSize = 0;
    int closedSize = 0;
    openSet[openSize++] = start;
    while (openSize > 0){
        Node* current = findLowestF(openSet, openSize);
        if (isGoal(current->x, current->y, end)){
            printPath(current);
            return;
        }
        for (int dx = -1; dx <= 1; dx++){
            for (int dy = -1; dy <= 1; dy++){
                if (dx == 0 && dy == 0){
                    continue;
                }
                int nextX = current->x + dx;
                int nextY = current->y + dy;
                if (inBounds(nextX, nextY) && !isBlocked(nextX, nextY)){
                    int nextG = current->g + 1;
                    int nextH = heuristic(nextX, nextY, end);
                    int nextF = nextG + nextH;
                    Node* nextNode = createNode(nextX, nextY, nextG, nextH, current);
                    if (containsNode(closedSet, closedSize, nextX, nextY) &&
                        nextF >= nextNode->f){
                        continue;
                    }
                    if (!containsNode(openSet, openSize, nextX, nextY) ||
                        nextF < nextNode->f){
                        openSet[openSize++] = nextNode;
                    }
                }
            }
        }
        closedSet[closedSize++] = current;
        for (int i = 0; i < openSize; i++){    //Remove the current node from the openSet
            if (openSet[i]->x == current->x && openSet[i]->y == current->y){
                openSet[i] = openSet[--openSize];
                break;
            }
        }
    }
}

int main(){
    Node* start = createNode(1, 1, 0, 0, NULL);
    Node* end = createNode(8, 8, 0, 0, NULL);
    findPath(start, end);
    return 0;
}