//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PLAYERS 4
#define MAX_MESSAGES 10

struct Player {
    int socket;
    char name[20];
    char message[100];
    int message_index;
};

struct Game {
    struct Player players[MAX_PLAYERS];
    int num_players;
    int current_player;
    char key[20];
};

void generate_key(char *key) {
    int i;
    for (i = 0; i < 20; i++) {
        key[i] = (rand() % 26) + 'a';
    }
}

void encrypt_message(char *message, char *key) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        message[i] = (message[i] + key[i]) % 26 + 'a';
    }
}

void decrypt_message(char *message, char *key) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        message[i] = (message[i] - key[i] + 26) % 26 + 'a';
    }
}

void send_message(struct Game *game, int player_index) {
    char buffer[100];
    strcpy(buffer, game->players[player_index].message);
    encrypt_message(buffer, game->key);
    int i;
    for (i = 0; i < game->num_players; i++) {
        if (i != player_index) {
            send(game->players[i].socket, buffer, strlen(buffer), 0);
        }
    }
}

void receive_message(struct Game *game, int player_index) {
    char buffer[100];
    int len = recv(game->players[player_index].socket, buffer, 100, 0);
    if (len > 0) {
        buffer[len] = '\0';
        decrypt_message(buffer, game->key);
        strcpy(game->players[player_index].message, buffer);
        game->players[player_index].message_index++;
    }
}

void start_game(struct Game *game) {
    int i;
    for (i = 0; i < game->num_players; i++) {
        send(game->players[i].socket, "Welcome to the game!\n", 20, 0);
    }
    generate_key(game->key);
    for (i = 0; i < game->num_players; i++) {
        send(game->players[i].socket, game->key, 20, 0);
    }
    game->current_player = 0;
}

void run_game(struct Game *game) {
    while (1) {
        receive_message(game, game->current_player);
        if (game->players[game->current_player].message_index >= MAX_MESSAGES) {
            break;
        }
        send_message(game, game->current_player);
        game->current_player = (game->current_player + 1) % game->num_players;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return 1;
    }

    int bind_result = bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (bind_result == -1) {
        perror("bind");
        return 1;
    }

    int listen_result = listen(server_socket, MAX_PLAYERS);
    if (listen_result == -1) {
        perror("listen");
        return 1;
    }

    struct Game game;
    game.num_players = 0;
    game.current_player = 0;

    while (game.num_players < MAX_PLAYERS) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        game.players[game.num_players].socket = client_socket;
        recv(client_socket, game.players[game.num_players].name, 20, 0);
        game.num_players++;
    }

    start_game(&game);
    run_game(&game);

    int i;
    for (i = 0; i < game.num_players; i++) {
        close(game.players[i].socket);
    }

    close(server_socket);

    return 0;
}