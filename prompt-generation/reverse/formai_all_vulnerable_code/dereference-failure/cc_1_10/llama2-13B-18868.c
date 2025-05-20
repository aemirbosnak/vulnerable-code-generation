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
    struct sockaddr_in client_addr;
};

void handle_request(int sock, struct sockaddr_in *client_addr) {
    char buffer[1024];
    int bytes_read = recv(sock, buffer, 1024, 0);
    if (bytes_read < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("Received request: %s\n", buffer);

    // Handle the request here...
    char *url = strtok(buffer, " ");
    if (strcmp(url, "/") == 0) {
        char *message = "Hello, world!";
        send(sock, message, strlen(message), 0);
    } else {
        char *message = "Unknown request";
        send(sock, message, strlen(message), 0);
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    struct server_context *context = malloc(sizeof(struct server_context));
    context->sock = sock;
    context->client_addr = server_addr;

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        handle_request(client_sock, (struct sockaddr_in *)&context->client_addr);
        close(client_sock);
    }

    return 0;
}