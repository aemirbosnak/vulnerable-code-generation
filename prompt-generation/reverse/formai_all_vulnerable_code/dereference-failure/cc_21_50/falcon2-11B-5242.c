//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    int height;
    int width;
    int visited;
    int neighbor;
} cell;

int main() {
    // Set maze dimensions
    int width = 10;
    int height = 10;

    // Initialize maze
    cell* maze = malloc(height * width * sizeof(cell));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze[i * width + j].x = j;
            maze[i * width + j].y = i;
            maze[i * width + j].visited = 0;
            maze[i * width + j].neighbor = -1;
        }
    }

    // Set start and end cells
    int start_x = 5;
    int start_y = 5;
    int end_x = 8;
    int end_y = 8;

    // Set cell values
    maze[start_y * width + start_x].visited = 1;
    maze[end_y * width + end_x].visited = 1;

    // Initialize queue
    cell* queue = malloc(height * width * sizeof(cell));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            queue[i * width + j].x = j;
            queue[i * width + j].y = i;
            queue[i * width + j].visited = 0;
            queue[i * width + j].neighbor = -1;
        }
    }

    // Initialize visited cells
    int visited[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            visited[i][j] = 0;
        }
    }

    // Generate maze
    while (queue[0].visited == 0) {
        // Print maze
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (maze[i * width + j].visited == 1) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Get next cell
        int index = 0;
        int max_neighbor = -1;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (visited[i][j] == 0 && queue[index].neighbor == -1) {
                    queue[index].neighbor = j - start_x;
                    queue[index].y = i - start_y;
                    visited[i][j] = 1;
                    index++;
                    if (queue[index - 1].neighbor == -1) {
                        max_neighbor = j - start_x;
                    }
                }
            }
        }

        // Check for end cell
        if (max_neighbor == end_x) {
            break;
        }

        // Connect cells
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (maze[i * width + j].visited == 0 && visited[i][j] == 0) {
                    if (maze[i * width + j].neighbor == -1) {
                        maze[i * width + j].neighbor = max_neighbor;
                        maze[i * width + j].visited = 1;
                    }
                }
            }
        }
    }

    // Print maze
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (maze[i * width + j].visited == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    free(maze);
    free(queue);
    return 0;
}