//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX 100

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Error: Unable to create socket\n");
        exit(1);
    }

    portno = atoi("8080");
    server = gethostbyname("127.0.0.1");
    if (server == NULL)
    {
        printf("Error: Unable to resolve host\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret < 0)
    {
        printf("Error: Unable to connect to server\n");
        exit(1);
    }

    while (1)
    {
        bzero(buffer, MAX);
        ret = read(sockfd, buffer, MAX);
        if (ret < 0)
        {
            printf("Error: Unable to read from socket\n");
            exit(1);
        }
        printf("Received message: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}