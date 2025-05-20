//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define OBSTACLE '#'
#define FREE ' '
#define START 'S'
#define END 'E'

typedef struct {
    int x;
    int y;
} Point;

typedef struct Node {
    Point point;
    int g; // Cost from start to current node
    int h; // Heuristic cost to end node
    int f; // Total cost (g + h)
    struct Node* parent;
} Node;

Node* createNode(int x, int y, Node* parent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->point.x = x;
    newNode->point.y = y;
    newNode->g = 0;
    newNode->h = 0;
    newNode->f = 0;
    newNode->parent = parent;
    return newNode;
}

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool isValid(int x, int y, char grid[HEIGHT][WIDTH]) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && grid[y][x] != OBSTACLE);
}

void reconstructPath(Node* target) {
    Node* current = target;
    while (current) {
        printf("(%d, %d) ", current->point.x, current->point.y);
        current = current->parent;
    }
    printf("\n");
}

void AStar(char grid[HEIGHT][WIDTH], Point start, Point end) {
    Node* openList[WIDTH * HEIGHT];
    int openCount = 0;
    bool closedList[HEIGHT][WIDTH] = {false};

    Node* startNode = createNode(start.x, start.y, NULL);
    startNode->g = 0;
    startNode->h = heuristic(start, end);
    startNode->f = startNode->g + startNode->h;
    openList[openCount++] = startNode;

    while (openCount > 0) {
        // Find the node with the lowest f in openList
        int lowestIndex = 0;
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->f < openList[lowestIndex]->f) {
                lowestIndex = i;
            }
        }

        Node* currentNode = openList[lowestIndex];

        // Check if we reached the end
        if (currentNode->point.x == end.x && currentNode->point.y == end.y) {
            printf("Path found: ");
            reconstructPath(currentNode);
            return;
        }

        // Remove currentNode from openList
        openList[lowestIndex] = openList[--openCount];
        closedList[currentNode->point.y][currentNode->point.x] = true;

        // Explore neighbors
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        for (int i = 0; i < 4; i++) {
            int newX = currentNode->point.x + dx[i];
            int newY = currentNode->point.y + dy[i];

            if (!isValid(newX, newY, grid) || closedList[newY][newX]) {
                continue;
            }

            Node* neighbor = createNode(newX, newY, currentNode);
            neighbor->g = currentNode->g + 1;
            neighbor->h = heuristic(neighbor->point, end);
            neighbor->f = neighbor->g + neighbor->h;

            // Check if neighbor is already in openList
            bool skip = false;
            for (int j = 0; j < openCount; j++) {
                if (openList[j]->point.x == neighbor->point.x && openList[j]->point.y == neighbor->point.y && openList[j]->f <= neighbor->f) {
                    skip = true;
                    break;
                }
            }

            if (!skip) {
                openList[openCount++] = neighbor;
            } else {
                free(neighbor);
            }
        }
    }

    printf("No path found!\n");
}

int main() {
    char grid[HEIGHT][WIDTH] = {
        {'S', ' ', ' ', '#', ' ', 'E', ' ', ' ', '#', ' '},
        {' ', '#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' '},
        {' ', '#', ' ', ' ', ' ', '#', '#', '#', ' ', ' '},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' '},
        {'#', '#', '#', '#', ' ', '#', '#', '#', '#', '#'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', '#', '#', '#', ' ', ' ', '#', ' '},
        {' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    Point start = {0, 0}; // Starting Point
    Point end = {5, 0};   // Ending Point

    AStar(grid, start, end);
  
    return 0;
}