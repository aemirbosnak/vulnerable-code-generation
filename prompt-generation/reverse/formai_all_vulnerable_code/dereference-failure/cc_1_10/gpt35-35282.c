//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2) 
    {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char request[2048];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1]);

    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) 
    {
        fprintf(stderr, "Error: no such host as %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
    {
        perror("Error: opening socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);
    serv_addr.sin_port = htons(80);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
    {
        perror("Error: connecting");
        exit(EXIT_FAILURE);
    }

    if (write(sockfd, request, strlen(request)) < 0) 
    {
        perror("Error: writing to socket");
        exit(EXIT_FAILURE);
    }

    char response[4096];
    int total_read = 0;
    int num_read;

    while ((num_read = read(sockfd, response + total_read, sizeof(response) - total_read - 1)) > 0) 
    {
        total_read += num_read;
        response[total_read] = 0;
    }

    if (num_read < 0) 
    {
        perror("Error: reading from socket");
        exit(EXIT_FAILURE);
    }

    printf("%s", response);
    close(sockfd);

    return 0;
}