//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to handle the player's movement
void move_player(char **map, int *player_x, int *player_y, int map_size) {
    // Store the player's current location
    int x = *player_x, y = *player_y;
    // Get user input for movement direction
    char dir;
    printf("Enter direction (w/a/s/d): ");
    scanf(" %c", &dir);
    switch (dir) {
        case 'w':
            // Move up
            if (x-1 >= 0 && map[x-1][y] != '#') {
                map[x][y] = ' ';
                *player_x = x-1;
            }
            break;
        case 'a':
            // Move left
            if (y-1 >= 0 && map[x][y-1] != '#') {
                map[x][y] = ' ';
                *player_y = y-1;
            }
            break;
        case 's':
            // Move down
            if (x+1 < map_size && map[x+1][y] != '#') {
                map[x][y] = ' ';
                *player_x = x+1;
            }
            break;
        case 'd':
            // Move right
            if (y+1 < map_size && map[x][y+1] != '#') {
                map[x][y] = ' ';
                *player_y = y+1;
            }
            break;
    }
    // Update player location on map
    map[*player_x][*player_y] = 'P';
}

// Function to print the game map
void print_map(char **map, int map_size) {
    printf("\n");
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Recursive function for the game loop
void game_loop(char **map, int *player_x, int *player_y, int map_size) {
    // Check if player has reached the goal
    if (map[*player_x][*player_y] == 'G') {
        printf("Congratulations, you have reached the goal!\n");
        return;
    }
    // Print the game map and handle player movement
    print_map(map, map_size);
    move_player(map, player_x, player_y, map_size);
    // Recurse to continue game loop
    game_loop(map, player_x, player_y, map_size);
}

int main(void) {
    // Define game map and player variables
    int map_size = 5;
    char **map = (char**) malloc(map_size * sizeof(char*));
    for (int i = 0; i < map_size; i++) {
        map[i] = (char*) malloc(map_size * sizeof(char));
    }
    int player_x = 2, player_y = 2;
    // Generate random game map
    srand(42);
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            if (i == 0 || i == map_size-1 || j == 0 || j == map_size-1) {
                map[i][j] = '#';
            } else if (rand() % 10 < 5) {
                map[i][j] = '#';
            } else {
                map[i][j] = ' ';
            }
        }
    }
    // Set player and goal locations on map
    map[player_x][player_y] = 'P';
    map[map_size-2][map_size-2] = 'G';
    // Start the game loop
    game_loop(map, &player_x, &player_y, map_size);
    // Free allocated memory
    for (int i = 0; i < map_size; i++) {
        free(map[i]);
    }
    free(map);
    return 0;
}