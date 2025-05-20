//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct request {
    char method[10];
    char path[100];
    char *query;
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("binding failed");
        exit(EXIT_FAILURE);
    }

    listen(sock, 3);

    while (1) {
        struct request *req = malloc(sizeof(struct request));

        if (req == NULL) {
            perror("memory allocation failed");
            exit(EXIT_FAILURE);
        }

        socklen_t client_len = sizeof(struct sockaddr_in);
        int client_sock = accept(sock, (struct sockaddr *)&server_addr, &client_len);

        if (client_sock < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        char buffer[1024];
        read(client_sock, buffer, 1024);

        // parse request
        char *token = strtok(buffer, " ");
        req->method[0] = *token;
        req->method[1] = '\0';

        token = strtok(NULL, " ");
        req->path[0] = *token;
        req->path[1] = '\0';

        token = strtok(NULL, "?");
        if (token != NULL) {
            req->query = token;
        } else {
            req->query = NULL;
        }

        // handle request
        if (strcmp(req->method, "GET") == 0) {
            if (strcmp(req->path, "/") == 0) {
                char *message = "Hello, world!";
                send(client_sock, message, strlen(message), 0);
            } else {
                char *message = "404 Not Found";
                send(client_sock, message, strlen(message), 0);
            }
        } else if (strcmp(req->method, "POST") == 0) {
            char *message = "POST request not implemented";
            send(client_sock, message, strlen(message), 0);
        } else {
            char *message = "Method not supported";
            send(client_sock, message, strlen(message), 0);
        }

        free(req);
        close(client_sock);
    }

    close(sock);

    return 0;
}