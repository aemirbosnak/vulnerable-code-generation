//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 2048
#define PROXY_PORT 8080
#define SERVER_IP "192.168.1.20"
#define SERVER_PORT 80

typedef struct {
    int client_fd;
} connection_args;

void *handle_client_connection(void *args) {
    connection_args *conn = (connection_args *) args;
    char buffer[MAX_BUFFER_SIZE];
    int read_size;
    int server_fd;
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    //Setting up the socket for communicating with server
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    if (connect(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }
    
    while ((read_size = recv(conn->client_fd, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        write(server_fd, buffer, read_size);
        memset(buffer, 0, MAX_BUFFER_SIZE);
        read_size = recv(server_fd, buffer, MAX_BUFFER_SIZE, 0);
        write(conn->client_fd, buffer, read_size);
        memset(buffer, 0, MAX_BUFFER_SIZE);
    }

    if (read_size == 0) {
        puts("Client disconnected");
    } else if (read_size == -1) {
        perror("Receive failed");
    }

    close(conn->client_fd);
    free(conn);
    return 0;
}

int main() {
    int proxy_fd;
    struct sockaddr_in proxy_addr;
    pthread_t thread_id;

    //Setting up the socket for accepting client connections
    proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_fd == -1) {
        perror("Error creating proxy socket");
        exit(EXIT_FAILURE);
    }

    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(PROXY_PORT);

    if (bind(proxy_fd, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    listen(proxy_fd, 5);

    puts("Proxy server is running...");

    while (1) {
        connection_args *conn = malloc(sizeof(connection_args));
        conn->client_fd = accept(proxy_fd, NULL, NULL);
        if (conn->client_fd < 0) {
            perror("Accept failed");
            continue;
        }
        printf("Accepted connection from client: %d\n", conn->client_fd);
        if (pthread_create(&thread_id, NULL, handle_client_connection, (void *) conn) < 0) {
            perror("Thread creation failed");
        }
        pthread_detach(thread_id);
    }

    close(proxy_fd);

    return 0;
}