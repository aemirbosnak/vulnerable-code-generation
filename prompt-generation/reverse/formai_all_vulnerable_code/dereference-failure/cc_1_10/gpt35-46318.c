//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct hostent *he = gethostbyname(hostname);
    if (he == NULL) {
        printf("Failed to resolve hostname %s\n", hostname);
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *) he->h_addr);
    memset(&(server_addr.sin_zero), '\0', 8);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(struct sockaddr)) == -1) {
        perror("Failed to connect to server");
        exit(1);
    }

    char request[BUFFER_SIZE], response[BUFFER_SIZE];
    sprintf(request, "GET / HTTP/1.1\r\n"
                      "Host: %s:%d\r\n"
                      "Connection: close\r\n\r\n", hostname, port);

    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("Failed to send request");
        exit(1);
    }

    memset(response, 0, BUFFER_SIZE);
    int bytes_received = recv(sockfd, response, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Failed to receive response");
        exit(1);
    }

    printf("Response received:\n%s", response);

    close(sockfd);
    return 0;
}