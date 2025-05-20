//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the address info of the server
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(argv[1], argv[2], &hints, &res) != 0)
    {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    // Create a socket
    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1)
    {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send the request to the server
    char request[BUFF_SIZE];
    snprintf(request, BUFF_SIZE, "USER anonymous\r\nPASS guest@example.com\r\n");
    if (send(sockfd, request, strlen(request), 0) == -1)
    {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    char response[BUFF_SIZE];
    int nbytes;
    while ((nbytes = recv(sockfd, response, BUFF_SIZE, 0)) > 0)
    {
        printf("%s", response);
    }

    if (nbytes == -1)
    {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    if (close(sockfd) == -1)
    {
        perror("close");
        exit(EXIT_FAILURE);
    }

    return 0;
}