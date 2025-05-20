//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080

struct server_context {
    int sock;
    struct sockaddr_in client_addr;
    socklen_t client_len;
    char buffer[1024];
};

void handle_request(struct server_context *ctx) {
    int recv_len = recv(ctx->sock, ctx->buffer, 1024, 0);
    if (recv_len < 0) {
        perror("recv failed");
        return;
    }
    printf("Received request: %s\n", ctx->buffer);

    // Parse the request
    char *method = strtok(ctx->buffer, " ");
    char *uri = strtok(NULL, " ");
    char *version = strtok(NULL, " ");
    char *host = strtok(NULL, " ");

    if (strcmp(method, "GET") == 0) {
        if (strcmp(uri, "/") == 0) {
            printf("Server: Hello, world!%c", 0xA);
        } else {
            printf("Server: Not found%c", 0xA);
        }
    } else if (strcmp(method, "POST") == 0) {
        printf("Server: POST request not supported%c", 0xA);
    } else {
        printf("Server: Unsupported method%c", 0xA);
    }

    // Send the response
    char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 13\r\n\r\n";
    send(ctx->sock, response, strlen(response), 0);
}

int main(int argc, char *argv[]) {
    struct server_context ctx;
    ctx.sock = socket(AF_INET, SOCK_STREAM, 0);
    if (ctx.sock < 0) {
        perror("socket failed");
        return 1;
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(ctx.sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        return 1;
    }

    listen(ctx.sock, 3);

    printf("Listening on port %d...\n", PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(ctx.sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            continue;
        }

        ctx.client_addr = client_addr;
        ctx.client_len = client_len;

        handle_request(&ctx);

        close(client_sock);
    }

    return 0;
}