//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// function to build HTTP request given host and path
char *build_http_request(char *host, char *path) {
    char *request = (char *) malloc(200 * sizeof(char));
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
    return request;
}

int main() {
    // get host name and path from user
    char host[100], path[100];
    printf("Enter host name: ");
    scanf("%s", host);
    printf("Enter path: ");
    scanf("%s", path);

    // get host information
    printf("Resolving host name...\n");
    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        printf("Error resolving host name.\n");
        exit(1);
    }

    // create socket
    printf("Creating socket...\n");
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    // connect to server
    printf("Connecting to server...\n");
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(80);
    serveraddr.sin_addr = *((struct in_addr *) he->h_addr);
    memset(&(serveraddr.sin_zero), '\0', 8);
    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(struct sockaddr)) == -1) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    // build HTTP request
    printf("Building HTTP request...\n");
    char *request = build_http_request(host, path);

    // send HTTP request
    printf("Sending HTTP request...\n");
    int bytes_sent = send(sockfd, request, strlen(request), 0);
    if (bytes_sent == -1) {
        printf("Error sending HTTP request.\n");
        exit(1);
    }

    // receive HTTP response
    printf("Receiving HTTP response...\n");
    char response[8192] = ""; // assume maximum response size of 8192 bytes
    int bytes_received = recv(sockfd, response, sizeof(response), 0);
    if (bytes_received == -1) {
        printf("Error receiving HTTP response.\n");
        exit(1);
    }

    // print HTTP response
    printf("HTTP response:\n%s", response);

    // cleanup
    free(request);
    close(sockfd);

    return 0;
}