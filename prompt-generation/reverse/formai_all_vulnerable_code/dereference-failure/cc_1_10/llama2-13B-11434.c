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
    int len = recv(sock, buffer, 1024, 0);
    printf("Received request: %s\n", buffer);

    // Handle the request here, for example:
    if (strcmp(buffer, "/hello") == 0) {
        send(sock, "Hello, world!", 13, 0);
    } else if (strcmp(buffer, "/404") == 0) {
        send(sock, "Not found :(", 10, 0);
    } else {
        send(sock, "Invalid request", 14, 0);
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT),
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sock, 3);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        struct server_context *context = malloc(sizeof(struct server_context));
        context->sock = client_sock;
        context->client_addr = client_addr;

        handle_request(client_sock, &client_addr);

        free(context);
    }

    return 0;
}