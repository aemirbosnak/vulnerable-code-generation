//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct request {
    char *method;
    char *uri;
    char *body;
};

struct response {
    char *status;
    char *body;
};

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        struct request *req = malloc(sizeof(struct request));
        char *buffer = malloc(1024);

        if (recv(sock, buffer, 1024, 0) < 0) {
            perror("recv failed");
            free(req);
            continue;
        }

        req->method = buffer;
        req->uri = strtok(buffer, " ");
        req->body = strtok(NULL, " ");

        if (strcmp(req->method, "GET") == 0) {
            char *path = req->uri;
            char *file = "/var/www/html";
            struct response *res = malloc(sizeof(struct response));

            if (path[0] == '/') {
                file = path;
            }

            res->status = "200 OK";
            res->body = file;

            send(sock, res, strlen(res), 0);
            free(res);
        } else if (strcmp(req->method, "POST") == 0) {
            char *path = req->uri;
            char *file = "/var/www/html";
            struct response *res = malloc(sizeof(struct response));

            if (path[0] == '/') {
                file = path;
            }

            res->status = "201 Created";
            res->body = file;

            send(sock, res, strlen(res), 0);
            free(res);
        } else {
            char *message = "Method not allowed";
            struct response *res = malloc(sizeof(struct response));

            res->status = "405 Method Not Allowed";
            res->body = message;

            send(sock, res, strlen(res), 0);
            free(res);
        }

        free(req);
    }

    close(sock);

    return 0;
}