//GEMINI-pro DATASET v1.0 Category: Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 4444
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Client structure
typedef struct {
    int socket;
    char name[32];
    int score;
} Client;

// Game state
typedef struct {
    int num_clients;
    Client clients[MAX_CLIENTS];
    int current_player;
    char word[32];
    int word_length;
    int guesses_left;
    int game_over;
} GameState;

// Mutex for protecting game state
pthread_mutex_t game_state_mutex = PTHREAD_MUTEX_INITIALIZER;

// Client thread function
void *client_thread(void *arg) {
    int socket = *(int *)arg;
    free(arg);
    
    // Receive client name
    char name[32];
    recv(socket, name, sizeof(name), 0);

    // Lock game state
    pthread_mutex_lock(&game_state_mutex);

    // Add client to game state
    GameState *game_state = (GameState *)malloc(sizeof(GameState));
    game_state->num_clients++;
    game_state->clients[game_state->num_clients - 1].socket = socket;
    strcpy(game_state->clients[game_state->num_clients - 1].name, name);
    game_state->clients[game_state->num_clients - 1].score = 0;

    // Unlock game state
    pthread_mutex_unlock(&game_state_mutex);

    // Send game state to client
    send(socket, game_state, sizeof(GameState), 0);

    // Main game loop
    while (!game_state->game_over) {
        // Lock game state
        pthread_mutex_lock(&game_state_mutex);

        // Check if it's the client's turn
        if (game_state->current_player == socket) {
            // Send word to client
            send(socket, game_state->word, game_state->word_length, 0);

            // Receive guess from client
            char guess;
            recv(socket, &guess, sizeof(char), 0);

            // Check if guess is correct
            if (strchr(game_state->word, guess)) {
                // Correct guess
                game_state->guesses_left++;
            } else {
                // Incorrect guess
                game_state->guesses_left--;
            }

            // Check if game is over
            if (game_state->guesses_left == 0) {
                game_state->game_over = 1;
            }

            // Send updated game state to client
            send(socket, game_state, sizeof(GameState), 0);
        }

        // Unlock game state
        pthread_mutex_unlock(&game_state_mutex);
    }

    // Close client socket
    close(socket);

    return NULL;
}

int main() {
    // Initialize game state
    GameState game_state;
    game_state.num_clients = 0;
    game_state.current_player = -1;
    game_state.word_length = 0;
    game_state.guesses_left = 0;
    game_state.game_over = 0;

    // Create server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        exit(1);
    }

    // Set server socket options
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    // Bind server socket to address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    listen(server_socket, MAX_CLIENTS);

    while (1) {
        // Accept incoming connection
        int *client_socket = malloc(sizeof(int));
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        *client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (*client_socket < 0) {
            perror("accept");
            continue;
        }

        // Create client thread
        pthread_t client_thread_id;
        pthread_create(&client_thread_id, NULL, client_thread, client_socket);
    }

    // Close server socket
    close(server_socket);

    return 0;
}