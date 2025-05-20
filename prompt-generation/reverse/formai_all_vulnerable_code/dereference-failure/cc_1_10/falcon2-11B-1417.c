//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256];

    // Check command-line arguments
    if (argc!= 2)
    {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        exit(1);
    }

    portno = atoi(argv[1]);

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    strcpy(buffer, "GET / HTTP/1.1\r\nHost: ");
    strcat(buffer, argv[1]);
    strcat(buffer, "\r\n\r\n");

    if (send(sockfd, buffer, strlen(buffer), 0) < 0)
    {
        perror("send");
        exit(1);
    }

    while ((n = recv(sockfd, buffer, 255, 0)) > 0)
    {
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}