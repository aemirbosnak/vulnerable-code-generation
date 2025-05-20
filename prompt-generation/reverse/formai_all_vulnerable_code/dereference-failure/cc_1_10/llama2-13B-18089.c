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
    int bytes_read = recv(sock, buffer, 1024, 0);
    printf("Received request: %s\n", buffer);

    // Handle the request here, for example:
    if (strcmp(buffer, "/hello") == 0) {
        char *response = "Hello, world!";
        send(sock, response, strlen(response), 0);
    } else if (strcmp(buffer, "/404") == 0) {
        char *response = "Not found :(";
        send(sock, response, strlen(response), 0);
    } else {
        char *response = "Invalid request :S";
        send(sock, response, strlen(response), 0);
    }

    close(sock);
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT),
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sock, 3);

    struct server_context *context = malloc(sizeof(struct server_context));
    context->sock = sock;
    context->client_addr = server_addr;

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        handle_request(client_sock, &context->client_addr);
        close(client_sock);
    }

    return 0;
}