//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10
#define SERVER_PORT 8080

int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(*((int *) client_socket), buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            close(*((int *) client_socket));
            pthread_exit(NULL);
        }
        buffer[bytes_received] = '\0';
        printf("%s\n", buffer);
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_socket, MAX_CLIENTS);

    while (1) {
        printf("Waiting for client...\n");
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting client\n");
            continue;
        }
        client_sockets[num_clients] = client_socket;
        num_clients++;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, &client_socket);
    }

    return 0;
}