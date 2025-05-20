//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point start;
    Point end;
    int distance;
} Path;

Path* generate_path(int start_x, int start_y, int end_x, int end_y) {
    Path* path = (Path*)malloc(sizeof(Path));
    path->start.x = start_x;
    path->start.y = start_y;
    path->end.x = end_x;
    path->end.y = end_y;
    path->distance = abs(path->start.x - path->end.x) + abs(path->start.y - path->end.y);
    return path;
}

int get_random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void print_maze(char maze[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (maze[i][j] == 1) {
                printf("X ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char maze[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            maze[i][j] = rand() % 2;
        }
    }
    print_maze(maze);
    Point start = {0, 0};
    Point end = {9, 9};
    Path* path = generate_path(start.x, start.y, end.x, end.y);
    printf("Distance: %d\n", path->distance);
    return 0;
}