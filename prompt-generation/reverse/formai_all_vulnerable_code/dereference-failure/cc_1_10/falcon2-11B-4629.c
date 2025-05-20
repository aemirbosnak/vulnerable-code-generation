//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

int main() {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serveraddr, clientaddr;
    struct hostent *server;
    char buffer[1024];

    if ( (server = gethostbyname("localhost")) == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        fprintf(stderr,"ERROR opening socket\n");
        exit(1);
    }

    portno = htons(PORT);

    bzero((char *) &serveraddr, sizeof(serveraddr));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = portno;
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr)) < 0) {
        fprintf(stderr,"ERROR connecting\n");
        exit(1);
    }

    while (1) {
        bzero(buffer,1024);

        newsockfd = accept(sockfd,(struct sockaddr *)&clientaddr, (socklen_t*)&portno);

        if (newsockfd < 0) {
            fprintf(stderr,"ERROR on accept\n");
            exit(1);
        }

        printf("Connection from %s port %d\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));

        while (1) {
            int len = read(newsockfd,buffer,1024);

            if (len <= 0) {
                break;
            }

            write(sockfd,buffer,len);

            bzero(buffer,1024);

            len = read(sockfd,buffer,1024);

            if (len <= 0) {
                break;
            }

            write(newsockfd,buffer,len);
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}