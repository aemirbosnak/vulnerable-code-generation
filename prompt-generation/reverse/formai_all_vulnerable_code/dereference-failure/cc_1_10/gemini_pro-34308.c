//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    // Get the host name and port number
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        perror("gethostbyname");
        return 1;
    }
    servaddr.sin_addr = *((struct in_addr *)he->h_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send a greeting to the server
    char *greeting = "Hello, world!\n";
    if (send(sockfd, greeting, strlen(greeting), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive a response from the server
    char buffer[MAXLINE];
    int n = recv(sockfd, buffer, MAXLINE, 0);
    if (n == -1) {
        perror("recv");
        return 1;
    }

    // Print the response
    printf("%s", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}