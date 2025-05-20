//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char message[100];
    struct hostent *host;

    if (argc!= 2) {
        fprintf(stderr, "usage: %s hostname\n", argv[0]);
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error, no such host.\n");
        exit(1);
    }

    portno = htons(80);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&serv_addr.sin_addr.s_addr, host->h_length);
    serv_addr.sin_port = portno;

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    sprintf(message, "GET / HTTP/1.0\r\n\r\n");
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("send");
        exit(1);
    }

    printf("Sent %d bytes of data\n", n);

    n = recv(sockfd, message, sizeof(message), 0);
    if (n < 0) {
        perror("recv");
        exit(1);
    }

    printf("Received %d bytes of data\n", n);

    close(sockfd);
    exit(0);
}