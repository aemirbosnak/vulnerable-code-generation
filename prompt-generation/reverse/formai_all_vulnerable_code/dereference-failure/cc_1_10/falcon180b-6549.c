//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char *url = argv[1];

    // Get server information
    server = gethostbyname(url);
    if (server == NULL) {
        printf("Error: could not resolve host name\n");
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: could not create socket\n");
        exit(1);
    }

    // Connect to server
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: could not connect to server\n");
        exit(1);
    }

    // Send HTTP request
    char *request = "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n";
    sprintf(buffer, request, url);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive response
    char *response = "";
    while ((recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        response = strcat(response, buffer);
    }

    // Print response
    printf("%s", response);

    // Close socket
    close(sockfd);
    return 0;
}