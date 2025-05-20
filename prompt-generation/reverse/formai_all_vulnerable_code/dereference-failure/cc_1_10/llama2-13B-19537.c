//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: satisfied
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
    char *body;
};

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sock, 3);

    while (1) {
        struct request *req = malloc(sizeof(struct request));

        if (accept(sock, (struct sockaddr *)NULL, NULL) < 0) {
            perror("accept failed");
            free(req);
            continue;
        }

        printf("Connection accepted from %s\n", inet_ntoa(server_addr.sin_addr));

        // Read request headers
        char *line = NULL;
        size_t len = 0;
        while (getline(&line, &len, stdin) > 0) {
            if (line[0] == 'GET') {
                req->method = line;
            } else if (line[0] == 'POST') {
                req->method = line;
                break;
            }
        }

        // Read request body
        char body[1024];
        size_t bytes_read = read(sock, body, sizeof(body) - 1);
        body[bytes_read] = '\0';
        req->body = body;

        // Handle request
        if (req->method == NULL) {
            printf("Invalid request method\n");
            free(req);
            continue;
        }

        if (req->body == NULL) {
            printf("Invalid request body\n");
            free(req);
            continue;
        }

        // Print request details
        printf("Request method: %s\n", req->method);
        printf("Request URI: %s\n", req->uri);
        printf("Request body: %s\n", req->body);

        // Free resources
        free(req);
    }

    return 0;
}