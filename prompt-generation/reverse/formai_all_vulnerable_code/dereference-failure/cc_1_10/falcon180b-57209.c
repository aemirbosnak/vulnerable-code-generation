//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_CLIENTS 1000
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *socket_desc) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int client_socket = *(int *) socket_desc;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        send(client_socket, buffer, bytes_received, 0);
    }

    close(client_socket);
    return NULL;
}

int main(int argc, char *argv[]) {
    int server_socket, new_socket, addrlen;
    struct sockaddr_in server_addr, client_addr;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        perror("socket failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[2]));

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Server is running on IP %s and port %d\n", argv[1], atoi(argv[2]));

    while (1) {
        addrlen = sizeof(client_addr);
        new_socket = accept(server_socket, (struct sockaddr *) &client_addr, &addrlen);

        if (new_socket == -1) {
            perror("accept");
            exit(1);
        }

        if (num_clients >= MAX_CLIENTS) {
            send(new_socket, "Server is full. Please try again later.\n", strlen("Server is full. Please try again later.\n"), 0);
            close(new_socket);
            continue;
        }

        client_sockets[num_clients] = new_socket;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_sockets[num_clients - 1]);
    }

    return 0;
}