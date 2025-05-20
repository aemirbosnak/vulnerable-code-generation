//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void findRoute(int currentPosition, int targetPosition, int **maze, int **visited, int **bestPath) {

    if (currentPosition == targetPosition) {
        bestPath[currentPosition] = 1;
        return;
    }

    if (visited[currentPosition] == 1) {
        return;
    }

    visited[currentPosition] = 1;

    for (int i = 0; i < 4; i++) {
        int nextPosition = currentPosition + maze[currentPosition][i];

        if (nextPosition >= 0 && nextPosition < 10 && maze[currentPosition][i] != -1 && visited[nextPosition] == 0) {
            findRoute(nextPosition, targetPosition, maze, visited, bestPath);

            if (bestPath[nextPosition] == 1) {
                bestPath[currentPosition] = 1;
            }
        }
    }

    return;
}

int main() {

    int maze[] = {{0, -1, 1, 0},
                   {-1, 0, 1, 0},
                   {0, 0, 0, -1},
                   {0, 0, 1, 0}};

    int visited[] = {0, 0, 0, 0};

    int bestPath[] = {0, 0, 0, 0};

    findRoute(0, 2, maze, visited, bestPath);

    if (bestPath[2] == 1) {
        printf("The target position has been reached.");
    } else {
        printf("The target position has not been reached.");
    }

    return 0;
}