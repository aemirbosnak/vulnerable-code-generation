//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: Romeo and Juliet
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define SERVER_ADDR "192.168.0.100"
#define SERVER_PORT 80

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in serveraddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERVER_PORT);
    serveraddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0)
    {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s:%d\n", SERVER_ADDR, SERVER_PORT);

    // send some data to server
    char message[] = "GET / HTTP/1.1\r\nHost: ";
    strcat(message, SERVER_ADDR);
    strcat(message, " HTTP/1.1\r\n\r\n");

    if (send(sockfd, message, strlen(message), 0) < 0)
    {
        perror("ERROR sending data");
        exit(EXIT_FAILURE);
    }

    // receive response from server
    char response[1024];
    bzero(response, sizeof(response));

    n = recv(sockfd, response, sizeof(response), 0);

    if (n < 0)
    {
        perror("ERROR receiving data");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", response);

    // close socket
    close(sockfd);

    return 0;
}