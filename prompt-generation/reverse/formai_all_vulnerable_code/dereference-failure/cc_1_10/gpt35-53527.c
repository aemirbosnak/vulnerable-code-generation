//FormAI DATASET v1.0 Category: Socket programming ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CONNECTIONS 10

typedef struct {
    int socket_fd;
    struct sockaddr_in address;
} client_connection;

void *handle_connection(void *arg) {
    client_connection *client = (client_connection *) arg;
    char buffer[1024] = {0};
    int valread = 0;
    while ((valread = read(client->socket_fd, buffer, 1024)) > 0 ) {
        send(client->socket_fd , buffer , strlen(buffer) , 0 );
        memset(buffer, 0, sizeof(buffer));
    }
    close(client->socket_fd);
    free(client);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    pthread_t thread_id;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Error bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("Error listen");
        exit(EXIT_FAILURE);
    }

    printf("\nServer is listening on port %d\n", PORT);

    while(1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Error accept");
            exit(EXIT_FAILURE);
        }

        printf("\nNew client connected.\n");

        client_connection *client = malloc(sizeof(client_connection));
        client->socket_fd = new_socket;
        client->address = address;

        if (pthread_create(&thread_id, NULL, handle_connection, (void *) client) < 0) {
            perror("Error thread create");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}