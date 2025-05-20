//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

void goto_xy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

int main() {
    system("clear");
    goto_xy(0, 0);

    // Map dimensions
    int map_width = 20;
    int map_height = 20;

    // Allocate memory for the map
    char **map = (char **)malloc(map_height * sizeof(char *) + map_width * sizeof(char));
    for (int i = 0; i < map_height; i++) {
        map[i] = (char *)malloc(map_width * sizeof(char));
    }

    // Initialize the map
    for (int y = 0; y < map_height; y++) {
        for (int x = 0; x < map_width; x++) {
            map[y][x] = '-';
        }
    }

    // Player position
    int player_x = 5;
    int player_y = 5;

    // Game loop
    while (1) {
        // Draw the map
        system("clear");
        goto_xy(0, 0);
        for (int y = 0; y < map_height; y++) {
            for (int x = 0; x < map_width; x++) {
                if (x == player_x && y == player_y) {
                    printf("P ");
                } else {
                    printf("%c ", map[y][x]);
                }
            }
            printf("\n");
        }

        // Get player input
        int input = getchar();

        // Move the player
        switch (input) {
            case 65:
                player_y--;
                break;
            case 68:
                player_x++;
                break;
            case 87:
                player_y++;
                break;
            case 83:
                player_x--;
                break;
            default:
                break;
        }

        // Check if the player has reached the edge of the map
        if (player_x < 0 || player_x >= map_width || player_y < 0 || player_y >= map_height) {
            break;
        }

        // Update the map
        map[player_y][player_x] = 'O';
    }

    // Free the memory
    for (int i = 0; i < map_height; i++) {
        free(map[i]);
    }
    free(map);

    return 0;
}