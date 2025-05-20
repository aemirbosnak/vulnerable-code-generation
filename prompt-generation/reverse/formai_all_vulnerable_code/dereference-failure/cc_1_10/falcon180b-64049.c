//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>

int main()
{
    int sockfd, newsockfd, portno, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        perror("socket failed");
        exit(1);
    }

    portno = 8080;

    server = gethostbyname("192.168.1.1");

    if (server == NULL)
    {
        printf("No such host\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to server\n");

    while (1)
    {
        bzero(buffer, sizeof(buffer));

        ret = recv(sockfd, buffer, 1024, 0);

        if (ret <= 0)
        {
            printf("Disconnected from server\n");
            exit(1);
        }

        printf("Received from server: %s\n", buffer);
    }

    close(sockfd);

    return 0;
}