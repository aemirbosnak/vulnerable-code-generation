//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Haunted House Simulator
//
// This program simulates a haunted house. The user must navigate through the house, avoiding ghosts and other hazards. If the user reaches the end of the house, they win.

// The house is represented by a 2D array of characters. Each character represents a different type of space in the house.
// The possible values are:
//
//   ' ': Empty space
//   '#': Wall
//   'G': Ghost
//   'S': Starting point
//   'E': Ending point
//
// The user is represented by the character '@'.

// The user has the following controls:
//
//   'w': Move up
//   's': Move down
//   'a': Move left
//   'd': Move right

// The following function generates a random haunted house.
char** generate_house(int width, int height) {
    // Allocate memory for the house.
    char** house = malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        house[i] = malloc(width * sizeof(char));
    }

    // Initialize the house with empty spaces.
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            house[i][j] = ' ';
        }
    }

    // Create walls around the house.
    for (int i = 0; i < height; i++) {
        house[i][0] = '#';
        house[i][width - 1] = '#';
    }
    for (int j = 0; j < width; j++) {
        house[0][j] = '#';
        house[height - 1][j] = '#';
    }

    // Place the starting point in the house.
    int start_x = rand() % (width - 2) + 1;
    int start_y = rand() % (height - 2) + 1;
    house[start_y][start_x] = 'S';

    // Place the ending point in the house.
    int end_x = rand() % (width - 2) + 1;
    int end_y = rand() % (height - 2) + 1;
    house[end_y][end_x] = 'E';

    // Place ghosts in the house.
    int num_ghosts = rand() % 5 + 1;
    for (int i = 0; i < num_ghosts; i++) {
        int ghost_x = rand() % (width - 2) + 1;
        int ghost_y = rand() % (height - 2) + 1;
        house[ghost_y][ghost_x] = 'G';
    }

    // Return the house.
    return house;
}

// The following function prints the house to the console.
void print_house(char** house, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", house[i][j]);
        }
        printf("\n");
    }
}

// The following function moves the user through the house.
void move_user(char** house, int width, int height, int* x, int* y) {
    // Get the user's input.
    char input = getchar();

    // Move the user based on the input.
    switch (input) {
        case 'w':
            if (*y > 0 && house[*y - 1][*x] != '#') {
                (*y)--;
            }
            break;
        case 's':
            if (*y < height - 1 && house[*y + 1][*x] != '#') {
                (*y)++;
            }
            break;
        case 'a':
            if (*x > 0 && house[*y][*x - 1] != '#') {
                (*x)--;
            }
            break;
        case 'd':
            if (*x < width - 1 && house[*y][*x + 1] != '#') {
                (*x)++;
            }
            break;
    }
}

// The following function checks if the user has won the game.
int check_win(char** house, int width, int height, int x, int y) {
    // Check if the user is at the ending point.
    if (house[y][x] == 'E') {
        return 1;
    } else {
        return 0;
    }
}

// The following function checks if the user has lost the game.
int check_lose(char** house, int width, int height, int x, int y) {
    // Check if the user is at a ghost.
    if (house[y][x] == 'G') {
        return 1;
    } else {
        return 0;
    }
}

// The following function plays the game.
void play_game(char** house, int width, int height) {
    // Initialize the user's position.
    int x = 1;
    int y = 1;

    // Play the game until the user wins or loses.
    while (!check_win(house, width, height, x, y) && !check_lose(house, width, height, x, y)) {
        // Print the house.
        print_house(house, width, height);

        // Move the user.
        move_user(house, width, height, &x, &y);
    }

    // Print the final message.
    if (check_win(house, width, height, x, y)) {
        printf("You win!\n");
    } else if (check_lose(house, width, height, x, y)) {
        printf("You lose!\n");
    }
}

// The main function.
int main() {
    //srand(time(NULL));
    int width=20;
    int height=20;
    char** house = generate_house(width, height);
    // Play the game.
    play_game(house, width, height);

    // Free the memory allocated for the house.
    for (int i = 0; i < height; i++) {
        free(house[i]);
    }
    free(house);

    return 0;
}