//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define PORT 8080
#define MAX_CLIENTS 5

struct client_info {
    int socket;
    char ip_address[INET6_ADDRSTRLEN];
    struct sockaddr_in server_addr;
};

void *handle_client(void *arg) {
    struct client_info *client = (struct client_info *) arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client->socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Client %s sent message: %s\n", inet_ntoa(client->server_addr.sin_addr), buffer);
        send(client->socket, buffer, strlen(buffer), 0);
    }

    close(client->socket);
    free(client);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_size);

        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        struct client_info *new_client = (struct client_info *) malloc(sizeof(struct client_info));

        inet_ntop(AF_INET, &client_addr.sin_addr, new_client->ip_address, INET6_ADDRSTRLEN);
        memcpy(&new_client->server_addr, &server_addr, sizeof(server_addr));
        new_client->socket = client_socket;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) new_client);
    }

    close(server_socket);

    return 0;
}