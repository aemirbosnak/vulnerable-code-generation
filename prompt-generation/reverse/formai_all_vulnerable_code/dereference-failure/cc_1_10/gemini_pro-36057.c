//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Define the maximum number of players
#define MAX_PLAYERS 10

// Define the maximum size of a message
#define MAX_MESSAGE_SIZE 1024

// Define the port number for the server
#define PORT 5555

// Define the structure of a player
typedef struct {
    int socket;
    char name[32];
    int x;
    int y;
    int health;
} player_t;

// Define the structure of a game
typedef struct {
    player_t players[MAX_PLAYERS];
    int num_players;
} game_t;

// Create a new game
game_t *create_game() {
    game_t *game = malloc(sizeof(game_t));
    game->num_players = 0;
    return game;
}

// Add a player to the game
void add_player(game_t *game, player_t *player) {
    // Check if the game is full
    if (game->num_players >= MAX_PLAYERS) {
        return;
    }

    // Add the player to the game
    game->players[game->num_players] = *player;
    game->num_players++;
}

// Remove a player from the game
void remove_player(game_t *game, player_t *player) {
    // Find the player in the game
    int i;
    for (i = 0; i < game->num_players; i++) {
        if (strcmp(game->players[i].name, player->name) == 0) {
            break;
        }
    }

    // If the player was found, remove them from the game
    if (i < game->num_players) {
        for (i = i + 1; i < game->num_players; i++) {
            game->players[i-1] = game->players[i];
        }
        game->num_players--;
    }
}

// Send a message to all players in the game
void send_message_to_all(game_t *game, char *message) {
    // Loop through all players in the game
    for (int i = 0; i < game->num_players; i++) {
        // Send the message to the player
        send(game->players[i].socket, message, strlen(message), 0);
    }
}

// Handle a message from a player
void handle_message(game_t *game, player_t *player, char *message) {
    // Parse the message
    char *command = strtok(message, " ");
    char *args = strtok(NULL, "\n");

    // Handle the command
    if (strcmp(command, "move") == 0) {
        // Parse the move command
        int x = atoi(strtok(args, " "));
        int y = atoi(strtok(NULL, "\n"));

        // Move the player
        player->x = x;
        player->y = y;

        // Send the move command to all players
        char message[MAX_MESSAGE_SIZE];
        sprintf(message, "move %s %d %d\n", player->name, player->x, player->y);
        send_message_to_all(game, message);
    } else if (strcmp(command, "attack") == 0) {
        // Parse the attack command
        char *target = strtok(args, " ");

        // Find the target player
        player_t *target_player = NULL;
        for (int i = 0; i < game->num_players; i++) {
            if (strcmp(game->players[i].name, target) == 0) {
                target_player = &game->players[i];
                break;
            }
        }

        // If the target player was found, attack them
        if (target_player) {
            target_player->health -= 10;

            // Send the attack command to all players
            char message[MAX_MESSAGE_SIZE];
            sprintf(message, "attack %s %d\n", player->name, target_player->health);
            send_message_to_all(game, message);
        }
    }
}

// Main function
int main() {
    // Create a new game
    game_t *game = create_game();

    // Create a server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Bind the server socket to the port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Listen for incoming connections
    listen(server_socket, 10);

    // Main game loop
    while (1) {
        // Accept incoming connections
        struct sockaddr_in client_addr;
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));

        // Create a new player
        player_t player;
        player.socket = client_socket;
        player.name[0] = '\0';
        player.x = 0;
        player.y = 0;
        player.health = 100;

        // Add the player to the game
        add_player(game, &player);

        // Send the player their name
        char message[MAX_MESSAGE_SIZE];
        sprintf(message, "name %s\n", player.name);
        send(player.socket, message, strlen(message), 0);

        // Send the player the list of players
        for (int i = 0; i < game->num_players; i++) {
            sprintf(message, "player %s %d %d %d\n", game->players[i].name, game->players[i].x, game->players[i].y, game->players[i].health);
            send(player.socket, message, strlen(message), 0);
        }

        // Handle messages from the player
        while (1) {
            // Receive a message from the player
            char message[MAX_MESSAGE_SIZE];
            int bytes_received = recv(player.socket, message, MAX_MESSAGE_SIZE, 0);

            // If the player has disconnected, remove them from the game
            if (bytes_received == 0) {
                remove_player(game, &player);
                break;
            }

            // Handle the message
            handle_message(game, &player, message);
        }
    }

    // Close the server socket
    close(server_socket);

    // Free the game
    free(game);

    return 0;
}