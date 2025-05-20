//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_MSG_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_MSG_SIZE];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        fprintf(stderr,"ERROR opening socket\n");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }
    
    // Set server address properties
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Make connection
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr,"ERROR connecting\n");
        exit(EXIT_FAILURE);
    }

    // Send message to server
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    n = send(sockfd, buffer, strlen(buffer), 0);

    if (n < 0) {
        fprintf(stderr,"ERROR writing to socket\n");
        exit(EXIT_FAILURE);
    }

    // Receive message from server
    memset(buffer, 0, MAX_MSG_SIZE);
    n = recv(sockfd, buffer, MAX_MSG_SIZE-1, 0);

    if (n < 0) {
        fprintf(stderr,"ERROR reading from socket\n");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer);

    // Send QUIT command to server
    sprintf(buffer, "QUIT\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);

    if (n < 0) {
        fprintf(stderr,"ERROR writing to socket\n");
        exit(EXIT_FAILURE);
    }

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}