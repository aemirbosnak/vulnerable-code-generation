//FormAI DATASET v1.0 Category: Socket programming ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void *client_handler(void *);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    int server_socket_fd, client_socket_fd;
    struct sockaddr_in server, client;

    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket_fd < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    if(bind(server_socket_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Failed to bind to port");
        exit(1);
    }

    listen(server_socket_fd, 5);

    while(1) {
        printf("Waiting for connections on port %d...\n", port);

        int client_len = sizeof(client);
        client_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client, (socklen_t *)&client_len);

        printf("Connected to client %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        pthread_t client_thread;
        if(pthread_create(&client_thread, NULL, client_handler, (void *)&client_socket_fd) < 0) {
            perror("Failed to create thread for client");
            exit(1);
        }
    }

    close(server_socket_fd);

    return 0;
}

void *client_handler(void *socket_fd) {
    int client_socket_fd = *(int *)socket_fd;
    char buffer[256];
    int n;

    while(1) {
        bzero(buffer, 256);
        n = read(client_socket_fd, buffer, 255);
        if(n < 0) {
            perror("Failed to read from client");
            exit(1);
        }

        printf("Received message: %s", buffer);

        if(strncmp(buffer, "exit", 4) == 0) {
            break;
        }

        n = write(client_socket_fd, "Message received", 16);
        if(n < 0) {
            perror("Failed to write to client");
            exit(1);
        }
    }

    close(client_socket_fd);
    pthread_exit(NULL);
}