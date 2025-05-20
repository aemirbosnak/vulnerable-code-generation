//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

struct proxy_request {
    int client_fd;
    int server_fd;
    char *request;
    char *host;
    int port;
};

void *handle_client(void *arg) {
    struct proxy_request *request = (struct proxy_request *)arg;

    // Send the request to the server
    send(request->server_fd, request->request, strlen(request->request), 0);

    // Receive the response from the server
    char buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(request->server_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        // Send the response to the client
        send(request->client_fd, buffer, bytes_received, 0);
    }

    // Close the client and server connections
    close(request->client_fd);
    close(request->server_fd);

    // Free the request struct
    free(request);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Create the proxy socket
    int proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_fd == -1) {
        perror("socket");
        return 1;
    }

    // Set the proxy socket options
    int optval = 1;
    if (setsockopt(proxy_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        return 1;
    }

    // Bind the proxy socket to the proxy port
    struct sockaddr_in proxy_addr;
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_addr.sin_port = htons(atoi(argv[1]));
    if (bind(proxy_fd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections on the proxy socket
    if (listen(proxy_fd, 10) == -1) {
        perror("listen");
        return 1;
    }

    // Accept incoming connections on the proxy socket
    while (1) {
        // Accept the incoming connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(proxy_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd == -1) {
            perror("accept");
            continue;
        }

        // Parse the HTTP request from the client
        char buffer[BUFFER_SIZE];
        int bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            close(client_fd);
            continue;
        }
        buffer[bytes_received] = '\0';

        char *request_line = strtok(buffer, "\r\n");
        char *method = strtok(request_line, " ");
        char *path = strtok(NULL, " ");
        char *version = strtok(NULL, "\r\n");

        char *host = NULL;
        int port = 80;
        if (strncasecmp(method, "CONNECT", 7) == 0) {
            host = strtok(path, ":");
            port = atoi(strtok(NULL, ":"));
        } else {
            host = strtok(path, "/");
            port = 80;
        }

        // Create the server socket
        int server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd == -1) {
            perror("socket");
            close(client_fd);
            continue;
        }

        // Connect the server socket to the server
        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(host);
        server_addr.sin_port = htons(port);
        if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            perror("connect");
            close(client_fd);
            close(server_fd);
            continue;
        }

        // Create the proxy request struct
        struct proxy_request *request = malloc(sizeof(struct proxy_request));
        request->client_fd = client_fd;
        request->server_fd = server_fd;
        request->request = buffer;
        request->host = host;
        request->port = port;

        // Create a new thread to handle the client request
        pthread_t thread;
        if (pthread_create(&thread, NULL, handle_client, (void *)request) != 0) {
            perror("pthread_create");
            close(client_fd);
            close(server_fd);
            free(request);
            continue;
        }

        // Detach the thread so that it can run independently
        pthread_detach(thread);
    }

    // Close the proxy socket
    close(proxy_fd);

    return 0;
}