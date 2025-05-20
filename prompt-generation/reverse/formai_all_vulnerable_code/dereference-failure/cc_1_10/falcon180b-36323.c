//Falcon-180B DATASET v1.0 Category: Chat server ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define SERVER_PORT 8080

int server_socket;
int clients[MAX_CLIENTS][2];
int num_clients;

void * handle_client(void * client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        send(client_socket, buffer, bytes_received, 0);
    }

    close(client_socket);

    return NULL;
}

void accept_connections() {
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                perror("accept");
                exit(1);
            }
        }

        if (num_clients >= MAX_CLIENTS) {
            send(client_socket, "SERVER FULL\n", 12, 0);
            close(client_socket);
            continue;
        }

        clients[num_clients][0] = client_socket;
        clients[num_clients][1] = 0;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) clients[num_clients - 1][0]);
    }
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, 3) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Chat server started on port %d\n", SERVER_PORT);

    accept_connections();

    return 0;
}