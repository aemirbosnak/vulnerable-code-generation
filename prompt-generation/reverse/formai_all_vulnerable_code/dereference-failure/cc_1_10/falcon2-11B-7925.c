//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Parse command line arguments
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // Get server address information
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Error: Unknown host\n");
        exit(1);
    }

    // Set up the server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send HTTP request
    char request[1000];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", host);
    send(sockfd, request, strlen(request), 0);

    // Receive HTTP response
    bzero(request, sizeof(request));
    n = recv(sockfd, request, sizeof(request), 0);
    if (n <= 0) {
        perror("recv");
        exit(1);
    }
    request[n] = '\0';

    // Print HTTP response
    printf("%s\n", request);

    // Close socket
    close(sockfd);

    return 0;
}