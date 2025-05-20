//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EMPTY ' '
#define WALL '#'
#define PLAYER 'P'
#define MAZE_SIZE 5

typedef struct {
    int x;
    int y;
} Player;

void initializeMaze(char **maze);
void printMaze(char **maze, Player *player);
int movePlayer(char **maze, Player *player, char direction);
void cleanupMaze(char **maze);

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Dynamically allocate memory for the maze
    char **maze = (char **)malloc(MAZE_SIZE * sizeof(char *));
    for (int i = 0; i < MAZE_SIZE; i++) {
        maze[i] = (char *)malloc(MAZE_SIZE * sizeof(char));
    }

    // Create a player struct
    Player player = {0, 0}; // Starting position

    // Initialize the maze
    initializeMaze(maze);
    maze[player.x][player.y] = PLAYER; // Place player in maze

    char direction;
    while (1) {
        printMaze(maze, &player);
        printf("Enter direction (W=up, A=left, S=down, D=right, Q=quit): ");
        scanf(" %c", &direction);
        
        if (direction == 'Q' || direction == 'q') {
            break; // Quit the game
        }

        if (!movePlayer(maze, &player, direction)) {
            printf("Invalid move! Try again.\n");
        }
    }

    cleanupMaze(maze);
    return 0;
}

void initializeMaze(char **maze) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if ((i == 0) || (i == MAZE_SIZE - 1) || (j == 0) || (j == MAZE_SIZE - 1)) {
                maze[i][j] = WALL; // Create walls
            } else {
                maze[i][j] = (rand() % 4 == 0) ? WALL : EMPTY; // Randomly place walls
            }
        }
    }
}

void printMaze(char **maze, Player *player) {
    printf("\nMaze:\n");
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (i == player->x && j == player->y) {
                printf("%c ", PLAYER);
            } else {
                printf("%c ", maze[i][j]);
            }
        }
        printf("\n");
    }
}

int movePlayer(char **maze, Player *player, char direction) {
    int newX = player->x;
    int newY = player->y;

    switch (direction) {
        case 'W': case 'w':
            newX--;
            break;
        case 'S': case 's':
            newX++;
            break;
        case 'A': case 'a':
            newY--;
            break;
        case 'D': case 'd':
            newY++;
            break;
        default:
            return 0; // Invalid direction
    }

    // Check boundaries and walls
    if (newX < 0 || newX >= MAZE_SIZE || newY < 0 || newY >= MAZE_SIZE || maze[newX][newY] == WALL) {
        return 0; // Invalid move
    }

    // Update player position
    player->x = newX;
    player->y = newY;
    return 1; // Valid move
}

void cleanupMaze(char **maze) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        free(maze[i]); // Free each row
    }
    free(maze); // Free the array of pointers
}