//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define LISTEN_PORT 8080
#define MAX_REQUEST_SIZE 2048
#define BUFFER_SIZE 1024

void serve_client(int client_socket) {
    int server_socket, ret;
    char request[MAX_REQUEST_SIZE], buffer[BUFFER_SIZE];

    // Receive request from client
    ret = recv(client_socket, request, MAX_REQUEST_SIZE, 0);
    if (ret < 0) {
        perror("ERROR: Failed to receive request from client");
        return;
    }

    // Parse request to get remote server and port number
    char remote_server[100];
    int remote_port;
    sscanf(request, "GET http://%99[^/:]:%d/", remote_server, &remote_port);

    // Connect to remote server
    struct sockaddr_in server_addr;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("ERROR: Failed to create server socket");
        return;
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(remote_port);
    ret = inet_pton(AF_INET, remote_server, &server_addr.sin_addr);
    if (ret < 0) {
        perror("ERROR: Failed to convert remote server address");
        return;
    }
    ret = connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (ret < 0) {
        perror("ERROR: Failed to connect to remote server");
        return;
    }

    // Forward request to remote server
    ret = send(server_socket, request, strlen(request), 0);
    if (ret < 0) {
        perror("ERROR: Failed to forward request to server");
        return;
    }

    // Receive response from remote server
    while (1) {
        ret = recv(server_socket, buffer, BUFFER_SIZE, 0);
        if (ret == 0) break; // Connection closed by server
        if (ret < 0) {
            perror("ERROR: Failed to receive response from server");
            return;
        }
        // Forward response to client
        ret = send(client_socket, buffer, ret, 0);
        if (ret < 0) {
            perror("ERROR: Failed to forward response to client");
            return;
        }
    }

    // Close sockets
    close(server_socket);
    close(client_socket);
}

int main() {
    int server_socket, client_socket, ret;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    char client_address[INET_ADDRSTRLEN];

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("ERROR: Failed to create server socket");
        exit(errno);
    }

    // Bind server socket to listen port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(LISTEN_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    ret = bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (ret < 0) {
        perror("ERROR: Failed to bind server socket");
        exit(errno);
    }

    // Listen for incoming connections
    ret = listen(server_socket, 5);
    if (ret < 0) {
        perror("ERROR: Failed to listen on server socket");
        exit(errno);
    }

    // Wait for incoming connections
    while (1) {
        client_addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("ERROR: Failed to accept incoming connection");
            continue;
        }
        inet_ntop(AF_INET, &client_addr.sin_addr, client_address, INET_ADDRSTRLEN);
        printf("Accepted connection from %s\n", client_address);
        serve_client(client_socket);
    }

    return 0;
}