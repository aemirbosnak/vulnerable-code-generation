//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

typedef struct {
    int sockfd;
    struct sockaddr_in serv_addr;
} client;

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) die("socket");

    struct hostent *host = gethostbyname(argv[1]);
    if (!host) die("gethostbyname");

    client cli = {sockfd, {
        .sin_family = AF_INET,
        .sin_port = htons(atoi(argv[2])),
        .sin_addr = *((struct in_addr *)host->h_addr),
    }};

    if (connect(cli.sockfd, (struct sockaddr *)&cli.serv_addr, sizeof(cli.serv_addr)) < 0)
        die("connect");

    char req[1024] = "GET / HTTP/1.1\r\nHost: %s:%s\r\nUser-Agent: Shocked-Style-HTTP-Client/0.1\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\nConnection: keep-alive\r\nAccept-Language: en-US,en;q=0.5\r\n\r\n";

    snprintf(req, sizeof(req), req, argv[1], argv[2]);

    int n = send(cli.sockfd, req, strlen(req), 0);
    if (n < 0) die("send");

    char resp[1024];
    ssize_t i;

    do {
        i = recv(cli.sockfd, resp + sizeof(resp) - i, sizeof(resp) - (sizeof(resp) - i), 0);
        if (i < 0) die("recv");
        resp[sizeof(resp) - i] = '\0';
        printf("%s", resp + sizeof(resp) - i);
        fflush(stdout);
    } while (i > 0);

    close(cli.sockfd);
    return 0;
}