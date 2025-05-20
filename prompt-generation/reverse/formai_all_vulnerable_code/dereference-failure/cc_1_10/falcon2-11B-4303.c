//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "usage: %s <proxy-port> <destination-host> <destination-port>\n", argv[0]);
        exit(1);
    }

    int sockfd, n;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clientlen;
    char buffer[1024];
    char proxy_port[6];
    char destination_host[256];
    char destination_port[6];

    strncpy(proxy_port, argv[1], 5);
    strncpy(destination_host, argv[2], 255);
    strncpy(destination_port, argv[3], 5);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(proxy_port));
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, 5);

    printf("Proxy server listening on port %s\n", proxy_port);

    clientlen = sizeof(cli_addr);
    sockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clientlen);
    if (sockfd < 0)
        error("ERROR on accept");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(destination_port));
    inet_pton(AF_INET, destination_host, &serv_addr.sin_addr);

    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        if (sendto(sockfd, buffer, n, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
            error("ERROR on sendto");

        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (sendto(sockfd, buffer, n, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
            error("ERROR on sendto");
    }

    close(sockfd);
    return 0;
}