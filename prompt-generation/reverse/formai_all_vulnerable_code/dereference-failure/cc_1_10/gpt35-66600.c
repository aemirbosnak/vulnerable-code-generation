//FormAI DATASET v1.0 Category: Game of Life ; Style: Linus Torvalds
/* The Game of Life
 *
 * Copyright (C) 2021 Linus Torvalds
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

/* Returns the number of neighboring cells that are alive */
int count_neighbors(int x, int y, int *world)
{
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int xpos = (x + i + WIDTH) % WIDTH;
            int ypos = (y + j + HEIGHT) % HEIGHT;
            if (i == 0 && j == 0) continue;
            count += world[xpos + ypos * WIDTH];
        }
    }
    return count;
}

/* Runs one iteration of the Game of Life */
void iterate(int *world)
{
    int *newworld = (int *)malloc(WIDTH * HEIGHT * sizeof(int));
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int neighbors = count_neighbors(x, y, world);
            if (world[x + y * WIDTH]) {
                /* Any live cell with fewer than two live neighbors dies */
                if (neighbors < 2) newworld[x + y * WIDTH] = 0;
                /* Any live cell with two or three live neighbors lives */
                else if (neighbors == 2 || neighbors == 3) newworld[x + y * WIDTH] = 1;
                /* Any live cell with more than three live neighbors dies */
                else if (neighbors > 3) newworld[x + y * WIDTH] = 0;
            } else {
                /* Any dead cell with three live neighbors becomes a live cell */
                if (neighbors == 3) newworld[x + y * WIDTH] = 1;
            }
        }
    }
    for (int i = 0; i < WIDTH * HEIGHT; i++)
        world[i] = newworld[i];
    free(newworld);
}

/* Prints out the world */
void print_world(int *world)
{
    printf("\033[H");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++)
            printf("%c", world[x + y * WIDTH] ? '*' : '.');
        printf("\n");
    }
    fflush(stdout);
}

int main(void)
{
    int *world = (int *)calloc(WIDTH * HEIGHT, sizeof(int));

    /* Initialize the world with random cells */
    srand(time(NULL));
    for (int i = 0; i < WIDTH * HEIGHT; i++)
        world[i] = (rand() % 2);

    while (1) {
        print_world(world);
        iterate(world);
        usleep(50000);
    }

    free(world);
    return 0;
}