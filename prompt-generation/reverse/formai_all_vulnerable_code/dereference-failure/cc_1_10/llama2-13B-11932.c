//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PLAYERS 10
#define MAX_MESSAGE_LENGTH 100

struct player {
    int sock;
    char name[50];
};

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct player players[MAX_PLAYERS];
    int player_count = 0;

    // Create a server socket
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(1234),
        .sin_addr.s_addr = INADDR_ANY
    };
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started. Waiting for connections...\n");

    while (1) {
        // Accept an incoming connection
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("Accept failed");
            continue;
        }

        // Add the client to the player list
        struct player *player = malloc(sizeof(struct player));
        player->sock = client_sock;
        strcpy(player->name, "Client");
        player_count++;

        // Broadcast a message to all players
        char message[MAX_MESSAGE_LENGTH];
        message[0] = 'M';
        message[1] = 'E';
        message[2] = 'S';
        message[3] = 'S';
        message[4] = 'A';
        message[5] = 'G';
        message[6] = 'E';
        message[7] = 'S';
        message[8] = 'S';
        message[9] = '\0';
        sendto(client_sock, message, strlen(message), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

        // Handle player messages
        while (1) {
            char buffer[MAX_MESSAGE_LENGTH];
            recvfrom(client_sock, buffer, MAX_MESSAGE_LENGTH, 0, (struct sockaddr *)&client_addr, &client_len);
            if (strcmp(buffer, "QUIT") == 0) {
                break;
            }
            sendto(client_sock, "Received message: ", strlen("Received message: "), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        }

        // Remove the client from the player list
        for (int i = 0; i < player_count; i++) {
            if (players[i].sock == client_sock) {
                memmove(&players[i], &players[i + 1], (player_count - i - 1) * sizeof(struct player));
                player_count--;
                break;
            }
        }

        close(client_sock);
    }

    return 0;
}