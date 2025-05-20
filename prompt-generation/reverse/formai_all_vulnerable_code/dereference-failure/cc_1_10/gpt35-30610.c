//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// struct to hold x, y coordinates
typedef struct {
    int x;
    int y;
} Point;

// function to check if a point is valid
bool isValid(int x, int y, int width, int height, int maze[][height]) {
    return x >= 0 && y >= 0 && x < width && y < height && maze[x][y] == 1;
}

// function to find the shortest path using bfs algorithm
void bfs(int width, int height, int maze[][height], Point start, Point end) {
    
    // create visited array and initialize it to false
    bool visited[width][height];
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            visited[i][j] = false;
        }
    }
    
    // create queue
    Point queue[width * height];
    int front = 0, rear = 0;
    
    // add start point to queue and mark it as visited
    queue[rear++] = start;
    visited[start.x][start.y] = true;
    
    // continue till queue is not empty
    while (front != rear) {
        
        // remove point from queue
        Point current = queue[front++];
        
        // if current point is the destination point, we have found the shortest path
        if (current.x == end.x && current.y == end.y) {
            printf("Shortest path found!\n");
            return;
        }
        
        // check all neighbouring points
        Point neighbours[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int i = 0; i < 4; i++) {
            int x = current.x + neighbours[i].x;
            int y = current.y + neighbours[i].y;
            
            // if neighbour is valid and has not been visited, add it to queue and mark it as visited
            if (isValid(x, y, width, height, maze) && !visited[x][y]) {
                queue[rear++] = (Point){x, y};
                visited[x][y] = true;
            }
        }
    }
    
    // if we reach here, it means there is no path from start to end
    printf("No path found!\n");
}

// driver function
int main() {
    
    int maze[][5] = {
        { 1, 1, 1, 1, 1 },
        { 0, 0, 1, 0, 0 },
        { 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 0 },
        { 1, 1, 1, 1, 1 }
    };
    
    int width = 5;
    int height = 5;
    
    Point start = {0, 0};
    Point end = {4, 4};
    
    bfs(width, height, maze, start, end);
    
    return 0;
}