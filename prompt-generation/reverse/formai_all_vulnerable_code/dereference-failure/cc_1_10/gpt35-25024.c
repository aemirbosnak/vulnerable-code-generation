//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 80
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return -1;
    }

    char *hostname = argv[1];
    struct hostent *host = gethostbyname(hostname);

    if (!host) {
        printf("Cannot resolve hostname %s\n", hostname);
        return -1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr = *((struct in_addr *) host->h_addr);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        return -1;
    }

    char request[BUFFER_SIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", hostname);

    if (send(sockfd, request, strlen(request), 0) < 0) {
        printf("Error sending request\n");
        return -1;
    }

    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);

    if (recv(sockfd, response, BUFFER_SIZE, 0) < 0) {
        printf("Error receiving response\n");
        return -1;
    }

    printf("%s\n", response);

    close(sockfd);

    return 0;
}