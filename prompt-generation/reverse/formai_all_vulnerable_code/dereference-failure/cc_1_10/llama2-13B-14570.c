//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: safe
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
    int len;

    // Read the request
    len = recv(sock, buffer, 1024, 0);
    if (len < 0) {
        perror("recv");
        return;
    }

    // Check if the request is a GET request
    if (strcmp(buffer, "GET / HTTP/1.1\r\n") == 0) {
        // Send the HTML page
        char *html = "<!DOCTYPE html><html><body>Hello, world!</body></html>";
        send(sock, html, strlen(html), 0);
    } else {
        // Send a 404 error
        char *error = "404 Not Found\r\n";
        send(sock, error, strlen(error), 0);
    }

    // Close the connection
    close(sock);
}

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sock, 3) < 0) {
        perror("listen");
        exit(1);
    }

    struct server_context *ctx = malloc(sizeof(struct server_context));
    ctx->sock = sock;
    ctx->client_addr = server_addr;

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept");
            continue;
        }

        handle_request(client_sock, &client_addr);
        close(client_sock);
    }

    free(ctx);
    close(sock);
    return 0;
}