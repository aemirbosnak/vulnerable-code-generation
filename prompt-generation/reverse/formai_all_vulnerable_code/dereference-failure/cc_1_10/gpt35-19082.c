//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

typedef struct Node {
    int row;
    int col;
    int gScore;
    int hScore;
    int fScore;
    int visited;
    struct Node* parent;
} Node;

Node* createNode(int row, int col) {
    Node* node = malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->gScore = 0;
    node->hScore = 0;
    node->fScore = 0;
    node->visited = 0;
    node->parent = NULL;
    return node;
}

int heuristic(int startX, int startY, int goalX, int goalY) {
    return abs(startX - goalX) + abs (startY - goalY);
}

void printPath(Node* start, Node* goal) {
    Node* node = goal;
    printf("Path: (%d, %d)", node->row, node->col);
    while (node != start) {
        node = node->parent;
        printf(" <- (%d, %d)", node->row, node->col);
    }
    printf("\n");
}

int main() {
    Node* start = createNode(0, 0);
    Node* goal = createNode(9, 9);
    Node* nodes[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            nodes[i][j] = createNode(i, j);
        }
    }

    int walls[ROWS][COLS] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,1,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,1,0,0,0,1,0,0,0},
        {0,0,1,0,0,0,1,0,0,0},
        {0,0,1,0,0,0,1,0,0,0},
        {0,0,1,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
    };

    int openListCount = 0;
    Node* openList[ROWS * COLS];
    start->visited = 1;
    openList[openListCount++] = start;
    
    while (openListCount > 0) {
        int current = 0;
        for (int i = 0; i < openListCount; i++) {
            if (openList[i]->fScore < openList[current]->fScore) {
                current = i;
            }
        }

        Node* current_node = openList[current];
        if (current_node == goal) {
            printPath(start, goal);
            return 0;
        }

        openList[current] = openList[--openListCount];

        Node* neighbors[4] = {
            current_node->row > 0 ? nodes[current_node->row - 1][current_node->col] : NULL,
            current_node->col > 0 ? nodes[current_node->row][current_node->col - 1] : NULL,
            current_node->row < ROWS - 1 ? nodes[current_node->row + 1][current_node->col] : NULL,
            current_node->col < COLS - 1 ? nodes[current_node->row][current_node->col + 1] : NULL,
        };

        for (int i = 0; i < 4; i++) {
            Node* neighbor = neighbors[i];
            if (neighbor == NULL || neighbor->visited || walls[neighbor->row][neighbor->col]) {
                continue;
            }

            int tentativeGScore = current_node->gScore + 1;
            int tentativeHScore = heuristic(neighbor->row, neighbor->col, goal->row, goal->col);
            int tentativeFScore = tentativeGScore + tentativeHScore;

            if (tentativeFScore < neighbor->fScore || !neighbor->visited) {
                neighbor->parent = current_node;
                neighbor->gScore = tentativeGScore;
                neighbor->hScore = tentativeHScore;
                neighbor->fScore = tentativeFScore;

                if (!neighbor->visited) {
                    openList[openListCount++] = neighbor;
                    neighbor->visited = 1;
                }
            }
        }
    }

    printf("No path found\n");
}