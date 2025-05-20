//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_SIZE 1024

void receive(int sockfd);

int main(int argc, char *argv[])
{
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3)
    {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        perror("Error opening socket.");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL)
    {
        fprintf(stderr, "Error, no such host.\n");
        exit(1);
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error connecting.\n");
        exit(1);
    }

    char buffer[MAX_SIZE];
    bzero(buffer, MAX_SIZE);
    receive(sockfd);

    snprintf(buffer, MAX_SIZE, "USER username\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    receive(sockfd);

    snprintf(buffer, MAX_SIZE, "PASS password\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    receive(sockfd);

    snprintf(buffer, MAX_SIZE, "STAT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    receive(sockfd);

    snprintf(buffer, MAX_SIZE, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    receive(sockfd);

    close(sockfd);

    return 0;
}

void receive(int sockfd)
{
    char buffer[MAX_SIZE];
    int bytesRead = 0, totalBytesRead = 0;

    while ((bytesRead = recv(sockfd, buffer + totalBytesRead, MAX_SIZE - totalBytesRead, 0)) > 0)
    {
        totalBytesRead += bytesRead;
        if (buffer[totalBytesRead - 1] == '\n')
        {
            break;
        }
    }

    buffer[totalBytesRead] = '\0';
    printf("%s", buffer);
    if (buffer[0] == '-')
    {
        printf("Error: %s", buffer);
        exit(1);
    }
}