//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: curious
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

    printf("Client connecting...\n");

    // Read request
    bytes_read = recv(sock, buffer, 1024, 0);
    if (bytes_read < 0) {
        perror("recv");
        close(sock);
        return;
    }

    printf("Request received: %s\n", buffer);

    // Handle request
    if (strcmp(buffer, "GET /") == 0) {
        char *message = "Hello, world!";
        send(sock, message, strlen(message), 0);
    } else if (strcmp(buffer, "GET /about") == 0) {
        char *message = "This is a simple web server written in C.";
        send(sock, message, strlen(message), 0);
    } else {
        printf("Invalid request\n");
        close(sock);
        return;
    }

    printf("Response sent\n");
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
        exit(EXIT_FAILURE);
    }

    if (listen(sock, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    struct server_context *context = malloc(sizeof(struct server_context));
    context->sock = sock;
    context->client_addr = server_addr;

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept");
            continue;
        }

        handle_request(client_sock, &context->client_addr);

        close(client_sock);
    }

    return 0;
}