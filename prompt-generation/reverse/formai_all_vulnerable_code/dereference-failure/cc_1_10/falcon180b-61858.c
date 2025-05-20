//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAXLINE 4096
#define TRUE 1
#define FALSE 0
#define PORT "12345"
#define SERVER "127.0.0.1"

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAXLINE];
    int n;
    int len;
    char *ptr;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    server = gethostbyname(SERVER);
    if (server == NULL) {
        printf("Error getting host by name\n");
        exit(1);
    }
    memcpy(&serv_addr.sin_addr, server->h_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(PORT));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Receive server message
    n = recv(sockfd, buffer, MAXLINE, 0);
    if (n < 0) {
        printf("Error receiving message from server\n");
        exit(1);
    }
    buffer[n] = '\0';
    printf("Server message: %s\n", buffer);

    // Send client message
    printf("Enter your message: ");
    fgets(buffer, MAXLINE, stdin);
    len = strlen(buffer);
    if (send(sockfd, buffer, len, 0) < 0) {
        printf("Error sending message to server\n");
        exit(1);
    }

    // Receive server response
    n = recv(sockfd, buffer, MAXLINE, 0);
    if (n < 0) {
        printf("Error receiving message from server\n");
        exit(1);
    }
    buffer[n] = '\0';
    printf("Server response: %s\n", buffer);

    // Close socket
    close(sockfd);
    return 0;
}