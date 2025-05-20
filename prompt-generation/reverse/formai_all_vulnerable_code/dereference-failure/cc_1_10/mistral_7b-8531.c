//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    const char *host = argv[1];
    int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) die("socket");

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0)
        die("Invalid address/ Address not supported");

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        die("Connection failed");

    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE,
             "GET /%s HTTP/1.1\r\n"
             "Host: %s:%d\r\n"
             "User-Agent: Sherlock's Watson-Holmes HTTP Client\r\n"
             "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\n"
             "Connection: keep-alive\r\n"
             "\r\n", argv[1 + (argc > 3)], host, port);

    send(sockfd, request, strlen(request), 0);

    char response[BUFFER_SIZE];
    ssize_t n = recv(sockfd, response, BUFFER_SIZE, 0);
    if (n > 0) {
        fwrite(response, 1, n, stdout);
        printf("\n%s\n", "Sherlock: The data has been sent to the console. Can you find the culprit, Watson?");
    } else {
        perror("recv");
    }

    close(sockfd);
    return 0;
}