//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Server port
#define PORT 5000

// Maximum number of players
#define MAX_PLAYERS 10

// Player structure
typedef struct {
    int id;
    char name[32];
    int x;
    int y;
    int health;
} Player;

// Game state
typedef struct {
    Player players[MAX_PLAYERS];
    int num_players;
} GameState;

// Function to handle client connections
void* handle_client(void* arg) {
    int client_sock = *(int*)arg;
    free(arg);

    // Receive player name
    char name[32];
    recv(client_sock, name, sizeof(name), 0);

    // Add player to game state
    GameState* game_state = (GameState*)malloc(sizeof(GameState));
    game_state->players[game_state->num_players].id = game_state->num_players;
    strcpy(game_state->players[game_state->num_players].name, name);
    game_state->players[game_state->num_players].x = rand() % 1000;
    game_state->players[game_state->num_players].y = rand() % 1000;
    game_state->players[game_state->num_players].health = 100;
    game_state->num_players++;

    // Send game state to client
    send(client_sock, game_state, sizeof(GameState), 0);

    // Handle client input
    while (1) {
        // Receive player input
        char input[1024];
        recv(client_sock, input, sizeof(input), 0);

        // Parse input
        char* command = strtok(input, " ");

        if (strcmp(command, "move") == 0) {
            // Move player
            int dx = atoi(strtok(NULL, " "));
            int dy = atoi(strtok(NULL, " "));
            game_state->players[game_state->num_players].x += dx;
            game_state->players[game_state->num_players].y += dy;

            // Send game state to client
            send(client_sock, game_state, sizeof(GameState), 0);
        } else if (strcmp(command, "attack") == 0) {
            // Attack another player
            int target_id = atoi(strtok(NULL, " "));

            // Check if target player exists
            if (target_id >= 0 && target_id < game_state->num_players) {
                // Deal damage to target player
                game_state->players[target_id].health -= 10;

                // Send game state to client
                send(client_sock, game_state, sizeof(GameState), 0);
            }
        }
    }

    // Close client socket
    close(client_sock);
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Create server socket
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("socket");
        return 1;
    }

    // Set server socket options
    int opt = 1;
    setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Bind server socket to port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen for client connections
    if (listen(server_sock, 5) == -1) {
        perror("listen");
        return 1;
    }

    // Handle client connections
    while (1) {
        // Accept client connection
        int client_sock = accept(server_sock, NULL, NULL);
        if (client_sock == -1) {
            perror("accept");
            continue;
        }

        // Create thread to handle client connection
        pthread_t thread;
        int* arg = malloc(sizeof(int));
        *arg = client_sock;
        if (pthread_create(&thread, NULL, handle_client, arg) != 0) {
            perror("pthread_create");
            continue;
        }
    }

    // Close server socket
    close(server_sock);

    return 0;
}