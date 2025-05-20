//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
    {
        perror("connect");
        return EXIT_FAILURE;
    }

    char request[] = "GET /index.html HTTP/1.1\r\nHost: example.com\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    char response[4096];
    int nbytes;
    while ((nbytes = recv(sockfd, response, sizeof(response), 0)) > 0)
    {
        fwrite(response, 1, nbytes, stdout);
    }

    if (nbytes == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    close(sockfd);
    return EXIT_SUCCESS;
}