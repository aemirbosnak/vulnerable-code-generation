//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[4096];

    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error opening socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    strcpy(buffer, "GET / HTTP/1.1\r\nHost: www.example.com\r\nConnection: close\r\n\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0)
    {
        perror("Error sending request");
        exit(1);
    }

    memset(buffer, 0, sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0)
    {
        perror("Error receiving response");
        exit(1);
    }

    printf("%s", buffer);

    close(sockfd);

    return 0;
}