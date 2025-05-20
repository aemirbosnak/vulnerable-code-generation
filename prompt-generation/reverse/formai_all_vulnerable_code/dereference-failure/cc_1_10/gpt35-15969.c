//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 4096

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int proxy(int client_sock, struct sockaddr_in *server_addr) {
    int server_sock, bytes;
    char buffer[BUF_SIZE];
    struct sockaddr_in proxy_server_addr;

    // Create socket for server
    if ((server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        error("ERROR: unable to create server socket");
    }

    // Connect to server
    if (connect(server_sock, (struct sockaddr*) server_addr, sizeof(*server_addr)) < 0) {
        error("ERROR: unable to connect to server");
    }

    // Loop until server closes connection
    while ((bytes = recv(client_sock, buffer, BUF_SIZE, 0)) > 0) {
        // Forward client request to server
        if (send(server_sock, buffer, bytes, 0) < 0) {
            error("ERROR: unable to forward request to server");
        }

        // Receive response from server
        if ((bytes = recv(server_sock, buffer, BUF_SIZE, 0)) < 0) {
            error("ERROR: unable to receive response from server");
        }

        // Forward server response to client
        if (send(client_sock, buffer, bytes, 0) < 0) {
            error("ERROR: unable to forward response to client");
        }
    }

    // Close server socket
    close(server_sock);

    return 0;
}

int main(int argc, char **argv) {
    int proxy_sock, client_sock, optval = 1;
    unsigned int port = 8080;
    struct sockaddr_in proxy_addr, client_addr, server_addr;
    struct hostent *server;

    // Check arguments
    if (argc < 2) {
        error("Usage: ./proxy <hostname> [port]");
    }

    // Get server information
    if ((server = gethostbyname(argv[1])) == NULL) {
        error("ERROR: unable to resolve server hostname");
    }

    // Parse optional port
    if (argc == 3) {
        port = atoi(argv[2]);
    }

    // Create socket for proxy
    if ((proxy_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        error("ERROR: unable to create proxy socket");
    }

    // Allow reuse of address
    setsockopt(proxy_sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Bind to any interface
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_addr.sin_port = htons(port);

    if (bind(proxy_sock, (struct sockaddr*) &proxy_addr, sizeof(proxy_addr)) < 0) {
        error("ERROR: unable to bind to proxy address");
    }

    printf("Proxy running on port %d\n", port);

    // Listen for incoming connections
    if (listen(proxy_sock, 20) < 0) {
        error("ERROR: unable to listen on proxy socket");
    }

    // Accept incoming connections and handle them in a new thread
    while (1) {
        unsigned int client_len = sizeof(client_addr);

        if ((client_sock = accept(proxy_sock, (struct sockaddr*) &client_addr, &client_len)) < 0) {
            error("ERROR: unable to accept incoming connection");
        }

        // Fill in server address
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr = *(struct in_addr*) server->h_addr_list[0];
        server_addr.sin_port = htons(80);

        // Spawn new thread to handle client request
        if (fork() == 0) {
            close(proxy_sock);
            proxy(client_sock, &server_addr);
            close(client_sock);
            exit(EXIT_SUCCESS);
        } else {
            close(client_sock);
        }
    }

    // Close proxy socket
    close(proxy_sock);

    return 0;
}