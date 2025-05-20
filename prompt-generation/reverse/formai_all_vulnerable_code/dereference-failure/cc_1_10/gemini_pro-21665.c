//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define GRID_SIZE 4
#define NUM_PAIRS GRID_SIZE * GRID_SIZE / 2

typedef struct {
    int row, col;
} Coord;

typedef struct {
    int value;
    Coord *coords;
} Pair;

Pair *pairs;
Coord *grid;
int *revealed;

void init_game() {
    srand(time(NULL));

    pairs = malloc(sizeof(Pair) * NUM_PAIRS);
    grid = malloc(sizeof(Coord) * GRID_SIZE * GRID_SIZE);
    revealed = malloc(sizeof(int) * GRID_SIZE * GRID_SIZE);

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i * GRID_SIZE + j].row = i;
            grid[i * GRID_SIZE + j].col = j;
            revealed[i * GRID_SIZE + j] = 0;
        }
    }

    for (int i = 0; i < NUM_PAIRS; i++) {
        pairs[i].value = i + 1;
        pairs[i].coords = malloc(sizeof(Coord) * 2);
        int row1, col1, row2, col2;
        do {
            row1 = rand() % GRID_SIZE;
            col1 = rand() % GRID_SIZE;
            row2 = rand() % GRID_SIZE;
            col2 = rand() % GRID_SIZE;
        } while (row1 == row2 && col1 == col2);
        pairs[i].coords[0].row = row1;
        pairs[i].coords[0].col = col1;
        pairs[i].coords[1].row = row2;
        pairs[i].coords[1].col = col2;
    }
}

void print_grid() {
    printf("\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (revealed[i * GRID_SIZE + j]) {
                printf("%d ", pairs[grid[i * GRID_SIZE + j].row * GRID_SIZE + grid[i * GRID_SIZE + j].col].value);
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    init_game();

    int running = 1;
    int first_row, first_col, second_row, second_col;
    int first_revealed = 0, second_revealed = 0;

    while (running) {
        print_grid();

        printf("Enter the row and column of the first card to flip: ");
        scanf("%d %d", &first_row, &first_col);
        first_row--;
        first_col--;
        if (first_row < 0 || first_row >= GRID_SIZE || first_col < 0 || first_col >= GRID_SIZE) {
            printf("Invalid coordinates. Please try again.\n");
            continue;
        }
        if (revealed[first_row * GRID_SIZE + first_col]) {
            printf("That card has already been flipped. Please try again.\n");
            continue;
        }

        printf("Enter the row and column of the second card to flip: ");
        scanf("%d %d", &second_row, &second_col);
        second_row--;
        second_col--;
        if (second_row < 0 || second_row >= GRID_SIZE || second_col < 0 || second_col >= GRID_SIZE) {
            printf("Invalid coordinates. Please try again.\n");
            continue;
        }
        if (revealed[second_row * GRID_SIZE + second_col]) {
            printf("That card has already been flipped. Please try again.\n");
            continue;
        }

        revealed[first_row * GRID_SIZE + first_col] = 1;
        revealed[second_row * GRID_SIZE + second_col] = 1;

        int first_value = pairs[grid[first_row * GRID_SIZE + first_col].row * GRID_SIZE + grid[first_row * GRID_SIZE + first_col].col].value;
        int second_value = pairs[grid[second_row * GRID_SIZE + second_col].row * GRID_SIZE + grid[second_row * GRID_SIZE + second_col].col].value;

        if (first_value == second_value) {
            printf("Match! You have %d pairs left.\n", NUM_PAIRS - (first_revealed + second_revealed + 1) / 2);
            first_revealed++;
            second_revealed++;
        } else {
            printf("No match. Try again.\n");
            revealed[first_row * GRID_SIZE + first_col] = 0;
            revealed[second_row * GRID_SIZE + second_col] = 0;
        }

        if (first_revealed + second_revealed == NUM_PAIRS) {
            running = 0;
            printf("Congratulations! You have won the game.\n");
        }
    }

    return 0;
}