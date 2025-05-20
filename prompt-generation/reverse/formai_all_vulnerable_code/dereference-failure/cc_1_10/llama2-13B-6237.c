//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct request {
    char *method;
    char *uri;
    char *version;
    char *body;
};

struct response {
    char *status;
    char *body;
};

int main(void) {
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

    printf("Listening for incoming requests...\n");

    while (1) {
        struct request *req;
        int client_sock = accept(sock, NULL, NULL);

        req = malloc(sizeof(struct request));
        read(client_sock, req->body, 1024);
        req->method = req->body;
        req->body = NULL;

        if (strcmp(req->method, "GET") == 0) {
            char *uri = req->uri;
            char *path = strtok(uri, "/");
            char *query = NULL;

            if (path != NULL) {
                if (strcmp(path, "/") == 0) {
                    query = "Hello, world!";
                } else {
                    query = "Not found";
                }
            }

            struct response *res = malloc(sizeof(struct response));
            res->status = "200 OK";
            res->body = query;

            write(client_sock, res, sizeof(*res));
            free(res);
        } else {
            struct response *res = malloc(sizeof(struct response));
            res->status = "405 Method Not Supported";
            res->body = "Method Not Supported";

            write(client_sock, res, sizeof(*res));
            free(res);
        }

        free(req);
    }

    close(sock);
    return 0;
}