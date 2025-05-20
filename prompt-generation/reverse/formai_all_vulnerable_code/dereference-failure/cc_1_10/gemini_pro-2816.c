//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PLAYERS 4
#define MAX_PORTS 100

struct player {
    char name[32];
    int score;
    int ports[MAX_PORTS];
};

struct game {
    int num_players;
    struct player players[MAX_PLAYERS];
};

void print_usage(char *argv[]) {
    printf("Usage: %s <host> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv);
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    int n;

    // Join the game
    strcpy(buffer, "JOIN");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the game state
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    struct game game;
    memcpy(&game, buffer, sizeof(game));

    // Print the game state
    printf("Num players: %d\n", game.num_players);
    for (int i = 0; i < game.num_players; i++) {
        printf("Player %d: %s (%d points)\n", i + 1, game.players[i].name, game.players[i].score);
    }

    // Start scanning ports
    for (int i = 0; i < MAX_PORTS; i++) {
        int port = i + 1000;
        for (int j = 0; j < game.num_players; j++) {
            if (game.players[j].ports[i] == 1) {
                printf("Player %s has port %d open\n", game.players[j].name, port);
            }
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}