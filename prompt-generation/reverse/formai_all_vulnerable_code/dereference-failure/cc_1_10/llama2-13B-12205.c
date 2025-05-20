//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct request {
    int sock;
    char *method;
    char *path;
    char *query_string;
};

void handle_request(struct request *req) {
    char *message = "Hello, world!";
    char *header = "Content-Type: text/html\r\n";
    char *footer = "\r\n";
    int len = strlen(message) + strlen(header) + strlen(footer);

    if (req->method[0] == 'G') {
        header[0] = 'G';
        header[1] = 'E';
        header[2] = 'T';
        header[3] = ' ';
        message = "This is a GET request!";
    } else if (req->method[0] == 'P') {
        header[0] = 'P';
        header[1] = 'O';
        header[2] = 'S';
        header[3] = 'T';
        message = "This is a POST request!";
    }

    write(req->sock, header, strlen(header));
    write(req->sock, message, len);
    write(req->sock, footer, strlen(footer));
    close(req->sock);
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };

    bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(sock, 3);

    while (1) {
        struct request req;
        req.sock = accept(sock, NULL, NULL);
        read(req.sock, &req.method, 3);
        read(req.sock, &req.path, 100);
        read(req.sock, &req.query_string, 100);

        handle_request(&req);
    }

    close(sock);
    return 0;
}