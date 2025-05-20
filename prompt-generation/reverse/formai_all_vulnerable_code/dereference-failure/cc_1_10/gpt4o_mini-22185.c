//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define GRID_WIDTH 10
#define GRID_HEIGHT 10
#define OBSTACLE -1
#define FREE 0
#define START 1
#define GOAL 2

typedef struct {
    int x;
    int y;
} Node;

typedef struct {
    Node *nodes;
    int size;
    int capacity;
} NodeList;

NodeList* createNodeList() {
    NodeList* list = malloc(sizeof(NodeList));
    list->size = 0;
    list->capacity = 10;
    list->nodes = malloc(sizeof(Node) * list->capacity);
    return list;
}

void addNode(NodeList *list, Node node) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->nodes = realloc(list->nodes, sizeof(Node) * list->capacity);
    }
    list->nodes[list->size++] = node;
}

bool contains(NodeList *list, Node node) {
    for (int i = 0; i < list->size; i++) {
        if (list->nodes[i].x == node.x && list->nodes[i].y == node.y) {
            return true;
        }
    }
    return false;
}

float heuristic(Node a, Node b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y);
}

int grid[GRID_HEIGHT][GRID_WIDTH] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, -1, -1, 0, -1, -1, -1, -1, -1, 0},
    {0, 0, 0, 0, 0, 0, 0, -1, 0, 0},
    {0, -1, -1, -1, -1, -1, 0, -1, 0, -1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, -1, -1, -1, -1, -1, -1, -1, -1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, -1, -1, -1, -1, -1, -1, 0, -1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, -1, -1, -1, 0, 0, 0, 0, 0}
};

Node start = {0, 0};
Node goal = {9, 9};

bool isValid(int x, int y) {
    return x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT && grid[y][x] != OBSTACLE;
}

void printPath(Node* path, int length) {
    printf("Path found:\n");
    for (int i = 0; i < length; i++) {
        printf("(%d, %d) ", path[i].x, path[i].y);
    }
    printf("\n");
}

void aStar(Node start, Node goal) {
    NodeList *openSet = createNodeList();
    bool closedSet[GRID_HEIGHT][GRID_WIDTH] = {false};
    float gScore[GRID_HEIGHT][GRID_WIDTH] = {0};
    float fScore[GRID_HEIGHT][GRID_WIDTH] = {0};

    addNode(openSet, start);
    fScore[start.y][start.x] = heuristic(start, goal);

    while (openSet->size > 0) {
        int minIndex = 0;
        for (int i = 1; i < openSet->size; i++) {
            if (fScore[openSet->nodes[i].y][openSet->nodes[i].x] < fScore[openSet->nodes[minIndex].y][openSet->nodes[minIndex].x]) {
                minIndex = i;
            }
        }
        
        Node current = openSet->nodes[minIndex];
        if (current.x == goal.x && current.y == goal.y) {
            Node path[GRID_WIDTH * GRID_HEIGHT]; // reserve maximum length for the path
            int length = 0;
            path[length++] = current; // point to the goal
            printPath(path, length);
            return;
        }
        
        openSet->nodes[minIndex] = openSet->nodes[--openSet->size];
        closedSet[current.y][current.x] = true;

        // Explore neighbors
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (fabs(dx) == fabs(dy)) continue; // skip diagonal neighbor

                int neighborX = current.x + dx;
                int neighborY = current.y + dy;

                if (!isValid(neighborX, neighborY) || closedSet[neighborY][neighborX]) {
                    continue;
                }
                
                Node neighbor = {neighborX, neighborY};
                float tentativeGScore = gScore[current.y][current.x] + 1;

                if (!contains(openSet, neighbor)) {
                    addNode(openSet, neighbor);
                } else if (tentativeGScore >= gScore[neighbor.y][neighbor.x]) {
                    continue; // This is not a better path
                }
                
                gScore[neighbor.y][neighbor.x] = tentativeGScore;
                fScore[neighbor.y][neighbor.x] = gScore[neighbor.y][neighbor.x] + heuristic(neighbor, goal);
            }
        }
    }
    
    printf("No path found!\n");
}

int main() {
    printf("Welcome to the A* Pathfinding Algorithm!\n");
    aStar(start, goal);
    return 0;
}