//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char *host, *port;
    char buf[512];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = argv[2];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host, port, &hints, &res) != 0) {
        perror("getaddrinfo");
        exit(1);
    }
    servaddr.sin_addr = ((struct sockaddr_in *) res->ai_addr)->sin_addr;
    freeaddrinfo(res);

    servaddr.sin_port = htons(atoi(port));

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    char *msg = "Hello, world!\n";
    if (send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("send");
        exit(1);
    }

    while ((n = recv(sockfd, buf, sizeof(buf), 0)) > 0) {
        buf[n] = '\0';
        printf("Received: %s", buf);
    }

    if (n < 0) {
        perror("recv");
        exit(1);
    }

    close(sockfd);

    return 0;
}