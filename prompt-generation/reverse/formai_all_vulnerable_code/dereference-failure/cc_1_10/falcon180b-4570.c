//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client {
    int sock;
    char ip[16];
    int port;
};

struct client clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    int client_sock = *(int *) arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Client %s:%d sent: %s\n", clients[client_sock].ip, clients[client_sock].port, buffer);
    }

    close(client_sock);
    num_clients--;
}

void accept_connections() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_sock, 3);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_size = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &addr_size);

        if (num_clients >= MAX_CLIENTS) {
            send(client_sock, "Server is full.\r\n", 15, 0);
            close(client_sock);
            continue;
        }

        strcpy(clients[num_clients].ip, inet_ntoa(client_addr.sin_addr));
        clients[num_clients].port = ntohs(client_addr.sin_port);
        clients[num_clients].sock = client_sock;

        printf("Client connected: %s:%d\n", clients[num_clients].ip, clients[num_clients].port);
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_sock);
    }
}

int main() {
    accept_connections();

    return 0;
}