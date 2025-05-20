//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct server_context {
    int sock;
    int client_sock;
    struct sockaddr_in client_addr;
};

void handle_connection(int sock) {
    struct server_context *context = malloc(sizeof(struct server_context));
    context->sock = sock;
    context->client_sock = accept(sock, NULL, NULL);
    printf("Connection accepted from IPv4 address %s port %d\n",
           inet_ntoa(context->client_addr.sin_addr), ntohs(context->client_addr.sin_port));

    char buffer[1024];
    read(context->client_sock, buffer, 1024);
    printf("Received message: %s\n", buffer);

    char *message = "Hello, world!";
    send(context->client_sock, message, strlen(message), 0);

    close(context->client_sock);
    free(context);
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT),
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sock, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        struct server_context *context = malloc(sizeof(struct server_context));
        context->sock = accept(sock, NULL, NULL);
        handle_connection(context->sock);
        free(context);
    }

    return 0;
}