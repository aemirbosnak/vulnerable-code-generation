//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define OBSTACLE '#'
#define PATH '.'
#define START 'S'
#define END 'E'
#define EMPTY ' '

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    int gCost;
    int hCost;
    int fCost;
} Node;

Node* createNode(int x, int y, int gCost, int hCost) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->point.x = x;
    node->point.y = y;
    node->gCost = gCost;
    node->hCost = hCost;
    node->fCost = gCost + hCost;
    return node;
}

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool isValid(Point point, char grid[HEIGHT][WIDTH]) {
    return (point.x >= 0 && point.x < WIDTH && point.y >= 0 && point.y < HEIGHT && grid[point.y][point.x] != OBSTACLE);
}

void printGrid(char grid[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void aStar(char grid[HEIGHT][WIDTH], Point start, Point end) {
    Node* openList[WIDTH * HEIGHT];
    int openListSize = 0;
    Node* closedList[WIDTH * HEIGHT];
    int closedListSize = 0;

    openList[openListSize++] = createNode(start.x, start.y, 0, heuristic(start, end));

    while (openListSize > 0) {
        // Find the node with the lowest fCost
        int currentIndex = 0;
        for (int i = 1; i < openListSize; i++) {
            if (openList[i]->fCost < openList[currentIndex]->fCost) {
                currentIndex = i;
            }
        }

        Node* currentNode = openList[currentIndex];

        if (currentNode->point.x == end.x && currentNode->point.y == end.y) {
            // Path found!
            printf("Path found:\n");
            grid[currentNode->point.y][currentNode->point.x] = END;
            printGrid(grid);
            free(currentNode);
            return;
        }

        // Remove currentNode from openList
        for (int i = currentIndex; i < openListSize - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openListSize--;

        // Add currentNode to closedList
        closedList[closedListSize++] = currentNode;

        // Generate neighbors
        Point neighbors[4] = {
            {currentNode->point.x + 1, currentNode->point.y}, // right
            {currentNode->point.x - 1, currentNode->point.y}, // left
            {currentNode->point.x, currentNode->point.y + 1}, // down
            {currentNode->point.x, currentNode->point.y - 1}  // up
        };

        for (int i = 0; i < 4; i++) {
            Point neighbor = neighbors[i];
            if (isValid(neighbor, grid)) {
                // Check if neighbor is in closed list
                bool inClosedList = false;
                for (int j = 0; j < closedListSize; j++) {
                    if (closedList[j]->point.x == neighbor.x && closedList[j]->point.y == neighbor.y) {
                        inClosedList = true;
                        break;
                    }
                }
                if (inClosedList) continue;

                int gCost = currentNode->gCost + 1;
                bool inOpenList = false;

                for (int j = 0; j < openListSize; j++) {
                    if (openList[j]->point.x == neighbor.x && openList[j]->point.y == neighbor.y) {
                        inOpenList = true;
                        if (gCost < openList[j]->gCost) {
                            openList[j]->gCost = gCost;
                            openList[j]->fCost = gCost + openList[j]->hCost;
                        }
                        break;
                    }
                }
                if (!inOpenList) {
                    openList[openListSize++] = createNode(neighbor.x, neighbor.y, gCost, heuristic(neighbor, end));
                }
            }
        }
    }

    printf("No path found.\n");
}

int main() {
    char grid[HEIGHT][WIDTH] = {
        {EMPTY, EMPTY, OBSTACLE, EMPTY, EMPTY, EMPTY, EMPTY, OBSTACLE, EMPTY, EMPTY},
        {EMPTY, OBSTACLE, OBSTACLE, EMPTY, OBSTACLE, OBSTACLE, EMPTY, OBSTACLE, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {OBSTACLE, EMPTY, OBSTACLE, OBSTACLE, OBSTACLE, EMPTY, OBSTACLE, EMPTY, OBSTACLE, OBSTACLE},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, EMPTY, OBSTACLE, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, OBSTACLE, OBSTACLE},
        {EMPTY, OBSTACLE, OBSTACLE, EMPTY, OBSTACLE, OBSTACLE, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, OBSTACLE, EMPTY, OBSTACLE, END, EMPTY},
        {START, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, OBSTACLE, EMPTY, EMPTY}
    };

    Point start = {0, 9}; // Start position 'S'
    Point end = {8, 8};   // End position 'E'

    grid[start.y][start.x] = START;
    aStar(grid, start, end);
    
    return 0;
}