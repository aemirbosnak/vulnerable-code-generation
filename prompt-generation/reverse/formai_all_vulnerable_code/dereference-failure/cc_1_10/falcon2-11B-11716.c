//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 80
#define BUFFER_SIZE 512

int main(void) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Create a struct for server address
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    server.sin_addr.s_addr = inet_addr("192.168.0.1");

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("connect");
        return 1;
    }

    // Send request
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: 192.168.0.1\r\n\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive response
    char response[BUFFER_SIZE];
    if (recv(sockfd, response, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        return 1;
    }

    // Print response
    printf("%s", response);

    // Close socket
    close(sockfd);
    return 0;
}