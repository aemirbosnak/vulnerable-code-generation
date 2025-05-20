//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 8080

struct server_context {
    int sock;
    struct sockaddr_in server_addr;
    socklen_t client_len;
    char buffer[BUFFER_SIZE];
};

void handle_client(int sock) {
    struct server_context *ctx = (struct server_context *)sock;
    char *client_message;
    int client_len;

    // Receive message from client
    client_len = recv(sock, ctx->buffer, BUFFER_SIZE, 0);
    if (client_len <= 0) {
        perror("recv");
        close(sock);
        return;
    }

    client_message = ctx->buffer;

    // Print received message
    printf("Received message from client: %s\n", client_message);

    // Send response to client
    char *response = "Hello, client!";
    send(sock, response, strlen(response), 0);
}

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(sock);
        exit(EXIT_FAILURE);
    }

    listen(sock, 3);

    struct server_context ctx = {
        .sock = sock,
        .server_addr = server_addr,
        .client_len = 0
    };

    while (1) {
        // Accept client connection
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept");
            continue;
        }

        // Create new context for client
        struct server_context *new_ctx = (struct server_context *)malloc(sizeof(struct server_context));
        new_ctx->sock = client_sock;
        new_ctx->server_addr = server_addr;
        new_ctx->client_len = 0;

        // Start handling client
        handle_client(new_ctx->sock);

        // Free context memory
        free(new_ctx);
    }

    close(sock);
    return 0;
}