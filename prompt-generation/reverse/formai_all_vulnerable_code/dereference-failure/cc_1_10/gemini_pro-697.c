//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: Romeo and Juliet
// Two hearts entwined, seeking solace and respite,
// In this labyrinth of walls, they yearned to unite.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// The stage where our lovers' journey unfolds, a maze of walls and open paths
char** maze;
int mazeWidth, mazeHeight;

// Our star-crossed lovers, tracing their steps through the labyrinth
struct Lover {
    int x;
    int y;
    int steps;
};
struct Lover romeo, juliet;

// A beacon of hope, guiding their paths toward each other
struct Coordinate {
    int x;
    int y;
};
struct Coordinate rendezvous;

// As they venture forth, they keep a record of their journey
int** pathMap;

// A spark of hope amidst the obstacles, a path to their reunion
bool pathFound = false;

// Romeo and Juliet take their first steps into the labyrinth
void initializeLovers() {
    printf("Enter Romeo's starting coordinates (x, y): ");
    scanf("%d %d", &romeo.x, &romeo.y);
    printf("Enter Juliet's starting coordinates (x, y): ");
    scanf("%d %d", &juliet.x, &juliet.y);
}

// The maze, a tapestry of walls and open paths, is unveiled
void createMaze() {
    printf("Enter maze width and height: ");
    scanf("%d %d", &mazeWidth, &mazeHeight);

    maze = malloc(mazeHeight * sizeof(char*));
    for (int i = 0; i < mazeHeight; i++) {
        maze[i] = malloc(mazeWidth * sizeof(char));
    }

    printf("Input the maze (0 for path, 1 for wall):\n");
    for (int i = 0; i < mazeHeight; i++) {
        for (int j = 0; j < mazeWidth; j++) {
            scanf(" %c ", &maze[i][j]);
        }
    }
}

// A secret rendezvous, the beacon guiding their hearts toward each other
void setRendezvous() {
    printf("Enter rendezvous coordinates (x, y): ");
    scanf("%d %d", &rendezvous.x, &rendezvous.y);
}

// A tapestry woven with each step they take, marking their path through the maze
void createPathMap() {
    pathMap = malloc(mazeHeight * sizeof(int*));
    for (int i = 0; i < mazeHeight; i++) {
        pathMap[i] = malloc(mazeWidth * sizeof(int));
    }

    for (int i = 0; i < mazeHeight; i++) {
        for (int j = 0; j < mazeWidth; j++) {
            pathMap[i][j] = -1;
        }
    }
}

// As love conquers all, so too must Romeo and Juliet find their path
bool findPath(struct Lover* lover) {
    if (lover->x == rendezvous.x && lover->y == rendezvous.y) {
        return true;
    }

    if (lover->x < 0 || lover->x >= mazeWidth || lover->y < 0 || lover->y >= mazeHeight) {
        return false;
    }

    if (maze[lover->y][lover->x] == '1' || pathMap[lover->y][lover->x] != -1) {
        return false;
    }

    pathMap[lover->y][lover->x] = lover->steps;

    if (findPath(&romeo) || findPath(&juliet)) {
        return true;
    }

    pathMap[lover->y][lover->x] = -1;
    return false;
}

// The culmination of their journey, love's embrace amidst the labyrinth's embrace
void reuniteLovers() {
    if (!pathFound) {
        printf("Alas, Romeo and Juliet could not find their way to each other.\n");
        return;
    }

    printf("Romeo and Juliet have found their path to each other!\n");
    printf("Romeo's path:\n");
    for (int i = 0; i < mazeHeight; i++) {
        for (int j = 0; j < mazeWidth; j++) {
            if (pathMap[i][j] == romeo.steps) {
                printf("(%d, %d) ", j, i);
            }
        }
    }
    printf("\n\n");

    printf("Juliet's path:\n");
    for (int i = 0; i < mazeHeight; i++) {
        for (int j = 0; j < mazeWidth; j++) {
            if (pathMap[i][j] == juliet.steps) {
                printf("(%d, %d) ", j, i);
            }
        }
    }
    printf("\n");
}

// The eternal dance of love, Romeo and Juliet united in the labyrinth of life
int main() {
    printf("Welcome to the labyrinth of love, where Romeo and Juliet seek their destiny.\n");
    initializeLovers();
    createMaze();
    setRendezvous();
    createPathMap();

    romeo.steps = 0;
    juliet.steps = 0;

    pathFound = findPath(&romeo) || findPath(&juliet);
    reuniteLovers();

    return 0;
}