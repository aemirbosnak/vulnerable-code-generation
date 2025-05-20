//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define SERVER "imap.example.com"
#define PORT 143
#define USER "username"
#define PASSWORD "password"

int main() {
    int sockfd, status;
    struct sockaddr_in servaddr;
    struct hostent *server;
    char buffer[4096];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // set up address
    server = gethostbyname(SERVER);
    if (server == NULL) {
        perror("ERROR, no such host");
        exit(1);
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(PORT);

    // connect to server
    status = connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    if (status < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // login
    printf("Logging in...\n");
    status = send(sockfd, USER + strlen(USER) + strlen(PASSWORD) + strlen("\r\n"), strlen(USER) + strlen(PASSWORD) + 3, 0);
    if (status < 0) {
        perror("ERROR sending login data");
        exit(1);
    }
    status = recv(sockfd, buffer, 4096, 0);
    if (status < 0) {
        perror("ERROR receiving response");
        exit(1);
    }
    if (buffer[0] == '*') {
        printf("Login successful.\n");
    } else {
        printf("Login failed.\n");
        exit(1);
    }

    // list messages
    printf("Listing messages...\n");
    status = send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0);
    if (status < 0) {
        perror("ERROR sending LIST command");
        exit(1);
    }
    status = recv(sockfd, buffer, 4096, 0);
    if (status < 0) {
        perror("ERROR receiving response");
        exit(1);
    }
    if (buffer[0] == '*') {
        printf("Listing messages: %s\n", buffer);
    } else {
        printf("ERROR listing messages\n");
        exit(1);
    }

    // close socket
    close(sockfd);

    return 0;
}