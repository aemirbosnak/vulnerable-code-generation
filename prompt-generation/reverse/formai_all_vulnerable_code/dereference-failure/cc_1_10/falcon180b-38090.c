//Falcon-180B DATASET v1.0 Category: Chat server ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/sendfile.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_LENGTH 1024
#define PORT 8080

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;
pthread_t thread_ids[MAX_CLIENTS];

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[MAX_MESSAGE_LENGTH];
    ssize_t bytes_received;

    while ((bytes_received = recv(client_socket, buffer, MAX_MESSAGE_LENGTH, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d: %s\n", client_socket, buffer);
        for (int i = 0; i < num_clients; i++) {
            if (i!= client_socket) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
    }

    close(client_socket);
    return NULL;
}

int main() {
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        return 1;
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        return 1;
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_size);

        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        if (num_clients >= MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            close(client_socket);
            continue;
        }

        client_sockets[num_clients] = client_socket;
        num_clients++;

        pthread_create(&thread_ids[num_clients - 1], NULL, handle_client, &client_socket);
    }

    return 0;
}