//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: protected
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

int main()
{
    int sockfd, port, newSockfd;
    struct sockaddr_in serverAddr, clientAddr;
    int opt = 1;

    /* Bind the socket to a specific port */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Failed to create socket\n");
        return 1;
    }

    bzero((char *)&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        printf("Bind failed. Error: %s\n", strerror(errno));
        return 1;
    }

    listen(sockfd, 5);

    /* Accept incoming connection */
    newSockfd = accept(sockfd, (struct sockaddr *)&clientAddr, (socklen_t *)&port);
    if (newSockfd < 0)
    {
        printf("Accept failed. Error: %s\n", strerror(errno));
        return 1;
    }

    /* Check the port number */
    if (ntohs(clientAddr.sin_port) == htons(80) || ntohs(clientAddr.sin_port) == htons(22))
    {
        /* Close the connection */
        close(newSockfd);
    }
    else
    {
        /* Forward the connection */
        dup2(newSockfd, 0);
        dup2(newSockfd, 1);
        dup2(newSockfd, 2);
        close(newSockfd);
    }

    return 0;
}