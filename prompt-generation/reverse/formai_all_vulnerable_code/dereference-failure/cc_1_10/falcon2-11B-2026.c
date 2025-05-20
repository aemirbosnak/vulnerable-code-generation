//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 993
#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int opt = 1;
    char buffer[MAX_BUFFER];
    char *mailbox = "INBOX";

    // Initialize socket and server address structure
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if ((server = gethostbyname("imap.example.com")) == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(EXIT_FAILURE);
    } else {
        bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &opt, sizeof(int)) < 0) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Send the IMAP login command
    snprintf(buffer, MAX_BUFFER, "LOGIN %s %s\r\n", argv[1], argv[2]);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive the response from the server
    if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    // Print the server response
    printf("%s\n", buffer);

    // Send the IMAP select mailbox command
    snprintf(buffer, MAX_BUFFER, "SELECT %s\r\n", mailbox);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive the response from the server
    if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    // Print the server response
    printf("%s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}