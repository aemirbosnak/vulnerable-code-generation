//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <errno.h>

#define MAXLINE 1024

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAXLINE];
    char message[MAXLINE];
    char name[MAXLINE];

    // Initialize socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set server address and port number
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    portno = htons(1234);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    while (1) {
        printf("Enter message: ");
        fgets(message, MAXLINE, stdin);

        // Send message to server
        n = send(sockfd, message, strlen(message), 0);
        if (n < 0) {
            perror("ERROR sending message");
            exit(1);
        }

        // Receive response from server
        bzero(buffer, MAXLINE);
        n = recv(sockfd, buffer, MAXLINE, 0);
        if (n < 0) {
            perror("ERROR receiving response");
            exit(1);
        }

        printf("Server: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}