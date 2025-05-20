//Falcon-180B DATASET v1.0 Category: Chat server ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

// Maximum number of clients that can connect to the server
#define MAX_CLIENTS 10

// Structure to hold client socket information
typedef struct {
    int sock;
    struct sockaddr_in addr;
} Client;

// Array to hold all connected clients
Client clients[MAX_CLIENTS];

// Number of connected clients
int num_clients = 0;

// Function to broadcast a message to all connected clients
void broadcast(int sender_sock, char* message) {
    for(int i = 0; i < num_clients; i++) {
        if(clients[i].sock!= sender_sock) {
            send(clients[i].sock, message, strlen(message), 0);
        }
    }
}

// Function to handle a single client connection
void handle_client(int client_sock) {
    char buffer[1024];
    while(1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_sock, buffer, sizeof(buffer), 0);
        if(bytes_received <= 0) {
            break;
        }
        broadcast(client_sock, buffer);
    }
    close(client_sock);
}

// Main function to start the server and listen for client connections
int main(int argc, char* argv[]) {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));

    listen(server_sock, MAX_CLIENTS);

    printf("Server started on port 8080\n");

    while(1) {
        int client_sock = accept(server_sock, NULL, NULL);
        if(client_sock == -1) {
            continue;
        }
        if(num_clients >= MAX_CLIENTS) {
            send(client_sock, "Server is full.\n", strlen("Server is full.\n"), 0);
            close(client_sock);
            continue;
        }
        clients[num_clients].sock = client_sock;
        clients[num_clients].addr = *(struct sockaddr_in*)&(((struct sockaddr*)&server_addr)->sa_data);
        num_clients++;
        printf("Client connected: %s:%d\n", inet_ntoa(clients[num_clients-1].addr.sin_addr), ntohs(clients[num_clients-1].addr.sin_port));
        handle_client(client_sock);
    }

    close(server_sock);
    return 0;
}