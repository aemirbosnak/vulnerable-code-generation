//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct request {
    char *method;
    char *path;
    char *query;
};

struct response {
    char *status;
    char *body;
};

int main(int argc, char **argv) {
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

    listen(sock, 3);

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        struct request *req = malloc(sizeof(struct request));
        char buffer[1024];

        if (recv(sock, buffer, 1024, 0) < 0) {
            perror("recv failed");
            free(req);
            continue;
        }

        char *ptr = strtok(buffer, " ");
        req->method = ptr;
        ptr = strtok(NULL, " ");
        req->path = ptr;
        ptr = strtok(NULL, " ");
        req->query = ptr;

        if (strcmp(req->method, "GET") == 0) {
            char *path = req->path;
            char *query = req->query;
            char *file = "index.html";

            if (strcmp(path, "/") == 0) {
                file = "index.html";
            } else if (strcmp(path, "/hello") == 0) {
                file = "hello.html";
            } else {
                file = "404.html";
            }

            struct response *res = malloc(sizeof(struct response));
            res->status = "200 OK";
            res->body = file;

            send(sock, res, sizeof(struct response), 0);
            free(res);
        } else {
            char *message = "Method not supported";
            struct response *res = malloc(sizeof(struct response));
            res->status = "405 Method Not Supported";
            res->body = message;

            send(sock, res, sizeof(struct response), 0);
            free(res);
        }

        free(req);
    }

    close(sock);

    return 0;
}