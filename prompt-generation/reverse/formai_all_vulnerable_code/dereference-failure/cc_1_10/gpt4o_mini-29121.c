//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define MAX_PLAYERS 5
#define BUFFER_SIZE 1024

// Structure to hold player information
typedef struct {
    int socket;
    struct sockaddr_in address;
} Player;

// Rules for the firewall
const char *allow_list[] = {"192.168.1.10", "192.168.1.20"};
const char *deny_list[] = {"192.168.1.30", "192.168.1.40"};
const int allow_count = 2;
const int deny_count = 2;

void *handle_connection(void *arg);
int is_allowed(const char *ip);
int is_denied(const char *ip);

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Start listening for connections
    if (listen(server_fd, MAX_PLAYERS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Firewall Server is running on port %d.\n", PORT);
    
    // Accept players
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        
        pthread_t thread_id;
        Player *player = malloc(sizeof(Player));
        player->socket = new_socket;
        player->address = address;
        
        if (pthread_create(&thread_id, NULL, handle_connection, player) != 0) {
            perror("Failed to create thread");
            free(player);
        }
        pthread_detach(thread_id); // Detach the thread to allow for cleanup
    }

    return 0;
}

void *handle_connection(void *arg) {
    Player *player = (Player *)arg;
    char buffer[BUFFER_SIZE] = {0};
    char ip_address[INET_ADDRSTRLEN];
    
    // Get IP address
    inet_ntop(AF_INET, &(player->address.sin_addr), ip_address, INET_ADDRSTRLEN);
    
    // Check rules
    if (is_denied(ip_address)) {
        const char *message = "Connection denied by firewall!\n";
        send(player->socket, message, strlen(message), 0);
        close(player->socket);
        free(player);
        return NULL;
    }
    
    if (is_allowed(ip_address)) {
        const char *message = "Welcome to the game!\n";
        send(player->socket, message, strlen(message), 0);
    } else {
        const char *message = "Connection not found in rules, blocking...\n";
        send(player->socket, message, strlen(message), 0);
    }

    // Main loop for receiving messages
    while(read(player->socket, buffer, BUFFER_SIZE) > 0) {
        printf("Player (%s): %s\n", ip_address, buffer);
        send(player->socket, buffer, strlen(buffer), 0); // Echo the received message
    }

    printf("Player (%s) has disconnected.\n", ip_address);
    close(player->socket);
    free(player);

    return NULL;
}

int is_allowed(const char *ip) {
    for (int i = 0; i < allow_count; i++) {
        if (strcmp(ip, allow_list[i]) == 0) {
            return 1; // Allowed
        }
    }
    return 0; // Not allowed
}

int is_denied(const char *ip) {
    for (int i = 0; i < deny_count; i++) {
        if (strcmp(ip, deny_list[i]) == 0) {
            return 1; // Denied
        }
    }
    return 0; // Not denied
}