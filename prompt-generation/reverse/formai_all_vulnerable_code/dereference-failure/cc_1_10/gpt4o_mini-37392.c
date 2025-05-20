//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define WIDTH 10
#define HEIGHT 10
#define OBSTACLE '#'
#define EMPTY '.'
#define START 'S'
#define END 'E'

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point* points;
    int size;
    int capacity;
} Path;

// Function prototypes
void initializePath(Path* path);
void addPoint(Path* path, Point p);
bool isValidMove(int x, int y, char grid[HEIGHT][WIDTH]);
void printGrid(char grid[HEIGHT][WIDTH], Path* path);
bool findPath(char grid[HEIGHT][WIDTH], Point start, Point end, Path* path);
int heuristic(Point a, Point b);

int main() {
    char grid[HEIGHT][WIDTH] = {
        {'.', '.', '.', '#', '.', '.', '.', '#', '.', '.'},
        {'#', '#', '.', '#', '.', '#', '.', '#', '.', '.'},
        {'.', '.', '.', '.', '.', '#', '.', '#', '#', '.'},
        {'.', '#', '#', '#', '#', '#', '#', '#', '.', '.'},
        {'S', '.', '.', '.', '#', '.', '.', '#', '.', 'E'},
        {'#', '#', '#', '#', '#', '.', '#', '#', '#', '#'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'.', '.', '.', '.', 'D', '.', 'C', '.', '.', '.'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    Point start = {4, 0};  // Starting point S
    Point end = {4, 9};    // Ending point E
    Path path;
    initializePath(&path);

    if (findPath(grid, start, end, &path)) {
        printf("Path found:\n");
        printGrid(grid, &path);
    } else {
        printf("No path found.\n");
    }

    free(path.points);
    return 0;
}

void initializePath(Path* path) {
    path->size = 0;
    path->capacity = 10; // Initial capacity
    path->points = malloc(sizeof(Point) * path->capacity);
    if (!path->points) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}

void addPoint(Path* path, Point p) {
    if (path->size >= path->capacity) {
        path->capacity *= 2;
        path->points = realloc(path->points, sizeof(Point) * path->capacity);
        if (!path->points) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
    }
    path->points[path->size++] = p;
}

bool isValidMove(int x, int y, char grid[HEIGHT][WIDTH]) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && grid[y][x] != OBSTACLE);
}

void printGrid(char grid[HEIGHT][WIDTH], Path* path) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            bool isOnPath = false;
            for (int k = 0; k < path->size; k++) {
                if (path->points[k].x == j && path->points[k].y == i) {
                    isOnPath = true;
                    break;
                }
            }
            if (isOnPath) {
                printf("o "); // Path representation
            } else {
                printf("%c ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

bool findPath(char grid[HEIGHT][WIDTH], Point start, Point end, Path* path) {
    bool visited[HEIGHT][WIDTH] = {false};
    Point queue[WIDTH * HEIGHT];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start.y][start.x] = true;
    addPoint(path, start);

    while (front < rear) {
        Point current = queue[front++];
        
        if (current.x == end.x && current.y == end.y) {
            return true; // Reached the destination
        }

        static const int offsets[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        for (int i = 0; i < 4; i++) {
            int newX = current.x + offsets[i][0];
            int newY = current.y + offsets[i][1];

            if (isValidMove(newX, newY, grid) && !visited[newY][newX]) {
                visited[newY][newX] = true;
                queue[rear++] = (Point){newX, newY};
                addPoint(path, (Point){newX, newY});
            }
        }
    }
    return false; // No path found
}