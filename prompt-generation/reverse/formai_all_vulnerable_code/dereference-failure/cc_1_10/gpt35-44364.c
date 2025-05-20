//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <proxy_port> <server_port>\n", argv[0]);
        exit(1);
    }

    int proxy_port = atoi(argv[1]);
    int server_port = atoi(argv[2]);

    // Create socket for proxy server
    int proxy_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_sock < 0) {
        error("ERROR opening proxy socket");
    }

    // Bind socket to local address and port
    struct sockaddr_in proxy_addr, serv_addr;
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_addr.sin_port = htons(proxy_port);
    if (bind(proxy_sock, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        error("ERROR on binding proxy socket");
    }

    // Listen on proxy socket
    if (listen(proxy_sock, 5) < 0) {
        error("ERROR on proxy socket listen");
    }
    printf("Proxy listening on port %d...\n", proxy_port);

    // Accept incoming client connections
    while (1) {
        int client_sock = accept(proxy_sock, NULL, NULL);
        if (client_sock < 0) {
            error("ERROR on proxy socket client accept");
        }

        // Connect to server
        int server_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sock < 0) {
            error("ERROR opening server socket");
        }

        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        serv_addr.sin_port = htons(server_port);
        if (connect(server_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            error("ERROR connecting to server");
        }

        // Forward client data to server
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_read = read(client_sock, buffer, BUFFER_SIZE - 1);
        if (bytes_read < 0) {
            error("ERROR reading from client");
        }

        if (strncmp(buffer, "GET ", 4) == 0 || strncmp(buffer, "POST ", 5) == 0) {
            printf("Forwarding request:\n%s\n", buffer);
        }

        if (write(server_sock, buffer, bytes_read) < 0) {
            error("ERROR writing to server");
        }

        // Forward server data to client
        memset(buffer, 0, BUFFER_SIZE);
        bytes_read = read(server_sock, buffer, BUFFER_SIZE - 1);
        if (bytes_read < 0) {
            error("ERROR reading from server");
        }

        if (strncmp(buffer, "HTTP/1.1 200 OK", 15) == 0) {
            printf("Forwarding response:\n%s\n", buffer);
        }

        if (write(client_sock, buffer, bytes_read) < 0) {
            error("ERROR writing to client");
        }

        close(client_sock);
        close(server_sock);
    }

    close(proxy_sock);
    return 0;
}