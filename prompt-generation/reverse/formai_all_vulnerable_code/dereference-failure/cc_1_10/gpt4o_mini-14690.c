//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_PLAYERS 4
#define BUFFER_SIZE 1024

typedef struct {
    int sock;
    char name[30];
} Player;

Player players[MAX_PLAYERS];
int player_count = 0;

void* handle_player(void* arg) {
    Player player = *(Player*)arg;
    char buffer[BUFFER_SIZE];
    
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int read_size = recv(player.sock, buffer, BUFFER_SIZE, 0);
        if (read_size <= 0) break;

        printf("%s: %s\n", player.name, buffer);
        
        // Broadcast message to other players
        for (int i = 0; i < player_count; i++) {
            if (players[i].sock != player.sock) {
                send(players[i].sock, buffer, strlen(buffer), 0);
            }
        }
    }

    close(player.sock);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Waiting for players...\n");

    while (player_count < MAX_PLAYERS) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        Player new_player;
        new_player.sock = new_socket;
        sprintf(new_player.name, "Player %d", player_count + 1);
        players[player_count++] = new_player;

        pthread_t tid;
        pthread_create(&tid, NULL, handle_player, (void*)&new_player);

        printf("%s has joined the game!\n", new_player.name);
    }

    printf("Max players reached, starting the game...\n");
    // Game logic would be initiated here.

    for (int i = 0; i < player_count; i++) {
        close(players[i].sock);
    }
    
    close(server_fd);
    return 0;
}