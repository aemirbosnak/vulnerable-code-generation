//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define SERVER_PORT 80
#define BUFFER_SIZE 4096

typedef struct {
    char host[128];
    char path[512];
    int port;
} request_t;

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <path> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    request_t *req = malloc(sizeof(request_t));
    strcpy(req->host, argv[1]);
    strcpy(req->path, argv[2]);
    req->port = atoi(argv[3]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) die("socket");

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(req->port);

    if (inet_pton(AF_INET, req->host, &serv_addr.sin_addr) <= 0)
        die("Invalid address/ Address not supported");

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        die("Connection failed");

    char request[BUFFER_SIZE];
    char *method = "GET";
    char *version = "HTTP/1.1";

    snprintf(request, BUFFER_SIZE,
             "%s %s HTTP/%s\r\n"
             "Host: %s:%d\r\n"
             "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n"
             "Accept-Language: en-US,en;q=0.5\r\n"
             "Accept-Encoding: gzip, deflate\r\n"
             "Connection: keep-alive\r\n"
             "User-Agent: Lord-of-the-Code HTTP Client/1.0\r\n"
             "\r\n",
             method, req->path, version, req->host, req->port);

    send(sockfd, request, strlen(request), 0);

    char response[BUFFER_SIZE];
    ssize_t n;
    int status_code = -1;

    do {
        n = recv(sockfd, response, BUFFER_SIZE - 1, 0);
        if (n > 0) {
            response[n] = '\0';
            if (sscanf(response, "%d%*s", &status_code) > 0) {
                printf("Status code: %d\n", status_code);
            } else {
                fwrite(response, 1, n, stdout);
            }
        }
    } while (n > 0 || status_code == -1);

    close(sockfd);
    free(req);
    return 0;
}