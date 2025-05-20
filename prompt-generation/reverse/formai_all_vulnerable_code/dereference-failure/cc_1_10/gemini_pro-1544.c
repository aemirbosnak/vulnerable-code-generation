//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CONNECTIONS 10
#define MAX_REQUEST_SIZE 1024

typedef struct thread_args {
    int client_fd;
} thread_args;

void *handle_client(void *args) {
    thread_args *t_args = (thread_args *)args;
    int client_fd = t_args->client_fd;
    free(t_args);

    // Read request from client
    char request[MAX_REQUEST_SIZE];
    memset(request, 0, sizeof(request));
    int bytes_received = recv(client_fd, request, sizeof(request) - 1, 0);
    if (bytes_received <= 0) {
        perror("recv");
        close(client_fd);
        return NULL;
    }

    // Parse request
    char *method = strtok(request, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Handle request
    if (strcmp(method, "GET") == 0) {
        if (strcmp(path, "/") == 0) {
            path = "/index.html";
        }

        // Read file from disk
        char file_path[strlen(path) + 10];
        strcpy(file_path, "htdocs");
        strcat(file_path, path);
        FILE *file = fopen(file_path, "r");
        if (file == NULL) {
            perror("fopen");
            close(client_fd);
            return NULL;
        }

        // Send response to client
        char response[MAX_REQUEST_SIZE];
        memset(response, 0, sizeof(response));
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
        send(client_fd, response, strlen(response), 0);

        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), file)) {
            send(client_fd, buffer, strlen(buffer), 0);
        }

        fclose(file);
    } else {
        // Send error response to client
        char response[MAX_REQUEST_SIZE];
        memset(response, 0, sizeof(response));
        sprintf(response, "HTTP/1.1 400 Bad Request\r\nContent-Type: text/plain\r\n\r\nBad request\n");
        send(client_fd, response, strlen(response), 0);
    }

    // Close client socket
    close(client_fd);
    return NULL;
}

int main() {
    // Create server socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        return 1;
    }

    // Set socket options
    int optval = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Bind socket to address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        close(server_fd);
        return 1;
    }

    // Listen for connections
    if (listen(server_fd, MAX_CONNECTIONS) == -1) {
        perror("listen");
        close(server_fd);
        return 1;
    }

    // Main loop
    while (1) {
        // Accept new connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd == -1) {
            perror("accept");
            continue;
        }

        // Create thread to handle client
        pthread_t thread;
        thread_args *t_args = malloc(sizeof(thread_args));
        t_args->client_fd = client_fd;
        if (pthread_create(&thread, NULL, handle_client, (void *)t_args) != 0) {
            perror("pthread_create");
            close(client_fd);
            continue;
        }

        // Detach thread
        pthread_detach(thread);
    }

    // Close server socket
    close(server_fd);
    return 0;
}