//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: statistical
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int sockfd, port, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    if(argc < 3)
    {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[2]);
    server = gethostbyname(argv[1]);

    if(server == NULL)
    {
        fprintf(stderr, "ERROR: No such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        fprintf(stderr, "ERROR: Could not open socket\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        fprintf(stderr, "ERROR: Could not connect to server\n");
        exit(1);
    }

    while(1)
    {
        bzero(buffer, 256);
        printf("> ");
        fgets(buffer, 255, stdin);

        n = write(sockfd, buffer, strlen(buffer));

        if(n < 0)
        {
            fprintf(stderr, "ERROR: Could not write to socket\n");
            exit(1);
        }

        bzero(buffer, 256);
        n = read(sockfd, buffer, 255);

        if(n < 0)
        {
            fprintf(stderr, "ERROR: Could not read from socket\n");
            exit(1);
        }

        printf("%s\n", buffer);
    }

    close(sockfd);

    return 0;
}