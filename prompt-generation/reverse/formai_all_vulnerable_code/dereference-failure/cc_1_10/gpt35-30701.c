//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    char *hostname = "www.google.com";
    char path[MAX_BUFFER] = "/";
    int port = 80;

    // Check if the arguments were provided
    if (argc > 1) {
        hostname = argv[1];

        if (argc > 2) {
            strcpy(path, argv[2]);
        }
    }

    // Get host information
    struct hostent *host = gethostbyname(hostname);

    if (host == NULL) {
        perror("Error in gethostbyname()");
        exit(EXIT_FAILURE);
    }

    // Create a socket
    int sockfd;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error in socket()");
        exit(EXIT_FAILURE);
    }

    // Set server information
    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    bcopy((char *)host->h_addr, (char *)&serv_addr.sin_addr.s_addr, host->h_length);

    // Connect to server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("Error in connect()");
        exit(EXIT_FAILURE);
    }

    // Send request
    char request[MAX_BUFFER];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    if (write(sockfd, request, strlen(request)) < 0) {
        perror("Error in write()");
        exit(EXIT_FAILURE);
    }

    // Read response
    char buffer[MAX_BUFFER];
    int bytes;
    while ((bytes = read(sockfd, buffer, MAX_BUFFER)) > 0) {
        fwrite(buffer, sizeof(char), bytes, stdout);
    }

    if (bytes < 0) {
        perror("Error in read()");
        exit(EXIT_FAILURE);
    }

    // Close socket
    close(sockfd);

    return 0;
}