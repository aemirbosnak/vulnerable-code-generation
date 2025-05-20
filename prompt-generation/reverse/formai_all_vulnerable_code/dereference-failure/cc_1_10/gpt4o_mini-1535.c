//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ALIVE 'O'
#define DEAD ' '

void initialize_grid(char **grid, int rows, int cols);
void print_grid(char **grid, int rows, int cols);
void update_grid(char **grid, char **new_grid, int rows, int cols);
int count_neighbors(char **grid, int row, int col, int rows, int cols);
void free_grid(char **grid, int rows);

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Allocate memory for the grid
    char **grid = malloc(rows * sizeof(char *));
    char **new_grid = malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        grid[i] = malloc(cols * sizeof(char));
        new_grid[i] = malloc(cols * sizeof(char));
    }

    // Initialize the grid with random values
    srand(time(NULL));
    initialize_grid(grid, rows, cols);
    
    char command;
    printf("Press 's' to start the simulation or 'q' to quit: ");
    while ((command = getchar()) != 's' && command != 'q');

    if (command == 'q') {
        free_grid(grid, rows);
        free_grid(new_grid, rows);
        return 0;
    }

    // Run the simulation
    while (1) {
        printf("\033[H\033[J"); // Clear the screen
        print_grid(grid, rows, cols);
        update_grid(grid, new_grid, rows, cols);
        
        // Swap grids
        char **temp = grid;
        grid = new_grid;
        new_grid = temp;

        usleep(200000); // Wait for 200 milliseconds
    }

    // Clean up
    free_grid(grid, rows);
    free_grid(new_grid, rows);

    return 0;
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
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int count_neighbors(char **grid, int row, int col, int rows, int cols) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int r = row + i;
            int c = col + j;
            if (r >= 0 && r < rows && c >= 0 && c < cols) {
                count += (grid[r][c] == ALIVE) ? 1 : 0;
            }
        }
    }
    return count;
}

void update_grid(char **grid, char **new_grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int alive_neighbors = count_neighbors(grid, i, j, rows, cols);
            if (grid[i][j] == ALIVE) {
                new_grid[i][j] = (alive_neighbors < 2 || alive_neighbors > 3) ? DEAD : ALIVE;
            } else {
                new_grid[i][j] = (alive_neighbors == 3) ? ALIVE : DEAD;
            }
        }
    }
}

void free_grid(char **grid, int rows) {
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}