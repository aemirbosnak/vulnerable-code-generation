//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ALIVE 'O'
#define DEAD ' '

void initialize_grid(char **grid, int rows, int cols);
void display_grid(char **grid, int rows, int cols);
void update_grid(char **current, char **next, int rows, int cols);
int count_neighbors(char **grid, int x, int y, int rows, int cols);

int main() {
    int rows, cols, generations;

    printf("Enter grid size (rows cols): ");
    scanf("%d %d", &rows, &cols);
    printf("Enter number of generations: ");
    scanf("%d", &generations);

    // Allocate memory for current and next grids
    char **current = malloc(rows * sizeof(char *));
    char **next = malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        current[i] = malloc(cols * sizeof(char));
        next[i] = malloc(cols * sizeof(char));
    }

    initialize_grid(current, rows, cols);
    
    // User can set initial state
    printf("Enter initial state (row col) to toggle, input '-1 -1' to finish:\n");
    int r, c;
    while (1) {
        scanf("%d %d", &r, &c);
        if (r == -1 && c == -1) break;
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            current[r][c] = (current[r][c] == ALIVE) ? DEAD : ALIVE;
        } else {
            printf("Invalid coordinates. Try again.\n");
        }
    }

    printf("Starting simulation...\n");
    for (int gen = 0; gen < generations; gen++) {
        display_grid(current, rows, cols);
        update_grid(current, next, rows, cols);
        
        // Swap grids
        char **temp = current;
        current = next;
        next = temp;

        sleep(1); // Pause between generations
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(current[i]);
        free(next[i]);
    }
    free(current);
    free(next);

    return 0;
}

void initialize_grid(char **grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = DEAD;
        }
    }
}

void display_grid(char **grid, int rows, int cols) {
    system("clear");  // Clear the terminal (works in Linux)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void update_grid(char **current, char **next, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int alive_neighbors = count_neighbors(current, i, j, rows, cols);
            if (current[i][j] == ALIVE) {
                next[i][j] = (alive_neighbors < 2 || alive_neighbors > 3) ? DEAD : ALIVE;
            } else {
                next[i][j] = (alive_neighbors == 3) ? ALIVE : DEAD;
            }
        }
    }
}

int count_neighbors(char **grid, int x, int y, int rows, int cols) {
    int count = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int newX = x + i;
            int newY = y + j;

            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                if (grid[newX][newY] == ALIVE) {
                    count++;
                }
            }
        }
    }
    return count;
}