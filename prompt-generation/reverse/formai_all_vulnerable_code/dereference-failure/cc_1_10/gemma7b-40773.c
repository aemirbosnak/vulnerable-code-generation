//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

#define EMPTY 0
#define WALL 1
#define START 2
#define END 3

void draw_maze(int **maze, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            switch (maze[i][j])
            {
                case EMPTY:
                    printf(" ");
                    break;
                case WALL:
                    printf("#");
                    break;
                case START:
                    printf("S");
                    break;
                case END:
                    printf("E");
                    break;
            }
        }
        printf("\n");
    }
}

int main()
{
    int **maze;
    maze = (int**)malloc(MAZE_HEIGHT * sizeof(int*));
    for (int i = 0; i < MAZE_HEIGHT; i++)
    {
        maze[i] = (int*)malloc(MAZE_WIDTH * sizeof(int));
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate the maze
    for (int i = 0; i < MAZE_HEIGHT; i++)
    {
        for (int j = 0; j < MAZE_WIDTH; j++)
        {
            maze[i][j] = EMPTY;
        }
    }

    // Create the walls
    maze[2][3] = WALL;
    maze[2][4] = WALL;
    maze[3][4] = WALL;
    maze[4][4] = WALL;
    maze[4][3] = WALL;

    // Place the start and end points
    maze[0][0] = START;
    maze[9][9] = END;

    // Draw the maze
    draw_maze(maze, MAZE_WIDTH, MAZE_HEIGHT);

    free(maze);

    return 0;
}