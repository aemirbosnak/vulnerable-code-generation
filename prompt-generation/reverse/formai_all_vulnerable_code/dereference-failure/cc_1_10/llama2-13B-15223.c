//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct server_context {
    int sock;
    struct sockaddr_in server_addr;
};

struct client_context {
    int sock;
    struct sockaddr_in client_addr;
};

void init_server_context(struct server_context *context) {
    context->sock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&context->server_addr, 0, sizeof(context->server_addr));
    context->server_addr.sin_family = AF_INET;
    context->server_addr.sin_port = htons(PORT);
    if (bind(context->sock, (struct sockaddr *)&context->server_addr, sizeof(context->server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(context->sock, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
}

void handle_client_connection(struct server_context *context, int client_sock) {
    struct client_context *client_context;
    socklen_t client_len = sizeof(struct sockaddr_in);
    int client_addr_size = getpeername(client_sock, (struct sockaddr *)&client_context->client_addr, &client_len);
    if (client_addr_size < 0) {
        perror("getpeername failed");
        exit(EXIT_FAILURE);
    }
    printf("Client connected from IP address %s and port %d\n", inet_ntoa(client_context->client_addr.sin_addr), ntohs(client_context->client_addr.sin_port));
    // Handle client request here
}

int main(int argc, char *argv[]) {
    struct server_context context;
    init_server_context(&context);
    while (1) {
        int client_sock = accept(context.sock, NULL, NULL);
        handle_client_connection(&context, client_sock);
        close(client_sock);
    }
    return 0;
}