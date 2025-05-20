//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MSG_SIZE 256
#define MAX_CLIENTS 4

typedef struct {
    char name[32];
    int x, y;
    int hp, shield;
} Spaceship;

typedef struct {
    char name[32];
    int x, y;
    int resources;
} Planet;

typedef struct {
    char name[32];
    char description[128];
} AlienSpecies;

Spaceship ships[MAX_CLIENTS];
Planet planets[8];
AlienSpecies aliens[3];

int create_socket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("create_socket");
        exit(EXIT_FAILURE);
    }
    return sock;
}

void bind_socket(int sock, int port) {
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);
    if (bind(sock, (struct sockaddr*) &addr, sizeof(addr)) < 0) {
        perror("bind_socket");
        exit(EXIT_FAILURE);
    }
}

void listen_socket(int sock) {
    if (listen(sock, MAX_CLIENTS) < 0) {
        perror("listen_socket");
        exit(EXIT_FAILURE);
    }
}

int accept_socket(int sock) {
    struct sockaddr_in client_addr = {0};
    socklen_t addr_size = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr*) &client_addr, &addr_size);
    if (client_sock < 0) {
        perror("accept_socket");
        exit(EXIT_FAILURE);
    }
    printf("Connection from %s\n", inet_ntoa(client_addr.sin_addr));
    return client_sock;
}

void send_message(int sock, const char* msg) {
    if (send(sock, msg, strlen(msg), 0) < 0) {
        perror("send_message");
        exit(EXIT_FAILURE);
    }
}

void receive_message(int sock, char* buffer, size_t size) {
    ssize_t n = recv(sock, buffer, size, 0);
    if (n < 0) {
        perror("receive_message");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
}

int main(int argc, char** argv) {
    // Initialize game world
    strcpy(ships[0].name, "Player 1");
    ships[0].x = 3;
    ships[0].y = 5;
    ships[0].hp = 100;
    ships[0].shield = 20;
    
    strcpy(ships[1].name, "Player 2");
    ships[1].x = 8;
    ships[1].y = 2;
    ships[1].hp = 80;
    ships[1].shield = 30;
    
    // ...
    
    int srv_sock = create_socket();
    bind_socket(srv_sock, 8888);
    listen_socket(srv_sock);

    int client_socks[MAX_CLIENTS];
    int num_clients = 0;
    
    while (num_clients < MAX_CLIENTS) {
        client_socks[num_clients] = accept_socket(srv_sock);
        send_message(client_socks[num_clients], "Welcome to space adventure!\n");
        num_clients++;
    }
    
    // Game loop
    while (1) {
        // Handle player actions
        for (int i = 0; i < num_clients; i++) {
            char buffer[MSG_SIZE];
            receive_message(client_socks[i], buffer, MSG_SIZE);
            printf("Received message from %s: '%s'\n", ships[i].name, buffer);
            // ... parse message and perform action
            send_message(client_socks[i], "Action performed!\n");
        }
        // Update game state
        // ...
        // Send game state to all clients
        for (int i = 0; i < num_clients; i++) {
            // ... serialize game state to string
            send_message(client_socks[i], "Game state update:\n");
            // ...
        }
        // Wait for a while to avoid busy wait
        sleep(1);
    }

    // Cleanup
    for (int i = 0; i < num_clients; i++) {
        close(client_socks[i]);
    }
    close(srv_sock);

    return EXIT_SUCCESS;
}