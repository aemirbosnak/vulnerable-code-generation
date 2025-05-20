//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    if(argc < 4)
    {
        printf("Usage: ./httpclient METHOD HOST PATH\n");
        printf("Example: ./httpclient GET www.google.com / HTTP/1.1\n");
        exit(1);
    }

    char *method = argv[1];
    char *host = argv[2];
    char *path  = argv[3];

    char ip[INET_ADDRSTRLEN];
    struct hostent *he;
    struct in_addr **addr_list;

    if((he = gethostbyname(host)) == NULL)
    {
        printf("gethostbyname() failed\n");
        exit(1);
    }

    addr_list = (struct in_addr **) he->h_addr_list;
    inet_ntop(AF_INET, addr_list[0], ip, sizeof(ip));

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr.s_addr = inet_addr(ip);

    if(connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0)
    {
        printf("Connect Error\n");
        exit(1);
    }

    char request[MAX_BUFFER_SIZE];
    sprintf(request, "%s %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", method, path, host);
    int request_len = strlen(request);

    if(write(sockfd, request, request_len) < 0)
    {
        printf("Write Error\n");
        exit(1);
    }

    char response[MAX_BUFFER_SIZE];
    int response_len = 0;

    while((response_len = read(sockfd, response, sizeof(response)-1)) > 0)
    {
        response[response_len] = '\0';
        printf("%s", response);
    }

    if(response_len < 0)
    {
        printf("Read Error\n");
        exit(1);
    }

    close(sockfd);

    return 0;
}