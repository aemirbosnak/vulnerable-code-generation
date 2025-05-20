//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: brave
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
    char *protocol;
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

    listen(sock, 3);

    printf("Listening on port %d...\n", PORT);

    while (1) {
        struct request req;
        int client_sock = accept(sock, NULL, NULL);

        printf("Connection accepted from client...\n");

        read_request(client_sock, &req);

        if (strcmp(req.method, "GET") == 0) {
            char *uri = req.uri;
            char *file = "index.html";
            int file_len = strlen(file);

            if (send(client_sock, file, file_len, 0) < 0) {
                perror("send failed");
                exit(1);
            }

            printf("Sent file %s (%d bytes)...\n", file, file_len);
        } else if (strcmp(req.method, "POST") == 0) {
            char *uri = req.uri;
            char *data = NULL;
            int data_len = 0;

            if (read_post_data(client_sock, &data, &data_len) < 0) {
                perror("read_post_data failed");
                exit(1);
            }

            printf("Received post data (%d bytes)...\n", data_len);
        } else {
            printf("Invalid request method %s\n", req.method);
        }

        close(client_sock);
    }

    return 0;
}

int read_request(int sock, struct request *req) {
    char buffer[1024];
    int len = recv(sock, buffer, 1024, 0);

    if (len < 0) {
        perror("recv failed");
        exit(1);
    }

    buffer[len] = '\0';

    req->method = buffer;
    req->uri = buffer + strlen(req->method) + 1;
    req->protocol = buffer + strlen(req->method) + strlen(req->uri) + 1;

    return len;
}

int read_post_data(int sock, char **data, int *data_len) {
    char buffer[1024];
    int len = recv(sock, buffer, 1024, 0);

    if (len < 0) {
        perror("recv failed");
        exit(1);
    }

    buffer[len] = '\0';

    *data = buffer;
    *data_len = len;

    return len;
}