//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096

typedef struct ProxyState {
    int state;
    char buffer[MAX_BUFFER_SIZE];
    struct ProxyState* next;
} ProxyState;

ProxyState* head = NULL;

void proxy_handler(int sockfd) {
    ProxyState* state = malloc(sizeof(ProxyState));
    state->state = 0;
    strcpy(state->buffer, "");
    state->next = head;
    head = state;

    char* line = NULL;
    size_t len = 0;

    // Read client request line
    line = fgets(state->buffer, MAX_BUFFER_SIZE, stdin);

    // Check if client has sent an HTTP GET request
    if (line && strstr(line, "GET")) {
        // Send proxy response header
        write(sockfd, "HTTP/1.1 200 OK\r\n", 26);
        write(sockfd, "Content-Type: text/html\r\n", 38);
        write(sockfd, "\r\n", 2);

        // Forward client request to server
        int serverfd = socket(AF_INET, SOCK_STREAM, htons(80));
        connect(serverfd, NULL, NULL);
        write(serverfd, line, len);

        // Read server response and forward to client
        line = fgets(state->buffer, MAX_BUFFER_SIZE, stdin);
        write(sockfd, line, strlen(line));
    } else {
        // Send error message to client
        write(sockfd, "Error: Invalid request method.\r\n", 42);
    }

    free(state);
}

int main() {
    int sockfd;
    struct sockaddr_in sock_addr;

    // Bind socket to port 8080
    sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    sock_addr.sin_port = htons(8080);
    bind(sockfd, (struct sockaddr*)&sock_addr, sizeof(sock_addr));

    // Listen for client connections
    while (1) {
        // Accept client connection
        int clientfd = accept(sockfd, NULL, NULL);

        // Handle client connection
        proxy_handler(clientfd);

        // Close client connection
        close(clientfd);
    }

    return 0;
}