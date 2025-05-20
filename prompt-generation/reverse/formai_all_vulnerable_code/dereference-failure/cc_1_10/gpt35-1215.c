//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAZE_WIDTH 15
#define MAZE_HEIGHT 10

struct Maze {
    bool hor_walls[MAZE_HEIGHT][MAZE_WIDTH-1];
    bool ver_walls[MAZE_HEIGHT-1][MAZE_WIDTH];
};

void print_maze(struct Maze* maze) {
    printf(" ");
    for (int i=0; i<MAZE_WIDTH; i++)
        printf("__");
    
    printf("\n");
    for (int i=0; i<MAZE_HEIGHT; i++) {
        printf("|");
        for (int j=0; j<MAZE_WIDTH-1; j++)
            printf("%c%s", maze->hor_walls[i][j] ? '_' : ' ', maze->ver_walls[i][j] ? "|" : " ");
        printf("%c\n", maze->hor_walls[i][MAZE_WIDTH-1] ? '_' : ' ');
    }
}

void generate_maze(struct Maze* maze) {
    srand(time(NULL));
    for (int i=0; i<MAZE_HEIGHT; i++)
        for (int j=0; j<MAZE_WIDTH-1; j++)
            maze->hor_walls[i][j] = true;

    for (int i=0; i<MAZE_HEIGHT-1; i++)
        for (int j=0; j<MAZE_WIDTH; j++)
            maze->ver_walls[i][j] = true;

    bool visited[MAZE_HEIGHT][MAZE_WIDTH] = {false};
    int i = 0, j = rand() % (MAZE_WIDTH-1);
    visited[i][j] = true;

    while (true) {
        bool made_move = false;

        // Check if we can move up
        if (i > 0 && !visited[i-1][j]) {
            maze->hor_walls[i-1][j] = false;
            visited[i-1][j] = true;
            i--;
            made_move = true;
        }

        // Check if we can move down
        else if (i < MAZE_HEIGHT-1 && !visited[i+1][j]) {
            maze->hor_walls[i][j] = false;
            visited[i+1][j] = true;
            i++;
            made_move = true;
        }

        // Check if we can move left
        else if (j > 0 && !visited[i][j-1]) {
            maze->ver_walls[i][j-1] = false;
            visited[i][j-1] = true;
            j--;
            made_move = true;
        }

        // Check if we can move right
        else if (j < MAZE_WIDTH-2 && !visited[i][j+1]) {
            maze->ver_walls[i][j] = false;
            visited[i][j+1] = true;
            j++;
            made_move = true;
        }

        // If we didn't make a move, we're stuck, break out of the loop
        if (!made_move)
            break;
    }
}

int main() {
    // Allocate memory for the maze
    struct Maze* maze = malloc(sizeof(struct Maze));
    
    // Generate the maze
    generate_maze(maze);
    
    // Print the maze
    print_maze(maze);
    
    // Free memory
    free(maze);
    
    return 0;
}