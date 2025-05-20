//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: ultraprecise
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

int main()
{
    int sockfd, n;
    struct sockaddr_in serverAddr;
    struct hostent* server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");

    if (server == NULL)
    {
        fprintf(stderr, "Error, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char*)&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&serverAddr.sin_addr.s_addr, server->h_length);
    serverAddr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    n = read(sockfd, buffer, sizeof(buffer));
    printf("Received data: %s\n", buffer);

    write(sockfd, "Hello World\n", 12);
    close(sockfd);

    return 0;
}