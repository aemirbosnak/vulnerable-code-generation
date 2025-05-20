//GPT-4o-mini DATASET v1.0 Category: Procedurally Generated Maze ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL '#'
#define PATH ' '
#define VISITED '.'
#define START 'S'
#define END 'E'

typedef struct {
    int x;
    int y;
} Position;

void generateMaze(char **maze, int width, int height);
void carvePath(char **maze, int x, int y, int width, int height);
void printMaze(char **maze, int width, int height);
void playMaze(char **maze, int width, int height);
Position findStart(char **maze, int width, int height);

int main() {
    int width, height;
    printf("Enter width of the maze: ");
    scanf("%d", &width);
    printf("Enter height of the maze: ");
    scanf("%d", &height);

    // Allocate memory for the maze
    char **maze = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        maze[i] = malloc(width * sizeof(char));
    }
    
    // Seed random number generator
    srand(time(NULL));
    
    // Generate the maze
    generateMaze(maze, width, height);
    
    // Set Start and End points
    maze[1][1] = START;
    maze[height - 2][width - 2] = END;
    
    // Print the generated maze
    printMaze(maze, width, height);
    
    // Start playing the maze
    playMaze(maze, width, height);

    // Free memory
    for (int i = 0; i < height; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}

void generateMaze(char **maze, int width, int height) {
    // Set the entire maze to walls
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            maze[y][x] = WALL;
        }
    }
    
    // Carve the maze starting from a random position
    carvePath(maze, 1, 1, width, height);
}

void carvePath(char **maze, int x, int y, int width, int height) {
    int dx[] = { 2, -2, 0, 0 };
    int dy[] = { 0, 0, 2, -2 };
    
    // Shuffle directions
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int tempX = dx[i];
        int tempY = dy[i];
        dx[i] = dx[j];
        dy[i] = dy[j];
        dx[j] = tempX;
        dy[j] = tempY;
    }
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx > 0 && nx < width && ny > 0 && ny < height && maze[ny][nx] == WALL) {
            maze[ny][nx] = PATH; // Carve a path
            maze[ny - dy[i] / 2][nx - dx[i] / 2] = PATH; // Connect to current
            carvePath(maze, nx, ny, width, height); // Recursive call
        }
    }
}

void printMaze(char **maze, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            putchar(maze[y][x]);
        }
        putchar('\n');
    }
}

void playMaze(char **maze, int width, int height) {
    Position player = findStart(maze, width, height);
    int gameWon = 0;

    while (!gameWon) {
        printMaze(maze, width, height);
        printf("Move (WASD): ");
        
        char move;
        scanf(" %c", &move);
        
        int newX = player.x, newY = player.y;
        if (move == 'w' || move == 'W') newY--;
        else if (move == 's' || move == 'S') newY++;
        else if (move == 'a' || move == 'A') newX--;
        else if (move == 'd' || move == 'D') newX++;
        
        if (newX >= 0 && newX < width && newY >= 0 && newY < height &&
            (maze[newY][newX] == PATH || maze[newY][newX] == END)) {
            if (maze[newY][newX] == END) {
                gameWon = 1;
                printf("Congratulations! You have escaped the maze!\n");
            } else {
                maze[player.y][player.x] = PATH; // Clear previous position
                player.x = newX;
                player.y = newY;
                maze[player.y][player.x] = START;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

Position findStart(char **maze, int width, int height) {
    Position pos;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (maze[y][x] == START) {
                pos.x = x;
                pos.y = y;
                return pos;
            }
        }
    }
    pos.x = -1;
    pos.y = -1;
    return pos;
}