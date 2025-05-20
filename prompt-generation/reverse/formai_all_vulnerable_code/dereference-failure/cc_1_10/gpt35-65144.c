//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int connect_to_server(char *host, int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, host, &serv_addr.sin_addr);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting to server");
        exit(1);
    }

    return sockfd;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int server_socket, n;

    printf("Connected to client\n");

    // Read client request
    memset(buffer, 0, BUFFER_SIZE);
    if (read(client_socket, buffer, BUFFER_SIZE) < 0) {
        perror("ERROR reading from client");
        exit(1);
    }

    // Parse host and port from request
    char *host_start = strstr(buffer, "Host: ");
    if (!host_start) {
        printf("Invalid request\n");
        exit(1);
    }
    host_start += 6;
    char *host_end = strchr(host_start, '\r');
    if (!host_end) {
        printf("Invalid request\n");
        exit(1);
    }
    *host_end = '\0';
    char *host = strdup(host_start);

    char *port = "80";
    char *port_start = strstr(host, ":");
    if (port_start) {
        // If :port is specified, extract the port
        port_start++;
        port = strdup(port_start);
        *port_start = '\0';
    }

    // Connect to server
    server_socket = connect_to_server(host, atoi(port));
    free(host);
    free(port);

    // Send request to server
    if (write(server_socket, buffer, strlen(buffer)) < 0) {
        perror("ERROR writing to server");
        exit(1);
    }

    // Read response from server and send to client
    while ((n = read(server_socket, buffer, BUFFER_SIZE)) > 0) {
        if (write(client_socket, buffer, n) < 0) {
            perror("ERROR writing to client");
            exit(1);
        }
        memset(buffer, 0, BUFFER_SIZE);
    }
    if (n < 0) {
        perror("ERROR reading from server");
        exit(1);
    }

    printf("Disconnected from client\n");
}

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in serv_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Bind server socket to port
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));
    if (bind(server_socket, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for incoming connections
    listen(server_socket, 5);
    printf("Listening on port %s\n", argv[1]);

    // Accept incoming connections
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*) &client_addr, &client_len);
        if (client_socket < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        handle_client(client_socket);

        close(client_socket);
    }

    close(server_socket);
    return 0;
}