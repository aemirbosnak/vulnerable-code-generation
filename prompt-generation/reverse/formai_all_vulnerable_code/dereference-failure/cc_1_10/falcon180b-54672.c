//Falcon-180B DATASET v1.0 Category: Firewall ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>

#define MAX_CLIENTS 50
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
int num_clients = 0;
int server_socket;

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        printf("Received message from client %d: %s\n", client_socket, buffer);
        send(client_socket, buffer, bytes_received, 0);
    }

    close(client_socket);
}

void accept_connections() {
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            close(client_socket);
            continue;
        }

        clients[num_clients++] = client_socket;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
    }
}

int main() {
    int opt = 1;
    struct sockaddr_in server_addr;

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_socket, 5);

    printf("Server started on port 8080\n");

    accept_connections();

    return 0;
}