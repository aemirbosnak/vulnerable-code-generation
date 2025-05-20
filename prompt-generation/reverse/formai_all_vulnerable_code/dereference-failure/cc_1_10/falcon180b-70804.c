//Falcon-180B DATASET v1.0 Category: Chat server ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define TRUE    1
#define FALSE   0
#define PORT    8080
#define BACKLOG 10

typedef struct {
    int socket;
    char username[20];
} CLIENT;

CLIENT clients[100];
int num_clients = 0;

void broadcast(int sender_socket, char* message) {
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].socket!= sender_socket) {
            send(clients[i].socket, message, strlen(message), 0);
        }
    }
}

void handle_client(int client_socket) {
    char buffer[1024];
    while (TRUE) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            close(client_socket);
            clients[--num_clients].socket = 0;
            break;
        }
        broadcast(client_socket, buffer);
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_socket, BACKLOG);

    while (TRUE) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (num_clients >= 100) {
            send(client_socket, "Server is full.\n", 16, 0);
            close(client_socket);
            continue;
        }
        clients[num_clients].socket = client_socket;
        char username[20];
        send(client_socket, "Enter your username: ", 22, 0);
        recv(client_socket, username, sizeof(username), 0);
        strcpy(clients[num_clients].username, username);
        num_clients++;
        printf("New client connected: %s\n", username);
    }

    return 0;
}