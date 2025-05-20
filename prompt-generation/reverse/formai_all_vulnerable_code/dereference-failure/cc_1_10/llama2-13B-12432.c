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

    if (strcmp(buffer, "/hello") == 0) {
        char *response = "Hello, world!";
        send(sock, response, strlen(response), 0);
    } else if (strcmp(buffer, "/404") == 0) {
        char *response = "Not found :(";
        send(sock, response, strlen(response), 0);
    } else {
        char *response = "Invalid request :(";
        send(sock, response, strlen(response), 0);
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(sock, 3);

    struct server_context *context = malloc(sizeof(struct server_context));
    context->sock = sock;

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);

        handle_request(client_sock, &client_addr);

        free(context);
    }

    return 0;
}