//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    // Parse command line arguments
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <host> <port> <remote_host> <remote_port>\n", argv[0]);
        return 1;
    }
    char *host = argv[1];
    int port = atoi(argv[2]);
    char *remote_host = argv[3];
    int remote_port = atoi(argv[4]);

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // Connect to remote host
    struct sockaddr_in remote_addr;
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(remote_port);
    remote_addr.sin_addr.s_addr = inet_addr(remote_host);
    if (connect(sock, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Create proxy socket
    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(port);
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    int proxy_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_sock == -1) {
        perror("socket");
        return 1;
    }
    if (bind(proxy_sock, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen on proxy socket
    int backlog = 5;
    if (listen(proxy_sock, backlog) == -1) {
        perror("listen");
        return 1;
    }

    // Accept incoming connections
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sock = accept(proxy_sock, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sock == -1) {
        perror("accept");
        return 1;
    }

    // Handle incoming requests
    char buffer[4096];
    int n;
    while ((n = recv(client_sock, buffer, sizeof(buffer), 0)) > 0) {
        // Forward request to remote host
        send(sock, buffer, n, 0);

        // Read response from remote host
        n = recv(sock, buffer, sizeof(buffer), 0);

        // Send response back to client
        send(client_sock, buffer, n, 0);
    }

    // Clean up
    close(client_sock);
    close(sock);
    close(proxy_sock);

    return 0;
}