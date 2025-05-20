//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX_CONNECTION 5
#define MAX_RECV_BUFF 1024
#define PORT 8080
#define MAX_LINE 256

int main()
{
    int sockfd, newsockfd, portno;
    struct sockaddr_in serveraddr, cli_addr;
    struct hostent *server;
    char recv_buff[MAX_RECV_BUFF];
    char send_buff[MAX_LINE];

    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");

    if ( server == NULL )
    {
        fprintf(stderr, "Error, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(PORT);

    if ( (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr))) < 0 )
    {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("HTTP proxy server is running on port 8080...\n");

    while ( 1 )
    {
        bzero((char *) &cli_addr, sizeof(cli_addr));
        if ( (newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&portno)) < 0 )
        {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Accepted a new connection from client.\n");

        while ( 1 )
        {
            int n = read(newsockfd, recv_buff, MAX_RECV_BUFF);

            if (n < 0)
            {
                perror("read failed");
                exit(EXIT_FAILURE);
            }
            else if (n == 0)
            {
                printf("Client disconnected.\n");
                break;
            }
            else
            {
                send(newsockfd, recv_buff, n, 0);
            }
        }

        printf("Connection from client closed.\n");
        close(newsockfd);
    }

    close(sockfd);
    return 0;
}