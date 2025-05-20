//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    int sockfd, newsockfd, clientfd, portno, n;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;
    struct hostent *host_ent;

    portno = 8080;
    sockfd = socket(AF_INET, SOCK_STREAM, htons(portno));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portno);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
    if (newsockfd < 0)
    {
        perror("Error accepting connection");
        exit(1);
    }

    clientfd = dup(newsockfd);

    host_ent = gethostbyaddr((struct sockaddr *)&client_addr, sizeof(client_addr), NULL);
    printf("Client IP: %s\n", host_ent->h_name);

    n = read(clientfd, buffer, MAX_BUFFER_SIZE);
    if (n > 0)
    {
        write(clientfd, buffer, n);
    }

    close(clientfd);
    close(newsockfd);
    close(sockfd);

    return 0;
}