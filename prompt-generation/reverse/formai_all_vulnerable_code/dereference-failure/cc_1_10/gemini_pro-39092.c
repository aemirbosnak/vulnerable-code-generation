//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>

#define PORT 5000
#define BUFFER_SIZE 1024

// Player struct
typedef struct {
    int id;
    char name[32];
    int score;
    int ping;
} Player;

// Game state struct
typedef struct {
    int num_players;
    Player players[4];
    int current_player;
} GameState;

// Function to send a message to all players
void send_message_to_all(int sockfd, GameState *game_state, char *message) {
    for (int i = 0; i < game_state->num_players; i++) {
        if (i != game_state->current_player) {
            send(sockfd, message, strlen(message), 0);
        }
    }
}

// Function to handle a new player connecting
void handle_new_player(int sockfd, GameState *game_state) {
    // Receive the player's name
    char name[32];
    recv(sockfd, name, sizeof(name), 0);

    // Add the player to the game state
    game_state->players[game_state->num_players].id = game_state->num_players;
    strcpy(game_state->players[game_state->num_players].name, name);
    game_state->players[game_state->num_players].score = 0;
    game_state->players[game_state->num_players].ping = 0;

    // Send a welcome message to the player
    char message[BUFFER_SIZE];
    sprintf(message, "Welcome to the game, %s!", name);
    send(sockfd, message, strlen(message), 0);

    // Send the game state to the player
    send(sockfd, game_state, sizeof(GameState), 0);

    // Increment the number of players
    game_state->num_players++;
}

// Function to handle a player disconnecting
void handle_player_disconnect(int sockfd, GameState *game_state) {
    // Find the player's index
    int index = -1;
    for (int i = 0; i < game_state->num_players; i++) {
        if (game_state->players[i].id == sockfd) {
            index = i;
            break;
        }
    }

    // If the player was found, remove them from the game state
    if (index != -1) {
        for (int i = index; i < game_state->num_players - 1; i++) {
            game_state->players[i] = game_state->players[i + 1];
        }

        game_state->num_players--;
    }

    // Send a message to all players that the player has disconnected
    char message[BUFFER_SIZE];
    sprintf(message, "%s has disconnected from the game.", game_state->players[index].name);
    send_message_to_all(sockfd, game_state, message);
}

// Function to handle a player's move
void handle_player_move(int sockfd, GameState *game_state) {
    // Receive the player's move
    int move;
    recv(sockfd, &move, sizeof(int), 0);

    // Update the game state
    game_state->players[game_state->current_player].score += move;

    // Send the game state to all players
    send_message_to_all(sockfd, game_state, "Game state updated.");
}

// Function to handle a player's ping
void handle_player_ping(int sockfd, GameState *game_state) {
    // Receive the player's ping
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    recv(sockfd, &start_time, sizeof(struct timeval), 0);
    gettimeofday(&end_time, NULL);

    // Calculate the player's ping
    int ping = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000;

    // Update the game state
    game_state->players[game_state->current_player].ping = ping;

    // Send the player their ping
    send(sockfd, &ping, sizeof(int), 0);
}

// Main function
int main() {
    // Initialize the game state
    GameState game_state;
    game_state.num_players = 0;
    game_state.current_player = 0;

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set the socket to be reusable
    int reuseaddr = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(int)) < 0) {
        perror("Error setting socket to be reusable");
        exit(1);
    }

    // Bind the socket to the port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("Error binding socket to port");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    // Main game loop
    while (1) {
        // Accept incoming connections
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_sockfd < 0) {
            perror("Error accepting incoming connection");
            continue;
        }

        // Handle the new player
        handle_new_player(client_sockfd, &game_state);

        // Main game loop for the new player
        while (1) {
            // Receive a message from the player
            char buffer[BUFFER_SIZE];
            int n = recv(client_sockfd, buffer, BUFFER_SIZE, 0);
            if (n < 0) {
                perror("Error receiving message from player");
                break;
            } else if (n == 0) {
                // The player has disconnected
                handle_player_disconnect(client_sockfd, &game_state);
                break;
            }

            // Parse the message
            char *command = strtok(buffer, " ");
            if (strcmp(command, "move") == 0) {
                // Handle the player's move
                handle_player_move(client_sockfd, &game_state);
            } else if (strcmp(command, "ping") == 0) {
                // Handle the player's ping
                handle_player_ping(client_sockfd, &game_state);
            }
        }

        // Close the player's socket
        close(client_sockfd);
    }

    // Close the server socket
    close(sockfd);

    return 0;
}