//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 5
#define COL 5

/* Define a structure for Node of the Graph */
typedef struct Node {
    int row, col, f_score, g_score, h_score;
    struct Node *parent;
} Node;

/* Function to add adjacent Nodes to the open list */
void addNeighbors(Node *current, int (*maze)[COL], Node *openList[], int *numOpenList) {
    int row = current->row;
    int col = current->col;

    if (row > 0 && maze[row-1][col] == 0) {
        Node *neighbor = malloc(sizeof(Node));
        neighbor->row = row-1;
        neighbor->col = col;
        neighbor->g_score = current->g_score + 1;
        neighbor->h_score = abs(row-1 - (ROW-1)) + abs(col - (COL-1)); // Calculating Manhattan Distance
        neighbor->f_score = neighbor->g_score + neighbor->h_score;
        neighbor->parent = current;
        openList[*numOpenList] = neighbor;
        (*numOpenList)++;
    }

    if (col > 0 && maze[row][col-1] == 0) {
        Node *neighbor = malloc(sizeof(Node));
        neighbor->row = row;
        neighbor->col = col-1;
        neighbor->g_score = current->g_score + 1;
        neighbor->h_score = abs(row - (ROW-1)) + abs(col-1 - (COL-1)); // Calculating Manhattan Distance
        neighbor->f_score = neighbor->g_score + neighbor->h_score;
        neighbor->parent = current;
        openList[*numOpenList] = neighbor;
        (*numOpenList)++;
    }

    if (row < ROW-1 && maze[row+1][col] == 0) {
        Node *neighbor = malloc(sizeof(Node));
        neighbor->row = row+1;
        neighbor->col = col;
        neighbor->g_score = current->g_score + 1;
        neighbor->h_score = abs(row+1 - (ROW-1)) + abs(col - (COL-1)); // Calculating Manhattan Distance
        neighbor->f_score = neighbor->g_score + neighbor->h_score;
        neighbor->parent = current;
        openList[*numOpenList] = neighbor;
        (*numOpenList)++;
    }

    if (col < COL-1 && maze[row][col+1] == 0) {
        Node *neighbor = malloc(sizeof(Node));
        neighbor->row = row;
        neighbor->col = col+1;
        neighbor->g_score = current->g_score + 1;
        neighbor->h_score = abs(row - (ROW-1)) + abs(col+1 - (COL-1)); // Calculating Manhattan Distance
        neighbor->f_score = neighbor->g_score + neighbor->h_score;
        neighbor->parent = current;
        openList[*numOpenList] = neighbor;
        (*numOpenList)++;
    }
}

/* Function to check if a Node is in a list */
int inList(Node *node, Node *list[], int numList) {
    for (int i = 0; i < numList; i++) {
        if (node->row == list[i]->row && node->col == list[i]->col) {
            return 1;
        }
    }
    return 0;
}

/* Function to get the lowest score Node from the open list */
Node* getLowestScore(Node *list[], int numList) {
    Node *lowest = list[0];
    for (int i = 1; i < numList; i++) {
        if (list[i]->f_score < lowest->f_score) {
            lowest = list[i];
        }
    }
    return lowest;
}

/* Function to print the maze with the path */
void printPath(int (*maze)[COL], Node *end) {
    Node *current = end;
    while (current) {
        maze[current->row][current->col] = 2;
        current = current->parent;
    }
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

/* Main function */
int main() {
    int maze[ROW][COL] = {
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0}
    };

    Node *openList[ROW*COL] = {NULL};
    Node *closedList[ROW*COL] = {NULL};
    int numOpenList = 0;
    int numClosedList = 0;

    Node *start = malloc(sizeof(Node));
    start->row = 0;
    start->col = 0;
    start->f_score = 0;
    start->g_score = 0;
    start->h_score = abs(0 - (ROW-1)) + abs(0 - (COL-1)); // Calculating Manhattan Distance
    start->parent = NULL;

    openList[numOpenList] = start;
    numOpenList++;

    Node *end = NULL;

    while (numOpenList > 0) {
        Node *current = getLowestScore(openList, numOpenList);
        if (current->row == ROW-1 && current->col == COL-1) {
            end = current;
            break;
        }

        for (int i = 0; i < numOpenList; i++) {
            if (openList[i]->row == current->row && openList[i]->col == current->col) {
                for (int j = i; j < numOpenList-1; j++) {
                    openList[j] = openList[j+1];
                }
                numOpenList--;
                break;
            }
        }

        closedList[numClosedList] = current;
        numClosedList++;

        addNeighbors(current, maze, openList, &numOpenList);

        for (int i = 0; i < numOpenList; i++) {
            if (inList(openList[i], closedList, numClosedList)) {
                for (int j = i; j < numOpenList-1; j++) {
                    openList[j] = openList[j+1];
                }
                numOpenList--;
            }
        }
    }

    if (end) {
        printPath(maze, end);
    } else {
        printf("No path found!\n");
    }

    return 0;
}