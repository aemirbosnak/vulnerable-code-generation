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
    int num_clients;
    struct sockaddr_in client_addr;
};

void handle_request(int sock, struct sockaddr_in *client_addr) {
    char buffer[1024];
    int bytes_read;

    printf("New client connected! IP: %s\n", inet_ntoa(client_addr->sin_addr));

    // Read request
    bytes_read = read(sock, buffer, 1024);
    buffer[bytes_read] = 0; // Null-terminate

    printf("Request: %s\n", buffer);

    // Handle request
    if (strcmp(buffer, "/hello") == 0) {
        send(sock, "Hello, world!", 13, 0);
    } else if (strcmp(buffer, "/happy") == 0) {
        send(sock, "Happy days are here again! 😊", 22, 0);
    } else {
        send(sock, "Unsupported request.", 18, 0);
    }

    // Close connection
    close(sock);
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind socket
    bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Listen for incoming connections
    listen(sock, 3);

    struct server_context *context = malloc(sizeof(struct server_context));
    context->sock = sock;
    context->num_clients = 0;

    while (1) {
        // Accept incoming connection
        int client_sock = accept(sock, NULL, NULL);
        struct sockaddr_in client_addr;
        getpeername(client_sock, (struct sockaddr *)&client_addr, NULL);

        // Handle request
        handle_request(client_sock, &client_addr);

        // Decrement client count
        context->num_clients--;
    }

    return 0;
}