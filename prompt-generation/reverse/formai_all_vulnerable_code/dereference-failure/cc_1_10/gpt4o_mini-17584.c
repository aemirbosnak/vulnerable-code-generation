//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define N 10 // Dimension of the grid
#define INF 99999 // A large number for initialization

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    int g; // Cost from start to the node
    int h; // Heuristic cost to the goal
    int f; // Total cost
} Node;

Node* createNode(int x, int y, int g, int h) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->point.x = x;
    node->point.y = y;
    node->g = g;
    node->h = h;
    node->f = g + h;
    return node;
}

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool isValid(int grid[N][N], int row, int col) {
    return (row >= 0 && row < N && col >= 0 && col < N && grid[row][col] == 0);
}

bool isGoal(Point point, Point goal) {
    return point.x == goal.x && point.y == goal.y;
}

void printPath(Point* path, int size) {
    for (int i = 0; i < size; i++) {
        printf("(%d, %d) ", path[i].x, path[i].y);
    }
    printf("\n");
}

void aStar(int grid[N][N], Point start, Point goal) {
    Node* openList[N * N];
    bool closedList[N][N] = {false};
    int openListSize = 0;
    
    openList[openListSize++] = createNode(start.x, start.y, 0, heuristic(start, goal));

    while (openListSize > 0) {
        Node* currentNode = openList[0];
        int currentIndex = 0;

        // Find node with the lowest f in openList
        for (int i = 1; i < openListSize; i++) {
            if (openList[i]->f < currentNode->f) {
                currentNode = openList[i];
                currentIndex = i;
            }
        }

        // Remove current node from openList
        for (int i = currentIndex; i < openListSize - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openListSize--;

        // Add current node to closedList
        closedList[currentNode->point.x][currentNode->point.y] = true;

        // If goal is reached
        if (isGoal(currentNode->point, goal)) {
            printf("Path found: ");
            printPath((Point[]){start, currentNode->point}, 2);
            return;
        }

        // Adjacent cells (4 directions)
        int rowMoves[] = {0, 0, 1, -1};
        int colMoves[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int newRow = currentNode->point.x + rowMoves[i];
            int newCol = currentNode->point.y + colMoves[i];
            Point neighbor = {newRow, newCol};

            if (isValid(grid, newRow, newCol) && !closedList[newRow][newCol]) {
                int gNew = currentNode->g + 1;
                int hNew = heuristic(neighbor, goal);

                bool inOpenList = false;
                for (int j = 0; j < openListSize; j++) {
                    if (openList[j]->point.x == newRow && openList[j]->point.y == newCol) {
                        inOpenList = true;
                        if (gNew < openList[j]->g) {
                            openList[j]->g = gNew;
                            openList[j]->h = hNew;
                            openList[j]->f = gNew + hNew;
                        }
                        break;
                    }
                }

                if (!inOpenList) {
                    openList[openListSize++] = createNode(newRow, newCol, gNew, hNew);
                }
            }
        }
    }

    printf("Path not found.\n");
}

int main() {
    int grid[N][N] = {
        {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 1, 1, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 1, 1, 1, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    Point start = {0, 0};
    Point goal = {9, 9};

    aStar(grid, start, goal);

    return 0;
}