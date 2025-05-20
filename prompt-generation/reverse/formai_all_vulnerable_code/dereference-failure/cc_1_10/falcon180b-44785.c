//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

// Function to print error message and exit
void error(const char *msg) {
    perror(msg);
    exit(1);
}

// Function to generate a random number between 1 and 6
int roll_dice() {
    return rand() % 6 + 1;
}

// Function to send data to a client
void send_data(int client_socket, char *data) {
    send(client_socket, data, strlen(data), 0);
}

// Function to receive data from a client
char *receive_data(int client_socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    return strdup(buffer);
}

// Function to handle client connections
void handle_client(int client_socket) {
    char *message = receive_data(client_socket);
    printf("Client %d: %s\n", client_socket, message);
    
    int dice_roll = roll_dice();
    char *response = malloc(50 * sizeof(char));
    sprintf(response, "You rolled a %d\n", dice_roll);
    
    send_data(client_socket, response);
    free(response);
    close(client_socket);
}

// Main function to start the server
int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    
    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error("socket failed");
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    
    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("bind failed");
    }
    
    // Listen for connections
    if (listen(server_socket, BACKLOG) < 0) {
        error("listen failed");
    }
    
    printf("Server is listening on port %d\n", PORT);
    
    while (1) {
        // Accept client connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, sizeof(client_addr))) < 0) {
            error("accept failed");
        }
        
        printf("Client %d connected\n", client_socket);
        
        // Handle client in a separate thread
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, (void *)handle_client, (void *)&client_socket)!= 0) {
            error("pthread_create failed");
        }
    }
    
    return 0;
}