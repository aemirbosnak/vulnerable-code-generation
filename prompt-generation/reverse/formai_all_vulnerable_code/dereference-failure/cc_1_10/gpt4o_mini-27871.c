//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define ROW 10
#define COL 10
#define HEURISTIC 10 // Assuming diagonal movement cost is 14 and straight cost is 10

typedef struct Node {
    int parent_i, parent_j;
    double f, g, h;
} Node;

Node *openList;
Node closedList[ROW][COL];

int isSafe(int row, int col) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL);
}

double calculateH(int row, int col, int dest_row, int dest_col) {
    return HEURISTIC * (abs(row - dest_row) + abs(col - dest_col));
}

int isInOpenList(int row, int col) {
    for (int i = 0; i < ROW * COL; i++) {
        if (openList[i].parent_i == row && openList[i].parent_j == col) {
            return 1;
        }
    }
    return 0;
}

int isInClosedList(int row, int col) {
    return closedList[row][col].h != -1;
}

void addToOpenList(int row, int col, int parentRow, int parentCol, double g, double h) {
    int idx = row * COL + col;
    openList[idx].parent_i = row;
    openList[idx].parent_j = col;
    openList[idx].g = g;
    openList[idx].h = h;
    openList[idx].f = g + h;
}

void printPath(int path[][2], int length) {
    printf("The path is:\n");
    for (int i = 0; i < length; i++) {
        printf("(%d, %d) ", path[i][0], path[i][1]);
    }
    printf("\n");
}

void AStar(int start_row, int start_col, int dest_row, int dest_col) {
    int direction[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // Right, Down, Left, Up

    openList = (Node *)malloc(ROW * COL * sizeof(Node));
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            openList[i * COL + j].h = -1; // Mark all open nodes as unvisited
            closedList[i][j].h = -1; // Initialize closed list
        }
    }

    int path[ROW * COL][2], path_length = 0;

    addToOpenList(start_row, start_col, -1, -1, 0, calculateH(start_row, start_col, dest_row, dest_col));

    while (1) {
        double min_f = INT_MAX;
        int current_i = -1, current_j = -1;

        // Find the node with the minimum f in the open list
        for (int i = 0; i < ROW * COL; i++) {
            if (openList[i].h >= 0 && openList[i].f < min_f) {
                min_f = openList[i].f;
                current_i = openList[i].parent_i;
                current_j = openList[i].parent_j;
            }
        }

        if (current_i == -1) {
            printf("Path not found!\n");
            return;
        }

        // Move the current node from open to closed
        closedList[current_i][current_j].h = 0; // Mark as visited

        // Reached destination
        if (current_i == dest_row && current_j == dest_col) {
            path[path_length][0] = current_i;
            path[path_length][1] = current_j;
            path_length++;

            // Reconstruct the path
            while (current_i != start_row || current_j != start_col) {
                int parent_i = closedList[current_i][current_j].parent_i;
                int parent_j = closedList[current_i][current_j].parent_j;
                path[path_length][0] = parent_i; 
                path[path_length][1] = parent_j; 
                path_length++;
                current_i = parent_i;
                current_j = parent_j;
            }

            // Print the path
            for (int i = path_length - 1; i >= 0; i--) {
                printf("(%d, %d) ", path[i][0], path[i][1]);
            }
            printf("\n");
            free(openList);
            return;
        }

        // Process neighbors
        for (int k = 0; k < 4; k++) {
            int neighbor_i = current_i + direction[k][0];
            int neighbor_j = current_j + direction[k][1];

            if (isSafe(neighbor_i, neighbor_j) && !isInClosedList(neighbor_i, neighbor_j)) {
                double g = closedList[current_i][current_j].g + HEURISTIC;
                double h = calculateH(neighbor_i, neighbor_j, dest_row, dest_col);

                if (!isInOpenList(neighbor_i, neighbor_j) || g < openList[neighbor_i * COL + neighbor_j].g) {
                    addToOpenList(neighbor_i, neighbor_j, current_i, current_j, g, h);
                }
            }
        }
    }
}

int main() {
    int start_row = 0, start_col = 0;
    int dest_row = 7, dest_col = 7;

    printf("Starting A* pathfinding from (%d, %d) to (%d, %d)...\n", start_row, start_col, dest_row, dest_col);
    AStar(start_row, start_col, dest_row, dest_col);

    return 0;
}