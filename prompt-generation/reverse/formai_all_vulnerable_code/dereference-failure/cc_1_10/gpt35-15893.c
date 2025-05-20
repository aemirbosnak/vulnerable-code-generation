//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define ROW 7
#define COL 7

struct Node {
    int x;
    int y;
    struct Node *next;
};

void printMazeRoute(int maze[][COL], struct Node *route) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            int isRoute = 0;
            struct Node *temp = route;
            while (temp != NULL) {
                if (temp->x == i && temp->y == j) {
                    isRoute = 1;
                    break;
                }
                temp = temp->next;
            }
            if (isRoute) {
                printf("O ");
            } else if (maze[i][j] == 0) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void findMazeRoute(int maze[][COL], int row, int col, struct Node **route) {
    if (row < 0 || row >= ROW || col < 0 || col >= COL || maze[row][col] == 1) {
        return;
    }
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->x = row;
    temp->y = col;
    temp->next = (*route);
    (*route) = temp;
    if (row == ROW-1 && col == COL-1) {
        printMazeRoute(maze, *route);
        return;
    }
    findMazeRoute(maze, row, col+1, route);
    findMazeRoute(maze, row+1, col, route);
    (*route) = (*route)->next;
    free(temp);
}

int main() {
    int maze[ROW][COL] = {
        {0, 0, 0, 0, 1, 1, 0},
        {1, 1, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 0, 1},
        {0, 1, 1, 1, 1, 0, 0},
        {1, 0, 0, 1, 0, 0, 0}
    };
    struct Node *route = NULL;
    findMazeRoute(maze, 0, 0, &route);
    return 0;
}