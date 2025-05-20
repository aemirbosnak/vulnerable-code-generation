//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Function prototypes */
void generate_map(char** map, int width, int height);
void place_player(char** map, int width, int height, int* x, int* y);
void print_map(char** map, int width, int height);

int main()
{
    /* Set up the game */
    srand(time(NULL));
    int width = 20;
    int height = 10;
    int player_x, player_y;
    char** map = malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        map[i] = malloc(width * sizeof(char));
        memset(map[i], ' ', width);
    }
    
    /* Generate map and place player */
    generate_map(map, width, height);
    place_player(map, width, height, &player_x, &player_y);
    
    /* Game loop */
    int game_over = 0;
    while (!game_over) {
        print_map(map, width, height);
        /* Player movement code goes here */
    }
    
    /* Clean up memory */
    for (int i = 0; i < height; i++) {
        free(map[i]);
    }
    free(map);
    return 0;
}

/* Generate a random map with walls and floors */
void generate_map(char** map, int width, int height)
{
    /* Perlin noise generation code goes here */
}

/* Place the player in a random location */
void place_player(char** map, int width, int height, int* x, int* y)
{
    int done = 0;
    while (!done) {
        *x = rand() % width;
        *y = rand() % height;
        if (map[*y][*x] == ' ') {
            map[*y][*x] = '@';
            done = 1;
        }
    }
}

/* Print the map to the console */
void print_map(char** map, int width, int height)
{
    system("clear"); /* Clear console on Unix-based systems */
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}