//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    SHAPE_HUMAN,
    SHAPE_WOLF,
    SHAPE_BAT
} Shape;

struct Player {
    char *name;
    int health;
    Shape shape;
};

void createPlayer(struct Player *player, char *name) {
    player->name = strdup(name);
    player->health = 100;
    player->shape = SHAPE_HUMAN;
}

void freePlayer(struct Player *player) {
    free(player->name);
}

void printPlayerStatus(struct Player *player) {
    printf("Name: %s\n", player->name);
    printf("Health: %d\n", player->health);
    switch (player->shape) {
        case SHAPE_HUMAN:
            printf("Shape: Human\n");
            break;
        case SHAPE_WOLF:
            printf("Shape: Wolf\n");
            break;
        case SHAPE_BAT:
            printf("Shape: Bat\n");
            break;
    }
}

int main() {
    struct Player player;
    char input[256];

    // Create the player character
    createPlayer(&player, "John");

    // Game loop
    while (1) {
        // Print the player's status
        printPlayerStatus(&player);

        // Get the player's input
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Parse the player's input
        char *command = strtok(input, " ");
        char *argument = strtok(NULL, " ");

        // Handle the player's commands
        if (strcmp(command, "quit") == 0) {
            break;
        } else if (strcmp(command, "transform") == 0) {
            if (strcmp(argument, "wolf") == 0) {
                player.shape = SHAPE_WOLF;
            } else if (strcmp(argument, "bat") == 0) {
                player.shape = SHAPE_BAT;
            }
        } else if (strcmp(command, "attack") == 0) {
            // Handle the player's attack
        } else {
            printf("Unknown command '%s'\n", command);
        }
    }

    // Free the player's resources
    freePlayer(&player);

    return 0;
}