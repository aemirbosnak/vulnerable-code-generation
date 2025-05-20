//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];
    if (argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        return 1;
    }

    // Resolve the hostname
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "error: no such host: %s\n", argv[1]);
        return 1;
    }

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("error: cannot create socket");
        return 1;
    }

    // Set the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("error: cannot connect to server");
        return 1;
    }

    // Send the HTTP GET request
    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE, "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", argv[1]);
    n = write(sockfd, request, strlen(request));
    if (n < 0) {
        perror("error: cannot write to socket");
        return 1;
    }

    // Read the response from the server and print it to the console
    while((n = read(sockfd, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    // Cleanup
    close(sockfd);
    return 0;
}