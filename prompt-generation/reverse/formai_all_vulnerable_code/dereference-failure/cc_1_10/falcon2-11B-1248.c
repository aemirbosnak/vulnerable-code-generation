//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    struct timeval tv;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    // Initialize the socket and address structure
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR: no such host\n");
        exit(1);
    }
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    // Connect to the server
    connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    // Send the HTTP request
    char request[256];
    bzero(request, sizeof(request));
    sprintf(request, "GET / HTTP/1.0\r\n\r\n");
    send(sockfd, request, strlen(request), 0);

    // Receive the HTTP response
    bzero(request, sizeof(request));
    recv(sockfd, request, sizeof(request), 0);
    printf("HTTP/1.1 200 OK\r\n\r\n");

    // Print the HTTP response body
    while (strstr(request, "\r\n\r\n")) {
        char *ptr = strstr(request, "\r\n\r\n");
        ptr += 4;
        printf("%s", ptr);
        bzero(request, sizeof(request));
        recv(sockfd, request, sizeof(request), 0);
    }
    printf("\r\n");

    // Close the socket
    close(sockfd);

    return 0;
}