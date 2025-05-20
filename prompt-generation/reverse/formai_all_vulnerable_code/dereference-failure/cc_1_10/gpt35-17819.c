//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20

typedef enum { false, true } bool;

void generateMaze(int maze[][COLS], int startRow, int startCol);
bool canMove(int maze[][COLS], int row, int col, int dir);
bool inBounds(int row, int col);
bool isDeadEnd(int maze[][COLS], int row, int col);

int main()
{
    int maze[ROWS][COLS] = { 0 };
    srand(time(NULL));
    int startRow = rand() % ROWS;
    int startCol = 0;
    generateMaze(maze, startRow, startCol);
    // Print maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
    return 0;
}

void generateMaze(int maze[][COLS], int startRow, int startCol)
{
    int row = startRow, col = startCol;
    maze[row][col] = 1;

    int directions[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    while (true) {
        bool moved = false;
        int i = 0;
        while (i < 4) {
            int dir = rand() % 4;
            if (canMove(maze, row, col, dir)) {
                row += directions[dir][0];
                col += directions[dir][1];
                maze[row][col] = 1;
                moved = true;
                break;
            }
            i++;
        }
        if (!moved || isDeadEnd(maze, row, col)) {
            if (inBounds(row, col - 1) && maze[row][col - 1] == 1) {
                col--;
            } else if (inBounds(row - 1, col) && maze[row - 1][col] == 1) {
                row--;
            } else if (inBounds(row, col + 1) && maze[row][col + 1] == 1) {
                col++;
            } else if (inBounds(row + 1, col) && maze[row + 1][col] == 1) {
                row++;
            }
            if (row == startRow && col == startCol) {
                break;
            }
        }
    }
}

bool canMove(int maze[][COLS], int row, int col, int dir)
{
    int newRow = row + (2 * ((dir / 2) - 1));
    int newCol = col + (2 * (dir % 2) - 1);
    if (!inBounds(newRow, newCol)) {
        return false;
    }
    if (maze[newRow][newCol] == 1) {
        return false;
    }
    return true;
}

bool inBounds(int row, int col)
{
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return false;
    }
    return true;
}

bool isDeadEnd(int maze[][COLS], int row, int col) {
    int count = 0;
    if (inBounds(row - 1, col) && maze[row - 1][col] == 1) {
        count++;
    }
    if (inBounds(row + 1, col) && maze[row + 1][col] == 1) {
        count++;
    }
    if (inBounds(row, col - 1) && maze[row][col - 1] == 1) {
        count++;
    }
    if (inBounds(row, col + 1) && maze[row][col + 1] == 1) {
        count++;
    }
    if (count > 1) {
        return false;
    }
    return true;
}