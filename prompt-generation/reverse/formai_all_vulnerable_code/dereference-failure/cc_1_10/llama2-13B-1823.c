//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: genius
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
    socklen_t client_len;
};

void handle_request(int sock, struct sockaddr_in *client_addr, socklen_t client_len) {
    char buffer[4096];
    int bytes_read;

    printf("Received request from client %s:%d\n", inet_ntoa(client_addr->sin_addr), ntohs(client_addr->sin_port));

    // Read request data
    bytes_read = recv(sock, buffer, sizeof(buffer), 0);
    if (bytes_read <= 0) {
        printf("Error reading request data\n");
        return;
    }

    // Parse request data
    char *request_data = strtok(buffer, "\n");
    while (request_data != NULL && request_data[0] != '\0') {
        printf("Request data: %s\n", request_data);
        request_data = strtok(NULL, "\n");
    }

    // Send response data
    char *response_data = "Hello, world!";
    send(sock, response_data, strlen(response_data), 0);

    // Close connection
    close(sock);
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    listen(sock, 3);

    struct server_context *context = malloc(sizeof(struct server_context));
    context->sock = sock;
    context->client_addr = server_addr;
    context->client_len = sizeof(server_addr);

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("Error accepting connection");
            exit(1);
        }

        handle_request(client_sock, &context->client_addr, context->client_len);

        free(context);
    }

    return 0;
}