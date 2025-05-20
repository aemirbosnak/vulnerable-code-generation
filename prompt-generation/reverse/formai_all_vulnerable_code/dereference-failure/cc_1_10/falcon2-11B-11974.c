//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <ctype.h>

#define SERVER_PORT 993
#define SERVER_ADDR "imap.example.com"

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s username\n", argv[0]);
        exit(1);
    }

    char *username = argv[1];

    // Connect to the IMAP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("ERROR opening socket");
    }

    struct hostent *server = gethostbyname(SERVER_ADDR);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        error("ERROR connecting");
    }

    // Send the username
    char command[256];
    sprintf(command, "LOGIN %s", username);
    write(sockfd, command, strlen(command));

    // Read the server response
    char response[256];
    read(sockfd, response, 256);
    printf("Server response: %s\n", response);

    // Send the next command
    sprintf(command, "SELECT INBOX");
    write(sockfd, command, strlen(command));

    // Read the server response
    read(sockfd, response, 256);
    printf("Server response: %s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}