//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_PLAYERS 10
#define MAX_MESSAGE_LENGTH 100

struct player {
    int sock;
    char name[50];
};

int main(void) {
    int sock_server = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(1234),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock_server, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    if (listen(sock_server, MAX_PLAYERS) < 0) {
        perror("Error listening for connections");
        return 1;
    }

    struct player players[MAX_PLAYERS];
    int player_count = 0;

    while (1) {
        int client_sock = accept(sock_server, NULL, NULL);
        if (client_sock < 0) {
            perror("Error accepting connection");
            continue;
        }

        char name[50];
        if (read(client_sock, name, 50) < 0) {
            perror("Error reading name from client");
            close(client_sock);
            continue;
        }

        players[player_count].sock = client_sock;
        strcpy(players[player_count].name, name);
        player_count++;

        if (player_count >= MAX_PLAYERS) {
            fprintf(stderr, "Error: Too many players connected\n");
            break;
        }

        while (1) {
            char message[MAX_MESSAGE_LENGTH];
            if (read(players[player_count - 1].sock, message, MAX_MESSAGE_LENGTH) < 0) {
                perror("Error reading message from client");
                break;
            }

            // Handle message here
            printf("Received message from %s: %s\n", players[player_count - 1].name, message);

            if (strcmp(message, "QUIT") == 0) {
                player_count--;
                close(players[player_count].sock);
            }
        }
    }

    return 0;
}