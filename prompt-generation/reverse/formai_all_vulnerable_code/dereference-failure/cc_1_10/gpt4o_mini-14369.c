//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ALIVE 'O'
#define DEAD ' '

void initialize_grid(char **grid, int rows, int cols);
void print_grid(char **grid, int rows, int cols);
void update_grid(char **grid, int rows, int cols);
int count_neighbors(char **grid, int x, int y, int rows, int cols);
void free_grid(char **grid, int rows);
char **create_grid(int rows, int cols);

int main() {
    srand(time(NULL));
    
    int rows = 20;
    int cols = 40;
    
    char **grid = create_grid(rows, cols);
    
    initialize_grid(grid, rows, cols);
    
    while (1) {
        print_grid(grid, rows, cols);
        update_grid(grid, rows, cols);
        usleep(200000); // Sleep for 200ms to slow down the simulation
        printf("\033[H\033[J"); // Clear the terminal
    }
    
    free_grid(grid, rows);
    
    return 0;
}

char **create_grid(int rows, int cols) {
    char **grid = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        grid[i] = (char *)malloc(cols * sizeof(char));
    }
    return grid;
}

void initialize_grid(char **grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = (rand() % 2) ? ALIVE : DEAD;
        }
    }
}

void print_grid(char **grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == ALIVE) {
                printf("\033[32m%c\033[0m", ALIVE); // Print alive cells in green
            } else {
                printf("%c", DEAD); // Print dead cells
            }
        }
        printf("\n");
    }
}

void update_grid(char **grid, int rows, int cols) {
    char **new_grid = create_grid(rows, cols);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = count_neighbors(grid, i, j, rows, cols);
            if (grid[i][j] == ALIVE) {
                new_grid[i][j] = (neighbors == 2 || neighbors == 3) ? ALIVE : DEAD;
            } else {
                new_grid[i][j] = (neighbors == 3) ? ALIVE : DEAD;
            }
        }
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
    
    free_grid(new_grid, rows);
}

int count_neighbors(char **grid, int x, int y, int rows, int cols) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                if (grid[nx][ny] == ALIVE) {
                    count++;
                }
            }
        }
    }
    return count;
}

void free_grid(char **grid, int rows) {
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}