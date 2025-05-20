//LLAMA2-13B DATASET v1.0 Category: Terminal Based Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GALAXY_WIDTH 80
#define GALAXY_HEIGHT 25

// Structure to represent the galaxy
struct galaxy {
    int width;
    int height;
    char **map;
};

// Function to initialize the galaxy
void init_galaxy(struct galaxy *g) {
    g->width = GALAXY_WIDTH;
    g->height = GALAXY_HEIGHT;
    g->map = malloc(g->width * g->height * sizeof(char));
    for (int i = 0; i < g->width; i++) {
        for (int j = 0; j < g->height; j++) {
            g->map[i * g->width * sizeof(char) + j] = ' ';
        }
    }
}

// Function to print the galaxy
void print_galaxy(struct galaxy *g) {
    for (int i = 0; i < g->width; i++) {
        for (int j = 0; j < g->height; j++) {
            printf("%c", g->map[i * g->width * sizeof(char) + j]);
        }
        printf("\n");
    }
}

// Function to move the space explorer
void move_space_explorer(struct galaxy *g, int direction) {
    // Handle movement based on direction
    switch (direction) {
        case 'u':
            g->map[g->width * g->height - 1 - 1] = 'X';
            break;
        case 'd':
            g->map[g->width * g->height - 1] = 'X';
            break;
        case 'l':
            g->map[g->width * g->height - 2] = 'X';
            break;
        case 'r':
            g->map[g->width * g->height - 2] = 'X';
            break;
        default:
            printf("Invalid direction\n");
            return;
    }
    print_galaxy(g);
}

// Function to handle encounters
void handle_encounter(struct galaxy *g, char encounter) {
    // Handle encounters based on the current galaxy state
    switch (encounter) {
        case 'A':
            printf("You encounter an alien species!\n");
            break;
        case 'B':
            printf("You find a black hole that could potentially lead to the center of the galaxy.\n");
            break;
        case 'C':
            printf("You discover a hidden planet with a unique ecosystem.\n");
            break;
        default:
            printf("Invalid encounter\n");
            return;
    }
    print_galaxy(g);
}

// Function to handle player input
void handle_input(struct galaxy *g, char input) {
    // Handle player input based on the current galaxy state
    switch (input) {
        case 'u':
            move_space_explorer(g, 'u');
            break;
        case 'd':
            move_space_explorer(g, 'd');
            break;
        case 'l':
            move_space_explorer(g, 'l');
            break;
        case 'r':
            move_space_explorer(g, 'r');
            break;
        case 'q':
            printf("Goodbye, space explorer!\n");
            return;
    }
    print_galaxy(g);
}

int main() {
    // Initialize the galaxy
    struct galaxy g;
    init_galaxy(&g);

    // Print the initial galaxy state
    print_galaxy(&g);

    // Main game loop
    while (1) {
        // Handle player input
        char input = getchar();
        handle_input(&g, input);

        // Handle encounters
        char encounter = g.map[g.width * g.height - 1];
        handle_encounter(&g, encounter);
    }

    return 0;
}