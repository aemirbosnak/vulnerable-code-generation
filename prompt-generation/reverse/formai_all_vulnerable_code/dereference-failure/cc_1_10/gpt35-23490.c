//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: distributed
// This program is a distributed game where players can play a multiplayer puzzle game
// The game involves arranging a set of numbers in ascending order
// Each player can only see their own numbers and the numbers of the players they are connected to
// The game ends when all players have arranged their numbers in ascending order

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

// Constants
#define MAX_PLAYERS 10
#define BOARD_SIZE 10
#define MAX_COMMAND_LENGTH 20

// Global variables
int player_count = 0;
int players[MAX_PLAYERS];
int player_boards[MAX_PLAYERS][BOARD_SIZE];
char command[MAX_COMMAND_LENGTH];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function declarations
void *player_thread(void *arg);
void send_boards();
int check_board(int board[]);
void swap(int *a, int *b);
void shuffle_board(int board[]);

int main(int argc, char const *argv[]) {
    // Seed random number generator
    srand(time(NULL));

    // Create server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address, client_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    // Bind socket to port
    bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    // Listen for connections
    listen(server_socket, MAX_PLAYERS);

    // Accept player connections
    printf("Waiting for players to connect...\n");
    while (player_count < MAX_PLAYERS) {
        socklen_t address_size = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &address_size);
        if (client_socket < 0) {
            printf("Error accepting connection\n");
            continue;
        }

        // Add player to game
        pthread_mutex_lock(&mutex);
        if (player_count < MAX_PLAYERS) {
            players[player_count] = client_socket;
            player_count++;
            printf("Player %d connected\n", player_count);
        } else {
            printf("Game is full\n");
        }
        pthread_mutex_unlock(&mutex);

        // Create player thread
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, player_thread, &client_socket) != 0) {
            printf("Error creating player thread\n");
            continue;
        }
    }

    // Game is ready to start, shuffle boards and send to players
    printf("Game starting!\n");
    for (int i = 0; i < player_count; i++) {
        shuffle_board(player_boards[i]);
    }
    send_boards();

    // Wait for all players to finish
    int finished_count = 0;
    while (finished_count < player_count) {
        pthread_mutex_lock(&mutex);
        if (strcmp(command, "finished") == 0) {
            finished_count++;
            printf("%d players have finished\n", finished_count);
        }
        pthread_mutex_unlock(&mutex);
    }
    printf("Game over!\n");

    // Close all sockets
    for (int i = 0; i < player_count; i++) {
        close(players[i]);
    }

    return 0;
}

// Thread function for each player
void *player_thread(void *arg) {
    int client_socket = *(int *) arg;
    int player_index = -1;
    int board_index = -1;
    for (int i = 0; i < player_count; i++) {
        if (players[i] == client_socket) {
            player_index = i;
            board_index = i * BOARD_SIZE;
            break;
        }
    }

    // Wait for player to finish
    while (1) {
        // Receive command from player
        memset(command, 0, MAX_COMMAND_LENGTH);
        if (recv(client_socket, command, MAX_COMMAND_LENGTH, 0) <= 0) {
            continue;
        }

        // Check command
        if (strcmp(command, "board") == 0) {
            // Send player their board
            char board_string[BOARD_SIZE * 3]; // 3 characters per number (digit, space, null terminator)
            memset(board_string, 0, BOARD_SIZE * 3);
            for (int i = 0; i < BOARD_SIZE; i++) {
                sprintf(board_string + strlen(board_string), "%d ", player_boards[player_index][board_index + i]);
            }
            if (send(client_socket, board_string, strlen(board_string), 0) < 0) {
                continue;
            }
        } else if (strcmp(command, "swap") == 0) {
            // Receive swap indices from player
            int index_a, index_b;
            if (recv(client_socket, &index_a, sizeof(index_a), 0) <= 0) {
                continue;
            }
            if (recv(client_socket, &index_b, sizeof(index_b), 0) <= 0) {
                continue;
            }

            // Perform swap and check if board is finished
            swap(&(player_boards[player_index][board_index + index_a]), &(player_boards[player_index][board_index + index_b]));
            if (check_board(player_boards[player_index]) == 1) {
                printf("Player %d has finished\n", player_index + 1);
                pthread_mutex_lock(&mutex);
                strcpy(command, "finished");
                pthread_mutex_unlock(&mutex);
            } else {
                send_boards();
            }
        }
    }
}

// Send each player their board
void send_boards() {
    char board_string[MAX_PLAYERS * (BOARD_SIZE * 3 + 1) + 1];
    memset(board_string, 0, MAX_PLAYERS * (BOARD_SIZE * 3 + 1) + 1);
    for (int i = 0; i < player_count; i++) {
        int board_index = i * BOARD_SIZE;
        for (int j = 0; j < BOARD_SIZE; j++) {
            sprintf(board_string + strlen(board_string), "%d ", player_boards[i][board_index + j]);
        }
        strcat(board_string, "-");
    }
    for (int i = 0; i < player_count; i++) {
        if (send(players[i], board_string, strlen(board_string), 0) < 0) {
            continue;
        }
    }
}

// Check if board is finished
int check_board(int board[]) {
    for (int i = 0; i < BOARD_SIZE - 1; i++) {
        if (board[i] > board[i + 1]) {
            return 0;
        }
    }
    return 1;
}

// Swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Shuffle a board
void shuffle_board(int board[]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = i;
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        int j = rand() % BOARD_SIZE;
        swap(&(board[i]), &(board[j]));
    }
}