//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point position;
    int g;  // Movement cost from start to current node
    int h;  // Heuristic cost from current node to target
    int f;  // Total cost (g + h)
    struct Node* parent;  // Pointer to the previous node
} Node;

Node* openSet[WIDTH * HEIGHT];
Node* closedSet[WIDTH * HEIGHT];
int openSetSize = 0;
int closedSetSize = 0;

int grid[HEIGHT][WIDTH] = {
    {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 1, 1, 1, 0, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

Node* createNode(Point position, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->position = position;
    node->parent = parent;
    node->g = parent ? parent->g + 1 : 0;  // +1 for each move
    node->h = heuristic(position, (Point){WIDTH - 1, HEIGHT - 1});
    node->f = node->g + node->h;
    return node;
}

bool pointInSet(Point p, Node** set, int size) {
    for (int i = 0; i < size; i++) {
        if (set[i] && set[i]->position.x == p.x && set[i]->position.y == p.y) {
            return true;
        }
    }
    return false;
}

void addToOpenSet(Node* node) {
    openSet[openSetSize++] = node;
}

void addToClosedSet(Node* node) {
    closedSet[closedSetSize++] = node;
}

Node* lowestFCostNode() {
    Node* lowest = NULL;
    for (int i = 0; i < openSetSize; i++) {
        if (openSet[i]) {
            if (!lowest || openSet[i]->f < lowest->f) {
                lowest = openSet[i];
            }
        }
    }
    return lowest;
}

bool isValid(Point p) {
    return (p.x >= 0 && p.x < WIDTH && p.y >= 0 && p.y < HEIGHT && grid[p.y][p.x] == 0);
}

void reconstructPath(Node* node) {
    while (node) {
        printf("(%d, %d) ", node->position.x, node->position.y);
        node = node->parent;
    }
    printf("\n");
}

void aStar(Point start) {
    Node* startNode = createNode(start, NULL);
    addToOpenSet(startNode);

    while (openSetSize > 0) {
        Node* current = lowestFCostNode();
        if (current->position.x == WIDTH - 1 && current->position.y == HEIGHT - 1) {
            printf("Path found: ");
            reconstructPath(current);
            return;
        }

        // Move current node to closed set
        addToClosedSet(current);
        for (int i = 0; i < openSetSize; i++) {
            if (openSet[i] == current) {
                for (int j = i; j < openSetSize - 1; j++) {
                    openSet[j] = openSet[j + 1];
                }
                openSetSize--;
                break;
            }
        }

        // Explore neighbors
        Point neighbors[4] = {
            {current->position.x + 1, current->position.y},
            {current->position.x - 1, current->position.y},
            {current->position.x, current->position.y + 1},
            {current->position.x, current->position.y - 1}
        };

        for (int i = 0; i < 4; i++) {
            Point neighbor = neighbors[i];

            if (isValid(neighbor) && !pointInSet(neighbor, closedSet, closedSetSize)) {
                Node* neighborNode = createNode(neighbor, current);

                if (pointInSet(neighbor, openSet, openSetSize)) {
                    for (int j = 0; j < openSetSize; j++) {
                        if (openSet[j]->position.x == neighbor.x && openSet[j]->position.y == neighbor.y) {
                            if (neighborNode->g < openSet[j]->g) {
                                openSet[j]->g = neighborNode->g;
                                openSet[j]->f = openSet[j]->g + openSet[j]->h;
                                openSet[j]->parent = current;
                            }
                            free(neighborNode);
                            break;
                        }
                    }
                } else {
                    addToOpenSet(neighborNode);
                }
            }
        }
    }

    printf("No path found.\n");
}

int main() {
    Point start = {0, 0};
    aStar(start);
    return 0;
}