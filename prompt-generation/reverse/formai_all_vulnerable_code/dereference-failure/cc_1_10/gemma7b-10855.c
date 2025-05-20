//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 10
#define MAX_HEIGHT 10

void draw_maze(int **maze, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            switch (maze[y][x])
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("#");
                    break;
                default:
                    printf("O");
                    break;
            }
        }
        printf("\n");
    }
}

int main()
{
    int **maze;
    int width, height;

    // Seed the random number generator
    srand(time(NULL));

    // Create the maze
    width = rand() % MAX_WIDTH + 1;
    height = rand() % MAX_HEIGHT + 1;
    maze = (int *)malloc(height * sizeof(int *) + height);
    for (int i = 0; i < height; i++)
    {
        maze[i] = (int *)malloc(width * sizeof(int) + width);
        for (int j = 0; j < width; j++)
        {
            maze[i][j] = rand() % 2;
        }
    }

    // Draw the maze
    draw_maze(maze, width, height);

    return 0;
}