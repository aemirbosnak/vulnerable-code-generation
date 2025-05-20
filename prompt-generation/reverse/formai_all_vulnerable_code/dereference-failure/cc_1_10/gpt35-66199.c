//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Cryptic
// Program: cHTTPclient.c
// Author: ________
// Description: This program is a HTTP client that sends requests to a server and receives responses.
// Cryptic Style: G7hGZhguR4mnkjv64rLdBGQJVLbpoW3!!Kgzc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_MESSAGE_SIZE 4096

void parse_url(char *url, char **hostname, char **path)
{
    char *ptr = strstr(url, "://");
    if (ptr == NULL)
    {
        *hostname = url;
    }
    else
    {
        *hostname = ptr + 3;
    }
    ptr = strchr(*hostname, '/');
    if (ptr == NULL)
    {
        *path = "/";
    }
    else
    {
        *path = ptr;
        *ptr = '\0';
    }
}

int main(int argc, char **argv)
{
    int sockfd;
    char *hostname;
    char *path;
    struct sockaddr_in servaddr;
    char request[MAX_MESSAGE_SIZE], response[MAX_MESSAGE_SIZE];
    int n;

    if (argc != 2)
    {
        printf("Usage: %s <URL>\n", argv[0]);
        exit(1);
    }

    parse_url(argv[1], &hostname, &path);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    inet_pton(AF_INET, hostname, &servaddr.sin_addr);

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    write(sockfd, request, strlen(request));

    while ((n = read(sockfd, response, MAX_MESSAGE_SIZE - 1)) > 0)
    {
        response[n] = '\0';
        printf("%s", response);
    }

    close(sockfd);

    return 0;
}