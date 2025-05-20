//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // define variables for socket communication
    int sockfd, port;
    char *ip_address;
    struct sockaddr_in server;

    // check if command-line arguments are provided
    if(argc < 3) {
        printf("Usage: %s <IP Address> <Port>\n", argv[0]);
        return 1;
    }

    // assign IP address and port number
    ip_address = argv[1];
    port = atoi(argv[2]);

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        perror("Socket creation failed");
        return 1;
    }

    // set server information
    server.sin_addr.s_addr = inet_addr(ip_address);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // connect to the server
    if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        return 1;
    }

    // HTTP request
    char *http_request = "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n";
    char http_response[4096];

    // send HTTP request
    if(send(sockfd, http_request, strlen(http_request), 0) < 0) {
        perror("Send failed");
        return 1;
    }

    // receive HTTP response
    if(recv(sockfd, http_response, sizeof(http_response), 0) < 0) {
        perror("Receive failed");
        return 1;
    }

    // print HTTP response
    printf("HTTP Response:\n%s\n", http_response);

    // close the socket
    close(sockfd);

    return 0;
}