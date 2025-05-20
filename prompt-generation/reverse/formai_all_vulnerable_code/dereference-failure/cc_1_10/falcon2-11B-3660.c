//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define MAX_CONNECTION 5

int main()
{
    int sockfd, valread, n, addrlen;
    struct sockaddr_in serverAddr;
    struct hostent *server;
    char buffer[1024];

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket creation failed");
        exit(1);
    }

    // Resolving server hostname
    if ((server = gethostbyname("ftp.example.com")) == NULL)
    {
        fprintf(stderr, "gethostbyname failed\n");
        exit(1);
    }

    // Storing server IP address in serverAddr
    bzero((char *) &serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serverAddr.sin_addr.s_addr, server->h_length);
    serverAddr.sin_port = htons(PORT);

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) == -1)
    {
        perror("connect failed");
        exit(1);
    }

    // Sending command to server
    printf("Sending command...\n");
    n = write(sockfd, "USER anonymous\r\n", 16);
    if (n < 0)
    {
        perror("write failed");
        exit(1);
    }

    n = write(sockfd, "PASS anonymous\r\n", 15);
    if (n < 0)
    {
        perror("write failed");
        exit(1);
    }

    n = write(sockfd, "QUIT\r\n", 5);
    if (n < 0)
    {
        perror("write failed");
        exit(1);
    }

    close(sockfd);

    return 0;
}