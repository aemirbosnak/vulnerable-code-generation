//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

Point* findMazeRoute(Point* start, Point* end) {
    // Initialize a grid to keep track of visited cells
    int gridSize = 20;
    Point* grid[gridSize][gridSize];

    // Initialize the start and end cells as unvisited
    start->x = 0;
    start->y = 0;
    end->x = gridSize - 1;
    end->y = gridSize - 1;

    // Initialize the queue for BFS
    Point* queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = start;

    while (front < rear) {
        // Dequeue a cell from the front of the queue
        Point* current = queue[front++];

        // Check if the current cell is the end cell
        if (current->x == end->x && current->y == end->y) {
            return current;
        }

        // Add the neighboring cells to the queue
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            Point* neighbor = (Point*) malloc(sizeof(Point));
            neighbor->x = current->x + dx[i];
            neighbor->y = current->y + dy[i];

            // Check if the neighbor cell is within the grid bounds and not visited
            if (neighbor->x >= 0 && neighbor->x < gridSize && neighbor->y >= 0 && neighbor->y < gridSize && grid[neighbor->x][neighbor->y] == 0) {
                grid[neighbor->x][neighbor->y] = 1;
                queue[rear++] = neighbor;
            }
        }
    }

    // No path was found
    return NULL;
}

int main() {
    Point* start = (Point*) malloc(sizeof(Point));
    Point* end = (Point*) malloc(sizeof(Point));
    start->x = 0;
    start->y = 0;
    end->x = 4;
    end->y = 4;

    Point* path = findMazeRoute(start, end);
    if (path!= NULL) {
        printf("Path found: (%d, %d) -> (%d, %d)\n", path->x, path->y, path->x + 1, path->y + 1);
    } else {
        printf("No path was found\n");
    }

    free(start);
    free(end);
    free(path);

    return 0;
}