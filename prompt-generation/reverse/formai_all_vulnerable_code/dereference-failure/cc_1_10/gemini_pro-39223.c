//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_PLAYERS 2
#define MAX_NAME_LENGTH 32
#define MAX_MESSAGE_LENGTH 256

typedef struct {
    int socket;
    char name[MAX_NAME_LENGTH];
} player_t;

player_t players[MAX_PLAYERS];
int num_players = 0;

pthread_mutex_t lock;

void broadcast_message(char *message) {
    pthread_mutex_lock(&lock);
    for (int i = 0; i < num_players; i++) {
        send(players[i].socket, message, strlen(message), 0);
    }
    pthread_mutex_unlock(&lock);
}

void *player_thread(void *arg) {
    player_t *player = (player_t *)arg;
    char buffer[MAX_MESSAGE_LENGTH];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        recv(player->socket, buffer, sizeof(buffer), 0);
        if (strcmp(buffer, "/exit") == 0) {
            break;
        }
        char message[MAX_MESSAGE_LENGTH];
        sprintf(message, "%s: %s", player->name, buffer);
        broadcast_message(message);
    }
    pthread_mutex_lock(&lock);
    num_players--;
    for (int i = 0; i < num_players; i++) {
        if (players[i].socket == player->socket) {
            players[i] = players[num_players];
            break;
        }
    }
    pthread_mutex_unlock(&lock);
    close(player->socket);
    free(player);
    return NULL;
}

int main() {
    pthread_mutex_init(&lock, NULL);
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return 1;
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345);
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }
    if (listen(server_socket, 5) == -1) {
        perror("listen");
        return 1;
    }
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }
        if (num_players >= MAX_PLAYERS) {
            send(client_socket, "Server is full", strlen("Server is full"), 0);
            close(client_socket);
            continue;
        }
        char name[MAX_NAME_LENGTH];
        recv(client_socket, name, sizeof(name), 0);
        player_t *player = malloc(sizeof(player_t));
        player->socket = client_socket;
        strcpy(player->name, name);
        pthread_t thread;
        pthread_create(&thread, NULL, player_thread, player);
        pthread_mutex_lock(&lock);
        players[num_players] = *player;
        num_players++;
        pthread_mutex_unlock(&lock);
        char message[MAX_MESSAGE_LENGTH];
        sprintf(message, "%s has joined the game", player->name);
        broadcast_message(message);
    }
    pthread_mutex_destroy(&lock);
    close(server_socket);
    return 0;
}