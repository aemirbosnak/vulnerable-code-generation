//GEMINI-pro DATASET v1.0 Category: Networking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char** argv)
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error opening socket");
        exit(1);
    }

    bzero((char*)&serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    while (1)
    {
        newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);
        if (newsockfd < 0)
        {
            perror("Error accepting connection");
            exit(1);
        }

        char buffer[256];
        bzero(buffer, 256);

        int n = read(newsockfd, buffer, 255);
        if (n < 0)
        {
            perror("Error reading from socket");
            exit(1);
        }

        printf("Received message: %s\n", buffer);

        char* response = "Hello from the server!";
        n = write(newsockfd, response, strlen(response));
        if (n < 0)
        {
            perror("Error writing to socket");
            exit(1);
        }

        close(newsockfd);
    }

    close(sockfd);

    return 0;
}