//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: complete
// C Simple HTTP Proxy Example Program
// By Your Name Here

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int port = 8080; // Default port number
    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
    } else {
        port = atoi(argv[1]);
    }

    int proxy_fd, client_fd, server_fd;
    socklen_t client_len, server_len;
    struct sockaddr_in proxy_addr, client_addr, server_addr;
    char buffer[BUFFER_SIZE];

    proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_fd == -1) {
        error("Error opening socket");
    }

    memset(&proxy_addr, '\0', sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(port);

    if (bind(proxy_fd, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) == -1) {
        error("Error on binding");
    }

    if (listen(proxy_fd, 10) == -1) {
        error("Error on listen");
    }

    printf("Proxy server listening on port %d...\n", port);

    while (1) {
        client_len = sizeof(client_addr);
        client_fd = accept(proxy_fd, (struct sockaddr *) &client_addr, &client_len);

        if (client_fd == -1) {
            error("Error on accept");
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        memset(buffer, '\0', BUFFER_SIZE);
        if (read(client_fd, buffer, BUFFER_SIZE - 1) == -1) {
            error("Error reading from socket");
        }

        printf("Request received:\n%s\n", buffer);

        // Parse request to get server details
        char *method, *path, *version, *host, *hostname;
        method = strtok(buffer, " ");
        path = strtok(NULL, " ");
        version = strtok(NULL, "\r");
        strtok(NULL, " "); // Skip the first /
        host = strtok(NULL, "\r");
        strtok(host, " "); // Skip the Host: part
        hostname = strtok(NULL, "\r");

        printf("Host: %s, Hostname: %s\n", host, hostname);

        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd == -1) {
            error("Error opening socket");
        }

        struct hostent *he = gethostbyname(hostname);
        if (he == NULL) {
            error("Error resolving hostname");
        }

        memset(&server_addr, '\0', sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr = *((struct in_addr *) he->h_addr);
        server_addr.sin_port = htons(80);

        printf("Connecting to %s:%d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));

        if (connect(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
            error("Error connecting to server");
        }

        printf("Connected!\n");

        // Forward request to server
        if (write(server_fd, buffer, strlen(buffer)) == -1) {
            error("Error writing to socket");
        }

        // Forward response to client
        while (recv(server_fd, buffer, BUFFER_SIZE, 0) > 0) {
            if (send(client_fd, buffer, strlen(buffer), 0) == -1) {
                error("Error sending response to client");
            }
        }

        close(server_fd);
        close(client_fd);
    }

    return 0;
}