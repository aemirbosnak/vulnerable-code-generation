//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the constants
#define PORT 110 // POP3 server port
#define MAXLINE 100 // Maximum line length
#define MAXBUFF 1024 // Maximum buffer size
#define TIMEOUT 10 // Connection timeout

int main() {
    int sockfd, n;
    struct sockaddr_in serveraddr;
    struct hostent *server;

    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
        perror("Error creating socket");
        return 1;
    }

    server = gethostbyname("pop3.example.com");
    if ( server == NULL ) {
        fprintf(stderr, "Error, no such host\n");
        return 1;
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    memcpy(&serveraddr.sin_addr.s_addr, server->h_addr, server->h_length);

    if ( connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0 ) {
        perror("Error connecting");
        return 1;
    }

    char buffer[MAXBUFF];
    char line[MAXLINE];
    int numlines;

    // Initialize POP3 client protocol
    printf("User: ");
    fgets(line, MAXLINE, stdin);
    printf("Pass: ");
    fgets(line, MAXLINE, stdin);

    if ( send(sockfd, line, strlen(line), 0) < 0 ) {
        perror("Error sending username");
        return 1;
    }
    if ( send(sockfd, line, strlen(line), 0) < 0 ) {
        perror("Error sending password");
        return 1;
    }

    // Read the response and display the status
    memset(buffer, 0, MAXBUFF);
    n = recv(sockfd, buffer, MAXBUFF, 0);
    if ( n < 0 ) {
        perror("Error reading response");
        return 1;
    }
    buffer[n] = '\0';

    printf("%s\n", buffer);

    return 0;
}