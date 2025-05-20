//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_CLIENTS 100
#define MAX_MSG_SIZE 1024

// Player struct
typedef struct player {
    int sockfd;
    char name[32];
    int score;
} player_t;

// List of connected players
player_t players[MAX_CLIENTS];

// Broadcast a message to all players
void broadcast(char *msg) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (players[i].sockfd != -1) {
            send(players[i].sockfd, msg, strlen(msg), 0);
        }
    }
}

// Handle a new client connection
void handle_client(int sockfd) {
    char name[32];

    // Receive the player's name
    recv(sockfd, name, sizeof(name), 0);

    // Add the player to the list of connected players
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (players[i].sockfd == -1) {
            players[i].sockfd = sockfd;
            strcpy(players[i].name, name);
            players[i].score = 0;
            break;
        }
    }

    // Broadcast a message to all players announcing the new player
    char msg[MAX_MSG_SIZE];
    sprintf(msg, "%s has joined the game!", name);
    broadcast(msg);

    // Receive and handle messages from the player
    while (1) {
        char msg[MAX_MSG_SIZE];

        // Receive a message from the player
        recv(sockfd, msg, sizeof(msg), 0);

        // Check if the player has disconnected
        if (strcmp(msg, "/quit") == 0) {
            break;
        }

        // Handle the message
        else if (strcmp(msg, "/score") == 0) {
            // Send the player's score back to them
            sprintf(msg, "Your score is: %d", players[sockfd].score);
            send(sockfd, msg, strlen(msg), 0);
        } else if (strcmp(msg, "/roll") == 0) {
            // Roll a random number and send it back to the player
            int roll = rand() % 6 + 1;
            sprintf(msg, "You rolled a %d!", roll);
            send(sockfd, msg, strlen(msg), 0);

            // Increment the player's score
            players[sockfd].score += roll;
        } else {
            // Broadcast the message to all players
            broadcast(msg);
        }
    }

    // Remove the player from the list of connected players
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (players[i].sockfd == sockfd) {
            players[i].sockfd = -1;
            break;
        }
    }

    // Broadcast a message to all players announcing the player has left
    sprintf(msg, "%s has left the game!", name);
    broadcast(msg);

    // Close the player's socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Create a server socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Set the server socket to reuse the address and port
    int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Bind the server socket to the specified port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[1]));
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sockfd, MAX_CLIENTS) == -1) {
        perror("listen");
        return 1;
    }

    // Initialize the list of connected players
    for (int i = 0; i < MAX_CLIENTS; i++) {
        players[i].sockfd = -1;
    }

    // Main loop
    while (1) {
        // Accept a new connection
        int newsockfd = accept(sockfd, NULL, NULL);
        if (newsockfd == -1) {
            perror("accept");
            continue;
        }

        // Create a new thread to handle the new connection
        pthread_t tid;
        pthread_create(&tid, NULL, (void *)handle_client, (void *)newsockfd);
    }

    // Close the server socket
    close(sockfd);

    return 0;
}