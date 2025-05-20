//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *url = argv[1];

    // Create a socket
    int sockfd;
    struct sockaddr_in serv_addr;
    int addrlen = sizeof(serv_addr);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, addrlen) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    // Send HTTP request
    char request[1024] = "GET / HTTP/1.1\r\nHost: ";
    strcat(request, url);
    strcat(request, "\r\n\r\n");
    write(sockfd, request, strlen(request));

    // Read and print response
    int bytes_read;
    char response[1024];
    while ((bytes_read = read(sockfd, response, sizeof(response))) > 0) {
        printf("%s", response);
    }
    if (bytes_read == 0) {
        printf("Connection closed by server.\n");
    } else {
        perror("ERROR reading from socket");
    }

    // Close socket
    close(sockfd);

    return 0;
}