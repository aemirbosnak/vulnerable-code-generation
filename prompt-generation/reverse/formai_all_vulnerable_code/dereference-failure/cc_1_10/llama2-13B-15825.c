//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: protected
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

struct request {
    char *method;
    char *path;
    char *body;
};

void handle_request(int sock, struct request *req) {
    char *message;

    if (strcmp(req->method, "GET") == 0) {
        message = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body>Hello, World!</body></html>";
    } else if (strcmp(req->method, "POST") == 0) {
        message = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body>Thank you for posting!</body></html>";
    } else {
        message = "HTTP/1.1 405 Method Not Supported\r\nContent-Type: text/html\r\n\r\n<html><body>Method not supported.</body></html>";
    }

    send(sock, message, strlen(message), 0);
    close(sock);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    while (1) {
        struct request req;
        char *buffer;
        int client_sock;

        client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept failed");
            exit(1);
        }

        buffer = malloc(1024);
        read(client_sock, buffer, 1024);
        req.method = buffer;
        req.path = buffer + strlen(req.method) + 1;
        req.body = buffer + strlen(req.method) + strlen(req.path) + 1;

        handle_request(client_sock, &req);

        free(buffer);
        close(client_sock);
    }

    return 0;
}