//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

typedef struct {
    int client_socket;
    int player_id;
} client_t;

client_t *clients[MAX_CLIENTS];
int clients_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;
int ball_x = 0, ball_y = 0;
int ball_direction_x = 1, ball_direction_y = 1;

void *handle_client(void *arg) {
    client_t *cli = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    
    while (1) {
        int bytes_received = recv(cli->client_socket, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received <= 0) {
            break;
        }
        buffer[bytes_received] = '\0';
        
        // Example of handling player movement based on input
        if (strcmp(buffer, "UP") == 0) {
            // Update player's position up
            printf("Player %d moved UP\n", cli->player_id);
        } else if (strcmp(buffer, "DOWN") == 0) {
            // Update player's position down
            printf("Player %d moved DOWN\n", cli->player_id);
        }
        
        // Broadcast game state to all clients
        char game_state[BUFFER_SIZE];
        snprintf(game_state, sizeof(game_state), "BALL_POS %d %d\n", ball_x, ball_y);
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < clients_count; i++) {
            send(clients[i]->client_socket, game_state, strlen(game_state), 0);
        }
        pthread_mutex_unlock(&clients_mutex);
    }
    
    close(cli->client_socket);
    free(cli);
    return NULL;
}

void update_ball_position() {
    ball_x += ball_direction_x;
    ball_y += ball_direction_y;

    // Check for wall collision
    if (ball_x <= 0 || ball_x >= 10) {
        ball_direction_x *= -1; // Reverse direction
    }
    if (ball_y <= 0 || ball_y >= 10) {
        ball_direction_y *= -1; // Reverse direction
    }
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int opt = 1;
    int address_len = sizeof(address);
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    
    // Create socket address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Start listening for clients
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server started. Waiting for clients...\n");
    
    while (clients_count < MAX_CLIENTS) {
        if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&address_len)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        
        // Allocate and initialize client structure
        client_t *cli = malloc(sizeof(client_t));
        cli->client_socket = client_socket;
        cli->player_id = clients_count + 1;

        // Add client to the clients list
        pthread_mutex_lock(&clients_mutex);
        clients[clients_count++] = cli;
        pthread_mutex_unlock(&clients_mutex);

        // Create thread for client handling
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, cli) != 0) {
            perror("Thread creation failed");
            free(cli);
        }
        
        printf("Client %d connected.\n", cli->player_id);
    }

    // Game loop (simplified for demo purposes)
    while (1) {
        update_ball_position();
        usleep(100000); // 10 FPS
    }

    return 0;
}