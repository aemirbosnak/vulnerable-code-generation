//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define MAX_CLIENTS 10
#define PORT 9000

// Player struct
typedef struct Player {
    int sockfd;
    char name[32];
    char key[32];
    int score;
} Player;

// Server game loop
void *server_game_loop(void *arg) {
    Player *player = (Player *)arg;
    
    // Receive client name
    char name[32];
    recv(player->sockfd, name, sizeof(name), 0);
    strcpy(player->name, name);
    
    // Generate random key
    char key[32];
    for (int i = 0; i < 32; i++) {
        key[i] = rand() % 256;
    }
    strcpy(player->key, key);
    
    // Send key to client
    send(player->sockfd, key, sizeof(key), 0);
    
    // Game loop
    while (1) {
        // Receive encrypted message from client
        char encrypted_message[BUF_SIZE];
        recv(player->sockfd, encrypted_message, sizeof(encrypted_message), 0);
        
        // Decrypt message
        char message[BUF_SIZE];
        for (int i = 0; i < strlen(encrypted_message); i++) {
            message[i] = encrypted_message[i] ^ player->key[i % 32];
        }
        
        // Process message
        if (strcmp(message, "guess") == 0) {
            // Client is guessing a number
            int guess;
            recv(player->sockfd, &guess, sizeof(guess), 0);
            
            // Check if guess is correct
            int correct_number = rand() % 100;
            if (guess == correct_number) {
                // Client guessed correctly
                player->score++;
                char message[] = "Correct!";
                send(player->sockfd, message, sizeof(message), 0);
            } else {
                // Client guessed incorrectly
                char message[] = "Incorrect!";
                send(player->sockfd, message, sizeof(message), 0);
            }
        } else if (strcmp(message, "score") == 0) {
            // Client is requesting their score
            char message[BUF_SIZE];
            sprintf(message, "Your score is %d", player->score);
            send(player->sockfd, message, sizeof(message), 0);
        } else if (strcmp(message, "exit") == 0) {
            // Client is exiting
            break;
        }
    }
    
    return NULL;
}

int main() {
    // Create server socket
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }
    
    // Set server socket options
    int opt = 1;
    setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    
    // Bind server socket to address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    if (bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }
    
    // Listen for client connections
    if (listen(server_sockfd, MAX_CLIENTS) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }
    
    // Main server loop
    while (1) {
        // Accept client connection
        int client_sockfd = accept(server_sockfd, NULL, NULL);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }
        
        // Create new player
        Player *player = malloc(sizeof(Player));
        player->sockfd = client_sockfd;
        
        // Create new thread for player
        pthread_t thread;
        pthread_create(&thread, NULL, server_game_loop, player);
    }
    
    // Close server socket
    close(server_sockfd);
    
    return EXIT_SUCCESS;
}