//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point parent;
    Point current;
    int f; // f = g + h
    int g; // distance from start
    int h; // heuristic distance to goal
} Node;

int heuristic(Point p1, Point p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

bool isValid(Point p) {
    return p.x >= 0 && p.x < ROWS && p.y >= 0 && p.y < COLS;
}

bool isObstacle(Point p, int** matrix) {
    return matrix[p.x][p.y] == 1;
}

void printPath(Point** path, int length) {
    printf("Path: ");
    for (int i = 0; i < length; i++) {
        printf("(%d, %d) ", path[i]->x, path[i]->y);
    }
    printf("\n");
}

void reconstructPath(Node** cameFrom, Point* start, Point* goal) {
    Point** path = (Point**) malloc(sizeof(Point*) * ROWS * COLS);
    int length = 0;
    Point current = *goal;

    while (current.x != start->x || current.y != start->y) {
        path[length++] = (Point*) malloc(sizeof(Point));
        *path[length - 1] = current;
        current = cameFrom[current.x * COLS + current.y]->parent;
    }

    path[length++] = (Point*) malloc(sizeof(Point));
    *path[length - 1] = *start;
    printPath(path, length);
}

void aStar(int** matrix, Point start, Point goal) {
    bool visited[ROWS * COLS];
    for (int i = 0; i < ROWS * COLS; i++) {
        visited[i] = false;
    }

    Node* nodes[ROWS * COLS];
    for (int i = 0; i < ROWS * COLS; i++) {
        nodes[i] = (Node*) malloc(sizeof(Node));
        nodes[i]->current.x = i / COLS;
        nodes[i]->current.y = i % COLS;
    }

    nodes[start.x * COLS + start.y]->g = 0;
    nodes[start.x * COLS + start.y]->h = heuristic(start, goal);
    nodes[start.x * COLS + start.y]->f = nodes[start.x * COLS + start.y]->h;

    bool foundPath = false;

    while (!foundPath) {
        int minF = ROWS * COLS;
        int currentX;
        int currentY;

        for (int i = 0; i < ROWS * COLS; i++) {
            if (nodes[i]->f < minF && !visited[i]) {
                minF = nodes[i]->f;
                currentX = nodes[i]->current.x;
                currentY = nodes[i]->current.y;
            }
        }

        visited[currentX * COLS + currentY] = true;

        if (currentX == goal.x && currentY == goal.y) {
            foundPath = true;
            reconstructPath(nodes, &start, &goal);
            continue;
        }

        Point neighbors[4] = {
            {currentX - 1, currentY}, // top
            {currentX, currentY + 1}, // right
            {currentX + 1, currentY}, // bottom
            {currentX, currentY - 1}  // left
        };

        for (int i = 0; i < 4; i++) {
            if (isValid(neighbors[i]) && !isObstacle(neighbors[i], matrix)) {
                int neighborIdx = neighbors[i].x * COLS + neighbors[i].y;
                int tentativeG = nodes[currentX * COLS + currentY]->g + 1;
                
                if (tentativeG < nodes[neighborIdx]->g) {
                    nodes[neighborIdx]->parent = (Point) {currentX, currentY};
                    nodes[neighborIdx]->g = tentativeG;
                    nodes[neighborIdx]->h = heuristic(neighbors[i], goal);
                    nodes[neighborIdx]->f = tentativeG + nodes[neighborIdx]->h;
                }
            }
        }
    }

}

int main() {
    // create a 2D matrix for obstacles (1 = obstacle, 0 = free space)
    int** matrix = (int**) malloc(sizeof(int*) * ROWS);
    for (int i = 0; i < ROWS; i++) {
        matrix[i] = (int*) malloc(sizeof(int) * COLS);
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = 0;
        }
    }
    matrix[2][1] = 1;
    matrix[2][2] = 1;
    matrix[2][3] = 1;
    matrix[4][5] = 1;
    matrix[5][5] = 1;
    matrix[5][4] = 1;

    Point start = {0, 0};
    Point goal = {ROWS - 1, COLS - 1};

    aStar(matrix, start, goal);

    return 0;
}