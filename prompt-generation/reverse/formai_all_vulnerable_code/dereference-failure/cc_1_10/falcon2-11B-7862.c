//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int socketFD, portno, newsockfd, clilen;
    struct sockaddr_in serveraddr, clientaddr;
    struct hostent *server;
    char buffer[256];

    socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFD < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("ftp.example.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(21);

    portno = connect(socketFD, (struct sockaddr *) &serveraddr, sizeof(serveraddr));
    if (portno < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    bzero((char *) &clientaddr, sizeof(clientaddr));
    clilen = sizeof(clientaddr);

    newsockfd = accept(socketFD, (struct sockaddr *) &clientaddr, &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    while (1) {
        int bytesRead = recv(newsockfd, buffer, sizeof(buffer), 0);
        if (bytesRead < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        if (bytesRead == 0) {
            break;
        }

        if (bytesRead > 0) {
            printf("Received: %s\n", buffer);
        }

        int bytesWritten = send(newsockfd, buffer, bytesRead, 0);
        if (bytesWritten < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    }

    close(newsockfd);
    close(socketFD);

    return 0;
}