//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000
#define MAX_PLAYERS 2

struct player {
    int id;
    char name[32];
    int score;
};

struct game {
    struct player players[MAX_PLAYERS];
    int current_player;
    char board[3][3];
};

void init_game(struct game *game) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        game->players[i].id = i;
        game->players[i].score = 0;
    }
    game->current_player = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            game->board[i][j] = ' ';
        }
    }
}

void print_board(struct game *game) {
    printf("\n");
    printf("  %c | %c | %c\n", game->board[0][0], game->board[0][1], game->board[0][2]);
    printf(" ---+---+---\n");
    printf("  %c | %c | %c\n", game->board[1][0], game->board[1][1], game->board[1][2]);
    printf(" ---+---+---\n");
    printf("  %c | %c | %c\n", game->board[2][0], game->board[2][1], game->board[2][2]);
    printf("\n");
}

int check_winner(struct game *game) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (game->board[i][0] == game->board[i][1] && game->board[i][1] == game->board[i][2] && game->board[i][0] != ' ') {
            return game->players[game->current_player].id;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (game->board[0][i] == game->board[1][i] && game->board[1][i] == game->board[2][i] && game->board[0][i] != ' ') {
            return game->players[game->current_player].id;
        }
    }

    // Check diagonals
    if (game->board[0][0] == game->board[1][1] && game->board[1][1] == game->board[2][2] && game->board[0][0] != ' ') {
        return game->players[game->current_player].id;
    }
    if (game->board[0][2] == game->board[1][1] && game->board[1][1] == game->board[2][0] && game->board[0][2] != ' ') {
        return game->players[game->current_player].id;
    }

    // Check for draw
    int draw = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game->board[i][j] == ' ') {
                draw = 0;
            }
        }
    }
    if (draw) {
        return -1;
    }

    return 0;
}

void handle_move(struct game *game, int player_id, int row, int col) {
    if (game->players[player_id].id != game->current_player) {
        printf("It is not your turn!\n");
        return;
    }

    if (row < 0 || row > 2 || col < 0 || col > 2) {
        printf("Invalid move!\n");
        return;
    }

    if (game->board[row][col] != ' ') {
        printf("This square is already taken!\n");
        return;
    }

    game->board[row][col] = game->players[player_id].id == 0 ? 'X' : 'O';
    game->current_player = (game->current_player + 1) % MAX_PLAYERS;
}

int main() {
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Bind the socket to an address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Listen for connections
    if (listen(server_socket, MAX_PLAYERS) == -1) {
        perror("listen");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Accept connections
    int client_sockets[MAX_PLAYERS];
    for (int i = 0; i < MAX_PLAYERS; i++) {
        client_sockets[i] = accept(server_socket, NULL, NULL);
        if (client_sockets[i] == -1) {
            perror("accept");
            close(server_socket);
            for (int j = 0; j < i; j++) {
                close(client_sockets[j]);
            }
            return EXIT_FAILURE;
        }
    }

    // Initialize the game
    struct game game;
    init_game(&game);

    // Send the initial game state to the clients
    for (int i = 0; i < MAX_PLAYERS; i++) {
        send(client_sockets[i], &game, sizeof(game), 0);
    }

    // Main game loop
    while (1) {
        // Get the next move from the current player
        int player_id;
        int row;
        int col;
        recv(client_sockets[game.current_player], &player_id, sizeof(player_id), 0);
        recv(client_sockets[game.current_player], &row, sizeof(row), 0);
        recv(client_sockets[game.current_player], &col, sizeof(col), 0);

        // Handle the move
        handle_move(&game, player_id, row, col);

        // Send the updated game state to the clients
        for (int i = 0; i < MAX_PLAYERS; i++) {
            send(client_sockets[i], &game, sizeof(game), 0);
        }

        // Check for a winner
        int winner = check_winner(&game);
        if (winner != 0) {
            // Send the winner to the clients
            for (int i = 0; i < MAX_PLAYERS; i++) {
                send(client_sockets[i], &winner, sizeof(winner), 0);
            }

            // Close the connections
            for (int i = 0; i < MAX_PLAYERS; i++) {
                close(client_sockets[i]);
            }
            close(server_socket);

            return EXIT_SUCCESS;
        }
    }

    return EXIT_SUCCESS;
}