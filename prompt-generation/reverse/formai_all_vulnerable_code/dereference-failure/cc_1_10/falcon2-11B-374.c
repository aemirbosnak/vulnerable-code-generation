//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, valread, portno;
    struct sockaddr_in serveraddr;
    char buf[100];

    if (argc!= 3) {
        fprintf(stderr, "usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(portno);
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect");
        exit(1);
    }

    sprintf(buf, "PING %s\r\n", argv[1]);
    valread = write(sockfd, buf, strlen(buf));
    if (valread < 0) {
        perror("write");
        exit(1);
    }

    valread = read(sockfd, buf, 100);
    if (valread < 0) {
        perror("read");
        exit(1);
    }

    printf("%s", buf);
    close(sockfd);

    return 0;
}