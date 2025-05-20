//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 143
#define MAXLINE 1024

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAXLINE];

    // Connect to the IMAP server
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Get the server's IP address and port number
    server = gethostbyname("imap.example.com");
    if (server == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }
    portno = htons(PORT);

    // Fill in the structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send the login command
    sprintf(buffer, "login username password");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive the response
    n = recv(sockfd, buffer, MAXLINE, 0);
    if (n <= 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send the list command
    sprintf(buffer, "list");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive the response
    n = recv(sockfd, buffer, MAXLINE, 0);
    if (n <= 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Disconnect from the server
    close(sockfd);

    return 0;
}