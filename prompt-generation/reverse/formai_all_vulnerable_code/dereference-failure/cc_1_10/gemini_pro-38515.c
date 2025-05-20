//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>

#define PORT 5000
#define MAX_PLAYERS 4

struct player {
    int sockfd;
    char name[32];
    int score;
};

struct game_state {
    struct player players[MAX_PLAYERS];
    int num_players;
    int current_player;
    int game_over;
};

void handle_connection(struct game_state *game, int sockfd);
void handle_data(struct game_state *game, int sockfd, char *buf);
void start_game(struct game_state *game);
void end_game(struct game_state *game);

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sockfd, MAX_PLAYERS);

    struct game_state game;
    game.num_players = 0;
    game.current_player = -1;
    game.game_over = 0;

    while (!game.game_over) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept");
            continue;
        }

        handle_connection(&game, newsockfd);
    }

    close(sockfd);
    return 0;
}

void handle_connection(struct game_state *game, int sockfd) {
    char buf[256];
    int n;

    // Receive the player's name
    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n < 0) {
        perror("recv");
        close(sockfd);
        return;
    }

    // Add the player to the game
    strcpy(game->players[game->num_players].name, buf);
    game->players[game->num_players].sockfd = sockfd;
    game->players[game->num_players].score = 0;
    game->num_players++;

    // Start the game if there are enough players
    if (game->num_players == MAX_PLAYERS) {
        start_game(game);
    }

    // Handle data from the player
    while ((n = recv(sockfd, buf, sizeof(buf), 0)) > 0) {
        handle_data(game, sockfd, buf);
    }

    // The player has disconnected
    close(sockfd);
    game->num_players--;

    // End the game if there are no more players
    if (game->num_players == 0) {
        end_game(game);
    }
}

void handle_data(struct game_state *game, int sockfd, char *buf) {
    // Parse the data
    char *command = strtok(buf, " ");
    char *args = strtok(NULL, " ");

    // Handle the command
    if (strcmp(command, "move") == 0) {
        // The player has moved
        int x = atoi(args);
        int y = atoi(strtok(NULL, " "));

        // Check if the move is valid
        if (x < 0 || x > 10 || y < 0 || y > 10) {
            // The move is invalid
            char buf[256];
            sprintf(buf, "Invalid move: (%d, %d)\n", x, y);
            send(sockfd, buf, strlen(buf), 0);
            return;
        }

        // The move is valid
        game->players[game->current_player].score++;

        // Send the move to the other players
        char buf[256];
        sprintf(buf, "move %d %d\n", x, y);
        for (int i = 0; i < game->num_players; i++) {
            if (game->players[i].sockfd != sockfd) {
                send(game->players[i].sockfd, buf, strlen(buf), 0);
            }
        }
    } else if (strcmp(command, "chat") == 0) {
        // The player has sent a chat message
        char buf[256];
        sprintf(buf, "chat %s: %s\n", game->players[game->current_player].name, args);

        // Send the chat message to the other players
        for (int i = 0; i < game->num_players; i++) {
            if (game->players[i].sockfd != sockfd) {
                send(game->players[i].sockfd, buf, strlen(buf), 0);
            }
        }
    } else if (strcmp(command, "quit") == 0) {
        // The player has quit the game
        close(sockfd);
        game->num_players--;

        // End the game if there are no more players
        if (game->num_players == 0) {
            end_game(game);
        }
    }
}

void start_game(struct game_state *game) {
    // Set the current player
    game->current_player = 0;

    // Send a start game message to all players
    char buf[256];
    strcpy(buf, "start game\n");
    for (int i = 0; i < game->num_players; i++) {
        send(game->players[i].sockfd, buf, strlen(buf), 0);
    }
}

void end_game(struct game_state *game) {
    // Send an end game message to all players
    char buf[256];
    strcpy(buf, "end game\n");
    for (int i = 0; i < game->num_players; i++) {
        send(game->players[i].sockfd, buf, strlen(buf), 0);
    }

    // Close all player sockets
    for (int i = 0; i < game->num_players; i++) {
        close(game->players[i].sockfd);
    }

    // Reset the game state
    game->num_players = 0;
    game->current_player = -1;
    game->game_over = 0;
}