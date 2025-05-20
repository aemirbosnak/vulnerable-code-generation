//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int x, y;
    struct Node* parent;
    int f, g, h;
    bool wall;
} Node;

Node** createMap(int width, int height) {
    Node** map = (Node**)malloc(sizeof(Node*) * width);

    for (int i = 0; i < width; i++) {
        map[i] = (Node*)malloc(sizeof(Node) * height);
    }

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            map[x][y].x = x;
            map[x][y].y = y;
            map[x][y].parent = NULL;
            map[x][y].wall = false;
        }
    }

    return map;
}

void destroyMap(Node** map, int width) {
    for (int i = 0; i < width; i++) {
        free(map[i]);
    }

    free(map);
}

bool isValid(int x, int y, Node** map, int width, int height) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return false;
    }

    return !map[x][y].wall;
}

int manhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void calculateHeuristic(Node** map, int width, int height, int endX, int endY) {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            map[x][y].h = manhattanDistance(x, y, endX, endY);
        }
    }
}

void setWall(Node** map, int x, int y) {
    map[x][y].wall = true;
}

void unsetWall(Node** map, int x, int y) {
    map[x][y].wall = false;
}

void printMap(Node** map, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (map[x][y].wall) {
                printf("#");
            } else if (map[x][y].parent) {
                printf("+");
            } else {
                printf(".");
            }
        }

        printf("\n");
    }
}

void printPath(Node* node) {
    if (node->parent) {
        printPath(node->parent);
    }

    printf("(%i, %i) ", node->x, node->y);
}

Node* aStar(Node** map, int startX, int startY, int endX, int endY, int width, int height) {
    Node* openList[width * height];
    int openListSize = 1;

    Node* startNode = &map[startX][startY];
    Node* endNode = &map[endX][endY];

    startNode->g = 0;
    startNode->f = startNode->g + startNode->h;

    openList[0] = startNode;
    startNode->wall = false;

    while (openListSize > 0) {
        Node* currentNode = openList[0];
        if (currentNode == endNode) {
            return endNode;
        }

        openListSize--;
        for (int i = 0; i < openListSize; i++) {
            openList[i] = openList[i + 1];
        }

        int neighbours[8][2] = {
            { -1, -1 }, { 0, -1 }, { 1, -1 },
            { -1, 0 }, /* x, y */ { 1, 0 },
            { -1, 1 }, { 0, 1 }, { 1, 1 }
        };

        for (int i = 0; i < 8; i++) {
            int neighbourX = currentNode->x + neighbours[i][0];
            int neighbourY = currentNode->y + neighbours[i][1];

            if (!isValid(neighbourX, neighbourY, map, width, height)) {
                continue;
            }

            int neighbourG = currentNode->g + 1;
            Node* neighbourNode = &map[neighbourX][neighbourY];
            if (neighbourG < neighbourNode->g) {
                neighbourNode->parent = currentNode;
                neighbourNode->g = neighbourG;
                neighbourNode->f = neighbourNode->g + neighbourNode->h;

                bool inOpenList = false;
                for (int i = 0; i < openListSize; i++) {
                    if (openList[i] == neighbourNode) {
                        inOpenList = true;
                        break;
                    }
                }

                if (!inOpenList) {
                    openList[openListSize] = neighbourNode;
                    openListSize++;
                }
            }
        }
    }

    return NULL;
}

int main(int argc, char* argv[]) {
    Node** map = createMap(10, 10);

    setWall(map, 3, 3);
    setWall(map, 3, 4);
    setWall(map, 3, 5);

    calculateHeuristic(map, 10, 10, 8, 8);

    Node* path = aStar(map, 2, 2, 8, 8, 10, 10);
    printPath(path);

    destroyMap(map, 10);
    return 0;
}