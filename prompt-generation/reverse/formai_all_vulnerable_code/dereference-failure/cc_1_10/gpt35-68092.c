//FormAI DATASET v1.0 Category: Chat server ; Style: Romeo and Juliet
// Romeo and Juliet C Chat Server Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
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

    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd,
                (struct sockaddr *) &cli_addr,
                &clilen);
    if (newsockfd < 0)
        error("ERROR on accept");

    printf("Romeo: Oh, my dear, what news do you bring? I have opened a socket!\n");

    while(1) {

        bzero(buffer,256);

        n = read(newsockfd,buffer,255);
        if (n < 0)
            error("ERROR reading from socket");

        printf("Juliet: My sweet Romeo! I have received a message: %s",buffer);

        if (strncmp(buffer,"Goodbye",7) == 0) {
            printf("Romeo: Oh no, must you go so soon?\n");
            break;
        }

        printf("Romeo: I shall reply with 'Hello, my dearest Juliet!'...\n");

        n = write(newsockfd,"Hello, my dearest Juliet!",25);
        if (n < 0)
            error("ERROR writing to socket");
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}