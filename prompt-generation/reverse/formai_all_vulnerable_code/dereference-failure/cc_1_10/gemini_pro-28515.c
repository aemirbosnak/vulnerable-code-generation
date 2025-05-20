//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netdb.h>

int main()
{
    int sockfd, n, i;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[4096];
    char hostname[1024];
    char ipaddr[1024];
    int port = 80;
    int to = 1000; // timeout in milliseconds
    int count = 10; // number of pings

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // set socket timeout
    struct timeval tv;
    tv.tv_sec = to / 1000;
    tv.tv_usec = (to % 1000) * 1000;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) < 0)
    {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // get hostname and ip address of the server
    gethostname(hostname, sizeof(hostname));
    struct hostent *host = gethostbyname(hostname);
    strcpy(ipaddr, inet_ntoa(*((struct in_addr *)host->h_addr)));

    // set server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(ipaddr);

    // connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // send data to the server
    for (i = 0; i < count; i++)
    {
        bzero(buffer, sizeof(buffer));
        strcpy(buffer, "Hello from client");
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0)
        {
            perror("write failed");
            exit(EXIT_FAILURE);
        }
    }

    // receive data from the server
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0)
    {
        perror("read failed");
        exit(EXIT_FAILURE);
    }
    printf("Received from server: %s\n", buffer);

    // close the socket
    close(sockfd);

    return 0;
}