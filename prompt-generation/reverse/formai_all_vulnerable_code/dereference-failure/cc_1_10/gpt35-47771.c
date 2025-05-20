//FormAI DATASET v1.0 Category: Game of Life ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20  // Size of the grid
#define STEPS 10  // Number of steps to simulate

// Calculates number of live neighbors for a given cell
int count_n(int **grid, int x, int y)
{
    int i, j, cnt = 0;

    for(i = x-1; i <= x+1; i++)
        for(j = y-1; j <= y+1; j++)
            if(i >= 0 && i < SIZE && j >= 0 && j < SIZE && grid[i][j])
                cnt++;
    
    if(grid[x][y]) cnt--;  // Exclude self if cell is alive
    return cnt;
}

// Simulates one step of the Game of Life
void run_step(int **grid)
{
    int i, j, cnt;
    int **new_grid = malloc(SIZE * sizeof(int*));

    for(i = 0; i < SIZE; i++)
        new_grid[i] = malloc(SIZE * sizeof(int));

    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            cnt = count_n(grid, i, j);
            if(grid[i][j]) {
                if (cnt < 2 || cnt > 3) new_grid[i][j] = 0;  // Die
                else new_grid[i][j] = 1;
            } else {
                if (cnt == 3) new_grid[i][j] = 1;  // Become alive
                else new_grid[i][j] = 0;
            }
        }
    }

    for(i = 0; i < SIZE; i++)
        for(j = 0; j < SIZE; j++)
            grid[i][j] = new_grid[i][j];

    for (i = 0; i < SIZE; i++)
        free(new_grid[i]);
    free(new_grid);
}

// Prints out the current grid
void print_grid(int **grid)
{
    int i, j;

    printf("\033[H\033[J");
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++)
            if(grid[i][j]) printf("#");
            else printf(".");
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    int i, j;
    int **grid = malloc(SIZE * sizeof(int*));

    srand(time(NULL));
    for(i = 0; i < SIZE; i++) {
        grid[i] = malloc(SIZE * sizeof(int));
        for(j = 0; j < SIZE; j++)
            grid[i][j] = rand() % 2;
    }

    for(i = 0; i < STEPS; i++) {
        print_grid(grid);
        run_step(grid);
        usleep(200000);  // Delay for visibility
    }

    for(i = 0; i < SIZE; i++)
        free(grid[i]);
    free(grid);
    return 0;
}