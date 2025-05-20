//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <sys/select.h>

int main(int argc, char *argv[])
{
    int sockfd, portno;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buffer[256];
    char *url = argv[1];
    char *host = strtok(url, ":");
    char *port = strtok(NULL, ":");

    if (host == NULL || port == NULL)
    {
        fprintf(stderr, "Invalid URL\n");
        return 1;
    }

    portno = atoi(port);

    if (portno < 0 || portno > 65535)
    {
        fprintf(stderr, "Invalid port number\n");
        return 1;
    }

    server = gethostbyname(host);
    if (server == NULL)
    {
        fprintf(stderr, "Host not found\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        fprintf(stderr, "Error creating socket\n");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        fprintf(stderr, "Error connecting to server\n");
        return 1;
    }

    int n;
    while ((n = recv(sockfd, buffer, 256, 0)) > 0)
    {
        printf("%s", buffer);
    }

    return 0;
}