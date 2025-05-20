//FormAI DATASET v1.0 Category: Client Server Application ; Style: Claude Shannon
/* The following program implements a simple chat application between a server and a client using sockets in C, inspired by Claude Shannon's information theory. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_BUFFER_SIZE 256

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    printf("Waiting for client...\n");

    newsockfd = accept(sockfd,
                (struct sockaddr *) &cli_addr,
                &clilen);
    if (newsockfd < 0)
        error("ERROR on accept");

    printf("Connected!\n");

    while(1)
    {
        bzero(buffer,MAX_BUFFER_SIZE);

        n = read(newsockfd,buffer,MAX_BUFFER_SIZE);
        if (n < 0)
            error("ERROR reading from socket");

        printf("Client: %s\n",buffer);

        bzero(buffer,MAX_BUFFER_SIZE);

        printf("Server: ");
        fgets(buffer,MAX_BUFFER_SIZE,stdin);

        n = write(newsockfd,buffer,strlen(buffer));
        if (n < 0)
            error("ERROR writing to socket");
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}