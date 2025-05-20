//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

char maze[ROW][COL] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', ' ', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#', '#', ' ', '#'},
    {'#', ' ', '#', 'B', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

bool visited[ROW][COL];

typedef struct {
    int x;
    int y;
} Point;

int count_neighbors(Point p) {
    int count = 0;
    if (maze[p.y-1][p.x] != '#' && !visited[p.y-1][p.x]) {
        count++;
    }
    if (maze[p.y+1][p.x] != '#' && !visited[p.y+1][p.x]) {
        count++;
    }
    if (maze[p.y][p.x-1] != '#' && !visited[p.y][p.x-1]) {
        count++;
    }
    if (maze[p.y][p.x+1] != '#' && !visited[p.y][p.x+1]) {
        count++;
    }
    return count;
}

Point* get_neighbors(Point p, int* size) {
    Point* neighbors = malloc(count_neighbors(p) * sizeof(Point));
    *size = 0;
    if (maze[p.y-1][p.x] != '#' && !visited[p.y-1][p.x]) {
        neighbors[*size] = (Point) {p.x, p.y-1};
        (*size)++;
    }
    if (maze[p.y+1][p.x] != '#' && !visited[p.y+1][p.x]) {
        neighbors[*size] = (Point) {p.x, p.y+1};
        (*size)++;
    }
    if (maze[p.y][p.x-1] != '#' && !visited[p.y][p.x-1]) {
        neighbors[*size] = (Point) {p.x-1, p.y};
        (*size)++;
    }
    if (maze[p.y][p.x+1] != '#' && !visited[p.y][p.x+1]) {
        neighbors[*size] = (Point) {p.x+1, p.y};
        (*size)++;
    }
    return neighbors;
}

bool find_path(Point start, Point end) {
    bool found = false;

    Point* stack = malloc(ROW*COL * sizeof(Point));
    int top = 0;

    visited[start.y][start.x] = true;
    stack[top] = start;

    while (top >= 0 && !found) {
        Point current = stack[top];
        top--;

        if (current.x == end.x && current.y == end.y) {
            found = true;
        }

        int size;
        Point* neighbors = get_neighbors(current, &size);
        for (int i = 0; i < size; i++) {
            visited[neighbors[i].y][neighbors[i].x] = true;
            stack[++top] = neighbors[i];
        }
        free(neighbors);
    }

    free(stack);
    return found;
}

int main() {
    Point start = {1, 1};
    Point end = {8, 3};

    if (find_path(start, end)) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }

    // print maze with path
    for (int y = 0; y < ROW; y++) {
        for (int x = 0; x < COL; x++) {
            if (visited[y][x]) {
                printf("X ");
            } else {
                printf("%c ", maze[y][x]);
            }
        }
        printf("\n");
    }

    return 0;
}