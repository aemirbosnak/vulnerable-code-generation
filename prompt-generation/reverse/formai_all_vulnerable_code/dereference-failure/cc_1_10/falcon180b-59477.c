//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

// Struct for each client
typedef struct {
    int socket;
    char ip[16];
    char username[32];
    char password[32];
    int authenticated;
} client_t;

// Struct for the thread data
typedef struct {
    int index;
    client_t* client;
} thread_data_t;

// Function prototypes
void* handle_client(void* arg);
void accept_connections(int server_socket);

// Global variables
client_t clients[MAX_CONNECTIONS];
pthread_t threads[MAX_CONNECTIONS];
int num_clients = 0;

int main(int argc, char* argv[]) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, MAX_CONNECTIONS) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server started on port 8080\n");

    accept_connections(server_socket);

    return 0;
}

void accept_connections(int server_socket) {
    while (num_clients < MAX_CONNECTIONS) {
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_len);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        clients[num_clients].socket = client_socket;
        strcpy(clients[num_clients].ip, inet_ntoa(client_addr.sin_addr));
        clients[num_clients].authenticated = 0;

        pthread_create(&threads[num_clients], NULL, handle_client, &clients[num_clients]);
        num_clients++;
    }
}

void* handle_client(void* arg) {
    client_t* client = arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client->socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Client disconnected\n");
            close(client->socket);
            pthread_exit(0);
        }

        printf("Received message from %s: %s\n", client->ip, buffer);
    }
}