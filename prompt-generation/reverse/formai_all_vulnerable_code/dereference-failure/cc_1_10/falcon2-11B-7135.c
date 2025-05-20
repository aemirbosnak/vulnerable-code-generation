//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <time.h>

#define MAX_URL_LENGTH 1024
#define TIMEOUT_SECONDS 3

int main(int argc, char **argv) {
    // Check if correct number of arguments are provided
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    // Get the URL from command line argument
    char url[MAX_URL_LENGTH];
    strncpy(url, argv[1], MAX_URL_LENGTH);

    // Set up the socket
    int sockfd;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return 1;
    }
    server = gethostbyname(url);
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        return 1;
    }
    bzero((char *)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(80);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send a GET request
    char request[MAX_URL_LENGTH];
    strncpy(request, "GET / HTTP/1.1\r\nHost: ", MAX_URL_LENGTH);
    strncat(request, url, MAX_URL_LENGTH - strlen(request));
    strncat(request, "\r\n\r\n", MAX_URL_LENGTH - strlen(request));
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the response
    char response[MAX_URL_LENGTH];
    bzero(response, MAX_URL_LENGTH);
    int n = recv(sockfd, response, MAX_URL_LENGTH, 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }

    // Close the socket
    close(sockfd);

    // Check the HTTP status code
    if (response[0]!= '3') {
        printf("Website is down: %s\n", response);
        return 1;
    } else {
        printf("Website is up: %s\n", response);
        return 0;
    }
}