//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} client_t;

typedef struct {
    int num_clients;
    client_t* clients;
} server_t;

server_t* server_init() {
    server_t* server = malloc(sizeof(server_t));
    server->num_clients = 0;
    server->clients = malloc(sizeof(client_t));
    return server;
}

void server_add_client(server_t* server, client_t* client) {
    server->clients[server->num_clients++] = *client;
}

void server_send_message(server_t* server, char* message) {
    for (int i = 0; i < server->num_clients; i++) {
        send(server->clients[i].sockfd, message, strlen(message), 0);
    }
}

void server_close(server_t* server) {
    for (int i = 0; i < server->num_clients; i++) {
        close(server->clients[i].sockfd);
    }
    free(server->clients);
    free(server);
}

client_t* client_init(char* ip, int port) {
    client_t* client = malloc(sizeof(client_t));
    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    client->addr.sin_family = AF_INET;
    client->addr.sin_port = htons(port);
    client->addr.sin_addr.s_addr = inet_addr(ip);
    return client;
}

void client_connect(client_t* client) {
    if (connect(client->sockfd, (struct sockaddr*)&client->addr, sizeof(client->addr)) != 0) {
        perror("client_connect");
        exit(1);
    }
}

void client_send_message(client_t* client, char* message) {
    send(client->sockfd, message, strlen(message), 0);
}

void client_close(client_t* client) {
    close(client->sockfd);
    free(client);
}

int main() {
    server_t* server = server_init();
    char buffer[1024];

    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) != 0) {
        perror("bind");
        exit(1);
    }

    if (listen(server_sockfd, 5) != 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        client_t* client = client_init("127.0.0.1", PORT);
        client_connect(client);
        server_add_client(server, client);

        while (1) {
            memset(buffer, 0, sizeof(buffer));
            int n = recv(client->sockfd, buffer, sizeof(buffer), 0);
            if (n <= 0) {
                client_close(client);
                break;
            }

            server_send_message(server, buffer);
        }
    }

    server_close(server);
    return 0;
}