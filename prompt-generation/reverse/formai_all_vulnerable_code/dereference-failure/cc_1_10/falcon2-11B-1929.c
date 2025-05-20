//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 80
#define MAXLINE 512

int main() {
    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    int sockfd, n;
    char url[100];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Resolve the server address
    struct hostent *server;
    if ((server = gethostbyname("www.google.com")) == NULL) {
        perror("ERROR, no such host");
        exit(EXIT_FAILURE);
    }

    // Copy the address into servaddr
    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s\n", "www.google.com");

    char request[100];
    char response[MAXLINE];
    int response_len = 0;

    printf("Enter a URL: ");
    fgets(request, sizeof(request), stdin);
    request[strcspn(request, "\n")] = '\0';

    n = send(sockfd, request, strlen(request), 0);
    if (n < 0) {
        perror("ERROR sending request");
        exit(EXIT_FAILURE);
    }

    n = recv(sockfd, buf, MAXLINE, 0);
    if (n < 0) {
        perror("ERROR receiving response");
        exit(EXIT_FAILURE);
    }

    response_len = n;
    response[strcspn(buf, "\n")] = '\0';

    printf("Response:\n%s\n", response);

    return 0;
}