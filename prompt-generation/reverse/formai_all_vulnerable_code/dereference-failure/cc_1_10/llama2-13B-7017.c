//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct server_context {
    int sock;
    struct sockaddr_in client_addr;
};

void handle_request(int sock, struct sockaddr_in *client_addr) {
    char buffer[1024];
    int bytes_read;

    printf("Connection established from IP: %s, Port: %d\n",
           inet_ntoa(client_addr->sin_addr), ntohs(client_addr->sin_port));

    // Read request
    bytes_read = recv(sock, buffer, 1024, 0);
    if (bytes_read < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    // Print request
    printf("Request: %s\n", buffer);

    // Send response
    char *message = "Hello, world!";
    send(sock, message, strlen(message), 0);

    // Close connection
    close(sock);
}

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sock, 3);

    struct server_context *ctx = malloc(sizeof(struct server_context));
    ctx->sock = sock;
    ctx->client_addr = server_addr;

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        handle_request(client_sock, &ctx->client_addr);
        close(client_sock);
    }

    return 0;
}