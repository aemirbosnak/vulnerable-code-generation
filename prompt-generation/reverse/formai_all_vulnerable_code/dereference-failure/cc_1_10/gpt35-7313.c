//FormAI DATASET v1.0 Category: Simple Web Server ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

typedef struct {
    int client_socket;
    struct sockaddr_in client_address;
} client_info;

void *handle_client(void *args) {
    client_info *info = (client_info *) args;

    char buffer[BUFFER_SIZE];
    ssize_t read_count = read(info->client_socket, buffer, BUFFER_SIZE);
    if (read_count < 0) {
        perror("read from client failed");
        close(info->client_socket);
        free(info);
        pthread_exit(NULL);
    }

    printf("Received request from %s:%d:\n%s\n", inet_ntoa(info->client_address.sin_addr),
            ntohs(info->client_address.sin_port), buffer);
    
    char *response = "HTTP/1.1 200 OK\r\n"
                     "Content-Type: text/html;charset=UTF-8\r\n"
                     "\r\n"
                     "<html><head><title>Simple Web Server</title></head>"
                     "<body><h1>Welcome to my simple web server!</h1></body></html>";
    ssize_t write_count = write(info->client_socket, response, strlen(response));
    if (write_count < 0) {
        perror("write response to client failed");
    }

    close(info->client_socket);
    free(info);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("create server socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address = {0};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[1]));
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof server_address) < 0) {
        perror("bind server socket failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 10) < 0) {
        perror("listen server socket failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server started, listening on port %s...\n", argv[1]);

    while (1) {
        struct sockaddr_in client_address = {0};
        socklen_t client_address_size = sizeof client_address;
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_size);
        if (client_socket < 0) {
            perror("accept client socket failed");
            continue;
        }

        client_info *info = malloc(sizeof *info);
        info->client_socket = client_socket;
        info->client_address = client_address;

        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, info) != 0) {
            perror("create thread failed");
            close(client_socket);
            free(info);
        }
    }

    close(server_socket);
    return 0;
}