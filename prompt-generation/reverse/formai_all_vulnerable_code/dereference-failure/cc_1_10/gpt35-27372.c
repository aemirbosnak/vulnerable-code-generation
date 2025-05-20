//FormAI DATASET v1.0 Category: Client Server Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    if (argc < 2) {
        fprintf(stderr,"Usage: %s port\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    printf("Waiting for a client to connect...\n");
    newsockfd = accept(sockfd,
                (struct sockaddr *) &cli_addr,
                &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    printf("A client has connected!\n");

    while(1) {
        bzero(buffer,256);
        n = read(newsockfd,buffer,255);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Message from client: %s\n", buffer);

        if (strcmp(buffer, "exit\n") == 0) {
            break;
        }

        n = write(newsockfd,"I got your message",18);
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}