//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    char host[256], port[6], buffer[1024];
    int sockfd, n;

    memset(buffer, 0, sizeof(buffer));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    struct hostent *server;
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    struct sockaddr_in address;
    bzero((char *)&address, sizeof(address));
    address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&address.sin_addr.s_addr, server->h_length);
    address.sin_port = htons(atoi(argv[2]));

    n = connect(sockfd, (struct sockaddr *)&address, sizeof(address));
    if (n < 0) {
        perror("connect");
        exit(1);
    }

    send(sockfd, "HELO PostApocalypticWorld\r\n", 14, 0);
    if (send(sockfd, "MAIL FROM:<Survivor>\r\n", 20, 0) < 0) {
        perror("send");
        exit(1);
    }

    send(sockfd, "RCPT TO:<NewSurvivor>\r\n", 17, 0);
    if (send(sockfd, "DATA\r\n", 7, 0) < 0) {
        perror("send");
        exit(1);
    }

    printf("Enter email message:\n");
    fgets(buffer, sizeof(buffer), stdin);

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    send(sockfd, "QUIT\r\n", 7, 0);

    close(sockfd);

    return 0;
}