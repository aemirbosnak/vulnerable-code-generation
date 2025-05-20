//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_PORT_LEN 6
#define MAX_REQUEST_LEN 1024
#define MAX_RESPONSE_LEN 1024*10

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME_LEN] = {0};
    strncpy(hostname, argv[1], MAX_HOSTNAME_LEN-1);

    struct addrinfo hints, *result = NULL;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    int gai_err = getaddrinfo(hostname, NULL, &hints, &result);
    if (gai_err!= 0) {
        printf("Error resolving hostname: %s\n", gai_strerror(gai_err));
        return 1;
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen)!= 0) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    char request[MAX_REQUEST_LEN] = {0};
    snprintf(request, MAX_REQUEST_LEN-1, "GET / HTTP/1.0\r\nHost: %s\r\nConnection: close\r\n\r\n", hostname);

    send(sockfd, request, strlen(request), 0);

    char response[MAX_RESPONSE_LEN] = {0};
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, response+bytes_received, MAX_RESPONSE_LEN-bytes_received-1, 0)) > 0) {
        response[bytes_received] = '\0';
    }

    close(sockfd);

    printf("Response:\n%s\n", response);

    return 0;
}