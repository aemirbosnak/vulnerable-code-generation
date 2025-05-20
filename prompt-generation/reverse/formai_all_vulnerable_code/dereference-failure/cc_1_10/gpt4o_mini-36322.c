//GPT-4o-mini DATASET v1.0 Category: Maze Route Finder ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define MAZE_WIDTH 7
#define MAZE_HEIGHT 5

#define PATH ' '
#define WALL '#'
#define START 'S'
#define END 'E'
#define VISITED '.'

char maze[MAZE_HEIGHT][MAZE_WIDTH] = {
    {'#', '#', '#', '#', '#', '#', '#'},
    {'#', 'S', ' ', ' ', '#', 'E', '#'},
    {'#', '#', '#', ' ', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#'}
};

int start_x = 1, start_y = 1; // Starting point
int end_x = 1, end_y = 5; // End point
bool found = false;

typedef struct {
    int x, y;
} Position;

void printMaze() {
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void *searchRoute(void *arg) {
    Position *pos = (Position *)arg;
    
    if (found || pos->x < 0 || pos->x >= MAZE_WIDTH || 
        pos->y < 0 || pos->y >= MAZE_HEIGHT || 
        maze[pos->y][pos->x] == WALL || maze[pos->y][pos->x] == VISITED) {
        free(pos);
        pthread_exit(NULL);
    }
    
    if (pos->x == end_x && pos->y == end_y) {
        found = true;
        printf("Found the exit at (%d, %d)!\n", pos->x, pos->y);
        free(pos);
        pthread_exit(NULL);
    }
    
    maze[pos->y][pos->x] = VISITED;

    Position *up = malloc(sizeof(Position)); 
    up->x = pos->x;
    up->y = pos->y - 1;

    Position *down = malloc(sizeof(Position));
    down->x = pos->x;
    down->y = pos->y + 1;

    Position *left = malloc(sizeof(Position));
    left->x = pos->x - 1;
    left->y = pos->y;

    Position *right = malloc(sizeof(Position));
    right->x = pos->x + 1;
    right->y = pos->y;

    pthread_t threads[4];
    pthread_create(&threads[0], NULL, searchRoute, up);
    pthread_create(&threads[1], NULL, searchRoute, down);
    pthread_create(&threads[2], NULL, searchRoute, left);
    pthread_create(&threads[3], NULL, searchRoute, right);

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    maze[pos->y][pos->x] = PATH; // Backtrack
    free(pos);
    pthread_exit(NULL);
}

int main() {
    printf("Maze before search:\n");
    printMaze();
    
    Position *startPos = malloc(sizeof(Position));
    startPos->x = start_x;
    startPos->y = start_y;

    pthread_t startThread;
    pthread_create(&startThread, NULL, searchRoute, startPos);
    
    pthread_join(startThread, NULL);

    printf("Maze after search:\n");
    printMaze();

    if (!found) {
        printf("No route to exit found!\n");
    }

    return 0;
}