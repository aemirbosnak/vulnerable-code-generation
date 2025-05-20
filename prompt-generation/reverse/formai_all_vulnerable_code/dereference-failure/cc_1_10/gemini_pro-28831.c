//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char **argv)
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        fprintf(stderr, "Error opening socket\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        fprintf(stderr, "Error binding socket to port\n");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    while (1)
    {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0)
        {
            fprintf(stderr, "Error accepting connection\n");
            exit(EXIT_FAILURE);
        }

        bzero(buffer, 256);
        int n = read(newsockfd, buffer, 255);
        if (n < 0)
        {
            fprintf(stderr, "Error reading from socket\n");
            exit(EXIT_FAILURE);
        }

        printf("Received message: %s\n", buffer);

        char *response = "Hello from the smart home!\n";
        n = write(newsockfd, response, strlen(response));
        if (n < 0)
        {
            fprintf(stderr, "Error writing to socket\n");
            exit(EXIT_FAILURE);
        }

        close(newsockfd);
    }

    close(sockfd);

    return 0;
}