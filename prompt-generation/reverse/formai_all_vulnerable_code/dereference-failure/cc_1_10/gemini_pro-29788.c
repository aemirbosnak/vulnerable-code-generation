//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_PLAYERS 10
#define MAX_MESSAGE_LENGTH 1024

// Define the player struct
typedef struct player {
    int socket;
    char username[32];
    char message[MAX_MESSAGE_LENGTH];
} player_t;

// Define the game struct
typedef struct game {
    int num_players;
    player_t players[MAX_PLAYERS];
} game_t;

// Create a new game
game_t* new_game() {
    game_t* game = malloc(sizeof(game_t));
    game->num_players = 0;
    return game;
}

// Add a player to the game
void add_player(game_t* game, int socket, char* username) {
    if (game->num_players >= MAX_PLAYERS) {
        printf("Error: Maximum number of players reached.\n");
        return;
    }

    // Create a new player
    player_t* player = malloc(sizeof(player_t));
    player->socket = socket;
    strcpy(player->username, username);

    // Add the player to the game
    game->players[game->num_players++] = *player;
}

// Remove a player from the game
void remove_player(game_t* game, int socket) {
    // Find the player to remove
    for (int i = 0; i < game->num_players; i++) {
        if (game->players[i].socket == socket) {
            // Remove the player from the game
            game->players[i] = game->players[game->num_players - 1];
            game->num_players--;
            return;
        }
    }
}

// Send a message to all players
void send_message(game_t* game, char* message) {
    for (int i = 0; i < game->num_players; i++) {
        send(game->players[i].socket, message, strlen(message), 0);
    }
}

// Receive a message from a player
void receive_message(game_t* game, int socket, char* message) {
    // Find the player who sent the message
    for (int i = 0; i < game->num_players; i++) {
        if (game->players[i].socket == socket) {
            // Copy the message into the player's message buffer
            strcpy(game->players[i].message, message);
            return;
        }
    }
}

// Main game loop
void game_loop(game_t* game) {
    // Main game loop
    while (true) {
        // Check for new connections
        fd_set read_fds;
        FD_ZERO(&read_fds);
        for (int i = 0; i < game->num_players; i++) {
            FD_SET(game->players[i].socket, &read_fds);
        }

        int max_fd = 0;
        for (int i = 0; i < game->num_players; i++) {
            if (game->players[i].socket > max_fd) {
                max_fd = game->players[i].socket;
            }
        }

        int num_ready = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
        if (num_ready < 0) {
            perror("Error: select()");
            return;
        }

        // Handle new connections
        for (int i = 0; i < game->num_players; i++) {
            if (FD_ISSET(game->players[i].socket, &read_fds)) {
                // Receive the message from the player
                char message[MAX_MESSAGE_LENGTH];
                int num_bytes = recv(game->players[i].socket, message, MAX_MESSAGE_LENGTH, 0);
                if (num_bytes <= 0) {
                    // The player has disconnected
                    remove_player(game, game->players[i].socket);
                    continue;
                }

                // Process the message
                receive_message(game, game->players[i].socket, message);

                // Send the message to all other players
                send_message(game, message);
            }
        }
    }
}

// Main function
int main(int argc, char** argv) {
    // Create a new game
    game_t* game = new_game();

    // Start the game loop
    game_loop(game);

    // Free the game
    free(game);

    return 0;
}