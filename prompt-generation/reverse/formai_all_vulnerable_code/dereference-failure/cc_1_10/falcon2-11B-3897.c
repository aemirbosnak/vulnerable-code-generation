//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

// Function prototypes
int create_connection(const char* host, const char* port);
int create_socket(int domain, int type, int protocol);
void close_socket(int sockfd);
void connect_socket(int sockfd, const struct sockaddr* server_addr, socklen_t addrlen);
void proxy_handler(int sockfd, int connfd);
void proxy_server(const char* host, const char* port);
void proxy_client(const char* host, const char* port);

int main(int argc, char *argv[]) {
    // Create a socket for the server
    int server_sockfd = create_socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    // Bind the socket to the server's address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = inet_addr(argv[2]);

    if (bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error binding socket\n");
        exit(1);
    }

    // Start listening for incoming connections
    int backlog = 5;
    if (listen(server_sockfd, backlog) < 0) {
        fprintf(stderr, "Error listening on socket\n");
        exit(1);
    }

    // Main proxy server loop
    while (1) {
        // Accept a new connection from the client
        struct sockaddr_in client_addr;
        socklen_t addrlen = sizeof(client_addr);
        int connfd = accept(server_sockfd, (struct sockaddr*)&client_addr, &addrlen);
        if (connfd < 0) {
            fprintf(stderr, "Error accepting connection\n");
            exit(1);
        }

        // Create a new socket for the proxy connection
        int proxy_sockfd = create_socket(AF_INET, SOCK_STREAM, 0);
        if (proxy_sockfd < 0) {
            fprintf(stderr, "Error creating proxy socket\n");
            exit(1);
        }

        // Connect the proxy socket to the client
        struct sockaddr_in proxy_addr;
        proxy_addr.sin_family = AF_INET;
        proxy_addr.sin_port = htons(atoi(argv[3]));
        proxy_addr.sin_addr.s_addr = inet_addr(argv[2]);
        connect_socket(proxy_sockfd, (struct sockaddr*)&proxy_addr, sizeof(proxy_addr));

        // Proxy the client's data to the server and vice versa
        proxy_handler(connfd, proxy_sockfd);

        // Close the proxy socket
        close_socket(proxy_sockfd);

        // Close the client socket
        close_socket(connfd);
    }

    return 0;
}

// Proxy handler function
void proxy_handler(int connfd, int proxy_sockfd) {
    char buffer[1024];
    int nread;
    int nwritten;

    // Main loop for handling data
    while (1) {
        // Read data from the client socket
        nread = read(connfd, buffer, sizeof(buffer));
        if (nread < 0) {
            fprintf(stderr, "Error reading from client socket\n");
            exit(1);
        }

        // Write data to the proxy socket
        nwritten = write(proxy_sockfd, buffer, nread);
        if (nwritten < 0) {
            fprintf(stderr, "Error writing to proxy socket\n");
            exit(1);
        }

        // Read data from the proxy socket
        nread = read(proxy_sockfd, buffer, sizeof(buffer));
        if (nread < 0) {
            fprintf(stderr, "Error reading from proxy socket\n");
            exit(1);
        }

        // Write data to the client socket
        nwritten = write(connfd, buffer, nread);
        if (nwritten < 0) {
            fprintf(stderr, "Error writing to client socket\n");
            exit(1);
        }
    }
}

// Create a new socket
int create_socket(int domain, int type, int protocol) {
    int sockfd;
    if ((sockfd = socket(domain, type, protocol)) < 0) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }
    return sockfd;
}

// Close a socket
void close_socket(int sockfd) {
    close(sockfd);
}

// Connect a socket to a remote host
void connect_socket(int sockfd, const struct sockaddr* server_addr, socklen_t addrlen) {
    int connected = connect(sockfd, server_addr, addrlen);
    if (connected < 0) {
        fprintf(stderr, "Error connecting socket\n");
        exit(1);
    }
}

// Proxy server function
void proxy_server(const char* host, const char* port) {
    // Start listening for incoming connections
    int server_sockfd = create_socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr.s_addr = inet_addr(host);

    if (bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error binding socket\n");
        exit(1);
    }

    if (listen(server_sockfd, 5) < 0) {
        fprintf(stderr, "Error listening on socket\n");
        exit(1);
    }

    // Main proxy server loop
    while (1) {
        // Accept a new connection from the client
        struct sockaddr_in client_addr;
        socklen_t addrlen = sizeof(client_addr);
        int connfd = accept(server_sockfd, (struct sockaddr*)&client_addr, &addrlen);
        if (connfd < 0) {
            fprintf(stderr, "Error accepting connection\n");
            exit(1);
        }

        // Connect the client socket to the proxy
        struct sockaddr_in proxy_addr;
        proxy_addr.sin_family = AF_INET;
        proxy_addr.sin_port = htons(atoi(port));
        proxy_addr.sin_addr.s_addr = inet_addr(host);
        connect_socket(connfd, (struct sockaddr*)&proxy_addr, sizeof(proxy_addr));

        // Proxy the client's data to the server and vice versa
        proxy_handler(connfd, proxy_addr.sin_port);

        // Close the client socket
        close_socket(connfd);
    }
}

// Proxy client function
void proxy_client(const char* host, const char* port) {
    // Create a new socket for the client
    int client_sockfd = create_socket(AF_INET, SOCK_STREAM, 0);
    if (client_sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    // Connect the client socket to the proxy
    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(atoi(port));
    proxy_addr.sin_addr.s_addr = inet_addr(host);
    connect_socket(client_sockfd, (struct sockaddr*)&proxy_addr, sizeof(proxy_addr));

    // Proxy the client's data to the server and vice versa
    proxy_handler(client_sockfd, proxy_addr.sin_port);

    // Close the client socket
    close_socket(client_sockfd);
}