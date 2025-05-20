//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUF_SIZE];

    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        printf("Error: Host not found\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    /* Login to the server */
    bzero(buffer, BUF_SIZE);
    sprintf(buffer, "%s\r\n", "LOGIN user@domain.com password");
    n = send(sockfd, buffer, strlen(buffer), 0);

    if (n < 0) {
        perror("Error sending message to server");
        exit(1);
    }

    /* Receive the response from the server */
    bzero(buffer, BUF_SIZE);
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    printf("SERVER RESPONSE: %s", buffer);
    printf("\n");

    /* Select mailbox */
    bzero(buffer, BUF_SIZE);
    sprintf(buffer, "%s\r\n", "SELECT Inbox");
    n = send(sockfd, buffer, strlen(buffer), 0);

    if (n < 0) {
        perror("Error sending message to server");
        exit(1);
    }

    /* Receive the response from the server */
    bzero(buffer, BUF_SIZE);
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    printf("SERVER RESPONSE: %s", buffer);
    printf("\n");

    /* Logout */
    bzero(buffer, BUF_SIZE);
    sprintf(buffer, "%s\r\n", "LOGOUT");
    n = send(sockfd, buffer, strlen(buffer), 0);

    if (n < 0) {
        perror("Error sending message to server");
        exit(1);
    }

    /* Receive the response from the server */
    bzero(buffer, BUF_SIZE);
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    printf("SERVER RESPONSE: %s", buffer);
    printf("\n");

    close(sockfd);

    return 0;
}