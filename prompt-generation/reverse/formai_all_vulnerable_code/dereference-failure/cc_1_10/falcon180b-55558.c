//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE 1024
#define PORT "80"

int main()
{
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    char buffer[MAX_LINE];
    int n;
    int opt = 1;
    int addrlen = sizeof(cli_addr);

    // creating socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(errno);
    }

    // setsockopt
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(errno);
    }

    // connect to the server
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(atoi(PORT));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect failed");
        exit(errno);
    }

    // receive a welcome message from the server
    if (recv(sockfd, buffer, MAX_LINE, 0) < 0)
    {
        perror("recv failed");
        exit(errno);
    }
    printf("Welcome message from the server: %s", buffer);

    while (1)
    {
        // send a GET request to the server
        sprintf(buffer, "GET / HTTP/1.1\r\nHost: 127.0.0.1\r\nConnection: close\r\n\r\n");
        if (send(sockfd, buffer, strlen(buffer), 0) < 0)
        {
            perror("send failed");
            exit(errno);
        }

        // receive a response from the server
        if (recv(sockfd, buffer, MAX_LINE, 0) < 0)
        {
            perror("recv failed");
            exit(errno);
        }
        printf("Response from the server: %s", buffer);
    }

    // close socket
    close(sockfd);
    return 0;
}