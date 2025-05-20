//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

int main()
{
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char sendbuf[256];
    char recvbuf[256];
    int n;

    server = gethostbyname("smtp.gmail.com");

    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(25); // SMTP port

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    bzero(sendbuf, 256);
    strcpy(sendbuf, "HELO example.com");

    write(sockfd, sendbuf, strlen(sendbuf));

    bzero(recvbuf, 256);

    n = read(sockfd, recvbuf, 256);

    printf("Received: %s\n", recvbuf);

    bzero(sendbuf, 256);
    strcpy(sendbuf, "MAIL FROM: <example@example.com>");

    write(sockfd, sendbuf, strlen(sendbuf));

    bzero(recvbuf, 256);

    n = read(sockfd, recvbuf, 256);

    printf("Received: %s\n", recvbuf);

    bzero(sendbuf, 256);
    strcpy(sendbuf, "RCPT TO: <user@example.com>");

    write(sockfd, sendbuf, strlen(sendbuf));

    bzero(recvbuf, 256);

    n = read(sockfd, recvbuf, 256);

    printf("Received: %s\n", recvbuf);

    bzero(sendbuf, 256);
    strcpy(sendbuf, "DATA");

    write(sockfd, sendbuf, strlen(sendbuf));

    bzero(recvbuf, 256);

    n = read(sockfd, recvbuf, 256);

    printf("Received: %s\n", recvbuf);

    bzero(sendbuf, 256);
    strcpy(sendbuf, "Subject: Test Message\n");

    write(sockfd, sendbuf, strlen(sendbuf));

    bzero(sendbuf, 256);
    strcpy(sendbuf, "Hello World\n.\n");

    write(sockfd, sendbuf, strlen(sendbuf));

    bzero(recvbuf, 256);

    n = read(sockfd, recvbuf, 256);

    printf("Received: %s\n", recvbuf);

    bzero(sendbuf, 256);
    strcpy(sendbuf, "QUIT");

    write(sockfd, sendbuf, strlen(sendbuf));

    bzero(recvbuf, 256);

    n = read(sockfd, recvbuf, 256);

    printf("Received: %s\n", recvbuf);

    close(sockfd);
    return 0;
}