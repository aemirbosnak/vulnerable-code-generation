//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_BUFFER], request[MAX_BUFFER], response[MAX_BUFFER];

    // Ensure the user provided a hostname and port number
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    // Resolve hostname
    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"error: no such host %s\n", argv[1]);
        exit(0);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("error: could not open socket");
        exit(0);
    }

    // Clear server address struct
    bzero((char *) &serv_addr, sizeof(serv_addr));

    portno = atoi(argv[2]);

    // Set server address struct attributes
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("error: could not connect");
        exit(0);
    }

    // Compose HTTP request
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nUser-Agent: HTTPClient/1.0\r\nConnection: close\r\n\r\n", argv[1]);

    // Send HTTP request
    n = write(sockfd, request, strlen(request));

    if (n < 0) {
        perror("error: could not write to socket");
        exit(0);
    }

    // Receive HTTP response
    bzero(response, MAX_BUFFER);

    while ((n = read(sockfd, buffer, MAX_BUFFER-1)) > 0) {
        strcat(response, buffer);
    }

    if (n < 0) {
        perror("error: could not read from socket");
        exit(0);
    }

    // Print HTTP response
    printf("%s", response);

    // Close socket
    close(sockfd);

    return 0;
}