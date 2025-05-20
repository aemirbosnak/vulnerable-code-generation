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

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind() failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sock, 3) < 0) {
        perror("listen() failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        struct server_context *ctx = malloc(sizeof(struct server_context));
        ctx->sock = accept(sock, NULL, NULL);
        if (ctx->sock < 0) {
            perror("accept() failed");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted from client...\n");

        char buffer[1024];
        read(ctx->sock, buffer, 1024);
        printf("Client message: %s\n", buffer);

        char *message = "Hello, world!";
        send(ctx->sock, message, strlen(message), 0);

        free(ctx);
    }

    close(sock);
    return 0;
}