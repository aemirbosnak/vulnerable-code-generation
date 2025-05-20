//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define HAUNTED_HOUSE_WIDTH 25
#define HAUNTED_HOUSE_HEIGHT 10

typedef struct {
    char symbol;
    int color;
} cell;

void print_haunted_house(cell **grid) {
    for (int i = 0; i < HAUNTED_HOUSE_HEIGHT; i++) {
        for (int j = 0; j < HAUNTED_HOUSE_WIDTH; j++) {
            printf("%c", grid[i][j].symbol);
            if (grid[i][j].color > 0)
                printf("\033[%dm", grid[i][j].color);
        }
        printf("\n");
    }
}

void generate_random_cell(cell **grid, int x, int y) {
    int rand_symbol = rand() % 4 + 'A';
    int rand_color = rand() % 8 + 30;

    grid[y][x].symbol = rand_symbol;
    grid[y][x].color = rand_color;
}

void populate_haunted_house(cell **grid) {
    for (int i = 0; i < HAUNTED_HOUSE_HEIGHT; i++) {
        for (int j = 0; j < HAUNTED_HOUSE_WIDTH; j++) {
            if (i % 2 == 0 || j % 2 == 0)
                generate_random_cell(grid, j, i);
            else
                grid[i][j].symbol = ' ';
        }
    }
}

void print_welcome_message() {
    printf("\033[2J"); // clear the terminal
    printf("\033[%d;%dH", 1, 1); // go to the top left corner
    printf("*********************************************\n");
    printf("* Welcome to the Haunted House Simulator! *\n");
    printf("*********************************************\n");
    printf("\n");
}

int main() {
    srand(time(NULL));

    cell **grid = malloc(HAUNTED_HOUSE_HEIGHT * sizeof(cell *));
    for (int i = 0; i < HAUNTED_HOUSE_HEIGHT; i++)
        grid[i] = malloc(HAUNTED_HOUSE_WIDTH * sizeof(cell));

    print_welcome_message();
    populate_haunted_house(grid);
    print_haunted_house(grid);

    free(grid);

    return 0;
}