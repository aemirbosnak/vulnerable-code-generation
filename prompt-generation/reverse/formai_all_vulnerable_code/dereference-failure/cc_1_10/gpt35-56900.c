//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

// function to generate a random number between min and max (inclusive)
int rand_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// function to generate a random character for the map
char rand_char() {
    int r = rand_int(0, 2);
    if (r == 0) {
        return '#';
    } else if (r == 1) {
        return '.';
    } else {
        return '@';
    }
}

// function to generate a new map
char** gen_map(int width, int height) {
    char** map = malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        map[i] = malloc(width * sizeof(char));
        for (int j = 0; j < width; j++) {
            map[i][j] = rand_char();
        }
    }
    return map;
}

// function to print the map
void print_map(char** map, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator

    char** map = gen_map(WIDTH, HEIGHT);

    printf("Generated map:\n");
    print_map(map, WIDTH, HEIGHT);

    // free memory
    for (int i = 0; i < HEIGHT; i++) {
        free(map[i]);
    }
    free(map);

    return 0;
}