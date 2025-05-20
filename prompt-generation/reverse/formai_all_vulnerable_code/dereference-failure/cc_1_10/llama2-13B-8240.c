//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

    printf("Received request from client %s\n", inet_ntoa(client_addr->sin_addr));

    // Read request data
    bytes_read = recv(sock, buffer, 1024, 0);
    if (bytes_read <= 0) {
        perror("recv failed");
        return;
    }

    // Print request data
    printf("Request data: %s\n", buffer);

    // Send response
    char *message = "Hello, client!";
    send(sock, message, strlen(message), 0);

    // Close connection
    close(sock);
}

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sock, 3);

    printf("Server listening on port %d...\n", PORT);

    struct server_context *context = malloc(sizeof(struct server_context));
    context->sock = sock;
    context->client_addr = server_addr;

    while (1) {
        // Accept incoming connection
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept failed");
            exit(1);
        }

        handle_request(client_sock, &context->client_addr);
    }

    free(context);
    close(sock);

    return 0;
}