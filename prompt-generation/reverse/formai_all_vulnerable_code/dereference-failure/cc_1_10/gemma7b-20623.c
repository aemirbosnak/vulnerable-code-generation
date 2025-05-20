//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'
#define PLAYER_CHAR 'P'

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void generateMaze(Node** maze) {
    int x, y;
    *maze = NULL;

    for (x = 0; x < MAZE_WIDTH; x++) {
        for (y = 0; y < MAZE_HEIGHT; y++) {
            Node* newNode = malloc(sizeof(Node));
            newNode->x = x;
            newNode->y = y;
            newNode->next = NULL;

            if (rand() % 2 == 0) {
                maze = &newNode;
            } else {
                (*maze)->next = newNode;
                maze = &newNode;
            }
        }
    }
}

void printMaze(Node* maze) {
    int x, y;
    for (x = 0; x < MAZE_WIDTH; x++) {
        for (y = 0; y < MAZE_HEIGHT; y++) {
            if (maze->x == x && maze->y == y) {
                printf("%c", PLAYER_CHAR);
            } else if (maze->x == x && maze->y == y - 1) {
                printf("%c", WALL_CHAR);
            } else if (maze->x == x + 1 && maze->y == y) {
                printf("%c", WALL_CHAR);
            } else if (maze->x == x - 1 && maze->y == y) {
                printf("%c", WALL_CHAR);
            } else {
                printf("%c", EMPTY_CHAR);
            }
        }
        printf("\n");
    }
}

int main() {
    Node* maze;
    generateMaze(&maze);
    printMaze(maze);

    return 0;
}